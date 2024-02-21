public class LockedTest {
    private static Runnable getRunnable(Counter counter) {
        return () -> {
            for (int i = 0; i < 1e6; i++)
                counter.increment();

            System.out.println(counter.get());
        };
    }
    
    public static void main(String[] args) {
        Counter counter = new Counter();
        LockedCounter lockedCounter = new LockedCounter();

        // Increment method does not have a lock so the increments can run simultaneously which
        // would result in the loss of one of the increments
        System.out.println("Without lock:");
        Thread thread1 = new Thread(getRunnable(counter));
        Thread thread2 = new Thread(getRunnable(counter));

        thread1.start();
        thread2.start();

        while (thread1.isAlive() || thread2.isAlive()) {
            // wait until both threads stop
        }

        // When a thread starts incrementing, it puts a lock on it so all other threads that start
        // incrementing have to wait for the current thread to unlock it when it finishes
        // incrementing
        System.out.println("With lock:");
        thread1 = new Thread(getRunnable(lockedCounter));
        thread2 = new Thread(getRunnable(lockedCounter));

        thread1.start();
        thread2.start();
    }
}