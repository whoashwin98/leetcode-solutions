// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
    vector<int> arr;
    int size;
public:
    NumArray(vector<int>& nums) {
        for(int num : nums) arr.push_back(num);
        size = arr.size();
    }
    
    int sumRange(int left, int right) {
        if(left < 0 || right > size) return INT_MAX;
        
        int sum = 0;
        for(int i=left; i<=right; i++) {
            sum += arr[i];
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */