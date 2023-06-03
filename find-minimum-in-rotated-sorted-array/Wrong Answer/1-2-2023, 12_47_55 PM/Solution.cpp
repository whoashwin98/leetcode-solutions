// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while(low < high) {
            int mid = low +(high-low)/2;

            if(arr[mid] > arr[0]) low = mid+1;
            else high = mid;
        }

        if(low == arr.size() - 1) return arr[0];
        return arr[low];
    }
};