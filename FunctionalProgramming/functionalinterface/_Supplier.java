package functionalinterface;

import java.util.function.Supplier;

public class _Supplier {
    public static void main(String[] args) {
        System.out.println(getURL());
        System.out.println(getURLSupplier.get());
    }

    static Supplier<String> getURLSupplier = () -> "jdbc://localhost:5432/users";

    static String getURL() { return "jdbc://localhost:5432/users"; }
}
