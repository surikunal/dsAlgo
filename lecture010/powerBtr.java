import java.util.Scanner;
public class powerBtr{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        System.out.println(powerBtr(2,5));
    }
    public static int powerBtr(int a , int b){
        if(b==0) return 1;
        
        int recAns=powerBtr(a,b/2);
        recAns*=recAns;
        if(b%2!=0){
            recAns*=a;
        }

        return recAns;
    }
}