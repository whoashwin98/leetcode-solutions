// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string dir = "";
        string res = "/";

        for(int i=0; i<path.size(); i++) {
            dir.clear();
            
            while(path[i] == '/') i++;

            while(i < path.size() && path[i] != '/') {
                dir.push_back(path[i]); 
                i++;
            }

            if(dir == "..") {
                if(!st.empty()) st.pop();
            }
            else if(dir == ".") continue;
            else if(dir.length() != 0) st.push(dir);
        }

        stack<string> dummy;
        while(!st.empty()) {
            dummy.push(st.top());
            st.pop();
        }

        while(!dummy.empty()) {
            string ans = dummy.top();

            if(dummy.size() != 1) res.append(ans+"/");
            else res.append(ans);
            
            dummy.pop();
        }

        return res;
    }
};