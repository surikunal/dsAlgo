import java.util.Scanner ;
public class transpose{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        int row , col ;
        System.out.println("enter row and col val ");
        row = scn.nextInt();
        col = scn.nextInt();
        int [][] arr = new int [row][col];
        System.out.println("enter array ");
        input(arr);
        System.out.print("array after transpose ");
        transpose(arr);
    }
    public static void input(int [][] arr){
        for(int i=0 ; i<arr.length ; i++){
            for(int j=0 ; j<arr[0].length ; j++){
                arr[i][j]= scn.nextInt();
            }
        }
    }
    public static void transpose(int [][] arr){
        for(int i=0 ; i<arr.length ; i++){
            System.out.println();
            for(int j=0 ; j<arr[0].length ; j++){
                System.out.print(arr[j][i] + " ");
            }
        }
    }
}