class Queue {
public:
    stack<int> st;
    // Push element x to the back of queue.
    void push(int x) {
        st.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> ss;
        while (!st.empty()) {
            ss.push(st.top());
            st.pop();
        }
        ss.pop();
        while (!ss.empty()) {
            st.push(ss.top());
            ss.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> ss;
        while (!st.empty()) {
            ss.push(st.top());
            st.pop();
        }
        int p = ss.top();
        while (!ss.empty()) {
            st.push(ss.top());
            ss.pop();
        }
        return p;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
};