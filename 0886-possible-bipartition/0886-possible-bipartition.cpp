class Solution {
private:
    bool dfs(int node, int currColor, vector<int> &color, vector<vector<int>> &graph)
    {
        color[node] = currColor;

        for (int neighbour : graph[node])
        {
            if (color[neighbour] == 0)
            {
                int nextColor = (currColor == 1) ? 2 : 1;

                if (!dfs(neighbour, nextColor, color, graph))
                    return false;
            }
            else if (color[neighbour] == currColor)
            {
                return false;
            }
        }

        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> graph(n + 1);

        for (auto &edge : dislikes)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                if (!dfs(i, 1, color, graph))
                    return false;
            }
        }

        return true;
    }
};