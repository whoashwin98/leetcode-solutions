// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int countLessThan(vector<vector<int>> matrix, int num) {
        int count = 0;
        for(int i=0; i<matrix.size(); i++) {
            int rowCount = upper_bound(matrix[i].begin(), matrix[i].end(), num) - matrix[i].begin();
            count += rowCount;
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        int ans = 0;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(countLessThan(matrix,mid) >= k) {
                ans = mid;
                high = mid-1;
            }

            else low = mid+1;
        }

        return ans;
    }
};