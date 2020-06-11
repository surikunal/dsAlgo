import java.util.Scanner;

public class arrSubsets {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("enter size of array : ");
        int n = scn.nextInt();
        int[] arr = new int[n];
        System.out.print("enter array ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        Subsets(arr);
    }

    public static void Subsets(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = i; j < arr.length; j++) {
                print(arr, i, j);
            }
        }

    }

    public static void print(int[] arr, int si, int ei) {
        for (int i = si; i < ei; i++) {
            System.out.print(arr[i]);
        }
        System.out.println();
    }
}