#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list and indegree array
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }
        
        // Add all courses with no prerequisites to queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int coursesCompleted = 0;
        
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesCompleted++;
            
            // Reduce indegree for all neighbors
            for (int neighbor : graph[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If we completed all courses, no cycle exists
        return coursesCompleted == numCourses;
    }
};