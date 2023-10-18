import java.util.Scanner;

public class allowance {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int w, n;
        w = scan.nextInt();
        
        for (int i = 0; i < w; i++) {
            n = scan.nextInt() + 1;
            int targetNumber;
            
            if (n <= 2) {
                System.out.println(1 + " " + 1);
                continue;
            }
            targetNumber = (int)(Math.log(n) / Math.log(2));
            System.out.println(targetNumber + " " + (int)(Math.pow(2, targetNumber) - 1));
        }
        scan.close();
    }
}