// https://leetcode.com/problems/best-team-with-no-conflicts

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr;

        for(int i=0; i<scores.size(); i++) {
            arr.push_back(make_pair(ages[i], scores[i]));
        }

        sort(arr.begin(), arr.end());

        int maxScore = INT_MIN;
        int score = 0;

        for(int i=0; i<arr.size(); i++) {
            score = arr[i].second;
            int j = i+1;
            while(j < arr.size()) {
                if(arr[j].second >= arr[i].second) score += arr[j].second;
                j++;
            }
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};