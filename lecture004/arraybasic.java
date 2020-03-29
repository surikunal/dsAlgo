import java.util.Scanner;

public class arraybasic {
    public static Scanner scn = new Scanner(System.in); // to make it a global variable

    public static void main(String[] args) {
        System.out.print("Enter size of array : ");
        int k = scn.nextInt();
        int[] arr = new int[k];
        System.out.print("Enter array : ");
        input(arr);
        System.out.println();
        System.out.print("Entered array is : ");
        display(arr);
        System.out.println();
        System.out.println("minimum is : " + minimum(arr));
        System.out.println("maximum is : " + maximum(arr));
        int n;
        System.out.print("Enter a no to find : ");
        n = scn.nextInt();
        System.out.print(find(arr, n));
    }

    public static void display(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }

    public static void input(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            arr[i] = scn.nextInt();
    }

    public static int maximum(int[] arr) {
        int maximum;
        maximum = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > maximum)
                maximum = arr[i];
        }
        return maximum;
    }

    public static int minimum(int[] arr) {
        int minimum;
        minimum = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < minimum)
                minimum = arr[i];
        }
        return minimum;
    }

    public static boolean find(int[] arr, int data) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == data) {
                return true;
            }
        }
        return false;
    }

}