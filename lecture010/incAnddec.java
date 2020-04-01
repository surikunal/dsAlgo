import java.util.Scanner;
public class incAnddec{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        solve();
    }
    public static void solve(){
        increasing(1,10);
        decreasing(1,10);
    }
    public static void increasing(int a , int b){
        if(b==a-1) return ;

        increasing(a,b-1);
        System.out.println(b);
    }
    public static void decreasing(int a , int b){
        if(b==a-1) return ;

        System.out.println(b);
        decreasing(a,b-1);
        
    }
}