// #include <iostream>
// using namespace std;


// int main(int args,char**argv){
//     int n;
//     cin>>n;
//     int nsp=2*(n-1)-1;
//     int nst=1;
//     int val=1;
//     for(int r=1;r<n;r++){
//            for(int cst=1;cst<=nst;cst++){
//                 cout<<val;
//                 val++;
//             }
            
//             for(int csp=1;csp<=nsp;csp++){
//                 cout<<" ";
//             }
            
//             for(int cst=1;cst<=nst;cst++){
//                 val--;
//                 cout<<val;
            
//             }
//             cout<<endl;
//             nsp-=2;
//             nst++;
//     }
//         for(int cst=1;cst<=nst;cst++){
//             cout<<val;
//             val++;
//         }
            
//         for(int cst=1;cst<nst;cst++){
//                 val--;
//                 cout<<val;
            
//             }
           
// return 0;
//     }
// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// void fibo(int n)
// {
//     int n1=0,n2=1,sum=0;
//     if(n<=1)
//     {
//         cout<<"0"<<" "<<"1"<<" "<<"1"<<" ";
//     }
//     else
//     {   
//         cout<<"0"<<" "<<"1"<<" ";
//         int i=2;
//         while(i<=n)
//         {
//             sum = n1 + n2;
//             n1 = n2;
//             n2 = sum;
//             ++i;
//             if(n>sum)
//             {
//                 cout<<sum<<" ";
//             }
//         }
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     fibo(n);
//     return 0;
// }
// import java.io.*;
// import java.util.*;

// public class test {
//     public static Scanner scn = new Scanner(System.in);
//     public static void main(String[] args) {
        
//         String str = scn.nextLine();
//         for(int i=0; i<str.length(); ++i)
//         {
//             System.out.print(str.charAt(i));
//         }
//         // int n = scn.nextInt();
//         // int[] arr = new int[]{1,2,3,4,5};
//         // if(sorted(arr, n-1))
//         // {
//         //     System.out.println(true);
//         // }
//         // else
//         // {
//         //     System.out.println(false);
//         // }
//     }
    
//     public static boolean sorted(int[] arr, int n)
//     {
//         if(n == 0 )
//             return true;
        
//         if(arr[n-1] >= arr[n])
//             return false;
        
//         return sorted(arr, n-1);
//     }
// }
import java.io.*;
import java.util.*;

// public class test {
//     public static Scanner scn = new Scanner(System.in);
//     public static void main(String[] args) {
//         // char ch = scn.next().charAt(4);
//         // System.out.println(ch);
//         // String str = scn.nextLine();
//         int i = scn.nextInt();
//         System.out.println(i);
//         // System.out.println(str.charAt(i));
//         // System.out.print(str.charAt(0));
//         // duplicate(str, 1);
//     }
//     public static String duplicate(String str, int idx)
//     {
//         if(idx == str.length())
//         {
//             String base = "";
//             return base ;
//         }
//         if(str.charAt(idx-1) == str.charAt(idx))
//         {
//             System.out.print("*" + str.charAt(idx));
//         }
//         else
//         {
//             System.out.print(str.charAt(idx));
//         }
        
//         return duplicate(str, idx+1);
//     }
// }

public class test {

    public int longestMountain(int[] nums) {
        int start = 0;
        int max = 0;
        State state = State.STARTED;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                start = i;
                state = State.STARTED;
            }
            else if (nums[i] > nums[i - 1]) {
                if (state == State.DECREASING || state == State.STARTED) {
                    start = i - 1;
                    state = State.INCREASING;
                }
            } else {
                if (state == State.INCREASING || state == State.DECREASING) {
                    state = State.DECREASING;
                    max = Math.max(max, i - start + 1);
                } else {
                    start = i;
                }
            }
        }
        return max;
    }

    enum State {
        STARTED,
        INCREASING,
        DECREASING;
    }

    public static void main(String[] args) {
        test lm = new test();
        int[] nums = {2, 1, 4, 7, 3, 2, 5};
        System.out.println(lm.longestMountain(nums));
    }
}

