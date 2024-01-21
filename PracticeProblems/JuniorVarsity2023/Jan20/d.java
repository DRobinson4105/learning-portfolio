import java.util.*;
import java.io.*;

public class d {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[201];
        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            arr[num] = 1;
            if (num > maxNum) maxNum = num;
        }
        boolean foundOne = false;
        for (int i = 1; i < maxNum; i++) {
            if (arr[i] != 1) {
                foundOne = true;
                System.out.println(i);
            }
        }
        if (!foundOne) System.out.println("good job");
        br.close();
    }
}