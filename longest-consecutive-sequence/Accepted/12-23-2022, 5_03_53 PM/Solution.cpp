// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> st;
        for(int num : nums) {
            st.insert(num);
        }

        int count = 1;
        int maxCount = 0;
        auto it = st.begin();
        int prev = *it;
        it++;

        while(it != st.end()) {
            int curr = *it;
            cout << curr <<  " " << prev << " " << count << endl;
            if(curr == prev + 1) count++;
            else {
                maxCount = max(maxCount,count);
                count = 1;
            }
            prev = curr;
            it++;
        }
        
        maxCount = max(maxCount, count);
        return maxCount;
    }
};