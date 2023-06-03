// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    bool isZero(vector<int> nums) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> mp(26,0);

        for(char ch : p) mp[ch - 'a']++;

        int n = s.size();
        int m = p.size();
        
        int left = 0;
        int right = m-1;

        while(left<=n-m) {
            vector<int> chars(mp);
            int j = left;
            while(j <= right) {
                int idx = s[j] - 'a';
                if(chars[idx] > 0) chars[idx]--;
                j++;
            }
            
            if(isZero(chars)) ans.push_back(left);
            left++;
            right++;
        }

        return ans;
    }
};