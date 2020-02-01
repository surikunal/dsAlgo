import java.util.*;

public class keypad {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(keypad_01("11024", ""));
        // System.out.println(keypad_01("234", ""));
        // System.out.println(keypad_02("234"));
        System.out.println(keypad_02("11024"));
    }

    static String words[] = { "!@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "uvw", "xyz", "*", "#", "%^&" };

    public static int keypad_01(String str, String ans) {

        if (str.length() == 0) {
            System.out.println(ans);
            return 1;
        }
        int count = 0;
        int idx = str.charAt(0) - '0';
        String roq = str.substring(1);
        String word = words[idx];

        for (int i = 0; i < word.length(); i++) {
            count += keypad_01(roq, ans + word.charAt(i));
        }

        if (str.length() >= 2) {
            idx = idx * 10 + (str.charAt(1) - '0');
            if (idx >= 10 && idx <= 11) {
                word = words[idx];
                for (int i = 0; i < word.length(); i++) {
                    count += keypad_01(str.substring(2), ans + word.charAt(i));
                }
            }
        }
        return count;
    }

    public static ArrayList<String> keypad_02(String str){
        if (str.length() == 0){
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }

        int idx = str.charAt(0) - '0';
        String roq = str.substring(1);
        String word = words[idx];

        ArrayList<String> recAns = keypad_02(roq);
        
        ArrayList<String> myAns = new ArrayList<>();
        for (int i = 0; i < word.length(); i++){
            for (String s : recAns){
                myAns.add(word.charAt(i) + s);
            }
        }

        if (str.length() > 1){
            idx = idx * 10 + (str.charAt(1) - '0');
            if (idx == 10 || idx == 11){
                word = words[idx];
                recAns = keypad_02(str.substring(2));   
                for (int i = 0; i < word.length(); i++){
                    for (String s : recAns){
                        myAns.add(word.charAt(i) + s);
                    }
                }
            }
        }
        return myAns;
    }
}