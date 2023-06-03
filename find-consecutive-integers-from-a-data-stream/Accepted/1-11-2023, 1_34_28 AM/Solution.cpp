// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream

class DataStream {
    queue<int> stream;
    int value, k;
    int count;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        count = 0;
    }
    
    bool consec(int num) {
        if(stream.size() == k) {
            int front = stream.front();
            if(front == value) count--;
            stream.pop();
        }

        stream.push(num);
        if(num == value) count++;

        if(count == k) return true;
        else return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */