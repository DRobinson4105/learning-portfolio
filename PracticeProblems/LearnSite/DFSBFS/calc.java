import java.util.*;

public class calc {

    final public static int MOD = 1000000;

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int numCases = scan.nextInt();

        for (int loop = 0; loop < numCases; loop++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            int c = scan.nextInt();
            int target = scan.nextInt();

            LinkedList<Integer> q = new LinkedList<Integer>();
            int[] dist = new int[MOD];
            Arrays.fill(dist, -1);
            dist[0] = 0;
            q.offer(0);

            while (q.size() > 0) {
                if (dist[target] != -1) break;
                int curr = q.poll();

                ArrayList<Integer> next = new ArrayList<Integer>();
                next.add((curr+a) % MOD);
                next.add((curr*b) % MOD);
                next.add(curr/c);

                for (int i = 0; i < next.size(); i++) {
                    if (dist[next.get(i)] == -1) {
                        q.offer(next.get(i));
                        dist[next.get(i)] = dist[curr] + 1;
                    }
                }

            }

            System.out.println(dist[target]);
        }

        scan.close();
    }
}