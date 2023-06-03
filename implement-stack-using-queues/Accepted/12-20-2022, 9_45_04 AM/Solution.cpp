// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
    queue<int> first, second;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(first.empty()) {
            first.push(x);
            return;
        }

        while(!first.empty()) {
            second.push(first.front());
            first.pop();
        }
        first.push(x);
        while(!second.empty()) {
            first.push(second.front());
            second.pop();
        }
    }
    
    int pop() {
        if(first.empty()) return -1;

        int ele = first.front();
        first.pop();
        return ele;
    }
    
    int top() {
        return first.front();
    }
    
    bool empty() {
        return first.empty();
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