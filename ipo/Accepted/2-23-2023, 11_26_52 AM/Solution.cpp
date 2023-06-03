// https://leetcode.com/problems/ipo

class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> pairs;
        int n = profits.size();
        for(int i=0; i<profits.size(); i++) {
            pairs.push_back({capital[i], profits[i]});
        }

        sort(pairs.begin(), pairs.end());

        int i = 0;
        priority_queue<int> maxCapital;
        while(k--) {
            while(i < n && pairs[i].first <= w) {
                maxCapital.push(pairs[i].second);
                i++;
            }

            if(maxCapital.empty()) break;
            
            w += maxCapital.top();
            maxCapital.pop();
            cout << i << " " << w << " " << k << endl;
        }

        return w;
    }
};