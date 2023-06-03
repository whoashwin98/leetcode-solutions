// https://leetcode.com/problems/integer-to-english-words

class Solution {
public:
    void convert(int n, vector<string>& ans) {
        vector<string> ones = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

        if(n == 100) {
            n = n / 100;
            ans.push_back("Hundred");
            ans.push_back(ones[n-1]);
            return;
        }

        int place = 1;
        while(n > 0) {
            int dig = n % 100;
            place++;

            if(place == 3) ans.push_back("Hundred");

            if(dig == 0) continue;
            else if(dig >= 1 && dig <= 19) ans.push_back(ones[dig-1]);
            else {
                int firstdig = dig / 10;
                int seconddig = dig % 10;
                if(seconddig > 0) ans.push_back(ones[seconddig-1]);
                ans.push_back(tens[firstdig-1]); 
            }
            n = n / 100;
        }
    }

    string numberToWords(int num) {

        if(num == 0) return "Zero";
        
        vector<int> nums;
        while(num > 0) {
            nums.push_back(num % 1000);
            num = num / 1000;
        }

        vector<string> ans;
        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
        
            if(i == 1 && n != 0) ans.push_back("Thousand");
            if(i == 2 && n != 0) ans.push_back("Million");
            if(i == 3 && n != 0) ans.push_back("Billion");

            convert(n, ans);
        }
        
        string res = "";
        for(int i=ans.size()-1; i>=1; i--) {
            res += ans[i];
            res += " ";
        }

        res += ans[0];
        return res;
    }
};