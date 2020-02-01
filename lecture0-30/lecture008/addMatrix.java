import java.util.Scanner;

public class addMatrix {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("enter rows and col value : ");
        int n = scn.nextInt();
        int m = scn.nextInt();
        int[][] arr = new int[n][m];
        System.out.println("enter array : ");
        input(arr);
        // System.out.println("enter rows and col : ");
        // int p=scn.nextInt();
        // int q=scn.nextInt();
        int[][] ar = new int[n][m];
        System.out.println("enter 2nd array : ");
        input(ar);
        addition(arr, ar);
        print(arr);
    }

    public static void input(int[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] = scn.nextInt();
            }
        }

    }

    public static void addition(int[][] mat1, int[][] mat2) {
        for (int i = 0; i < mat1.length; i++) {
            for (int j = 0; j < mat2[0].length; j++) {
                mat1[i][j] += mat2[i][j];
            }
        }

    }

    public static void print(int[][] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.println();
            for (int j = 0; j < a[0].length; j++) {
                System.out.print(a[i][j] + " ");
            }
        }

    }

}
