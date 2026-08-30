class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &road : roads) {
            int u = road[0], v = road[1], time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<int> ways_to_reach(n);
        vector<long long> time_taken(n, LLONG_MAX);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > minHeap;

        // {current_time, node}
        minHeap.push({0, 0});
        ways_to_reach[0] = 1;

        while (!minHeap.empty()) {
            auto [cur_time, node] = minHeap.top();
            minHeap.pop();

            // Ignore outdated entries
            if (cur_time > time_taken[node]) {
                continue;
            }

            for (auto [nbr, edge_time] : adj[node]) {

                // Found a shorter path
                if (cur_time + edge_time < time_taken[nbr]) {
                    time_taken[nbr] = cur_time + edge_time;
                    ways_to_reach[nbr] = ways_to_reach[node];
                    minHeap.push({time_taken[nbr], nbr});
                }

                // Found another shortest path
                else if (cur_time + edge_time == time_taken[nbr]) {
                    ways_to_reach[nbr] =
                        (ways_to_reach[nbr] + ways_to_reach[node]) % MOD;
                }
            }
        }

        return ways_to_reach[n - 1];
    }
};