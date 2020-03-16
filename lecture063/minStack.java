class MinStack {
    Stack<Integer> st;
    Stack<Integer> minSt;
    /** initialize your data structure here. */
    public MinStack() {
        st = new Stack<>();
        minSt = new Stack<>();
    }
    
    public void push(int x) {
        if (st.size() == 0) {
            st.push(x);
            minSt.push(x);
        }

        if (x > minSt.top()) {
            st.push(x);
            minSt.push(minSt.peek());
        }
        else {
            st.push(x);
            minSt.push(x);
        }
    }
    
    public void pop() {
        if (st.size() == 0) {
            return;
        }

        if (st.top() == minSt.top()) {
            st.pop();
            minSt.pop();
        }
        else {
            st.pop();
        }
    }
    
    public int top() {
        return st.top();
    }
    
    public int getMin() {
        return minSt.top();
    }
}