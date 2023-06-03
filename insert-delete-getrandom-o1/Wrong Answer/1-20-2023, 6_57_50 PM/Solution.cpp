// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
    vector<int> ans;
    unordered_set<int> us;

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(us.find(val) == us.end()) {
            us.insert(val);
            ans.push_back(val);
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if(us.find(val) != us.end()) {
            us.erase(val);
            int i=0;
            while(i < ans.size() && ans[i] != val) i++;
            ans.erase(ans.begin()+i);
            return true;
        }

        return false;
    }
    
    int getRandom() {
        if(ans.size() == 0) return false;
        if(ans.size() == 1) return ans[0];
        
        int random = rand() % (ans.size()-1);
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