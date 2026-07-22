class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &edge : prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);   
            indegree[edge[0]]++;
        }

        queue<int> q;

        for (int node = 0; node < numCourses; node++)
        {
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }

        int count = 0;

        while (!q.empty())
        {
            int src = q.front();
            q.pop();
            count++;

            for (int neighbour : graph[src])
            {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return count == numCourses;
    }
};