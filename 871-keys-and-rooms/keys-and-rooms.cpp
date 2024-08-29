#include <vector>
using namespace std;

class Solution
{
    public:
        void dfs(vector<bool> &vis, vector<vector< int>> &rooms, int room)
        {
            vis[room] = true;	// Mark the current room as visited
            for (int key: rooms[room])
            {
            	// Iterate through all keys in the current room
                if (!vis[key])
                {
                	// If the room corresponding to the key hasn't been visited
                    dfs(vis, rooms, key);	// Perform DFS for that room
                }
            }
        }

    bool canVisitAllRooms(vector<vector < int>> &rooms)
    {
        int n = rooms.size();	// Number of rooms
        vector<bool> vis(n, false);	// Visited rooms tracker

        dfs(vis, rooms, 0);	// Start DFS from room 0

        for (bool visited: vis)
        {
            if (!visited)
            {
            	// If any room hasn't been visited, return false
                return false;
            }
        }

        return true;	// If all rooms have been visited, return true
    }
};