class Solution {
private:

    void dfs(int src, vector<bool> &vis, vector <vector<int>> &adj)
    {
        vis[src] = 1;

        for(int &neighbourNode : adj[src])
        {
            if(not vis[neighbourNode])
            {
                dfs(neighbourNode, vis, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int v = isConnected.size();
        vector<vector<int>> adj(v);  
        for(int i = 0; i < v; i++) 
        {
            for(int j = 0; j < v; j++)
            {
                if(i != j && isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        int provinces = 0;
        vector<bool> vis(v, 0);
        for(int node = 0; node < v; node++)
        {
            if(not vis[node])
            {
                provinces ++;
                dfs(node, vis, adj);
            }
        }
        return provinces;
    }
};