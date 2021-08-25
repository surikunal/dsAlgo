import java.util.Scanner;

public class incdec {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        solve(1, 6);
    }

    public static void solve(int a, int b) {
        if (a == b) {
            System.out.println(a);
            return;
        }

        System.out.println(a);
        // if(a==5) return ;
        solve(a + 1, b);

        System.out.println(a);

    }
}