import java.util.*;
import java.io.*;

public class a {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Integer> key = new ArrayList<Integer>();
        Stack<Integer> s = new Stack<Integer>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            if (st.nextToken().equals("T"))
                key.add(1);
            else key.add(0);
        }

        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            char cur = st.nextToken().charAt(0);

            int res;
            switch (cur) {
                case '*':
                    res = s.peek(); s.pop();
                    res *= s.peek(); s.pop();
                    s.add(res);
                    break;
                case '+':
                    res = s.peek(); s.pop();
                    res += s.peek(); s.pop();
                    s.add(res > 0 ? 1 : 0);
                    break;
                case '-':
                    res = s.peek(); s.pop();
                    s.add((res + 1) % 2);
                    break;
                default:
                    s.add(key.get(cur - 'A'));
            }
        }

        System.out.println(s.peek() == 1 ? 'T' : 'F');
    }
}
