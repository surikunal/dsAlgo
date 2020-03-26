import java.util.ArrayList;

public class heap {
    private ArrayList<Integer> arr;
    private boolean isMax = false;

    public heap() {
        this.arr = new ArrayList<>();
    }

    public void createHeap(int[] ar) {
        this.arr = new ArrayList<>();
        for (int ele : ar)
            this.arr.add(ele);

        for (int i = arr.size() - 1; i >= 0; i--) { // seen to be nlogn, but it is o(n)
            downheapify(i); // logn
        }
    }

    public heap(int[] ar) { // heap creation from array O(n)
        createHeap(ar);
    }

    public heap(int[] ar, boolean isMax) { // heap creation from array O(n)
        this.isMax = isMax;
        createHeap(ar);
    }
    // API =======================================

    public void push(int val) {
        arr.add(val);
        upheapify(arr.size() - 1);
    }

    public void pop() {
        swap(0, arr.size() - 1);
        arr.remove(arr.size() - 1);
        downheapify(0);
    }

    public int top() {
        return arr.get(0);
    }

    public void update(int idx, int val) {
        arr.set(idx, val);
        upheapify(idx);
        downheapify(idx);
    
    }
    // util. ========================================

    public int size() {
        return arr.size();
    }

    public void downheapify(int idx) {  // log(n)
        int maxIdx = idx;
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;

        if (leftChild < arr.size() && compareTo(leftChild, maxIdx) > 0)     /* arr.get(leftChild) > arr.get(maxIdx) */
            maxIdx = leftChild;

        if (rightChild < arr.size() && compareTo(rightChild, maxIdx) > 0)        /* arr.get(rightChild) > arr.get(maxIdx) */
            maxIdx = rightChild;

        if (maxIdx != idx) {
            swap(idx, maxIdx);
            downheapify(maxIdx);
        }
    }

    public void upheapify(int cidx) {      // log(n)
        int par = (cidx - 1) / 2;
        if (par >= 0 && compareTo(cidx, par) > 0) {         /* arr.get(par) < arr.get(cidx) */
            swap(par, cidx);
            upheapify(par);
        }
    }

    public void swap(int i, int j) {
        int val1 = arr.get(i);
        int val2 = arr.get(j);

        arr.set(i, val2);
        arr.set(j, val1);
    }

    public int compareTo(int child, int par) {
        if (isMax) {
            return arr.get(child) - arr.get(par);
        }
        else {
            return  arr.get(par) - arr.get(child);
        }
    }
}