// https://leetcode.com/problems/lru-cache

class LRUNode {
    public:
    int value;
    int time;
    
    LRUNode(int value, int time) {
        this->value = value;
        this->time = time;
    }
};

class LRUCache {
    map<int, LRUNode*> mp;
    int cap;
    int time;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        time = 0;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            time++;
            mp[key]->time = time;
            return mp[key]->value;
        }   
        time++;
        return -1;
    }
    
    void put(int key, int value) {       
        if(mp.size() >= cap) {
            int mini = INT_MAX;
            int minKey = INT_MAX;
            for(auto &it : mp) {
                if(it.second->time < mini) {
                    mini = it.second->time;
                    minKey = it.first;
                }
            }
            mp.erase(minKey);
        }
        
        time++;
        LRUNode *temp = new LRUNode(value,time);
        mp[key] = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */