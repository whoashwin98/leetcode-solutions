class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
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

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int r=0; r<n; r++) {
            for(int c=0; c<n; c++) {
                if(grid[r][c] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for(int i=0; i<4; i++) {
                    int newr = r + dr[i];
                    int newc = c + dc[i];

                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1) {
                        int node = r*n + c;
                        int adjNode = newr*n + newc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }    

        int maxi = 0;
        for(int r=0; r<n; r++) {
            for(int c=0; c<n; c++) {
                if(grid[r][c] == 1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> components;
                for(int i=0; i<4; i++) {
                    int newr = r + dr[i];
                    int newc = c + dc[i];

                    if(newr >= 0 && newr < n && newc >= 0 && newc < n) {
                        if(grid[newr][newc] == 1) {
                            components.insert(ds.findUPar(newr*n + newc));
                        }
                    }
                }
                int totalSize = 0;
                for(auto it : components) {
                    totalSize += ds.size[it];
                }
                maxi = max(maxi, totalSize + 1);
            }
        }    

        for(int cell = 0; cell < n*n; cell++) {
            maxi = max(maxi, ds.size[ds.findUPar(cell)]);
        }

        return maxi;
    }
};