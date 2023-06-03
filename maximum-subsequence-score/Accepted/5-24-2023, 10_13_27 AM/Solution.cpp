// https://leetcode.com/problems/maximum-subsequence-score

class Solution {
public:
    // Define a shorthand for pair<int, int>
    using int2 = pair<int, int>;

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        // Create a vector of pairs to store the elements from nums1 and nums2
        vector<int2> p(n);
        for(int i = 0; i < n; i++){
            p[i] = {nums2[i], nums1[i]};
        }
        
        // Create a min heap using a priority queue to store the k smallest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Sort the vector of pairs based on the first element in ascending order
        // If the first elements are equal, sort based on the second element in ascending order
        sort(p.begin(), p.end(), [](int2& x, int2& y){
            if(x.first == y.first)
                return x.second < y.second;
            return x.first < y.first;
        });

        long long ans = 0, sum = 0;

        // Iterate over the sorted vector of pairs in reverse order
        for(int i = n - 1; i >= 0; i--){
            auto& [x, y] = p[i];
            
            // Add the second element of the current pair to the sum
            sum += y;
            
            // Push the second element of the current pair to the priority queue
            pq.push(y);
            
            // Once i < n - k + 1, we have encountered k elements
            if(i < n - k + 1){     
                // If the priority queue size exceeds k, remove the smallest element
                if(pq.size() > k){
                    sum -= pq.top();
                    pq.pop();
                }
                
                // Calculate the product of the sum and the first element of the current pair
                // Update the maximum score (ans) if necessary
                ans = max(ans, sum * x);
            }
        }
        
        // Return the maximum score
        return ans;
    }
};