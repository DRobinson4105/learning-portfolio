import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicBoolean;

public class SynchronizedTest2 {
    public static void main(String[] args) {
        Map<String, String> map = new ConcurrentHashMap<>();
        AtomicBoolean raceConditionOccurred = new AtomicBoolean(false);

        // Map method calls are not synchronized so both threads can call map.containsKey() before
        // one of them removes the key, resulting in the key being removed twice
        // ### check-then-act race condition ###
        // both threads check if key is in map
        // both threads remove key since it is in map (if statement block is run twice)
        Runnable runnable = () -> {
            for (int i = 0; i < 1e6; i++) {
                if (map.containsKey("key")) {
                    String val = map.remove("key");
                    if (val == null) raceConditionOccurred.set(true);
                } else {
                    map.put("key", "value");
                }
            }
        };

        Runnable synchronizedRunnable = () -> {
            for (int i = 0; i < 1e6; i++) {
                synchronized (map) {
                    if (map.containsKey("key")) {
                        String val = map.remove("key");
                        if (val == null) raceConditionOccurred.set(true);
                    } else {
                        map.put("key", "value");
                    }
                }
            }
        };

        Thread thread1 = new Thread(runnable);
        Thread thread2 = new Thread(runnable);

        thread1.start();
        thread2.start();

        while (thread1.isAlive() || thread2.isAlive()) {
            // wait until both threads stop
        }

        if (raceConditionOccurred.get())
            System.out.println("Race condition occurred without synchronized block");
        else
            System.out.println("Race condition did not occurr without synchronized block");

        raceConditionOccurred.set(false);

        thread1 = new Thread(synchronizedRunnable);
        thread2 = new Thread(synchronizedRunnable);

        thread1.start();
        thread2.start();

        while (thread1.isAlive() || thread2.isAlive()) {
            // wait until both threads stop
        }

        if (raceConditionOccurred.get())
            System.out.println("Race condition occurred with synchronized block");
        else
            System.out.println("Race condition did not occur with synchronized block");
    }
}