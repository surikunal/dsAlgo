
/* leetcode question 215 , 378 , 703 */

import java.util.*;

public class leetcode {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        // int[] arr = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
        // int k = 4;
        // System.out.println(findKthLargest(arr, k));

        int[][] matrix = { { 1, 5, 9 },
                           { 10, 11, 13 },
                           { 12, 13, 15 }
                         };
        int k = 8;
        System.out.println(kthSmallest(matrix, k));
    }

    // public static void swap(int[] arr, int i, int j) {
    // int val1 = arr[i];
    // int val2 = arr[j];

    // arr[i] = val2;
    // arr[j] = val1;
    // }

    // public static void downheapify(int[] arr, int idx, int lidx) {
    // int maxidx = idx;
    // int lci = (idx << 1) + 1;
    // int rci = (idx << 1) + 2;

    // if (lci <= lidx && arr[lci] > arr[maxidx]) {
    // maxidx = lci;
    // }

    // if (rci <= lidx && arr[rci] > arr[maxidx]) {
    // maxidx = rci;
    // }

    // if (maxidx != idx) {
    // swap(arr, arr[idx], arr[maxidx]);
    // downheapify(arr, maxidx, lidx);
    // }
    // }

    // public static int findKthLargest(int[] arr, int k) {
    // int n = arr.length - 1;
    // for (int i = n; i >= 0; i++) {
    // downheapify(arr, i, n);
    // }

    // for (int i = 0; i < k; i++) {
    // swap(arr, arr[0], arr[n - i]);
    // downheapify(arr, 0, n - i - 1);
    // }

    // return arr[n - k + 1];
    // }

    // leet 378 ============================================

    public static class pair {
        int ele, i, j;

        pair(int ele, int i, int j) {
            this.ele = ele;
            this.i = i;
            this.j = j;
        }
    }

    public static int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<pair> pq = new PriorityQueue<>((pair a, pair b) -> {
            return a.ele - b.ele;
        });
        // min priority queue
        // and for max pq
        // ele.b - ele.a

        int n = matrix.length;
        int m = matrix[0].length;

        for (int i = 0; i < n; i++) {
            pq.add(new pair(matrix[i][0], i, 0));
        }

        while (--k > 0) /* k-1 times chalega*/ {
            pair p = pq.poll();  // same as pop()
            int x = p.i;
            int y = p.j;

            if (++y < m) 
                pq.add(new pair(matrix[x][y], x, y));
        } 
        return pq.poll().ele;
    }

    // leet 703 =======================================

    // PriorityQueue<Integer> pq = new PriorityQueue<>();
    // int size;
    // public KthLargest(int k, int[] nums) {
    //     size = k;
    //     for (int ele : nums) {
    //         pq.add(ele); 
            
    //         if (pq.size() > k) {
    //             pq.peek();
    //         }
    //     }        
    // }
    
    // public int add(int val) {
    //     pq.add(val);
        
    //     if (pq.size() > size) {
    //         pq.remove();
    //     }
    //     return pq.peek();
    // }
}