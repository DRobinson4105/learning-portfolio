public class WaitAndNotifyTest {
    public static void main(String[] args) {
        Object signalObject = new Object();

        Thread waitingThread = new Thread(() -> {
            System.out.println("started waiting");

            synchronized (signalObject) {
                try {
                    signalObject.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            System.out.println("finished waiting");
        });

        Thread notifyingThread = new Thread(() -> {
            try {
                Thread.sleep(4000);
            } catch (InterruptedException e) {}

            System.out.println("notifying thread");
            synchronized (signalObject) {
                signalObject.notify();
            }
        });

        waitingThread.start(); notifyingThread.start();
    }
}