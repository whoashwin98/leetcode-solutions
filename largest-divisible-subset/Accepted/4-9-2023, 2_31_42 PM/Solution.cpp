// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        
        for(int i=0; i<=n-1; i++){
            hash[i] = i;
            for(int prev = 0; prev <=i-1; prev ++){
                if(arr[i]%arr[prev] == 0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }
        
        int lastEle = -1;
        int lastIndex =-1;
        for(int i=0; i<=n-1; i++){
            if(dp[i] > lastEle){
                lastEle = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){ 
            lastIndex = hash[lastIndex];
            ans.push_back(arr[lastIndex]);    
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};