import java.util.ArrayList;
import java.util.List;

public class VirtualThread {
    public static void main(String[] args) {
        Runnable runnable = () -> {
            System.out.println(Thread.currentThread().getName());
        };

        List<Thread> vThreads = new ArrayList<>();
        
        for (int i = 0; i < 1e5; i++) {
            Thread vThread = Thread.ofVirtual().name(i + "").start(runnable);
            vThreads.add(vThread);
        }

        for (Thread vThread : vThreads) {
            try {
                vThread.join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
