import java.util.Scanner;

public class rotate{
    public static Scanner scn=new Scanner(System.in);
        public static void main(String[] args){
            
            //System.out.println();
            int n,k;
            System.out.print("Enter size of array : ");
            n=scn.nextInt();
            int[] arr=new int[n];
            System.out.print("Enter the array : ");
            input(arr);
            System.out.print("Enter index of array to rotate from : ");
            k=scn.nextInt();
            rotate_( arr , k);
            System.out.print("rotated array is : ");
            display(arr);
    }
    public static void swap(int[] arr,int x, int y){
        int temp=arr[x];
        arr[x]=arr[y];
        arr[y]=temp;
    }
    public static void reverse_(int [] arr , int si ,int ei){
        while(si<ei){
            swap(arr , si ,ei);
            si++;
            ei--;
        }
    }
    public static void input(int [] arr)
    { 
     for (int i = 0; i < arr.length; i++)
           arr[i]=scn.nextInt();
    }

    public static void display(int [] arr)
    { 
    for (int i = 0; i < arr.length; i++)
       System.out.print(arr[i] + " ");

}
    public static void rotate_(int[] arr, int k){
        k%=arr.length;
        k=k<0 ? k + arr.length : k ;
        
        reverse_(arr , 0 , k-1);
        reverse_(arr , k , arr.length-1);
        reverse_(arr , 0 , arr.length-1);
    }
}