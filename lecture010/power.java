import java.util.Scanner;

public class power {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(power(2, 5));
    }

    public static int power(int a, int b) {
        if (b == 0)
            return 1;

        int recAns = power(a, b - 1);
        return recAns * a;
    }
}