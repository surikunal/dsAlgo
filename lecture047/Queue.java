public class Queue {
    private int st = -1;
    private int end = -1;
    private int size = 0;

    Queue() {
        this.st = new int[10];
    }

    Queue(int size) {
        this.st = new int[size];
    }

    public void print(){
        System.out.print("[");
        for (int i = idx; i > 0; i--){
            System.out.print(que[i] + ",");
        }
        System.out.print(que[0] + "]");
    }

    public int size() {
        return idx + 1;
    }

    public boolean isEmpty() {
        return idx == -1;
    }

    public int front() {
        if (idx == -1){
            System.err.println("StackisEmpty");
            return -1;
        }
        return que[idx];
    }

    public void push(int data){
        if (this.size == this.arr.length){
            System.err.print("QueueIsOverFlow");
            return;
        }
        this.arr[idx] = data;


    }

    public int pop(){
        if (idx == -1){
            System.err.println("UnderFlow");
            return -1;
        }
        int rv = this.que[idx];
        que[idx] = 0;
        this.idx--;
        return rv;
    }
}