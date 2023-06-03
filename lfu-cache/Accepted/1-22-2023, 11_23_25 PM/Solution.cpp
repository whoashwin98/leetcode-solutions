// https://leetcode.com/problems/lfu-cache

// a node class for storing (key,value,count) in list
struct Node {
    int key, value, cnt;
    Node *next; 
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value; 
        cnt = 1; 
    }
}; 

// a list class that has functionalities for adding and removing (doubly linked list)
struct List {
    int size; 
    Node *head; 
    Node *tail; 
    List() {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void addFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
};

class LFUCache {
    // one map to store the occurence of nodes
    map<int, Node*> keyNode; 
    // another map that has frequency values mapped to list containing nodes that have occured 
    // that many times
    map<int, List*> freqListMap; 
    int maxSizeCache;
    // maintain the current minimum frequency for deletion purposes
    int minFreq; 
    int curSize; 
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }

    // a function to delete a node from one freq. list and insert into another freq. list
    void updateFreqListMap(Node *node) {
        // remove old address from map 
        keyNode.erase(node->key); 
        // remove from old frequency list
        freqListMap[node->cnt]->removeNode(node); 

        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++; 
        }

        // create a new list to store in a new frequency         
        List* nextHigherFreqList = new List();
        // if the next frequency list exists, get it
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 

        // increase the count of the node
        node->cnt += 1; 
        // add this node to the front of the list (most recently used)
        nextHigherFreqList->addFront(node); 
        // add the list to the current node count map
        freqListMap[node->cnt] = nextHigherFreqList; 
        // add the current node to the keynode map
        keyNode[node->key] = node;
    }
    
    // function to get an element from the LFU
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            int val = node->value; 
            // update the frequency of the node once accessed
            updateFreqListMap(node); 
            return val; 
        }
        // key not found case
        return -1; 
    }
    
    void put(int key, int value) {
        // cannot put if capacity itself is zero
        if (maxSizeCache == 0) {
            return;
        }
        // if node already exists
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            // update the value
            node->value = value; 
            // update both the maps with the new values
            updateFreqListMap(node); 
        }

        // otherwise perform new insertion
        else {
            // if cache full
            if(curSize == maxSizeCache) {
                // get the minimum frequency list
                List* list = freqListMap[minFreq]; 
                // remove the LRU node from the map
                keyNode.erase(list->tail->prev->key); 
                // remove this node from the list as well
                freqListMap[minFreq]->removeNode(list->tail->prev);
                // reduce the size
                curSize--; 
            }
            // increase the size for new element
            curSize++; 
            // since new element has come, minimum frequency is 1
            minFreq = 1; 

            // create a new list or get the minimum frequency list if it exists
            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq]; 
            }

            // create a new node for the given value and insert it into the list and maps
            Node* node = new Node(key, value); 
            listFreq->addFront(node);
            keyNode[key] = node; 
            freqListMap[minFreq] = listFreq; 
        }
    }
};