// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int cLen = matrix[0].size();    // column length
        int rLen = matrix.size();       // row length
        // height array
        vector<int> h(cLen + 1);
        h[cLen] = 0;
        int max = 0;

        for (int row = 0; row < rLen; row++) {
            stack<int> s;
            for (int i = 0; i < cLen + 1; i++) {
                if (i < cLen) {
                    if (matrix[row][i] == '1') {
                        h[i] += 1;
                    } else {
                        h[i] = 0;
                    }
                }

                if (s.empty() || h[s.top()] <= h[i]) {
                    s.push(i);
                } else {
                    while (!s.empty() && h[i] < h[s.top()]) {
                        int top = s.top();
                        s.pop();
                        int area = h[top] * (s.empty() ? i : (i - s.top() - 1));
                        if (area > max) {
                            max = area;
                        }
                    }
                    s.push(i);
                }
            }
        }
        return max;
    }
};
