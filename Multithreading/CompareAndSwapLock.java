import java.util.concurrent.atomic.AtomicBoolean;

public class CompareAndSwapLock {
    private AtomicBoolean isLocked = new AtomicBoolean();
    
    public void unlock() {
        isLocked.set(false);
    }

    public void lock() {
        // wait until boolean is false and then set it to true
        while (!isLocked.compareAndSet(false, true)) {}
    }
}