
/* leecode 350, 349 */

class Solution {
    public void GetCommonSeries(int[] one, int[] two) {
        HashMap<Integer, Boolean> map = new HashMap<>();
        for (int ele : one) {
            map.put(ele, true);
        }

        for (int ele : two) {
            if (map.containsKey(ele)) {
                System.out.print(ele + " ");
                map.remove(ele);
            }
        }
        System.out.println();
    }
}

class Solution {
    public static void GetCommonSeries02(int[] one, int[] two) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int ele : one) {
            map.put(ele, map.getOrDefault(ele, 0) + 1);
        }

        for (int ele : two) {
            if (map.containsKey(ele)) {
                System.out.print(ele + " ");
                if (map.get(ele) == 1)
                    map.remove(ele);
                else
                    map.put(ele, map.get(ele) - 1);
            }
        }
        System.out.println();
    }
}