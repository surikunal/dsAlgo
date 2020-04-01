import java.util.Scanner;

public class maxi{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        int [] arr = {1,2,3,4,5,6,7,8,75,8,9,68,9,9,8,6,8};
        System.out.println(maxi(arr, 0)); 
    }
    public static int maxi(int [] arr , int idx){
        // if(idx==arr.length)
        // return INT_MIN;
        
        if(idx==arr.length-1)
        return arr[idx];

        int ans=maxi(arr , idx+1);
        
        if(arr[idx]>ans)
        ans=arr[idx];

        return ans;
    }
}