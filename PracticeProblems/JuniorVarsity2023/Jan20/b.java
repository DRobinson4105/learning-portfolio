import java.util.*;
import java.io.*;

public class b {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long rows = Long.parseLong(st.nextToken()), cols = Long.parseLong(st.nextToken());
        long GCD = gcd(Math.max(rows, cols), Math.min(rows, cols));

        rows /= GCD; cols /= GCD;

        if (rows % 2 == 1 && cols % 2 == 1)
            System.out.println(GCD);
        else
            System.out.println(0);

    }
    public static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
 }
