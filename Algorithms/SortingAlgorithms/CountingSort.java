import java.util.*;

public class CountingSort {
    private static final int RANGE = 1000000;
    
    public static void sort(List<Integer> list) {
        List<Integer> freq = new ArrayList<>(RANGE);

        for (int i = 0; i < RANGE; i++) freq.add(0);
        for (Integer num : list) freq.set(num, freq.get(num) + 1);

        list.clear();
        
        for (int val = 0; val < RANGE; val++)
            for (int i = 0; i < freq.get(val); i++)
                list.add(val);
    }

    private static boolean isSorted(List<Integer> list) {
        for (int i = 1; i < list.size(); i++)
            if (list.get(i) < list.get(i-1)) return false;

        return true;
    }

    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        Random r = new Random();

        for (int i = 0; i < 10; i++) list.add(r.nextInt(RANGE));

        System.out.println(list);

        CountingSort.sort(list);

        System.out.println(list);
        System.out.println(isSorted(list));
    }
}
