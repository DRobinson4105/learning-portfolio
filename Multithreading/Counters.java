import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Counters {
    public static Counter createBasicCounter() {
        return new Counter() {
            private int count = 0;

            public void increment() {
                count++;
            }
        
            public int get() {
                return count;
            }
        };
    }

    public static Counter createSynchronizedCounter() {
        return new Counter() {
            private int count = 0;

            public synchronized void increment() {
                count++;
            }
        
            public synchronized int get() {
                return count;
            }
        };
    }

    public static Counter createLockedCounter() {
        return new Counter() {
            private Lock lock = new ReentrantLock();
            private int count = 0;

            public void increment() {
                lock.lock();
                count++;
                lock.unlock();
            }

            public int get() {
                return count;
            }
        };
    }
}