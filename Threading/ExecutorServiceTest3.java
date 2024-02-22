import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ExecutorServiceTest3 {
    public static void main(String[] args) {
        ExecutorService executorService = Executors.newFixedThreadPool(3);
        List<Callable<String>> callables = new ArrayList<>();

        for (int i = 1; i <= 3; i++) {
            int taskNumber = i;
            callables.add(() -> Thread.currentThread().getName() + ": Task " + taskNumber);
        }

        // return the first completed callable
        try {
            System.out.println(executorService.invokeAny(callables));
        } catch (InterruptedException e) {} catch (ExecutionException e) {}

        // returns all callables as Futures
        try {
            System.out.println(executorService.invokeAll(callables).stream().map(result -> {
                try {
                    return result.get();
                } catch (InterruptedException e) {} catch (ExecutionException e) {}
                return "Failed task";
            }).toList());
        } catch (InterruptedException e) {}
        executorService.shutdown();
    }
}