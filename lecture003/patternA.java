import java.util.Scanner;

public class patternA {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        int n;
        System.out.print("Enter no of rows : ");
        n = scn.nextInt();
        int nst = 1;
        int nsp = n - 1;
        for (int r = 0; r < n; r++) {
            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }
            for (int cst = 1; cst <= nst; cst++) {
                System.out.print("*");
            }
            nst += 2;
            nsp--;
            System.out.println();
        }
    }

}