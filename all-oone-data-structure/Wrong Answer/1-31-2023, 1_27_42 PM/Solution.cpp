// https://leetcode.com/problems/all-oone-data-structure

class AllOne {
    unordered_map<string, int> mp;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
    }
    
    void dec(string key) {
        if(mp[key] == 0) mp.erase(key);
        mp[key]--;
    }
    
    string getMaxKey() {
        if(mp.empty()) return "";

        int maxi = INT_MIN;
        string ans = "";
        for(auto it : mp) {
            if(it.second > maxi) {
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
    
    string getMinKey() {
        if(mp.empty()) return "";

        int mini = INT_MAX;
        string ans = "";
        for(auto it : mp) {
            if(it.second < mini) {
                mini = it.second;
                ans = it.first;
            }
        }
        return ans;   
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */