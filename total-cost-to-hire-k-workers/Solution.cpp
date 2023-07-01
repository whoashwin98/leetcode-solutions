class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // push first & last elements into the PQ
        // make sure to keep track of the last indices of both the sections
        for(int i=0; i<candidates; i++) {
            pq.push({costs[i], i});
        }
        int frontLast = candidates-1;

        int i = costs.size()-1;
        int count = 0;
        while(count < candidates && i >= candidates) {
            pq.push({costs[i], i});
            count++;
            i--;
        }
        int backLast = i+1;
        
        while(k > 0) {
            // get the top element from the PQ and add it to the cost
            int cst = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            cost += cst;

            // this condition fails when the indices are about to overlap
            if(frontLast + 1 != backLast) {
                // if element is removed from the back then add element from the back
                if(idx >= backLast) {
                    backLast--;
                    pq.push({costs[backLast], backLast});
                }

                // otherwise element has been removed from the front so add element
                // from the front
                else {
                    frontLast++;
                    pq.push({costs[frontLast], frontLast});
                }
            }

            // decrement counter
            k--;
        }

        return cost;
    }
};