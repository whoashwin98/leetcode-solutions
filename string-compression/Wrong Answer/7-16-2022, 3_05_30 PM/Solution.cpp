// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {   
        sort(chars.begin(),chars.end());
        int count[26] = {0};
        int ansIndex = 0;
        for(int i=0; i<chars.size(); i++) {
            count[chars[i] - 'a']++;    
        }
        
        int j=0;
        while(j<chars.size()) {
            chars[ansIndex++] = chars[j];
            int cnt = count[chars[j]-'a'];
            if(cnt > 1) {
                string cntChar = to_string(cnt);
                for(char ch: cntChar) {
                    chars[ansIndex++] = ch;
                }
            }
            j = j+cnt;
        }
        
        return ansIndex;
    }
};