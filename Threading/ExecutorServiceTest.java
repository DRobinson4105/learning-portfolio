import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ExecutorServiceTest {
    public static void main(String[] args) {
        ExecutorService executorService = Executors.newFixedThreadPool(3);

        for (int i = 1; i <= 10; i++) {
            int taskNumber = i;
            executorService.execute(() -> {
                System.out.println(Thread.currentThread().getName() + ": Task " + taskNumber);
            });
        }

        executorService.shutdown();
    }
}