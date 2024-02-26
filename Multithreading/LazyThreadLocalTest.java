public class LazyThreadLocalTest {
    public static void main(String[] args) {
        ThreadLocal<String> threadLocal = new ThreadLocal<>();

        // Initialize value when needed
        String value = threadLocal.get();
        if (value == null) {
            threadLocal.set("Lazily set value");
            value = threadLocal.get();
        }

        System.out.println(value);
    }
}