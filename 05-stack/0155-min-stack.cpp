#include <stack>

class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> mins;

    MinStack() {
    }

    void push(int value) {
        stack.push(value);

        if (mins.empty()) {
            mins.push(value);
        } else if (mins.top() >= value) {
            mins.push(value);
        }
    }

    void pop() {
        if (stack.top() == mins.top()) {
            stack.pop();
            mins.pop();
        } else {
            stack.pop();
        }
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return mins.top();
    }
};
