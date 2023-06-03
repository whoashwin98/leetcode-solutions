// https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    string getPermutation(int n, int k) {
        // find the number of permutations
        int fact = 1;
        // store the numbers from 1 to n in a list to use it later
        vector<int> nums;
        for(int i=1; i<n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        // push back n since it isn't added in the above loop
        nums.push_back(n);
        
        string ans = "";
        k--;
        
        while(true) {
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            
            if(nums.size() == 0) break;
            
            k = k % fact;
            fact = fact / nums.size();    
        }
        
        return ans;
    }
};
