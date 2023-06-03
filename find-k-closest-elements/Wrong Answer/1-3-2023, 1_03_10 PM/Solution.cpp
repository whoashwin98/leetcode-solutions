// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        if(arr.size() <= 1) return ans;

        int l = 0;
        int r = arr.size()-1;

        while(l < r) {
            int adiff = abs(arr[l] - x);
            int bdiff = abs(arr[r] - x);

            if((adiff < bdiff) || (adiff == bdiff && arr[l] < arr[r])) {
                ans.push_back(arr[l]);
                l++;
            }

            else r--;
        }
    
        return ans;
    }
};