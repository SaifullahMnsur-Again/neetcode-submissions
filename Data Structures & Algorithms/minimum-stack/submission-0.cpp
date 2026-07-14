class MinStack {
    stack<int> stc, mstc;
public:
    MinStack() {
    }
    
    void push(int val) {
        stc.push(val);
        if(!mstc.empty())
            mstc.push(min(stc.top(), mstc.top()));
        else
            mstc.push(stc.top());
    }
    
    void pop() {
        stc.pop();
        mstc.pop();
    }
    
    int top() {
        return stc.top();
    }
    
    int getMin() {
        return mstc.top();
    }
};
