// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX;
        int mini = INT_MAX;
        priority_queue<int> pq;
        
        for (auto n : nums) {
            n = n % 2 ? n * 2 : n;
            pq.push(n);
            mini = min(mini, n); 
        }
        
        while (pq.top() % 2 == 0) {
            res = min(res, pq.top() - mini);
            mini = min(mini, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }

        return min(res, pq.top() - mini);
    }
};