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

        for(auto it : arr) {
            cout << it.first << " " << it.second << endl;
        }

        for(int i=0; i<arr.size(); i++) {
            score = arr[i].second;
            int maxTillNow = arr[i].second;
            cout << score << " $ ";
            int j = i+1;
            while(j < arr.size()) {
                if(arr[j].first >= arr[i].first && arr[j].second >= maxTillNow) {
                    score += arr[j].second;
                    maxTillNow = arr[j].second;
                }
                j++;
                cout << score << " $ ";
            }
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};