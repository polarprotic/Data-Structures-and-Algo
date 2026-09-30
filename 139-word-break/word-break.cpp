class Solution {
public:

    unordered_map<string, int> mp;
    vector<vector<int>> dp;

    bool solve(string s, int i, int j) {

        // Whole string has been matched
        if (i == s.size())
            return true;

        // j reached the end
        if (j > s.size())
            return false;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        string temp = s.substr(i, j - i);

        // If current substring is a word
        if (mp.find(temp) != mp.end()) {

            // Take this word and start searching from j
            if (solve(s, j, j + 1))
                return dp[i][j] = 1;
        }

        // Keep extending current word
        return dp[i][j] = solve(s, i, j + 1);
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for (int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]] = i;
        }

        dp.assign(s.size() + 1, vector<int>(s.size() + 1, -1));

        return solve(s, 0, 1);
    }
};