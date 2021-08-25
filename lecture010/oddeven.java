import java.util.Scanner;

public class oddeven {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("enter a no ");
        int a = scn.nextInt();
        solve(1, a);
    }

    public static void solve(int a, int b) {
        if (a == b) {
            System.out.println(a);
            return;
        }
        if (a % 2 != 0) {
            System.out.println(a);
        }
        // if(a==5) return ;
        solve(a + 1, b);
        if (a % 2 == 0) {
            System.out.println(a);
        }
    }
}