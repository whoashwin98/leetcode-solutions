// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
            vector<int> count(2001, 0);
    int maxi = *max_element(arr.begin(), arr.end());
    int offset = *min_element(arr.begin(), arr.end());

    if (offset > 0)
        offset = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i] + offset]++;
    }

    unordered_set<int> us;
    for (int i = 0; i <= maxi; i++)
    {
        if (us.find(count[i]) != us.end())
        {
            return false;
        }
        us.insert(count[i]);
    }

    return true;
    }
};