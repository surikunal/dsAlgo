
// using 2 stacks

class MinStack {
public:
    /** initialize your data structure here. */
    int minsf = INT_MAX;
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        minSt.push(min(minsf, x));
        minsf = minSt.top();
    }
    
    void pop() {
        if (st.size() == 0)
            return;
        
        st.pop();
        minSt.pop();
        
        if(minSt.size() != 0)
            minsf = minSt.top();
        else 
            minsf = INT_MAX;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

//using 1 stack (better)

class MinStack {
public:
    /** initialize your data structure here. */
    long minsf = INT_MAX;
    stack<long> st;
    MinStack() {
        
    }
    
    void push(int x) {
        long value = x;
        if (st.size() == 0) {
            st.push(value);
            minsf = value;
            return;
        }
        
        if (value > minsf)
        {
            st.push(value);
        }
        else 
        {
            st.push(value - minsf + value);
            minsf = value;
        }
    }
    
    void pop() {
        if (st.top() < minsf)
            minsf = minsf - st.top() + minsf;
        st.pop();
    }
    
    int top() {
        if (st.top() <= minsf)
            return (int)minsf;
        
        return (int)st.top();
    }
    
    int getMin() {
        return (int)minsf;
    }
};