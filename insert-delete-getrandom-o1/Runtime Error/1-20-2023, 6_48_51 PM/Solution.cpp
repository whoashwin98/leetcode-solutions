// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
    int size;
    unordered_map<int, bool> mp;
public:
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        if(mp[val]) return false;
        size++;
        mp[val] = true;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end() || mp[val] == false) return false;

        mp[val] = false;
        return true;
    }
    
    int getRandom() {
        if(size == 0) return INT_MAX;

        vector<int> ans;

        for(auto it : mp) ans.push_back(it.first);

        int random = rand() % (size-1);
        return ans[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */