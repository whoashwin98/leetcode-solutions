// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
    vector<int> arr;
    vector<int> prefix;

    int size;
public:
    NumArray(vector<int>& nums) {
        for(int num : nums) arr.push_back(num);
        size = arr.size();

        prefix.push_back(arr[0]);
        for(int i=1; i<size; i++) {
            prefix.push_back(prefix[i-1] + arr[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefix[right];
        int sum = prefix[right] - prefix[left-1];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */