// https://leetcode.com/problems/super-pow

class Solution {
public:
    const int M = 1337;

    int findPower(int x, int n) {
        int ans = 1;
        
        while(n > 0) {
            if(n % 2 == 1) {
                ans = ((ans%M) * (x%M))%M;
                n--;
            }

            else {
                x = ((x%M) * (x%M))%M;
                n/=2;
            }
        }

        return ans;
    }

    int superPow(int a, vector<int>& b) {
        long long int power = 0;
        for(int i = 0; i<b.size(); i++) {
            power = power * 10 + b[i];
        }

        int ans = findPower(a,power);
        return ans;
    }
};