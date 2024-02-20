public class InheritableThreadLocalTest {
    public static void main(String[] args) {
        ThreadLocal<String> threadLocal = new ThreadLocal<>();
        InheritableThreadLocal<String> inheritableThreadLocal = new InheritableThreadLocal<>();

        // ThreadLocal stores unique value for each thread
        // InheritableThreadLocal will share values between parent and child threads
        Thread parentThread = new Thread(() -> {
            threadLocal.set("val set");
            inheritableThreadLocal.set("val set");
            
            System.out.println("Parent Thread:");
            System.out.println("Thread Local: " + threadLocal.get());
            System.out.println("Inheritable Thread Local: " + inheritableThreadLocal.get());

            Thread childThread = new Thread(() -> {
                System.out.println("Child Thread: ");
                System.out.println("Thread Local: " + threadLocal.get());
                System.out.println("Inheritable Thread Local: " + inheritableThreadLocal.get());
            });

            childThread.start();
        });

        parentThread.start();
    }
}