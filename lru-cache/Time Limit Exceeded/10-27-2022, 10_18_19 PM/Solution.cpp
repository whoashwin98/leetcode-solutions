// https://leetcode.com/problems/lru-cache

class LRUNode {
    public:
    int key, value;
    
    LRUNode(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
    deque<LRUNode*> dq;
    map<int, LRUNode*> mp;
    int cap;
    
public:
    LRUCache(int capacity) {
        cap = capacity;    
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            LRUNode *temp = mp[key];
            auto it = dq.begin();
            for (; it != dq.end(); ++it) {
                if((*it)->key == key) break;
            }
            dq.erase(it);
            dq.push_front(temp);
            return temp->value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            LRUNode *temp = mp[key];
            auto it = dq.begin();
            for (; it != dq.end(); ++it) {
                if((*it)->key == key) break;
            }
            dq.erase(it);
        }
        else {
            if(dq.size() == cap) {
                LRUNode *temp = dq.back();
                dq.pop_back();
                mp.erase(temp->key);
            }
        } 
        
        LRUNode *newEntry = new LRUNode(key, value);
        dq.push_front(newEntry);
        mp[newEntry->key] = newEntry;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */