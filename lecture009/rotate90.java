import java.util.*;
public class rotate90{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        System.out.println("enter row and col value ");
        int row = scn.nextInt();
        int col = scn.nextInt();
        int [][] arr = new int[row][col];
        System.out.println("enter matrix ");
        input(arr);
        transpose(arr);
        swapCol(arr);
        System.out.print("matrix after rotation is ");
        print(arr);
    } 
    public static void input(int [][] arr){
        for(int i=0 ; i<arr.length ; i++){
            for(int j=0 ; j<arr[0].length ; j++){
                arr[i][j] = scn.nextInt();
            }
        }
    }
    public static void print(int [][] arr){
        for(int i=0 ; i<arr.length ; i++){
            System.out.println();
            for(int j=0 ; j<arr[0].length ; j++){
                System.out.print(arr[i][j] + " ");
            }
        }
    }
    public static void transpose(int [][] arr){
        for(int i=0 ; i<arr.length ; i++){
            for(int j=i ; j<arr[0].length ; j++){
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
    }
    public static void swapCol(int [][] arr){
        int c1 = 0 ;
        int c2 = arr[0].length -1;
        // System.out.println("bbc");
        while(c1<=c2){
            int r2 = arr.length-1;
            // System.out.println("bbd");
            for(int r=0 ; r<=arr.length/2 ; r++){
                int temp=arr[r][c1];
                arr[r][c1]=arr[r2-r][c1];
                arr[r2-r][c1]=temp;
            }
            // System.out.println("bba");
            c1++;
        }
        // System.out.println("bbbb");
        // c1++;
        // c2--;
    }
    // public static int swap_(int [][] arr , int r , int c1 ,int c2){
    //     int temp=arr[r][c1];
    //     arr[r][c1]=arr[r][c2];
    //     arr[r][c2]=temp;
    // }

}