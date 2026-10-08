class Solution {
public:

    bool solve(int p1, int p2, vector<int>& nums, int i, int j, int turn) {

        if (i > j) {
            return p1 >= p2;
        }

        if (turn % 2 == 0) {

            // P1 can choose either side.
            // If ANY choice lets P1 win, P1 can win.
            return solve(p1 + nums[i], p2, nums, i + 1, j, turn + 1) ||
                   solve(p1 + nums[j], p2, nums, i, j - 1, turn + 1);
        }

        else {

            // P2 will choose the option that makes P1 lose.
            // Therefore P1 must win BOTH possibilities.
            return solve(p1, p2 + nums[i], nums, i + 1, j, turn + 1) &&
                   solve(p1, p2 + nums[j], nums, i, j - 1, turn + 1);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(0, 0, nums, 0, nums.size() - 1, 0);
    }
};