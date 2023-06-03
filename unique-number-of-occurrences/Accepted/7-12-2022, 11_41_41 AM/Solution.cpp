// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> count(3001, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            count[arr[i] + 1000]++;
        }

        sort(count.begin(), count.end());

        for (int i = count.size() - 1; count[i] != 0; i--)
        {
            if (count[i] == count[i - 1])
            {
                return false;
            }
        }

        return true;
    }
};