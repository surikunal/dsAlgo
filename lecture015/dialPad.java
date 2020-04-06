import java.util.Scanner;
import java.io.StringReader;
import java.util.ArrayList;

public class dialPad {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        dialPad_("235", "");
    }


    public static int dialPad_(String ques, String ans) {
        if (ques.length() == 0) {
            // ArrayList<String> base = new ArrayList<>();
            // base.add("");
            // return base;
            System.out.println(ans);
            return 1;
        }
        char codes[] = { "+", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz", "*", "#" };

        int count = 0;
        int ch = ques.get(0);
        String roq = ques.subString(1);
        String code = codes.get(ch - '0');
        for (int i = 0; i < code.length(); i++) {
            count += dialPad(roq, ans + code[i]);
        }
        return count;
    }
}
