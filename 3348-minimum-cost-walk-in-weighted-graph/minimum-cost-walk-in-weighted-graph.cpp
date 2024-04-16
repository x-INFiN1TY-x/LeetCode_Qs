class DisjointSet {
    vector<int> rank, parent, weight;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        weight.resize(n, -1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v, int wht) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) {
            weight[ulp_u] = weight[ulp_v] = weight[ulp_v] & weight[ulp_u] & wht;
            return;
        }
        weight[ulp_u] = weight[ulp_v] = weight[ulp_v] & weight[ulp_u] & wht;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    int minw(int u, int v) {
        if (u == v)
            return 0;
        if (findUPar(u) != findUPar(v))
            return -1;
        else
            return weight[findUPar(u)];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        DisjointSet sett(n);
        for (auto& i : edges) {
            sett.unionByRank(i[0], i[1], i[2]);
        }
        vector<int> sol;
        for (auto& q : query) {
            sol.push_back(sett.minw(q[0], q[1]));
        }
        return sol;
    }
};
