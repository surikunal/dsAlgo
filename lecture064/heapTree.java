import java.util.ArrayList;

public class heapTree {

    ArrayList<Integer> arr = new ArrayList<>();

    heapTree() {
        this.arr = new ArrayList<>();
    }

    public void swap(int i, int j) {
        int val1 = arr.get(i);
        int val2 = arr.get(j);

        arr.set(i, val2);
        arr.set(j, val1);
    }

    public void downheapify(int idx) {
        int maxidx = idx;

        int lci = 2 * idx + 1;
        int rci = 2 * idx + 2;
        // but lci and rci can also go out of bound , so do check for that

        if (lci < arr.size() && arr.get(maxidx) < arr.get(lci)) {
            maxidx = lci;
        }

        if (rci < arr.size() && arr.get(maxidx) < arr.get(rci)) {
            maxidx = rci;
        }

        if (maxidx != idx) {
            swap(pidx, cidx);
            downheapify(pidx);
        }
    }

    public void upheapify(int cidx) {
        int pidx = (cidx - 1) / 2;

        if (arr.get(pidx) < arr.get(cidx)) {
            swap(pidx, cidx);
            upheapify(pidx);
        }
    }

    public void push() {
        
    }

    public void pop() {
        swap(0, arr.size() - 1);

    }

    public void top() {

    }

    public void update() {

    }
}