import java.util.*;
import static java.lang.Math.*;

public class RadixSort {
    public static void sort(List<Integer> list) {
        int highestDigit = 0;
        for (Integer num : list) {
            highestDigit = max(highestDigit, digits(num));
        }

        for (int i = 0; i < highestDigit; i++) {
            final int numDigits = i;
            Collections.sort(list, (Integer a, Integer b) -> {
                int aDigit = (a / (int)pow(10, numDigits)) % 10;
                int bDigit = (b / (int)pow(10, numDigits)) % 10;
                return aDigit - bDigit;
            });
        }
    }

    private static int digits(int num) {
        num = abs(num);
        int digits = 0;

        while (num > 0) {
            num /= 10;
            digits++;
        }

        return digits;
    }

    private static boolean isSorted(List<Integer> list) {
        for (int i = 1; i < list.size(); i++)
            if (list.get(i) < list.get(i-1)) return false;

        return true;
    }

    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        Random r = new Random();
        
        for (int i = 0; i < 10; i++) list.add(r.nextInt());

        System.out.println(list);

        RadixSort.sort(list);

        System.out.println(list);
        System.out.println(isSorted(list));
    }
}
