import java.util.ArrayList;
import java.util.Scanner;

public class mazePath1 {

    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.println(mazePath(0, 0, 2, 2));
    }

    public static ArrayList<String> mazePath(int si, int ei, int sp, int ep) {
        if (si == sp && ei == ep) {
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        ArrayList<String> myAns = new ArrayList<>();

        if (si + 1 <= sp) {
            ArrayList<String> VRecAns = mazePath(si + 1, ei, sp, ep);
            for (String s : VRecAns) {
                myAns.add("V" + s);
            }
        }
        if (ei + 1 <= ep) {
            ArrayList<String> HRecAns = mazePath(si, ei + 1, sp, ep);
            for (String s : HRecAns) {
                myAns.add("H" + s);
            }
        }
        return myAns;
    }

}