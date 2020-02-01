import java.util.Scanner;
import java.util.ArrayList;

public class mazePath2 {
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

        if (sr + 1 <= er) {
            ArrayList<String> vertical = mazePath(sr + 1, sc, er, ec);
            for (String s : vertical) {
                ans.add("V" + s);
            }
        }
        if (sc + 1 <= ec) {
            ArrayList<String> horizontal = mazePath(sr , sc+1, er, ec);
            for (String s : horizontal) {
                ans.add("H" + s);
            }
        }
        if (sr + 1 <= er && sc + 1 <= ec) {
            ArrayList<String> diagonal = mazePath(sr + 1, sc+1, er, ec);
            for (String s : diagonal) {
                ans.add("D" + s);
            }
        }
        return ans;
    }
}