import java.util.Scanner;
public class bitManu{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        int num = 6;
        int count = 0;
        
        System.out.println(count1(num,count)); 
        System.out.println(countbits(num,count)); 
        
    }
    /* ______________complexicity is 32_______________ */
    public static int count1(int num , int count){
        for(int i=0 ; i<32 ; i++){
            int mask=(1<<i);
            if((num & mask)!=0){
                count++;
            }
        }
        return count;
    }
    /* _______________with less complexity_____________ */
    
    public static int countbits(int n , int count){
        while(n!=0){
            if((n & 1)!=0){
            count++;
            }
            n>>=1;
        }
        return count;
    }
}