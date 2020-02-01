import java.util.ArrayList;
import java.util.Scanner;
public class boardPath{

    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        
       System.out.println(boardPath(0,10).size());
       System.out.println("CASES ARE ");
       System.out.println(boardPath(0,10) + " "); 
    } 
    public static ArrayList<String> boardPath(int si ,int ei){
        if(si==ei){
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        ArrayList<String> myAns = new ArrayList<>();
        
        for(int jump=1 ; jump+si<=ei && jump<=6 ; jump++){
            ArrayList<String> recAns = boardPath(si+jump , ei);
            for(String s : recAns){
                myAns.add(s + jump);
            }
        }
        return myAns;
    }

}