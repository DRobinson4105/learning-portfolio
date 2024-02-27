// java --add-exports java.base/jdk.internal.vm.annotation=ALL-UNNAMED --add-opens java.base/jdk.internal.vm.annotation=ALL-UNNAMED FalseSharing.java

import java.util.concurrent.atomic.AtomicInteger;

public class FalseSharing {
	static class CountersWithContended {
		@jdk.internal.vm.annotation.Contended
		public volatile int count1 = 0;
		@jdk.internal.vm.annotation.Contended
		public volatile int count2 = 0;
	}

	static class CountersWithoutContended {
		public volatile int count1 = 0;
		public volatile int count2 = 0;
	}

	public static void main(String[] args) {
		CountersWithContended countersWithContended = new CountersWithContended();
		CountersWithoutContended countersWithoutContended = new CountersWithoutContended();

		System.out.println("Runtime with Contended annotation:");
		Thread thread1 = new Thread(() -> {
			long start = System.currentTimeMillis();

			for (long i = 0; i < 1_000_000; i++)
				countersWithContended.count1++;

			long end = System.currentTimeMillis();

			System.out.println(Thread.currentThread().getName() + (end - start) + "ms");
		});
		Thread thread2 = new Thread(() -> {
			long start = System.currentTimeMillis();

			for (long i = 0; i < 1_000_000; i++)
				countersWithContended.count2++;

			long end = System.currentTimeMillis();

			System.out.println(Thread.currentThread().getName() + (end - start) + "ms");
		});

		thread1.start(); thread2.start();

        while (thread1.isAlive() || thread2.isAlive()) {
            // wait until both threads stop
        }

		System.out.println("Runtime without Contended annotation:");
		thread1 = new Thread(() -> {
			long start = System.currentTimeMillis();

			for (long i = 0; i < 1_000_000; i++)
				countersWithoutContended.count1++;

			long end = System.currentTimeMillis();

			System.out.println(Thread.currentThread().getName() + (end - start) + "ms");
		});
		thread2 = new Thread(() -> {
			long start = System.currentTimeMillis();

			for (long i = 0; i < 1_000_000; i++)
				countersWithoutContended.count2++;

			long end = System.currentTimeMillis();

			System.out.println(Thread.currentThread().getName() + (end - start) + "ms");
		});

		thread1.start(); thread2.start();
	}
}