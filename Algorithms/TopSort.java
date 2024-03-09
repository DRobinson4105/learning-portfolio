import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class TopSort {
    static List<Integer> topologicalSort(List<List<Integer>> graph, int v) {
        int[] inDegree = new int[v];
        List<Integer> result = new ArrayList<>();
        int count = 0;
        Queue<Integer> q = new LinkedList<>();

        for (List<Integer> outgoing : graph)
            for (int next : outgoing)
                inDegree[next]++;

        for (int i = 0; i < v; i++)
            if (inDegree[i] == 0) q.add(i);

        while (!q.isEmpty()) {
            int curr = q.poll();
            result.add(curr);
            count++;

            for (int next : graph.get(curr))
                if (--inDegree[next] == 0)
                    q.add(next);
        }

        return count != v ? new ArrayList<>() : result;
    }

    public static void main(String[] args) {
        int v = 6;
        List<List<Integer>> graph = new ArrayList<>();

        for (int i = 0; i < 6; i++)
            graph.add(new ArrayList<>());

        graph.get(5).add(2);
        graph.get(2).add(0);
        graph.get(4).add(0);
        graph.get(4).add(1);
        graph.get(2).add(3);
        graph.get(3).add(1);
        graph.get(5).add(4);
        graph.get(4).add(2);
        graph.get(1).add(0);
        
        List<Integer> result = topologicalSort(graph, v);
        List<Integer> answer = Arrays.asList(5, 4, 2, 3, 1, 0);
        System.out.println(result.equals(answer));
    }
}
