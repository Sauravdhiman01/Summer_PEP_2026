class Solution {
private:
    bool getTopoSort(int src, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &graph)
    {
        vis[src] = true;
        pathVis[src] = true;

        for (int &neighbourNode : graph[src])
        {
            if (!vis[neighbourNode])
            {
                if (getTopoSort(neighbourNode, vis, pathVis, graph))
                    return true;
            }
            else if (pathVis[neighbourNode])
            {
                return true;   
            }
        }

        pathVis[src] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);

        for (auto &edge : prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);

        for (int node = 0; node < numCourses; node++)
        {
            if (!vis[node])
            {
                if (getTopoSort(node, vis, pathVis, graph))
                {
                    return false;   
                }
            }
        }

        return true;   
    }
};