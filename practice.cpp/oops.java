// import java.util.Scanner;

// public class oops {

//    public static void print(int n) {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j <= i; j++) {
//                System.out.print(pascal(i, j) + " ");
//            }
//            System.out.println();
//        }
//    }

//    public static int pascal(int i, int j) {
//        if (j == 0) {
//            return 1;
//        } else if (j == i) {
//            return 1;
//        } else {
//            return pascal(i - 1, j - 1) + pascal(i - 1, j);
//        }

//    }

//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//        System.out.print("Enter the row number upto which Pascal's triangle has to be printed: ");
//        int row = scanner.nextInt();
//        print(row);
//    }
// }
// import java.io.*;
// import java.util.*;

// public class oops {
//     public static Scanner scn = new Scanner(System.in);
//     public static void main(String[] args) {
//         String str = scn.nextLine();
//         // int num = Integer.valueOf(str);
//         // System.out.println(num);
//         int i = scn.nextInt();
//         int num1 = StringToNum(str);
//         System.out.println(num1 / i);
//     }
//     public static int StringToNum(String str)
//     {
//         if(str.length() == 1)
//             return (str.charAt(0)-'0');
        
//         String restStr = str.substring(1);
//         double y = StringToNum(restStr);
//         double x = str.charAt(0) - '0';
     
//         x = x * Math.pow(10, str.length() - 1) + y;
//         return (int)(x);
//     }
// }
import java.io.*;
import java.util.*;

public class oops {
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {
        int k = scn.nextInt();
        for (int i = 0; i < k; i++)
        {
            int n = scn.nextInt();
            int[] arr = new int[n];
            for (int j = 0; j < n; j++)
            {
                arr[j] = scn.nextInt();
                System.out.print(maxSumSubArr(arr));
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
    public static int maxSumSubArr(int[] arr)
    {
        int s = 0, si = 0, ei = 0, imax = 0, omax = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++)
        {
            imax += arr[i];
            if (omax < imax)
            {
                si = s;
                ei = i;
                omax = imax;
            }
            if (imax < 0)
            {
                s = i + 1;
                imax = 0;
            }
        }
        return omax;
    }
}