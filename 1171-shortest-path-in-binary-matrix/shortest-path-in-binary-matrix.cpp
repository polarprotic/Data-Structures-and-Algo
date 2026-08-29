class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int row[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        int col[8] = {0, 0, -1, 1, 1, -1, 1, -1};

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > q;

        q.push({1, {0, 0}});
        vis[0][0] = 1;

        while (!q.empty()) {

            int d = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;

            q.pop();

            if (r == n - 1 && c == m - 1)
                return d;

            for (int i = 0; i < 8; i++) {

                int dr = r + row[i];
                int dc = c + col[i];

                if (dr >= 0 && dr < n &&
                    dc >= 0 && dc < m &&
                    grid[dr][dc] == 0 &&
                    !vis[dr][dc]) {

                    vis[dr][dc] = 1;

                    q.push({d + 1, {dr, dc}});
                }
            }
        }

        return -1;
    }
};