// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        if(stones.size() == 1) return stones[0];

        for(int stone: stones) pq.push(stone);

        while(1) {
            if(pq.size() == 1) break;
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            cout << x << " " << y << endl;
            if(x == y) continue;
            else pq.push(x-y);
        }

        return pq.top();
    }
};