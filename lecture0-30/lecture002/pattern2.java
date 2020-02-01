import java.util.Scanner;
public class pattern2{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int a;
        
        System.out.print("enter the no of layers : ");
        a=scn.nextInt();
        int nst=1;
        int nsp=a-1;

        for(int r=1;r<=a;r++){
            for(int csp=nsp;csp>=1;csp--){
                System.out.print(" ");
            }
            for(int cst=1;cst<=nst;cst++){
                System.out.print("*");
            }
            nst++;
            nsp--;
            System.out.println();
        }
    }
}