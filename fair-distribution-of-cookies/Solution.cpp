class Solution {
public:
    int ans = INT_MAX;

    void solve(vector<int>& cookies, vector<int>& children, int start) {
        if(start == cookies.size()) {
            int maxi = INT_MIN;
            for(auto it : children) maxi = max(maxi, it);
            ans = min(ans, maxi);
            return;
        }

        for(int i=0; i<children.size(); i++) {
            children[i] += cookies[start];
            solve(cookies, children, start+1);
            children[i] -= cookies[start];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        solve(cookies, children, 0);
        return ans;
    }
};