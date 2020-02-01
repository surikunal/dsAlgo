import java.util.ArrayList;
import java.util.Scanner;
public class min{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        ArrayList<Integer> arr=new ArrayList<>();
        //int [] arr={};
        input(arr);
        System.out.println(minimum(arr , 0)); 
    }   
    public static int minimum(ArrayList<Integer> arr , int idx){
        if(idx==arr.size())
        return Integer.MAX_VALUE;

        int res=minimum(arr,idx+1);
        return Math.min(res , arr.get(idx));

        if(arr.get(idx)<res)
        res=arr.add(arr.get(idx));
        
        return res;

    }
    public static void input(ArrayList<Integer> arr){
        int n=scn.nextInt();
        int val=0;
        for(int i=0 ; i<n ; i++){
            val=scn.nextInt();
        }
        arr.add(val);
    }
}