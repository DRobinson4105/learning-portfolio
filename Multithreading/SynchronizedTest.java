public class SynchronizedTest {
    private static Runnable getRunnable(Counter counter) {
        return () -> {
            for (int i = 0; i < 1e6; i++)
                counter.increment();

            System.out.println(counter.get());
        };
    }
    
    public static void main(String[] args) {
        Counter counter = Counters.createBasicCounter();
        Counter synchronizedCounter = Counters.createSynchronizedCounter();

        // Increment method is not synchronized so the increments can run simultaneously which
        // would result in the loss of one of the increments
        // ### read-modify-write race condition ###
        // both threads read old value
        // both threads increment the read value
        // both threads write back the old value + 1
        System.out.println("Not synchronized:");
        Thread thread1 = new Thread(getRunnable(counter));
        Thread thread2 = new Thread(getRunnable(counter));

        thread1.start();
        thread2.start();

        while (thread1.isAlive() || thread2.isAlive()) {
            // wait until both threads stop
        }

        // Threads are synchronized so the increments will not run simultaneously
        System.out.println("Synchronized:");
        thread1 = new Thread(getRunnable(synchronizedCounter));
        thread2 = new Thread(getRunnable(synchronizedCounter));

        thread1.start();
        thread2.start();
    }
}