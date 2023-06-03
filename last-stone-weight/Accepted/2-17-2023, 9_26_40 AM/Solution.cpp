// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        if(stones.size() == 1) return stones[0];

        for(int stone: stones) pq.push(stone);

        while(!pq.empty() && pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x == y) continue;
            else pq.push(x-y);
        }

        return pq.empty() ? 0 : pq.top();
    }
};