import java.util.ArrayList;
import java.util.HashMap;

public class hashMap {
    public static void main(String[] args) {
        // HashMapOperation_01("iamkunalsuri");
        // HashMapOperation_02();
        // HashMapOperation_03("iamkunalsuri");
        int[] arr = {0, 1, 2, 3, 5, 7, 8, 9, 10, 87, 88, 89, 99, 100, 101, 102, 103};
        longestSeries(arr);
    }

    public static void HashMapOperation_01(String str) {
        HashMap<Character, ArrayList<Integer>> map = new HashMap<>();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            if (!map.containsKey(ch)) {
                map.put(ch, new ArrayList<>());
            }
            map.get(ch).add(i);
        }

        for (Character ch : map.keySet()) { // return a set of keys in random order
            System.out.println(ch + " -> " + map.get(ch));
        }
    }

    public static void HashMapOperation_02() {
        HashMap<String, Integer> map = new HashMap<>();
        map.put("USA", 100);
        map.put("India", 19000);
        map.put("pak", -1);
        map.put("italy", 99);
        map.put("America", 109);
        map.put("kunal", 345);

        System.out.println(map);
    }

    public static void HashMapOperation_03(String str) {
        HashMap<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            /*
             * if (!map.containsKey(ch)) map.put(ch, 1); else map.put(ch, map.get(ch) + 1);
             */

            // OR

            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        for (Character ch : map.keySet())    // return a set of keys in random order
            System.out.println(ch + " -> " + map.get(ch));
    }

    public static void longestSeries(int[] arr) {
        HashMap<Integer, Boolean> map = new HashMap<>();
        for (int ele: map) {
            map.put(ele, true);
        }

        for (int keys: map.keySet()) {
            if (map.containsKey(keys - 1)) {
                map.put(keys, false);
            }

            for (int keys: map.keySet()) {
                
            }
        }
    }
}