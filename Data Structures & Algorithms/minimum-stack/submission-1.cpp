class MinStack {
public:
    stack<int> st;
    stack<int> stMin;

    MinStack() {
    }

    void push(int val) {
        st.push(val);
        val = min(val, stMin.empty() ? val : stMin.top());
        stMin.push(val);
    }
    
    void pop() {
        stMin.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stMin.top();
    }
};
