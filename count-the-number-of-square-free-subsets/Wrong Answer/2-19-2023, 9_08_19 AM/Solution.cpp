// https://leetcode.com/problems/count-the-number-of-square-free-subsets

class Solution {
public:
    long long M = 1000000007;
    
    bool isSquareFree(int n)
    {
        if (n % 2 == 0)
           n = n/2;

        // If 2 again divides n, then n is
        // not a square free number.
        if (n % 2 == 0)
           return false;

        // n must be odd at this point.  So we can 
        // skip one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i+2)
        {
            // Check if i is a prime factor
            if (n % i == 0)
            {
               n = n/i;

               // If i again divides, then
               // n is not square free
               if (n % i == 0)
                   return false;
            }
        }

        return true;
    }
    
    void solve(vector<int> nums, long long int& sum, int i, int& ans) {    
        if(i == nums.size()) {
            if(sum > 1 && isSquareFree(sum)) ans = ((ans%M) + (1%M))%M;
            return;
        }
        // pick current element
        sum = (sum%M * nums[i]%M)%M;
        solve(nums, sum, i+1, ans);
        // don't pick current element
        sum /= nums[i];
        solve(nums, sum, i+1, ans);
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        if(nums.size() == 1 && isSquareFree(nums[0])) return 1;
    
        long long int sum = 1;
        int i = 0;
        int ans = 0;
        solve(nums, sum, i, ans);
        // for(int sum : sums) cout << sum << " ";
        return ans;
    }
};