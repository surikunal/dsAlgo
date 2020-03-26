import java.util.Scanner;   //used to install inbulit Scanner file to take input 

public class simpleinterest{
    public static void main(String[] args){
        // int p=1000;
        // int r=2;
        // int t=3;
        Scanner scn=new Scanner(System.in);

        System.out.print("enter p :");
        int p=scn.nextInt();

        System.out.print("enter r :");
        int r=scn.nextInt();

        System.out.print("enter t :");
        int t=scn.nextInt();
    
        int si=(p*r*t)/100;
        System.out.println("simple int :" + si);  //take the curser to the next line
        System.out.print("simple int :" + si);   //doesnt take the curser to the next line
    }
}