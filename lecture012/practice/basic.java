import java.util.Scanner;
import java.sql.Array;
import java.util.ArrayList;

public class basic {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        // System.out.println(subsequence("1234"));
        // System.out.println(subseqPer("1234"));
        System.out.println(mazePath01(0,0,2,2));
        // System.out.println(mazePath02(0, 0, 2, 2));
    }

    // =====================================================

    public static ArrayList<String> subsequence(String str) {
        if (str.length() == 0) {
            ArrayList<String> base = new ArrayList<>();
            base.add(" ");
            return base;
        }
        char ch = str.charAt(0);
        String restStr = str.substring(1);

        ArrayList<String> recans = subsequence(restStr);

        ArrayList<String> ans = new ArrayList<>();
        for (String s : recans) {
            ans.add(s);
            ans.add(ch + s);
        }
        return ans;
    }

    // =======================================================

    public static ArrayList<String> subseqPer(String str) {
        if (str.length() == 0) {
            ArrayList<String> base = new ArrayList<>();
            base.add(" ");
            return base;
        }
        char ch = str.charAt(0);
        String restStr = str.substring(1);

        ArrayList<String> recans = subseqPer(restStr);

        ArrayList<String> ans = new ArrayList<>();

        for (String s : recans) {
            for (int i = 0; i < s.length(); i++) {
                String one = s.substring(0, i);
                String two = s.substring(i);

                String ans1 = one + ch + two;
                ans.add(ans1);

            }

        }
        return ans;
    }

    // =======================================================

    public static ArrayList<String> mazePath01(int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) {
            ArrayList<String> base = new ArrayList<>();
            base.add(" ");
            return base;
        }

        ArrayList<String> ans = new ArrayList<>();

        if (sr + 1 <= er) {
            ArrayList<String> vertical = mazePath01(sr + 1, sc, er, ec);
            for (String s : vertical) {
                ans.add("V" + s);
            }
        }

        if (sc + 1 <= ec) {
            ArrayList<String> horizontal = mazePath01(sr, sc + 1, er, ec);
            for (String s : horizontal) {
                ans.add("H" + s);
            }
        }

        if (sr + 1 <= er && sc + 1 <= ec) {
            ArrayList<String> diagonal = mazePath01(sr + 1, sc + 1, er, ec);
            for (String s : diagonal) {
                ans.add("D" + s);
            }
        }
        return ans;
    }

    // =======================================================================

    public static ArrayList<String> mazePath02(int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) {
            ArrayList<String> base = new ArrayList<>();
            base.add(" ");
            return base;
        }

        ArrayList<String> ans = new ArrayList<>();

        for (int jump = 1; jump + sr <= er; jump++) {
            ArrayList<String> vertical = mazePath02(sr + jump, sc, er, ec);
            for (String s : vertical) {
                ans.add("V" + jump + s);
            }
        }

        for (int jump = 1; jump + sc <= ec; jump++) {
            ArrayList<String> horizontal = mazePath02(sr, sc + jump, er, ec);
            for (String s : horizontal) {
                ans.add("H" + jump + s);
            }
        }

        for (int jump = 1; jump + sr <= er && jump + sc <= ec; jump++) {
            ArrayList<String> diagonal = mazePath02(sr + jump, sc + jump, er, ec);
            for (String s : diagonal) {
                ans.add("D" + jump + s);
            }
        }
        return ans;
    }

    // =========================================================

}