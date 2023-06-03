// https://leetcode.com/problems/smallest-number-in-infinite-set

class SmallestInfiniteSet {
    unordered_map<int,bool> mp;
public:
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++) {
            mp[i] = false;
        }
    }
    
    int popSmallest() {
        int i;
        for(i=1; i<=1000; i++) {
            if(!mp[i]) {
                mp[i] = true;
                break;
            }
        }
        
        return i;
    }
    
    void addBack(int num) {
        mp[num] = false;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */