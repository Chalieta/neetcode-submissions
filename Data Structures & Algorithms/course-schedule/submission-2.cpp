class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> catalog;
        vector<int> visited(numCourses, 0);

        // Initiate catalog with empty list
        for (int i = 0; i < numCourses; ++i) {
            catalog[i] = {};
        }

        // Populate catalog
        for (auto p : prerequisites) {
            catalog[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (!dfs(i, catalog, visited)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(int course, unordered_map<int, vector<int>>& catalog, vector<int>& visited) {
        if (visited[course] == 1) {
            return false;
        }
        if (visited[course] == 2) {
            return true;
        }

        visited[course] = 1;
        vector<int> prerequisites = catalog[course];
        for (int p : prerequisites) {
            if (!dfs(p, catalog, visited)) {
                return false;
            }
        }
        visited[course] = 2;
        return true;
    }
};