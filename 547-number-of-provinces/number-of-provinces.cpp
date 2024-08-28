#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &isc, int i, vector<bool> &visited) {
        visited[i] = true; // Mark the current node as visited
        for (int j = 0; j < isc.size(); j++) { // Iterate through all nodes
            // Check if there is a connection and the node hasn't been visited yet
            if (isc[i][j] == 1 && !visited[j]) {
                dfs(isc, j, visited); // Perform DFS on the connected node
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isc) {
        int n = isc.size(); // Number of nodes
        int c = 0; // Number of connected components (circles)
        vector<bool> visited(n, false); // Visited nodes tracker

        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // If the node hasn't been visited
                c++; // We've found a new connected component
                dfs(isc, i, visited); // Perform DFS from this node
            }
        }

        return c; // Return the number of connected components found
    }
};

