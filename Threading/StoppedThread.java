public class StoppedThread {
    static class StoppableRunnable implements Runnable {
        private boolean stopRequested = false;
    
        public synchronized void requestStop() {
            this.stopRequested = true;
        }
    
        public synchronized boolean isStopRequested() {
            return this.stopRequested;
        }
    
        private void sleep(long millis) {
            try {
                Thread.sleep(millis);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    
        @Override
        public void run() {
            System.out.println(Thread.currentThread().getName() + " started");
    
            while(!isStopRequested()) {
                sleep(1000);
                System.out.println(Thread.currentThread().getName() + " running");
            }
            
            System.out.println(Thread.currentThread().getName() + " stopped");
        }
    }
    
    public static void main(String[] args) {
        StoppableRunnable runnable = new StoppableRunnable();
        Thread thread = new Thread(runnable);

        thread.start();

        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        runnable.requestStop();
        System.out.println("requesting stop");
    }
}