import java.util.*;
import java.io.*;

public class c {
    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(stdin.readLine());
        int p = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        long[][] districts = new long[d][2];

        long totalV = 0, totalA = 0, totalB = 0;

        for (int i = 0; i < p; i++) {
            st = new StringTokenizer(stdin.readLine());
            int idx = Integer.parseInt(st.nextToken())-1;
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            districts[idx][0] += a;
            districts[idx][1] += b;
        }

        for (long[] district : districts) {
            boolean won = district[1] > district[0];
            long v = district[0] + district[1];
            long a = (!won) ? (district[0] - (v / 2 + 1)) : district[0];
            long b = (won) ? (district[1] - (v / 2 + 1)) : district[1];

            totalA += a;
            totalB += b;
            totalV += v;
            System.out.println((won ? "B" : "A") + " " + a + " " + b);
        }

        System.out.printf("%.10f\n", Math.abs(totalA - totalB) / (double)totalV);
    }
}
