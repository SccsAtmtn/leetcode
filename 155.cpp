class MinStack {
public:
    stack<int> st, min;
    void push(int x) {
        st.push(x);
        int minVal = x;
        if (!min.empty() && minVal>min.top()) minVal = min.top();
        min.push(minVal);
    }

    void pop() {
        st.pop();
        min.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min.top();
    }
};