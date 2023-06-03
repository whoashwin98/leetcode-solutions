// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool isValid(vector<int> piles, int h, int bph) {
        int n = piles.size();
        int operations = 0;

        for(int num : piles) {
            int curr = num/bph;
            if(num % bph > 0) curr++;
            operations += curr;
        }
                
        return operations <= h;
    }
    

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(isValid(piles,h,mid)) {
                ans = mid;
                high = mid-1;
            }

            else low = mid+1;
        }

        return ans;
    }
};