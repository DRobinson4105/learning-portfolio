public class ThreadLocalTest {
    public static void main(String[] args) {
        // Value stored is unique for each thread
        ThreadLocal<String> threadLocal = ThreadLocal.withInitial(() -> "val not set");

        Thread thread1 = new Thread(() -> {
            threadLocal.set("val set");
            System.out.println(Thread.currentThread().getName() + ": " + threadLocal.get());
        });

        Thread thread2 = new Thread(() -> {
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println(Thread.currentThread().getName() + ": " + threadLocal.get());
        });

        thread1.start();
        thread2.start();
    }
}