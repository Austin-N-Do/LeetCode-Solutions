#include <vector>
#include <queue>
#include <limits>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list: node -> [(neighbor, weight)]
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        // Min heap: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            // Skip if we've already found a better path
            if (d > dist[node]) {
                continue;
            }
            
            // Explore neighbors
            for (auto [neighbor, weight] : graph[node]) {
                int newDist = dist[node] + weight;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
        
        // Find maximum distance (last node to receive signal)
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;  // Node unreachable
            }
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
};