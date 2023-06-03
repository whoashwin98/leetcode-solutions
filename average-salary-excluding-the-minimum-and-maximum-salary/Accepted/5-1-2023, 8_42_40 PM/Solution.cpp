// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<salary.size(); i++) {
            maxi = max(salary[i], maxi);
            mini = min(salary[i], mini);
        }

        cout << maxi << mini << endl;
        double sum = 0.0;
        for(int i=0; i<salary.size(); i++) {
            if(salary[i] != maxi && salary[i] != mini) {
                sum += salary[i];
            }
        }

        double size = salary.size();
        double avg = sum / (size-2);
        return avg;
    }
};