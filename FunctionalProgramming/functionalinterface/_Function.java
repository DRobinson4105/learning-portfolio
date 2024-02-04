package functionalinterface;

import java.util.function.BiFunction;
import java.util.function.Function;

public class _Function {
    public static void main(String[] args) {
        int result = incrementByOne(0);
        System.out.println(result);

        result = incrementByOneFunction.apply(result);
        System.out.println(result);

        result = incrementByOneFunction.andThen(incrementByOneFunction).apply(result);
        System.out.println(result);

        result = addFunction.apply(result, 10);
        System.out.println(result);
    }

    static Function<Integer, Integer> incrementByOneFunction = number -> number + 1;

    static BiFunction<Integer, Integer, Integer> addFunction = (num1, num2) -> num1 + num2;

    static int incrementByOne(int num) { return num + 1; }
}
