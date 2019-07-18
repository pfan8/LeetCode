class MyStack {
/*
    用一个queue实现，记录top_val，每次push和pop更新front
*/
private:
    queue<int> q;
    int top_val;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        top_val = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        for(int i = 0; i < q.size(); i++) {
            if(i == q.size()-1) {
                res = q.front();
                q.pop();
            } else {
                top_val = q.front();
                q.pop();
                q.push(top_val);
            }
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return top_val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */