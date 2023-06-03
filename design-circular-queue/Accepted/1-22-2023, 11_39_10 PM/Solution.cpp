// https://leetcode.com/problems/design-circular-queue

class Node {
    public: 
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class MyCircularQueue {
    Node* head;
    Node* tail;
    int currSize;
    int maxSize;
public:
    MyCircularQueue(int k) {
        head = NULL;
        tail = NULL;
        currSize = 0;
        maxSize = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        Node* temp = new Node(value);

        if(head == NULL) {
            head = tail = temp;
            tail->next = head;
            currSize++;
            return true;
        }

        else {
            tail->next = temp;
            tail = temp;
            tail->next = head;
            currSize++;
            return true;
        }   
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        Node* del = head;

        if(head->next == head) {
            head = NULL;
            tail = NULL;
            delete del;
            currSize--;
            return true;
        }

        else {
            head = head->next;
            tail->next = head;
            delete del;
            currSize--;
            return true;
        }
    }
    
    int Front() {
        if(head == NULL) return -1;
        return head->val;
    }
    
    int Rear() {
        if(head == NULL) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */