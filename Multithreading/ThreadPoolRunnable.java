import java.util.concurrent.BlockingQueue;

public class ThreadPoolRunnable implements Runnable {
    private Thread thread = null;
    private BlockingQueue<Runnable> taskQueue = null;
    private boolean isStopped = false;

    public ThreadPoolRunnable(BlockingQueue<Runnable> taskQueue) {
        this.taskQueue = taskQueue;
    }

    @Override
    public void run() {
        this.thread = Thread.currentThread();

        while (!isStopped()) {
            try {
                taskQueue.take().run();
            } catch (InterruptedException e) {
                // if stop was not called
                if (!isStopped) e.printStackTrace();
            }
        }
    }

    public synchronized void stop() {
        isStopped = true;
        this.thread.interrupt();
    }

    public synchronized boolean isStopped() {
        return isStopped;
    }
}
