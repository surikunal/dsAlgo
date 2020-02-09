import java.util.*;

// import sun.misc.Queue;

public class rottenOranges {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        // int n = scn.nextInt();
        // int m = scn.nextInt();
        // int[][] arr = new int[n][m];
        // for (int i = 0; i < n; i++){
        // for (int j = 0; j < m; j++){
        // arr[i][j] = scn.nextInt();
        // }
        // }
        int[][] arr = { { 2, 1, 0, 2, 1 }, { 1, 0, 1, 2, 1 }, { 1, 0, 0, 2, 1 } };
        System.out.println(rotten(arr, 3, 5));
    }

    public static class pair {
        int i = 0;
        int j = 0;

        pair(int i, int j) {
            this.i = i;
            this.j = j;
        }

        pair() {
            // default
        }
    }

    public static boolean isValid(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }
        return true;
    }

    public static int rotten(int arr[][], int n, int m) {
        Queue<pair> que = new LinkedList<pair>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 2) {
                    que.add(new pair(i, j));
                }
            }
        }
        que.add(null);
        int ans = 0;

        while (!que.isEmpty()) {
            boolean flag = false;
            while (que.peek() != null) {
                pair temp = que.peek();

                if (isValid(temp.i + 1, temp.j, m, n) && arr[temp.i + 1][temp.j] == 1) {
                    if (!flag) {
                        flag = true;
                        ans++;
                    }
                    arr[temp.i + 1][temp.j] = 2;
                    que.add(new pair(temp.i + 1, temp.j));
                }
                if (isValid(temp.i, temp.j + 1, m, n) && arr[temp.i][temp.j + 1] == 1) {
                    if (!flag) {
                        flag = true;
                        ans++;
                    }
                    arr[temp.i][temp.j + 1] = 2;
                    que.add(new pair(temp.i, temp.j + 1));
                }
                if (isValid(temp.i - 1, temp.j, m, n) && arr[temp.i - 1][temp.j] == 1) {
                    if (!flag) {
                        flag = true;
                        ans++;
                    }
                    arr[temp.i - 1][temp.j] = 2;
                    que.add(new pair(temp.i - 1, temp.j));
                }
                if (isValid(temp.i, temp.j - 1, m, n) && arr[temp.i][temp.j - 1] == 1) {
                    if (!flag) {
                        flag = true;
                        ans++;
                    }
                    arr[temp.i][temp.j - 1] = 2;
                    que.add(new pair(temp.i, temp.j - 1));
                }
                que.poll();
            }
            que.poll();
            if (!que.isEmpty())
                que.add(null);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    ans = -1;
                    break;
                }
            }
        }
        return ans;
    }
}