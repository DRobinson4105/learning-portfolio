import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ExecutorServiceTest2 {
    public static void main(String[] args) {
        ExecutorService executorService = Executors.newFixedThreadPool(1);
        String result = "";

        Future<String> future = executorService.submit(() -> {
            return Thread.currentThread().getName() + ": Task";
        });

        System.out.println("Before waiting");
        System.out.println(future.isDone());

        try {
            // waits for result of runnable to be ready
            result = future.get();
        } catch (InterruptedException e) {} catch (ExecutionException e) {}
        
        System.out.println("After waiting");
        System.out.println(future.isDone());
        System.out.println(result);
        executorService.shutdown();
    }
}