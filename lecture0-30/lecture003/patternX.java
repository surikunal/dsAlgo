import java.util.Scanner;
public class patternX{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args){
        int n;
        System.out.print("Enter no of rows : ");
        n=scn.nextInt();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j || i+j==n+1){
                    System.out.print("*");
                }
                else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}