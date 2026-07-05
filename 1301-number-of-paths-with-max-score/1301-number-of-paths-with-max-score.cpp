class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        // score[i][j] = best total to reach (i,j) from S; -1 = unreachable.
        // ways[i][j]  = number of paths that achieve that best total.
        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways (n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;   // S: score 0
        ways [n - 1][n - 1] = 1;   //    1 way to start here

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == n - 1 && j == n - 1) continue;  // S is already set
                if (board[i][j] == 'X')       continue;  // wall stays unreachable

                int best = -1;
                if (i + 1 < n)              best = max(best, score[i + 1][j]);      // from below
                if (j + 1 < n)              best = max(best, score[i][j + 1]);      // from the right
                if (i + 1 < n && j + 1 < n) best = max(best, score[i + 1][j + 1]);  // from the diagonal
                if (best == -1) continue;    // no filled neighbour -> can't reach this cell

                long long cnt = 0;   // long long so three ~1e9 values can't overflow before the %
                if (i + 1 < n              && score[i + 1][j]     == best) cnt += ways[i + 1][j];
                if (j + 1 < n              && score[i][j + 1]     == best) cnt += ways[i][j + 1];
                if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] == best) cnt += ways[i + 1][j + 1];
                cnt %= MOD;

                int val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';
                score[i][j] = best + val;
                ways [i][j] = (int)cnt;
            }
        }

        if (score[0][0] == -1) return {0, 0};
        return {score[0][0], ways[0][0]};
    }
};