import java.util.*;

public class bits {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        // System.out.println(numbersOf1s_01(15));
        // System.out.println(numbersOf1s_02(15));
        System.out.println(numbersOf1s_best(15));
        System.out.println(is2pow(16));
    }

    public static int numbersOf1s_01(int a) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            int mask = (1 << i);
            if ((mask & a) != 0)
                count++;

        }
        return count;
    }

    public static int numbersOf1s_02(int a) {
        int count = 0;
        while (a != 0) {
            if ((a & 1) != 0)
                count++;
            a >>>= 1;    
        }
        return count;
    }

    public static int numbersOf1s_best(int a) {
        int count = 0;
        while (a != 0) {
            count++;
            a &= (a-1);   
        }
        return count;
    }

    public static boolean is2pow(int a){
        return a != 0 && (a & (a - 1)) == 0;
    }
}