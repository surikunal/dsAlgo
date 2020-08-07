import java.util.Scanner;

public class digits {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter a number to count no of digits : ");
        int n = scn.nextInt();
        int digit = 0;
        while (n != 0) {
            n /= 10;
            digit++;
        }
        System.out.print("no of digits in this no is " + digit);

    }
}