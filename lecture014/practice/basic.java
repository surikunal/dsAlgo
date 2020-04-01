import java.util.Scanner;
import java.util.ArrayList;

public class basic {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        // System.out.println(boardPath(0, 10));
        System.out.println(mazePath_multi(0, 0, 2, 2));
    }

    // ===========================================================================

    public static ArrayList<String> boardPath(int si, int ei) {
        if (si == ei) {
            ArrayList<String> base = new ArrayList<>();
            base.add(" ");
            return base;
        }

        ArrayList<String> ans = new ArrayList<>();

        for (int jump = 1; jump + si <= ei && jump <= 6; jump++) {
            ArrayList<String> recAns = boardPath(si + jump, ei);
            for (String s : recAns) {
                ans.add(s + jump);
            }
        }
        return ans;
    }

    // =============================================================================

    public static ArrayList<String> mazePath_multi(int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) {
            ArrayList<String> base = new ArrayList<>();
            base.add(" ");
            return base;
        }

        ArrayList<String> ans = new ArrayList<>();

        for (int jump = 1; jump + sr <= er; jump++) {
            ArrayList<String> vertical = mazePath_multi(sr + jump, sc, er, ec);
            for (String s : vertical) {
                ans.add("V" + jump + s);
            }
        }

        for (int jump = 1; jump + sc <= ec; jump++) {
            ArrayList<String> horizontal = mazePath_multi(sr, sc + jump, er, ec);
            for (String s : horizontal) {
                ans.add("H" + jump + s);
            }
        }

        for (int jump = 1; jump + sr <= er && jump + sc <= ec; jump++) {
            ArrayList<String> diagonal = mazePath_multi(sr + jump, sc + jump, er, ec);
            for (String s : diagonal) {
                ans.add("D" + jump + s);
            }
        }
        return ans;
    }
}
