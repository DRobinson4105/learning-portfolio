import java.util.*;
import java.io.*;
public class eggdrop {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());

        // 1 is safe
        // 2 is broken
        int[] values = new int[k];
        values[0] = 1;
        values[k-1] = 2;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int floor = Integer.parseInt(st.nextToken())-1;
            String str = st.nextToken();
            if (str.equals("SAFE")) {
                for (int j = floor; j >= 0; j--) values[j] = 1; 
            } else {
                for (int j = floor; j < k; j++) values[j] = 2;
            }
        }

        int lowestBreak = 1, highestSafe = k-1;
        for (int i = 0; i < k; i++) if (values[i] == 0 || values[i] == 1) highestSafe = i+1;
        for (int i = k-1; i >= 0; i--) if (values[i] == 0 || values[i] == 2) lowestBreak = i+1;

        System.out.println(lowestBreak + " " + highestSafe);
        
    }
}
