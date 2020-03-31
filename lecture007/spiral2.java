import java.awt.SystemTray;
import java.util.Scanner;
public class spiral2{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args){
        System.out.print("enter row and col value of array : ");
        int row=scn.nextInt();
        int col=scn.nextInt();
        System.out.println("enter array ");
        int [][] arr=new int[row][col];
        input(arr);
        System.out.println("new array is ");
        spiral_(arr);
        // display(arr);
}

public static void spiral_(int [][] arr){
        int minr=0;
        int minc=0;
        int maxr=arr.length-1;
        int maxc=arr[0].length-1;
        int total=arr.length * arr[0].length;
        int count=0;
        while(count<total){
            for(int row=minr ; row<=maxr && count<total ; row++){
                System.out.print(arr[row][minc] + " ");
                count++;
            }
            minc++;
            for(int col=minc ; col<=maxc && count<total ; col++){
                System.out.print(arr[maxr][col] + " ");
                count++;
            }
            maxr--;
            for(int row=maxr ; row>=minr && count<total ; row--){
                System.out.print(arr[row][maxc] + " ");
                count++;
            }
            maxc--;
            for(int col=maxc ; col>=minc && count<total ; col--){
                System.out.print(arr[minr][col] + " ");
                count++;
            }
            minr++;
        }
    
}

public static void input(int [][] arr){
    for(int row=0 ; row<arr.length ; row++){
        for(int col=0 ; col< arr[0].length ; col++){
            arr[row][col]=scn.nextInt();
        }
    }
}
public static void display(int [][] arr){
    for(int [] ar : arr){
        for(int i : ar){
            System.out.print(i + " ");
        }
    }
}

}
