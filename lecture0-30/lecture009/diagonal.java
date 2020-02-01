import java.util.Scanner;
public class diagonal{
    public static Scanner scn = new Scanner (System.in);
    public static void main(String[] args){
         
        System.out.println("enter row an col value ");
        int row = scn.nextInt();
        int col = scn.nextInt();
        System.out.println("enter array ");
        int [][] arr = new int [row][col];
        input(arr);
        System.out.println("diagonal elements are ");
        diagonal(arr);

    }
    public static void input(int [][] arr){
        for(int i=0 ; i<arr.length ; i++){
            for(int j=0 ; j<arr[0].length ; j++){
                arr[i][j] = scn.nextInt();
            }
        }
    }
    public static void diagonal(int [][] arr){
        
        int m=arr[0].length;
        int n=arr.length;
        for(int gap=0 ; gap<m ; gap++){
            for(int i=0 , j=gap ; i<m && j<n ; i++ , j++){
                System.out.print(arr[i][j] + " "); 
            }
        }
        
    }
}