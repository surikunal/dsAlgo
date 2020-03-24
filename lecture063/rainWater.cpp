class Solution {
public:
    
    int trap(vector<int>& arr) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (st.top() != -1 && arr[i] > arr[st.top()]) {
                int h = arr[st.top()];
                st.pop();
                if (st.top() == -1)
                    break;
                
                int width = i - st.top() - 1;
                int height = (min(arr[st.top()], arr[i]) - h);
                
                ans += (height * width);
            }
            st.push(i);
        }
        return ans;
    }
};