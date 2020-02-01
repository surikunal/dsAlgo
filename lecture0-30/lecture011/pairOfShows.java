import java.util.Scanner;

public class pairOfShows {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        int[] arr = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 8 };
        System.out.println("the missing num is " + pairOfShows(arr));
    }

    public static int pairOfShows(int[] arr) {
        if (arr.length % 2 == 0) {
            System.out.println("all are paired");
            return -1;
        }
        int si = 0, ei = arr.length - 1;
        while (si <= ei) {
            int mid = (si + ei) / 2;
            if (si == ei) {
                return arr[mid];
            }

            else if (mid % 2 == 0) {
                if (arr[mid] == arr[mid + 1]) {
                    si = mid + 1;
                } else {
                    ei = mid - 1;
                }
            }

            else if (mid % 2 != 0) {
                if (arr[mid] == arr[mid - 1]) {
                    si = mid + 1;
                } else {
                    ei = mid - 1;
                }
            }
        }
        return -1;
    }
}
