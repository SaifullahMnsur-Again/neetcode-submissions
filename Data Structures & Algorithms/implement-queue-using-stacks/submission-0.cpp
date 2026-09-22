class MyQueue {
    stack<int> stc1, stc2;
public:
    MyQueue() {
    }
    
    void push(int x) {
            stc1.push(x);
    }
    
    int pop() {
        if(stc2.empty()) {
            while(!stc1.empty()) {
                stc2.push(stc1.top());
                stc1.pop();
            }
        }
        int ans = stc2.top();
        stc2.pop();
        return ans;
    }
    
    int peek() {
        if(stc2.empty()) {
            while(!stc1.empty()) {
                stc2.push(stc1.top());
                stc1.pop();
            }
        }
        return stc2.top();
    }
    
    bool empty() {
        return stc1.empty() and stc2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */