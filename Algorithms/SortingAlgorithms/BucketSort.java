import java.util.*;
import static java.lang.Math.*;

public class BucketSort {
    private static final int NUM_BUCKETS = 100;

    public static void sort(List<Integer> list) {
        List<List<Integer>> buckets = new ArrayList<>();
        for (int i = 0; i < NUM_BUCKETS; i++) buckets.add(new ArrayList<>());

        int highest = Integer.MIN_VALUE, lowest = Integer.MAX_VALUE;
        for (Integer num : list) {
            highest = max(highest, num);
            lowest = min(lowest, num);
        }
        
        for (Integer num : list) buckets.get(index(num, lowest, highest)).add(num);

        list.clear();

        for (List<Integer> bucket : buckets) {
            RadixSort.sort(bucket);
            list.addAll(bucket);
        }
    }

    private static int index(int num, long lowest, long highest) {
        long shiftedNum = num - lowest;
        long range = highest - lowest + 1;
        double normalizedValue = (double) shiftedNum / range;
        
        return (int)(normalizedValue * NUM_BUCKETS);
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

        BucketSort.sort(list);

        System.out.println(list);
        System.out.println(isSorted(list));
    }
}
