// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
                int len = 0;
        int count = 0;
        bool flag = 0;
        // store all the strings with their number of occurences
        unordered_map<string,int> mp;
        for(int i = 0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        // now check cases
        for(int i = 0;i<words.size();i++)
        {
            // if s[0] != s[1]
            if(words[i][0] != words[i][1])
            {
              string s = "";
              // store the reverse
              s += words[i][1];
              s += words[i][0];
              // if we find the reverse in the map
              // we take the minimum count
              // we do len = count*4 because each string has 2 characters
              if(mp.find(s) != mp.end())
              {
                count = min(mp[words[i]],mp[s]);
                len += count*4;
              }
              // erase the words which are already counted including the reverse one
              mp.erase(words[i]);
              mp.erase(s);
            }
            // if s[0] == s[1]
            else if(words[i][0] == words[i][1])
            {
                // get number of occurence of such string
                count = mp[words[i]];
                // if that string occur even number of times
                if(mp[words[i]]%2==0)
                {
                    // if its even
                    len += count*2;
                }
                else{
                    // if its odd
                    // flag = 0 means its the first string that occurs odd number of times
                    // if its the first one then we can use all its occurences for our result
                    if(flag==0)
                    {
                      // means its the first string which is equal but odd occurence
                      len += count*2;
                      // make sure to turn the flag=1 because we already have one string with odd number of occurences in our output now
                      flag = 1;
                    }
                    else{
                        // if flag = 1 already then we need to count -1 from the all occurence of that string
                        len += (count-1)*2;
                    }
                }
                // erase that word from the map
                mp.erase(words[i]);
            }
        }
        // return the output length
        return len;
    }
};