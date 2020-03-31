import java.util.Scanner;

public class exitpoint {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("enter row and col val ");
        int row = scn.nextInt();
        int col = scn.nextInt();
        int[][] arr = new int[row][col];
        System.out.println("enter array ");
        input(arr);
        System.out.print("end position is ");
        exit_point(arr);
    }

    public static void input(int[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] = scn.nextInt();
            }
        }
    }

    public static void exit_point(int[][] a) {
        int r = 0, c = 0, dir = 0;
        while (true) {
            dir = (dir + a[r][c]) % 4;
            if (dir == 0) {
                c++;
                if (c == a[0].length) {
                    System.out.println(r + " " + --c);
                    break;
                }
            } else if (dir == 1) {
                r++;
                if (r == a.length) {
                    System.out.println(r - 1 + " " + c);
                    break;
                }
            } else if (dir == 2) {
                c--;
                if (c == -1) {
                    System.out.println(r + " " + --c);
                    break;
                }
            } else {
                r--;
                if (r == -1) {
                    System.out.println(r-1 + " " + c);
                    break;
                }
            }
        }
    }
}