import java.util.Scanner;
//verified
public class oddeven{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);

        System.out.print("Enter no :");
        int a=scn.nextInt();

        if(a%2==0){
            System.out.print("no is even");
        }
        else{
            System.out.print("no is odd");
        }
    }

}