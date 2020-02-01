import java.util.Scanner;
public class count01{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int[] arr={0,0,1,1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,1};
        zeroAndOnes(arr);
        for(int i=0 ; i<arr.length ; i++){
            System.out.print(arr[i] + " ");
        }
    }


    public static void zeroAndOnes(int[] arr) {
        int pt=0;
        int itr=0;
        while(itr<arr.length){
            if(arr[itr]==0){
                swap(arr ,itr , pt);
                // int temp = arr[itr];
                // arr[itr] = arr[pt];
                // arr[pt] = temp;
                pt++;
            }
            itr++;
        }
        //return  arr[pt];
        //return arr[itr];       
    }
    public static void swap(int [] arr ,int a , int b){
        int temp=arr[a];
            arr[a]=arr[b];
            arr[b]=temp;
            // System.out.print(a);
            // System.out.print(b);
         // return a;
          //return b;
}
}
