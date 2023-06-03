// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
    vector<int> arr;
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);
        arr.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++) {
            arr.push_back(nums[i]);
            prefix.push_back(nums[i] + prefix[i-1]);
        }
    }
    
    void update(int index, int val) {
        arr[index] = val;

        for(int i=index; i<prefix.size(); i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefix[right];
        return prefix[right] - prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */