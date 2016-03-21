class Stack {
public:
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> q;
        while (que.size()>1) {
            q.push(que.front());
            que.pop();
        }
        que.pop();
        while (!q.empty()) {
            que.push(q.front());
            q.pop();
        }
    }

    // Get the top element.
    int top() {
        queue<int> q;
        while (que.size()>1) {
            q.push(que.front());
            que.pop();
        }
        int ans = que.front();
        q.push(que.front());
        que.pop();
        while (!q.empty()) {
            que.push(q.front());
            q.pop();
        }
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};