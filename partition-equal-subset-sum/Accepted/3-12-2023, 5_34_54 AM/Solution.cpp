// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& arr) {

        int sum = 0;
        for(int i=0; i<arr.size(); i++) sum += arr[i];
        if(sum & 1) return false;

        int k = sum / 2;
        int n = arr.size();
        vector<bool> prev(k+1,false);
        
        prev[0] = true;
        if(arr[0]<=k) prev[arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            vector<bool> temp(k+1,false);
            temp[0] = true;
            for(int target= 1; target<=k; target++){  
                bool notTaken = prev[target];
                bool taken = false;
                if(arr[ind]<=target) taken = prev[target-arr[ind]];
                temp[target]= notTaken||taken;
            }
            prev = temp;
        }
        
        return prev[k];
    }
};