import java.util.Scanner;
import java.util.ArrayList;

public class subSeq {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        System.out.println(subsequence("1234"));
    }

    public static ArrayList<String> subsequence(String str) {
        if (str.length() == 0) {
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        char ch = str.charAt(0);
        String restStr = str.substring(1);

        ArrayList<String> recAns = subsequence(restStr);
        ArrayList<String> myAns = new ArrayList<>();

        for (String s : recAns) {
            myAns.add(s);
            myAns.add(ch + s);
        }
        return myAns;
    }

}
