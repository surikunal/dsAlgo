import java.util.Scanner;
public class wave2{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        System.out.println("Enter row and col values : ");
        int row=scn.nextInt();
        int col=scn.nextInt();
        int [][] arr=new int[row][col];
        System.out.println("Enter array : ");
        input(arr);
        System.out.println("new array is ");
        wave(arr);
    }

    public static void input(int [][] arr ){
        for(int row=0 ; row<arr.length ; row++){
            for(int col=0 ; col<arr[0].length ; col++){
                arr[row][col]=scn.nextInt();
            }
        }
    }

    public static void wave(int [][] arr){
        int m=arr.length;
        int n=arr[0].length;
        for(int col=0 ; col<m ; col++){
            if(col%2==0){
                for(int row=0 ; row<n ; row++)
                System.out.print(arr[row][col] + " ");
            }
            else{
                for(int row=n-1 ; row>=0 ; row--)
                System.out.print(arr[row][col] + " ");
            }
        }

    }

}