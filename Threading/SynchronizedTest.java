public class SynchronizedTest {
    private static long count = 0;

    public static synchronized void set(long val) {
        count = val;
    }

    public static void increment() {
        count++;
    }

    public static long get() {
        return count;
    }

    public static synchronized void syncIncrement() {
        count++;
    }

    public static synchronized long syncGet() {
        return count;
    }
    
    public static void main(String[] args) {
        // Threads are not synchronized so the increments can run simultaneously which would result
        // in the loss of one of the increments
        System.out.println("Not synchronized:");
        Thread thread1 = new Thread(() -> {
            for (int i = 0; i < 1e6; i++) {
                SynchronizedTest.increment();
            }
            System.out.println(SynchronizedTest.get());
        });

        Thread thread2 = new Thread(() -> {
            for (int i = 0; i < 1e6; i++) {
                SynchronizedTest.increment();
            }
            System.out.println(SynchronizedTest.get());
        });

        thread1.start();
        thread2.start();

        while (thread1.isAlive() || thread2.isAlive()) {
            // wait until both threads stop
        }
        SynchronizedTest.set(0);

        // Threads are synchronized so the increments will not run simultaneously
        System.out.println("Synchronized:");
        thread1 = new Thread(() -> {
            for (int i = 0; i < 1e6; i++) {
                SynchronizedTest.syncIncrement();
            }
            System.out.println(SynchronizedTest.syncGet());
        });

        thread2 = new Thread(() -> {
            for (int i = 0; i < 1e6; i++) {
                SynchronizedTest.syncIncrement();
            }
            System.out.println(SynchronizedTest.syncGet());
        });

        thread1.start();
        thread2.start();
    }
}