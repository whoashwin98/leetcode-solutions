// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while(low < high) {
            if(arr[low] < arr[high]) return arr[low];
            int mid = low +(high-low)/2;

            if(arr[mid] >= arr[low]) low = mid+1;
            else high = mid;
        }

        return arr[low];
    }
};