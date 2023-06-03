// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) pq.push(num);
    }
    
    int add(int val) {
        pq.push(val);
        
        stack<int> st;
        int i = 0;
        while(i < k-1) {
            st.push(pq.top());
            pq.pop();
            i++;
        }

        int ans = pq.top();
        
        while(!st.empty()) {
            pq.push(st.top());
            st.pop();
        }

        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */