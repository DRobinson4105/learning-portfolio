import java.util.Scanner;

public class a {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String line = scan.nextLine();

        int total = 0;
        int length = line.length();

        for (int i = 0; i < length; i++) {
            total += line.charAt(i);
        }

        System.out.println((char)(total / length));

        scan.close();
    }
}
