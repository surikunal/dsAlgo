import java.util.Scanner;
public class addarray{
    public static Scanner scn = new Scanner(System.in);
        public static void main(String[] args){
            int no1 , no2 ;
            System.out.println("enter size of 1st no ");
            no1=scn.nextInt();
            System.out.println("enter no ");
            int [] arr1 = new int [no1];
            input(arr1);
            System.out.println("enter size of 2nd no ");            
            no2=scn.nextInt();
            System.out.println("enter no ");
            int [] arr2 = new int [no2];
            input(arr2);
            System.out.println("num after addition ");
            addArray(arr1 , arr2);

        }
        public static void addArray(int [] arr1 , int [] arr2){
            int size = arr1.length > arr2.length ? arr1.length : arr2.length ;
            int carry =0 ;
            int [] res = new int [size + 1];
            
            int i= arr1.length-1;
            int j= arr2.length -1;
            int k= res.length -1 ;
            while(i>=0 || j>=0 || carry != 0 ){
                int ans=carry;
                if(i>=0)  ans+=arr1[i] ;
                if(j>=0)  ans+=arr2[j] ;
                
                int rem=ans%10;
                carry = ans/10;
                res[k]=rem;
                k--;
                i--;
                j--;
            }
            print(res);

        }
        public static void print(int [] a){
            for(int i=0 ; i<a.length ; i++){
                System.out.print(a[i]);
            }
        }
        public static void input(int [] a){
            for(int i=0 ; i<a.length ; i++){
                a[i] =scn.nextInt();
                }
        }
}