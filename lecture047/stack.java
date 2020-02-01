public class stack {
    private int[] st;
    private int idx = -1;

    stack() {
        this.st = new int[10];
    }

    stack(int size) {
        this.st = new int[size];
    }

    public void print(){
        System.out.print("[");
        for (int i = idx; i > 0; i--){
            System.out.print(st[i] + ",");
        }
        System.out.print(st[0] + "]");
    }

    public int size() {
        return idx + 1;
    }

    public boolean isEmpty() {
        return idx == -1;
    }

    public int top() {
        if (idx == -1){
            System.err.println("StackisEmpty");
            return -1;
        }
        return st[idx];
    }

    public void push(int data){
        if (idx == st.length){
            System.err.print("OverFlow");
            return;
        }
        idx++;
        this.st[idx] = data;
    }

    public int pop(){
        if (idx == -1){
            System.err.println("UnderFlow");
            return -1;
        }
        int rv = this.st[idx];
        st[idx] = 0;
        this.idx--;
        return rv;
    }
}