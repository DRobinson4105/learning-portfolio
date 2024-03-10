import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class NetworkFlow {
    final static int INF = (int)1e9;

    static class FordFulkerson {
        int[][] cap;
        int n, source, sink;

        public FordFulkerson(int size) {
            n = size; source = n++; sink = n++;
            cap = new int[n][n];
        }

        public void add(int v1, int v2, int c) {
            cap[v1][v2] = c;
        }

        public int maxFlow() {
            boolean[] visited = new boolean[n];
            int flow = 0;

            while (true) {
                Arrays.fill(visited, false);
                int res = dfs(source, visited, INF);

                if (res == 0) break;

                flow += res;
            }

            return flow;
        }

        private int dfs(int v, boolean[] visited, int min) {
            if (v == sink) return min;
            if (visited[v]) return 0;

            visited[v] = true;
            int flow = 0;

            for (int i = 0; i < n; i++) {
                if (cap[v][i] > 0) flow = dfs(i, visited, Math.min(min, cap[v][i]));

                if (flow > 0) {
                    cap[v][i] -= flow;
                    cap[i][v] += flow;
                    return flow;
                }
            }

            return 0;
        }
    }

    static class Dinic {
        static class Edge {
            int v1, v2, cap, flow;
            Edge rev;
    
            public Edge(int v1, int v2, int cap) {
                this.v1 = v1;
                this.v2 = v2;
                this.cap = cap;
                this.flow = 0;
            }
        }

        public ArrayDeque<Integer> q;

        public ArrayList<Edge>[] adj;
        public int n, s, t;

        public boolean[] blocked;
        public int[] dist;

        @SuppressWarnings("unchecked")
        public Dinic(int n) {
            s = n++; t = n++; this.n = n;

            blocked = new boolean[n];
            dist = new int[n];
            q = new ArrayDeque<>();
            adj = new ArrayList[n];

            for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        }

        public void add(int v1, int v2, int cap) {
            Edge e = new Edge(v1, v2, cap);
            Edge rev = new Edge(v2, v1, 0);
            e.rev = rev; rev.rev = e;
            adj[v1].add(e);
            adj[v2].add(rev);
        }

        public int maxFlow() {
            // clear flow
            for (ArrayList<Edge> edges : adj)
                for (Edge e : edges) e.flow = 0;

            int res = 0;

            while (bfs()) {
                Arrays.fill(blocked, false);
                res += dfs(s, INF);
            }

            return res;
        }

        private boolean bfs() {
            q.clear();
            Arrays.fill(dist, -1);
            dist[t] = 0;
            q.add(t);

            while (!q.isEmpty()) {
                int node = q.poll();

                if (node == s) return true;

                for (Edge e : adj[node]) {
                    if (e.rev.cap > e.rev.flow && dist[e.v2] == -1) {
                        dist[e.v2] = dist[node] + 1;
                        q.add(e.v2);
                    }
                }
            }

            return dist[s] != -1;
        }

        private int dfs(int pos, int min) {
            if (pos == t) return min;
            int flow = 0;

            for (Edge e : adj[pos]) {
                int cur = 0;

                if (!blocked[e.v2] && dist[e.v2] == dist[pos]-1 && e.cap - e.flow > 0) {
                    cur = dfs(e.v2, Math.min(min-flow, e.cap-e.flow));

                    e.flow += cur;
                    e.rev.flow = -e.flow;
                    
                    flow += cur;
                }

                if (flow == min) return flow;
            }

            blocked[pos] = flow != min;
            return flow;
        }
    }

    public static void main(String[] args) {
        int n = 4, source = n, sink = n+1;
        FordFulkerson fordFulkerson = new FordFulkerson(n);
        Dinic dinic = new Dinic(n);

        fordFulkerson.add(source, 0, 16);
        fordFulkerson.add(source, 1, 13);
        fordFulkerson.add(1, 0, 4);
        fordFulkerson.add(0, 2, 12);
        fordFulkerson.add(2, 1, 9);
        fordFulkerson.add(1, 3, 14);
        fordFulkerson.add(3, 2, 7);
        fordFulkerson.add(2, sink, 20);
        fordFulkerson.add(3, sink, 4);

        dinic.add(source, 0, 16);
        dinic.add(source, 1, 13);
        dinic.add(1, 0, 4);
        dinic.add(0, 2, 12);
        dinic.add(2, 1, 9);
        dinic.add(1, 3, 14);
        dinic.add(3, 2, 7);
        dinic.add(2, sink, 20);
        dinic.add(3, sink, 4);

        System.out.println(fordFulkerson.maxFlow() == 23);
        System.out.println(dinic.maxFlow() == 23);
    }
}
