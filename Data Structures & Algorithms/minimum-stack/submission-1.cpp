class MinStack {
    stack<pair<int, int>> stc;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stc.empty()) {
            stc.push({val, val});
        } else {
            stc.push({val, min(stc.top().second, val)});
        }
    }
    
    void pop() {
        stc.pop();
    }
    
    int top() {
        return stc.top().first;
    }
    
    int getMin() {
        return stc.top().second;
    }
};
