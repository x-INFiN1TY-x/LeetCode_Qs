class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> out(n);

        // build reverese-graph
        for (auto& e : edges)
            out[e[1]].push_back(e[0]);

        // mark nodes as unvisited
        for (auto& e : out)
            e.push_back(-1);

        // fill the children in the reveresed graph (ancestor)
        for (int i = 0; i < n; ++i)
            fillChildren(out, i);

        return out;
    }

    void fillChildren(vector<vector<int>>& out, int idx)
    {
        vector<int>& edges = out[idx];
        // if not visited
        if (!edges.empty() && edges.back() == -1)
        {
            // mark is as visited
            edges.pop_back();

            // fill the chidlren (DFS)
            for (auto child : edges)
                fillChildren(out, child);
                
            int n = edges.size();
            for (int i = 0; i < n; ++i)
                // add children of children
                edges.insert(edges.end(), out[edges[i]].begin(), out[edges[i]].end());

            // the output should be sorted
            sort(edges.begin(), edges.end());
            
            // remove the duplicates
            edges.erase(unique(edges.begin(), edges.end()), edges.end());
        }
    }
};
