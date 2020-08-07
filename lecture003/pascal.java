import java.util.Scanner;

public class pascal {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.print("Enter no of rows : ");
        int n;
        n = scn.nextInt();
        val_(n);

    }

    public static void val_(int n) {
        for (int i = 0; i < n; i++) {
            int val = 1;
            for (int j = 0; j <= i; j++) {
                System.out.print(val);
                val = (i - j) * val / (j + 1);
            }
            System.out.println();
        }
    }
}