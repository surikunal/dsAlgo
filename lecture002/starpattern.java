import java.util.Scanner;

public class starpattern {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n;

        System.out.print("enter no of layers : ");
        n = scn.nextInt();

        int nst = 1;
        int nsp = n / 2;

        for (int r = 0; r <= n; r++) {
            for (int csp = nsp; csp >= 1; csp--) {
                System.out.print(" ");
            }
            for (int cst = 1; cst <= nst; cst++) {
                System.out.print("*");
            }

            if (r < n / 2) {
                nsp--;
                nst += 2;
            } else {
                nsp++;
                nst -= 2;
            }
            System.out.println();
        }
    }
}