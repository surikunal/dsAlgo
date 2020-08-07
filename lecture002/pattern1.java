import java.util.Scanner;

public class pattern1 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int nst = 1, a;
        // int nsp=0;
        System.out.print("enter no of layers : ");
        a = scn.nextInt();

        for (int r = 1; r <= a; r++) {
            for (int cst = 1; cst <= nst; cst++) {
                System.out.print("*");
            }
            nst++;
            System.out.println();
        }

    }
}