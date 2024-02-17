import java.util.*;

public class QuickSort {
    public static void sort(List<Integer> list) {
        sortHelper(list, 0, list.size()-1);
    }
    private static void sortHelper(List<Integer> list, int low, int high) {
        if (low >= high) return;

        int mid = partition(list, low, high);
        
        sortHelper(list, low, mid-1);
        sortHelper(list, mid+1, high);
    }

    private static void swap(List<Integer> list, int i, int j) {
        int tmp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, tmp);
    }

    private static int partition(List<Integer> list, int low, int high) {
        int idx = new Random().nextInt(high-low+1) + low;
        swap(list, idx, low);
        int p = list.get(low);
        
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= j && list.get(i) < p) i++;
            while (i <= j && list.get(j) >= p) j--;

            if (i < j) swap(list, i, j);
        }
        
        swap(list, low, j);
        return j;
    }

    private static boolean isSorted(List<Integer> list) {
        for (int i = 1; i < list.size(); i++)
            if (list.get(i) < list.get(i-1)) return false;

        return true;
    }

    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();
        Random r = new Random();

        for (int i = 0; i < 10; i++)
            list.add(r.nextInt());

        System.out.println(list);

        QuickSort.sort(list);

        System.out.println(list);
        System.out.println(isSorted(list));
    }
}
