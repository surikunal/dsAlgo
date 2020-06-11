import java.util.Scanner;

public class arrfrequency {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        votingAlgo();
    }

    public static boolean isReallyCandidate(int[] arr, int data) {
        int count = 0;
        for (int i : arr) {
            if (i == data) {
                count++;
            }
        }
        if (count > arr.length / 2) {
            return true;
        }
        return false;
    }

    public static int potentialCandidate(int[] arr) {
        int freq = 1;
        int suspect = arr[0];

        for (int i = 1; i < arr.length; i++) { /*
                                                * here the loop is started from 1 because the zeroth position is already
                                                * been included
                                                */
            if (suspect == arr[i]) {
                freq++;
            } else {
                freq--;
            }
            if (freq == 0) {
                freq = 1;
                suspect = arr[i];
            }
        }
        return suspect;
    }

    public static void votingAlgo() {
        int[] arr = { 2, 3, 4, 3, 2, 2, 2, 2, 3, 2, 2, 2 };
        int potential = potentialCandidate(arr);
        boolean ans = isReallyCandidate(arr, potential);

        if (ans) {
            System.out.print("potential : " + potential);
        } else {
            System.out.print("potential : " + -1);
        }
    }

}
