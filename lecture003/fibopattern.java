import java.util.Scanner;

public class fibopattern{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args){
        

        int n;
        int a=0;
        int b=1;
        int sum=0;
        System.out.print("Enter no of layers : ");
        n=scn.nextInt();
        //System.out.print(a+" ");
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                System.out.print(a+" ");
                sum=a+b;
                a=b;
                b=sum;
                
            }
            System.out.println();
        }
    }
}