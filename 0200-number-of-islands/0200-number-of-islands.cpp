class Solution {
private:
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if ( i < 0 or j < 0 or i == grid.size() or j == grid[0].size() or grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;
        

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    islands ++;

                    dfs(i,j,grid);
                }
            }
        }
        return islands;
    }
};