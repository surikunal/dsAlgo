import java.util.Scanner;

public class fibo {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("enter positon of a num ");
        int a = scn.nextInt();
        System.out.println("num at position " + a + " is " + fibo_(a));
    }

    public static int fibo_(int a) {

        if (a <= 1)
            return a;

        int recAns = fibo_(a - 1) + fibo_(a - 2);
        return recAns;

    }
}