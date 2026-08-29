class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n + 1];

        // Create adjacency list
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back(
                {times[i][1], times[i][2]}
            );
        }

        // {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        q.push({0, k});

        while(!q.empty()) {

            int d = q.top().first;
            int node = q.top().second;

            q.pop();

            // Explore neighbours
            for(auto it : adj[node]) {

                int nextNode = it.first;
                int weight = it.second;

                if(d + weight < dist[nextNode]) {

                    dist[nextNode] = d + weight;

                    q.push({
                        dist[nextNode],
                        nextNode
                    });
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};