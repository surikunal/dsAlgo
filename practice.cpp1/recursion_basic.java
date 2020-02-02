import java.util.Scanner;

public class recursion_basic {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        // int [] arr = {10,20,30,40,50,60,70,21,1,4,7,8,9,4,0,5,4,2,56};
        // int[] ans = allidx(arr , 0 , 4 , 0);

        // for(int i : ans){
        // System.out.print(i + " ");
        // }

        // int n = scn.nextInt();
        // int[] arr = new int[n];
        // for(int i=0; i<n; i++)
        // {
        // arr[i] = scn.nextInt();
        // }
        // System.out.print(arr.toString());

        int n = scn.nextInt();
        String[] arr = new String[n];

        for (int j = 0; j < arr.length; j++) {
            arr[j] = scn.nextLine();
        }
        for (String ele : arr) {
            System.out.println(ele);
        }
    }
}
// public static int[] allidx(int [] arr , int idx , int data , int count){
// if(idx == arr.length){
// int [] baseArray = new int [count];
// return baseArray;
// }
// if(arr[idx] ==data){
// count++;
// }

// int[] recans = allidx(arr, idx+1, data, count);

// if(arr[idx]==data){
// recans[count-1] = idx;
// }
// return recans;
// }
// }
