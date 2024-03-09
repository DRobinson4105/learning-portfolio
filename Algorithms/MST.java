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

    static class DS {
        int arr[];
    
        public DS(int n) {
            arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = -1;
        }
    
        // Returns the parent of the set containing x
        public int find(int x) {
            return (arr[x] < 0) ? x : (arr[x] = find(arr[x]));
        }
    
        // Merges the sets containing a and b
        public boolean merge(int a, int b) {
            int p1 = find(a);
            int p2 = find(b);
            
            if (p1 == p2) return false;
    
            arr[p1] += arr[p2];
            arr[p2] = p1;
            return true;
        }
    }

    static int prims(List<Edge>[] graph, int n) {
        boolean[] used = new boolean[n];
        used[0] = true;

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        for (int i = 0; i < graph[0].size(); i++)
            pq.offer(graph[0].get(i));

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

    static int kruskals(Edge[] edges, int n) {
        Arrays.sort(edges);
        DS ds = new DS(n);
        int numEdges = 0, res = 0;

        for (Edge edge : edges) {
            if (!ds.merge(edge.v1, edge.v2)) continue;

            numEdges++;
            res += edge.w;
            if (numEdges == n-1) break;
        }

        return numEdges == n-1 ? res : -1;
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        int v = 4;

        ArrayList<Edge>[] graph = new ArrayList[]{
            new ArrayList<>(Arrays.asList(new Edge(0, 1, 1), new Edge(0, 2, 3),
                new Edge(0, 3, 2))),
            new ArrayList<>(Arrays.asList(new Edge(1, 0, 1), new Edge(1, 2, 3))),
            new ArrayList<>(Arrays.asList(new Edge(2, 0, 3), new Edge(2, 1, 3),
                new Edge(2, 3, 1))),
            new ArrayList<>(Arrays.asList(new Edge(3, 0, 2), new Edge(3, 2, 1)))
        };

        Edge[] edges = new Edge[]{
            new Edge(0, 1, 1), new Edge(0, 2, 3), new Edge(0, 3, 2),
            new Edge(1, 2, 3), new Edge(2, 3, 1)
        };

        int primsResult = prims(graph, v);
        int kruskalsResult = kruskals(edges, v);
        System.out.println(primsResult == 4);
        System.out.println(kruskalsResult == 4);
    }
}