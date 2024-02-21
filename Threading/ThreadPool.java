import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class ThreadPool {
    private BlockingQueue<Runnable> taskQueue = null;
    private List<ThreadPoolRunnable> runnables = new ArrayList<>();
    private boolean isStopped = false;

    public ThreadPool(int threads, int tasks) {
        taskQueue = new ArrayBlockingQueue<>(tasks);

        for (int i = 0; i < threads; i++)
            runnables.add(new ThreadPoolRunnable(taskQueue));
        
        for (ThreadPoolRunnable runnable : runnables)
            new Thread(runnable).start();

    }

    public synchronized void execute(Runnable task) throws Exception {
        if (this.isStopped) throw new IllegalStateException("ThreadPool is stopped");

        taskQueue.offer(task);
    }

    public synchronized void stop() {
        this.isStopped = true;
        for (ThreadPoolRunnable runnable : runnables) {
            runnable.stop();
        }
    }

    public synchronized void waitUntilAllTasksFinished() {
        while (this.taskQueue.size() > 0) {
            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) throws Exception {
        ThreadPool threadPool = new ThreadPool(3, 10);

        for (int i = 0; i < 10; i++) {
            int taskNumber = i;
            threadPool.execute(() -> {
                System.out.println(Thread.currentThread().getName() + ": Task " + taskNumber);
            });
        }

        threadPool.waitUntilAllTasksFinished();
        threadPool.stop();
    }
}