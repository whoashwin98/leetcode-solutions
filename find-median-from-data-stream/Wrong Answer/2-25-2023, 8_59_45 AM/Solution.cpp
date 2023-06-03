// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() {}    

    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return (double)(nums[0] + nums[1]) / 2.0;

        int pos = n / 2;
        if(n % 2 != 0) return nums[pos];
        double ans = (double)(nums[pos] + nums[pos + 1]) / (double)2;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */