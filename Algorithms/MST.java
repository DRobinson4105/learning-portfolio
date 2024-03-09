import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class MST {
    static class Edge implements Comparable<Edge> {
        int v1, v2, w;
        
        public Edge(int v1, int v2, int w) {
            this.v1 = v1; this.v2 = v2; this.w = w;
        }

        @Override
        public int compareTo(Edge other) {
            return this.w - other.w;
        }
    }

    public static int mst(List<Edge>[] graph, int v, int n) {
        boolean[] used = new boolean[n];
        used[v] = true;

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        for (int i = 0; i < graph[v].size(); i++)
            pq.offer(graph[v].get(i));

        int numEdges = 0, res = 0;

        while (!pq.isEmpty()) {
            Edge next = pq.poll();
            if (used[next.v1] && used[next.v2]) continue;

            if (!used[next.v1]) {
                for (int i = 0; i < graph[next.v1].size(); i++)
                    pq.offer(graph[next.v1].get(i));

                used[next.v1] = true;
            } else {
                for (int i = 0; i < graph[next.v2].size(); i++)
                    pq.offer(graph[next.v2].get(i));

                used[next.v2] = true;
            }

            numEdges++;
            res += next.w;
            if (numEdges == n-1) break;
        }

        return numEdges == n-1 ? res : -1;
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        ArrayList<Edge>[] graph = new ArrayList[]{
            new ArrayList<>(Arrays.asList(new Edge(0, 1, 1), new Edge(0, 2, 3), new Edge(0, 3, 2))),
            new ArrayList<>(Arrays.asList(new Edge(1, 0, 1), new Edge(1, 2, 3))),
            new ArrayList<>(Arrays.asList(new Edge(2, 0, 3), new Edge(2, 3, 1))),
            new ArrayList<>(Arrays.asList(new Edge(3, 0, 2), new Edge(3, 2, 1)))
        };

        int result = mst(graph, 0, 4);
        System.out.println(result == 4);
    }
}