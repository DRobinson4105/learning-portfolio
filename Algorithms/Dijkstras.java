import java.util.Arrays;

public class Dijkstras {
    static int INF = 1_000_000_000;
    static int[] dijkstras(int[][] graph, int source, int v) {
        int[] distance = new int[v];

        for (int i = 0; i < v; i++) distance[i] = INF;

        distance[source] = 0;

        boolean[] chosen = new boolean[v];
        for (int i = 0; i < v; i++) chosen[i] = false;

        for (int i = 0; i < v-1; i++) {
            int vertex = 0, best = INF;

            for (int j = 0; j < v; j++) {
                if (!chosen[j] && distance[j] < best) {
                    best = distance[j];
                    vertex = j;
                }
            }

            chosen[vertex] = true;

            for (int j = 0; j < v; j++) {
                if (graph[vertex][j] == -1) continue;
                distance[j] = Math.min(distance[j], distance[vertex] + graph[vertex][j]);
            }
        }

        return distance;
    }

    public static void main(String[] args) {
        int v = 7;
        int[][] graph = {
            { 0,  4, -1, 12, 10,  5,  3},
            { 5,  0, -1, 15, 20, -1, 30},
            {12,  6,  0, 25, -1, 18, -1},
            { 5,  9, -1,  0,  6, 12, 15},
            {20, 18, -1,  1,  0, -1,  6},
            {-1, -1, -1, 12,  1,  0, -1},
            {-1, -1, -1,  4,  5,  1,  0}
        };

        int[] distance = dijkstras(graph, 2, v);
        int[] answer = {11, 6, 0, 17, 16, 15, 14};

        System.out.println(Arrays.compare(distance, answer) == 0);
    }
}