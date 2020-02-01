import java.util.Scanner;
//verified
public class largest{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);

        System.out.print("Enter a: ");
        int a=scn.nextInt();

        System.out.print("Enter b: ");
        int b=scn.nextInt();

        System.out.print("Enter c: ");
        int c=scn.nextInt();

        if(a>b && a>c)
        {System.out.print("Largest is a");}

        else if(b>a && b>c)
        {System.out.print("Largest is b");
        }
        else
        {System.out.print("Largest is c");}
    }
}