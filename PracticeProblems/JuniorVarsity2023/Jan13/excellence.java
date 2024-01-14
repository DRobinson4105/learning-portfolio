import java.util.*;
import java.io.*;
public class excellence {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        Arrays.sort(arr);

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n/2; i++) if (arr[i] + arr[n-i-1] < min) min = arr[i]+arr[n-i-1];
        System.out.println(min);
        
    }
}
