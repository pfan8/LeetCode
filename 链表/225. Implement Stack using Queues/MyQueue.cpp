class MyQueue {
/*
    用两个栈实现,push,empty时间复杂度为O(1)，pop和top时间复杂度为O(n)
*/
private:
    /** Initialize your data structure here. */
    stack<int> push_st,pop_st;

public:
    MyQueue(): push_st(),pop_st() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        if(!pop_st.size()) {
            while(!push_st.empty()) {
                pop_st.push(push_st.top());
                push_st.pop();
            }
        }
        res = pop_st.top();
        pop_st.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(!pop_st.size()) {
            while(!push_st.empty()) {
                pop_st.push(push_st.top());
                push_st.pop();
            }    
        }
        return pop_st.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return push_st.empty() && pop_st.empty();
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