import java.util.*;
import java.io.*;
public class simplicity {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] str = br.readLine().toCharArray();

        int uniqueLetters = 0;
        int[] frequency = new int[26];
        for (int i = 0; i < str.length; i++) {
            frequency[str[i]-'a']++;
            if (frequency[str[i]-'a'] == 1) uniqueLetters++;
        }
        Arrays.sort(frequency);

        int firstLetterIndex = 0;
        for (int i = 0; i < 26; i++) {
            if (frequency[i] > 0) {
                firstLetterIndex = i;
                break;
            }
        }

        int res = 0;
        while (uniqueLetters > 2) {
            res += frequency[firstLetterIndex++];
            uniqueLetters--;
        }
        
        System.out.println(res);
    }
}
