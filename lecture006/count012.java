import java.util.Scanner;

public class count012 {
    public static void main(String[] args) {
        int[] arr = { 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 2, 1, 0, 1, 0, 1, 1, 2, 2, 2, 2, 1, 0, 0, 1 };
        zeroAndOnesTwo(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void zeroAndOnesTwo(int[] arr) {
        int pt1 = 0;
        int pt2 = arr.length - 1;
        int itr = 0;
        while (itr <= pt2) {
            if (arr[itr] == 0) {
                // swap(arr[itr] , arr[pt1]);
                int temp = arr[itr];
                arr[itr] = arr[pt1];
                arr[pt1] = temp;
                pt1++;
                itr++;
            } else if (arr[itr] == 2) {
                // swap(arr[itr] , arr[pt2]);
                int temp = arr[itr];
                arr[itr] = arr[pt2];
                arr[pt2] = temp;
                pt2--;
            } else {
                itr++;
            }
        }
        // return arr[pt];
        // return arr[itr];
    }

    public static void swap(int[] arr, int a, int b) {
        int temp = a;
        a = b;
        b = temp;
        // System.out.print(a);
        // System.out.print(b);
        // return a;
        // return b;
    }
}
