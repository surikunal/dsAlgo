class MinStack {

    Stack<Integer> st;
    Stack<Integer> minStack;
    int mini = Integer.MAX_VALUE;

    /** initialize your data structure here. */
    public MinStack() {
        st = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int x) {
        st.push(x);
        minStack.push(Math.min(mini, x));
        mini = minStack.peek();
    }

    public void pop() {
        if (st.size() == 0)
            return;

        st.pop(x);
        minStack.pop(x);

        if (minStack.size() != 0) {
            min = minStack.peek();
        }
        else {
            min = Integer.MAX_VALUE;
        }
    }

    public int top() {
        return st.peek();
    }

    public int getMin() {
        return minStack.peek();
    }
}

class MinStack2 {
    Stack<Long> st;
    long minsf = 0;
    public MinStack2() {
        st = new Stack<>();
    }

    public void push(int x) {
        long val = x;
        if (st.size() == 0) {
            minsf = val;
            st.push(val);
            return;
        }

        if (val > minsf) {
            st.push(val);
        }
        else {
            st.push(val - minsf + val);
            minsf = val;
        }
    }

    public int top() {
        if (st.peek() <= minsf) {
            return (int)minsf;
        }
        long val = st.peek();
        return (int) val; 
    }

    public void pop() {
        if (st.peek() < minsf) {
            minsf = minsf - st.peek() + minsf;
        }
        st.pop();
    }

    public int getMin() {
        return (int)minsf;
    }
}