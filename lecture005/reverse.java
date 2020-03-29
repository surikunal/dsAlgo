import java.util.Scanner;

public class reverse {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        // int n;
        // n=scn.nextInt();

        System.out.print("Enter si : ");
        int si = scn.nextInt();
        System.out.print("Enter ei : ");
        int ei = scn.nextInt();
        System.out.print("Enter no of elements in array : ");
        int n;
        n = scn.nextInt();
        // System.out.println();
        int[] arr = new int[n];
        // System.out.println();
        input(arr);
        // System.out.println();
        reverse_(arr, si, ei);
        // System.out.println();
        display(arr);
    }

    public static void display(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }

    public static void swap(int[] arr, int y, int x) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    public static void reverse_(int[] arr, int si, int ei) {
        while (si < ei) {
            swap(arr, si, ei);
            si++;
            ei--;
        }
    }

    public static void input(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            arr[i] = scn.nextInt();
    }

}