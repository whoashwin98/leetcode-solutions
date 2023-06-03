// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '$';
        int n = letters.size();

        int low = 0;
        int high = n-1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(letters[mid] > target) {
                ans = letters[mid];
                high = mid-1;
            }

            else low = mid+1;
        }

        if(ans == '$') return letters[0];
        return ans;
    }
};