import java.util.*;

public class ShellSort {
    public static void sort(List<Integer> list) {
        for (int gap = list.size() / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < list.size(); i++) {
                int tmp = list.get(i);

                int j;
                for (j = i; j >= gap && list.get(j - gap) > tmp; j -= gap)
                    list.set(j, list.get(j - gap));

                list.set(j, tmp);
            }
        }
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

        ShellSort.sort(list);

        System.out.println(list);
        System.out.println(isSorted(list));
    }
}
