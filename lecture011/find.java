import java.util.Scanner;

public class find {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        int[] arr = { 1, 1, 2, 3, 4, 5, 56, 7, 8, 99, 90 };
        System.out.println("enter value to find ");
        int n = scn.nextInt();
        System.out.println(find(arr, 0, n));
    }

    public static boolean find(int[] arr, int idx, int data) {
        if (idx == arr.length)
            return false;

        if (arr[idx] == data)
            return true;

        boolean recans = find(arr, idx + 1, data);
        return recans;
    }
}