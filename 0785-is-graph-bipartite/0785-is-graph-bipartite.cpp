class Solution {
private:
    bool isBipartite(int src, int color, vector<int> &vis,vector<vector<int>> &graph)
    {
        vis[src] = color;
        for(int neighbourNode : graph[src])
        {
            if(not vis[neighbourNode])
            {
                int nextColor = (color == 1 ? 2 : 1);
                if(not isBipartite(neighbourNode, nextColor, vis, graph))
                {
                    return 0;
                }
            }
            else if(vis[neighbourNode] == vis[src]) return 0;
        }
        return 1;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v = graph.size();

        vector <int> vis(v, 0);
        for(int node = 0; node < v; node++)
        {
            if(not vis[node])
            {
                if(not isBipartite(node,1, vis, graph)) 
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};