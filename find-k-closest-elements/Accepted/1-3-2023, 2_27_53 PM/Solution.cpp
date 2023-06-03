// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int midpoint = left + (right - left) / 2; 
            if (x - arr[midpoint] > arr[midpoint + k] - x) {
                left = midpoint + 1;
            }
            else {
                right = midpoint;
            }
        }

        vector<int> result;
        for (int i = left; i < left + k; i++) {
            result.push_back(arr[i]);
        }
        return result;
    }
};