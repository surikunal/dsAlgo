// this is how we swap 2 no 
// and return its value to the previous function

import java.util.Scanner;

public class alpha {
    public static void main(String[] args) {
        int a = 10;
        int b = 20;

        // System.out.println(a + " " + b);

        // int[] arr = new int[2];
        // arr[0]=a;
        // arr[1]=b;
        // swap(arr,0,1);
        // System.out.print(arr[0] + " " + arr[1]);

        SwapHelper s = new SwapHelper(a, b);

        System.out.println(s.x + " " + s.y);

        swap2(s);

        System.out.println(s.x + " " + s.y);

    }

    static class SwapHelper {
        int x;
        int y;

        SwapHelper(int a, int b) {
            x = a;
            y = b;
        }
    }

    public static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    public static void swap2(SwapHelper s) {
        int temp = s.x;
        s.x = s.y;
        s.y = temp;
    }

}