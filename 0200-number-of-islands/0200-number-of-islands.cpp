auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        if(grid.size()==0)
            return 0;
        vector<vector<bool>> visited(grid.size(),vector(grid[0].size(),false));
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j]&&grid[i][j]=='1')
                {
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        
        return count;
    }
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<bool>>& visited)
    {
        visited[x][y] = true;
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        for(auto d:dirs)
        {
            int r = x+d[0];
            int c = y+d[1];
            if(r<0||r>=grid.size()||c<0||c>=grid[0].size()||visited[r][c]) 
                continue;
            if(grid[r][c]=='1')
                dfs(r,c,grid,visited);
        }
    }
};