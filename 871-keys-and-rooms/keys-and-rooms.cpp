auto fastio=[]()  {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int node, vector<int>& visited) {
        visited[node] = 1; // Mark room as visited
        for (int i : rooms[node]) {
            if (!visited[i]) {
                dfs(rooms, i, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0); // Initialize all rooms as not visited
        dfs(rooms, 0, visited); // Start DFS from room 0
        // Check if all rooms have been visited during DFS
        for (int v : visited) {
            if (v == 0) {
                return false; // If any room is not visited, return false
            }
        }
        return true; // All rooms have been visited
    }
};
