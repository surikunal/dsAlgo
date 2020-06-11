import java.util.Scanner;

public class BSUB {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.print("Enter length of array : ");
        int n = scn.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter aray : ");
        input(arr);
        System.out.println("Enter a element to search : ");
        int data = scn.nextInt();
        boolean x = BSUB(arr, data);
        if (x == true)
            System.out.print("Found");
        else
            System.out.print("Not Found");

    }

    public static void input(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            arr[i] = scn.nextInt();
    }

    public static boolean BSUB(int[] arr, int data) {
        int si = 0;
        int ei = arr.length - 1;

        while (si < ei) {
            int mid = (si + ei) / 2;
            if (arr[mid] == data) {
                if (mid + 1 < arr.length && arr[mid + 1] == arr[mid]) {
                    si = mid + 1;
                } else {
                    System.out.print(mid);
                }
                return true;
            } else if (arr[mid] > data) {
                ei = mid - 1;
            } else {
                si = mid + 1;
            }
        }
        si++;
        ei--;
        return false;

    }
}
