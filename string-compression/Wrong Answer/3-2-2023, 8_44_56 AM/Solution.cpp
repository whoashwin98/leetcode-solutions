// https://leetcode.com/problems/string-compression

class Solution {
public:
    void insertNum(vector<char>& chars, int num) {
        vector<char> nums;
        while(num > 0) {
            int digit = num % 10;
            nums.push_back(digit + '0');
            num /= 10;
        }
        reverse(nums.begin(), nums.end());
        for(char n: nums) chars.push_back(n);
    }

    int compress(vector<char>& chars) {
        map<char, int> mp;
        for(char ch : chars) mp[ch]++;
        chars.clear();
        for(auto it : mp) {
            chars.push_back(it.first);
            if(it.second > 1) insertNum(chars, it.second);
        }

        return chars.size();
    }
};