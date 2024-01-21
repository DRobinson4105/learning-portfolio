import java.io.*;
import java.util.*;

public class k {
   public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        int res = 0;
        for (int i = 0; i < 26; i++) {
            int startIndex = str.indexOf(i+'a');
            int[] charMap = new int[26];

            charMap[i] = 1;
            if (startIndex != -1) {
                for (int j = startIndex+1; j < str.length(); j++) {
                    if (charMap[str.charAt(j)-'a'] != 1) {
                        res++;
                        charMap[str.charAt(j)-'a'] = 1;
                    } else if (str.charAt(j)-'a' == i) {
                        charMap = new int[26];
                        charMap[i] = 1;
                    }
                }
            }
        }
        System.out.println(res);   
   } 
}
