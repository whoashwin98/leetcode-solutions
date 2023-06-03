// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int sumOfArray(vector<int> arr, int low, int high) {
        int sum = 0;
        for(int i=low; i<=high; i++) {
            sum += arr[i];
        }
        return sum;
    }
    
    int pivotIndex(vector<int>& arr) {
        
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(sumOfArray(arr,0,i-1) == sumOfArray(arr,i+1,n-1)) {
                return i;
            }
        }
        
        return -1;
    }
};