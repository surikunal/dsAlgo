import java.util.Scanner;
public class find{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args){
        
        
        System.out.print("enter row and col value of array : ");
        int row=scn.nextInt();
        int col=scn.nextInt();
        System.out.println("enter array ");
        int [][] arr=new int[row][col];
        input(arr);
        System.out.println("maximum of array is " + maxi(arr));
        System.out.print("enter data to find : ");
        int n;
        n=scn.nextInt();
        System.out.println(find_(arr , n));
        
        }
public static boolean find_(int [][] arr , int data){
    for(int i=0; i<arr.length; i++){
        for(int j=0 ; j<arr.length ; j++){
            if(arr[i][j]==data)
            return true;

        }
}
return false;
}

public static void input(int [][] arr){
    for(int row=0 ; row<arr.length ; row++){
        for(int col=0 ; col< arr.length ; col++){
            arr[row][col]=scn.nextInt();
        }
    }
}
public static int maxi(int [][] arr){
    int max_=arr[0][0];
    for(int row=0 ; row<arr.length ; row++){
        for(int col=0 ; col< arr.length ; col++){
            if(max_<arr[row][col])
            max_=arr[row][col];
        }
    }
return max_;
}
}