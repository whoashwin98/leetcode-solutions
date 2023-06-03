// https://leetcode.com/problems/design-hashset

class MyHashSet {
    vector<int> set;
public:
    MyHashSet() {}
    
    void add(int key) {
        if(!contains(key)) {
            set.push_back(key);
        }
    }
    
    void remove(int key) {
        for(int i=0; i<set.size(); i++) {
            if(key == set[i]) {
                set.erase(set.begin() + i);
            }
        }
    }
    
    bool contains(int key) {
        for(int i=0; i<set.size(); i++) {
            if(key == set[i]) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */