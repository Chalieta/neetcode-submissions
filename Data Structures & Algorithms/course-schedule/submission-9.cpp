class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> catalog;
        unordered_set<int> visited;

        for (const auto& p : prerequisites) {
            catalog[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, catalog, visited)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int course, unordered_map<int, vector<int>>& catalog, unordered_set<int>& visited) {
        if (visited.count(course)) {
            return false;
        }

        if (catalog[course].empty()) {
            return true;
        }

        visited.insert(course);
        vector<int> prereqs = catalog[course];
        for (int p : prereqs) {
            if (!dfs(p, catalog, visited)) {
                return false;
            }
        }

        visited.erase(course);
        catalog[course].clear();
        return true;
    }
};
