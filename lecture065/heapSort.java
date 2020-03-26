public class heapSort {

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int compareTo(int[] arr, int child, int par, boolean isMax) {
        if (isMax) {
            return arr[child] - arr[par];
        } else {
            return arr[par] - arr[child];
        }
    }

    public static void downheapify(int[] arr, int idx, int lidx, boolean isMax) {
        int maxidx = idx;
        int lci = (2 * idx) + 1;
        int rci = (2 * idx) + 2;

        if (lci <= lidx && compareTo(arr, lci, maxidx, isMax) > 0) {
            maxidx = lci;
        }

        if (rci <= lidx && compareTo(arr, rci, maxidx, isMax) > 0) {
            maxidx = rci;
        }

        if (maxidx != idx) {
            swap(arr, idx, maxidx);
            downheapify(arr, maxidx, lidx, isMax);
        }
    }

    public static void heapSorting() {
        int[] arr = { 10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13 };
        int n = arr.length - 1;
        boolean isMax = true;
        for (int i = n; i >= 0; i--) {
            downheapify(arr, i, n, isMax);
        }

        for (int i = 0; i <= n; i++) {
            swap(arr, 0, n - i);
            downheapify(arr, 0, n - i - 1, isMax);
        }    

        for (int ele: arr) {
            System.out.print(ele + " ");
        }
    }

    public static void main(String[] args) {
        heapSorting();
        return;
    }
}