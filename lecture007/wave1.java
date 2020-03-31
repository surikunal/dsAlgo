import java.util.Scanner;
public class wave1{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        System.out.print("Enter row and col value : ");
        int row=scn.nextInt();
        int col=scn.nextInt();
        int [][] arr= new int[row][col];
        System.out.println("Enter array ");
        input(arr);
        System.out.println("new array is ");
        wave(arr);
    }

    public static void input(int[][] arr){
        for(int i=0 ; i<arr.length ; i++){
            for(int j=0 ; j<arr.length ; j++){
                arr[i][j]=scn.nextInt();
            }
        }
    }

    public static void wave(int [][] arr){
        int m=arr.length;
        int n=arr[0].length;
        for(int i =0 ; i<m ; i++){
            if(i%2==0){
                for(int j=0 ; j<n ; j++){
                    System.out.print(arr[i][j] + " ");
                }
            }
            else{
                for(int j=n-1 ; j>=0 ; j--){
                    System.out.print(arr[i][j] + " ");
                }
            }
            }
        }
    }
