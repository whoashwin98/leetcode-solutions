// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        if(arr.size() == 1) return 0;
        if(arr.size() == 2) {
            return arr[0] > arr[1] ? 0 : 1;
        }

        while(low < high) {
            int mid = low + (high-low)/2;

            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;

            else if(arr[mid] > arr[mid+1]) high = mid-1;
            else low = mid+1;
        }

        return 0;
    }
};