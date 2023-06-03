// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        int mid = 0;
        
        while(low <= high) {
            mid = (low + high) /2;
            // peak will be greater than both its adjacent members
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            }
            
            // left side means increasing order
            // if we are on the left side of peak we need to go to the right
            else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) {
                low = mid + 1;
            }
            
            // right side means decreasing order
            // if we are on the right side of peak we need to go to the left
            else if(arr[mid+1] < arr[mid] && arr[mid] < arr[mid-1]) {
                high = mid-1;
            }
        }
        
        return -1;
    }
};