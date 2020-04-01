import java.util.Scanner;
import java.util.ArrayList;

public class mazePath_multi {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        System.out.println(mazePath(0, 0, 2, 2));
    }

    public static ArrayList<String> mazePath(int sr, int sc, int er, int ec) {
        if (sr == er && sc == ec) {
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }

        ArrayList<String> ans = new ArrayList<>();

        for (int jump = 1; jump + sr <= er; jump++) {
            ArrayList<String> vertical = mazePath(sr + jump, sc, er, ec);
            for (String s : vertical) {
                ans.add("V" + jump + s);
            }
        }

        for (int jump = 1; jump + sc <= ec; jump++) {
            ArrayList<String> vertical = mazePath(sr, sc + jump, er, ec);
            for (String s : vertical) {
                ans.add("H" + jump + s);
            }
        }

        for (int jump = 1; jump + sr <= er && jump + sc <= ec; jump++) {
            ArrayList<String> diagonal = mazePath(sr + jump, sc + jump, er, ec);
            for (String s : diagonal) {
                ans.add("D" + jump + s);
            }
        }
        return ans;
    }
}