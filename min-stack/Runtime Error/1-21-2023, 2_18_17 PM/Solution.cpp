// https://leetcode.com/problems/min-stack

class MinStack {
    stack<int> st;
    int mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else {
            if(val < mini) {
                int newVal = 2*val - mini;
                st.push(newVal);
                mini = val;
            }

            else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        int curr = st.top();
        st.pop();

        if(curr > mini) return;
        else {
            int val = 2*mini - curr;
            mini = val;
        }
    }
    
    int top() {
        return st.top();       
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */