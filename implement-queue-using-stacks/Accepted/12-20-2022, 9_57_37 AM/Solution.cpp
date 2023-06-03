// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
    stack<int> q;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(q.empty()) q.push(x);
        else {
            stack<int> temp;
            while(!q.empty()) {
                temp.push(q.top());
                q.pop();
            }
            q.push(x);
            while(!temp.empty()) {
                q.push(temp.top());
                temp.pop();
            }
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int ele = q.top();
        q.pop();
        return ele;
    }
    
    int peek() {
        return q.top();
    }
    
    bool empty() {
        return q.empty();
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