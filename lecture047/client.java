public class client {
    public static void main(String[] args) {
        // stack st = new stack();
        // for (int i = 0; i < 10; i++) {
        //     st.push(i);
        // }
        // st.pop();
        // st.pop();
        // st.pop();
        // System.out.println(st.size());
        // System.out.println(st.top());
        // st.print();

        Queue que = new Queue();
        for (int i = 0; i < 10; i++){
            que.push(i);
        }
        que.pop();
        que.pop();
        que.print();
    }
}
