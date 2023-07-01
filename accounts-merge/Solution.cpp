class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp;

        // first iterate through the accounts and store the index mapping for each ID
        // if the index for a mail has already been stored, then for merging
        // we use DSU, and do the union operation for the existing index and the current index
        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                }

                else {
                    ds.unionByRank(i, mp[mail]);
                }
            }
        }

        // use the map and create a list of merged strings according to their indices
        // make sure the mails are pushed into the index of their ultimate parent only
        vector<string> mergedMails[n];
        for(auto it : mp) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMails[node].push_back(mail);
        }   

        // now return the answer in the format asked in the question
        vector<vector<string>> ans;

        for(int i=0; i<n; i++) {
            if(mergedMails[i].size() == 0) continue;
            
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(string mail : mergedMails[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};