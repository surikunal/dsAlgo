import java.util.Scanner;
public class allidx{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        int [] arr = {10,20,30,40,50,60,70,21,1,4,7,8,9,4,0,5,4,2,56};
        int [] ans = allidx(arr, 0, 4, 0);

        for(int i : ans)
        {
            System.out.print(i + " ");
        }
    }
    public static int[] allidx(int [] arr , int idx , int data , int count)
    {
        if(idx==arr.length)
        {
            int [] baseArray = new int[count];
            return baseArray;
        }
        if(arr[idx] == data)
        {
            count++;
        }

        int [] recAns = allidx(arr, idx+1 , data , count);

        if(arr[idx]==data)
        {
            recAns[count-1] = idx ;
        }
        return recAns;
    }
}