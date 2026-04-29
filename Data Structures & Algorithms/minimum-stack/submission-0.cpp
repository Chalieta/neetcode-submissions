class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(minStack.top(), val));
        }
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
