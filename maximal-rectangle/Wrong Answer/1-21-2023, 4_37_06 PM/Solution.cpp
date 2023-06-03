// https://leetcode.com/problems/maximal-rectangle

class Solution {
    vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

// function to find the index of the previous smaller element to the current element
vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

// function to find the largest rectangular area in a histogram
int largestRectangleArea(vector<int> heights, int n)
{
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    // global area variable for storing the answer
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        // EDGE CASE: if all elements are equal, we might get next as -1, which will make area as negative
        // so set next[i] = n if it is -1 already
        if (next[i] == -1)
        {
            next[i] = n;
        }

        // find breadth using the indices of the next smaller element and previous smaller element
        int b = next[i] - prev[i] - 1;

        // find the current area and update the global area
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        // find row and column length
        int cLen = matrix[0].size();    
        int rLen = matrix.size();       
        
        // height array for calculation of largest area
        vector<int> h(cLen + 1);

        h[cLen] = 0;
        int ans = INT_MIN;

        for (int row = 0; row < rLen; row++) {
            for (int i = 0; i < cLen + 1; i++) {
                if (i < cLen) {
                    // note that if the base itself is zero we cannot set the
                    // height hence it is set to zero
                    if (matrix[row][i] == '1') {
                        h[i] += 1;
                    } else {
                        h[i] = 0;
                    }
                }

                ans = max(ans, largestRectangleArea(h,h.size()));
            }
        }
        
        return ans;
    }
};
