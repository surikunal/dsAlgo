import java.util.Scanner ;
public class lastindex{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        int  [] arr ={100,16,100,1,-19,13,-12,5,100,1,-19,100,16,13,14,13};
        System.out.println("last index is " + lastIndex(arr , 0 , 100));
    }
    public static int lastIndex(int [] arr , int idx , int data){
        if(arr.length==idx){
            return -1;
        }
        
        int recAns=lastIndex(arr , idx+1 , data);
        
        if(recAns!=-1){
        return recAns;
        }
        else{
            return arr[idx] == data ? idx : -1 ; 
        }      
    }
}
