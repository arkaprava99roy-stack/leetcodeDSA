class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = total stones from i to n-1
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M] = maximum stones current player can get
        // starting from index i with M
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {

                // If we can take all remaining piles
                if (i + 2 * M >= n) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                int best = 0;

                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    int newM = max(M, X);

                    // Current player gets all remaining stones
                    // minus what the opponent can optimally get.
                    int current = suffix[i] - dp[i + X][newM];

                    best = max(best, current);
                }

                dp[i][M] = best;
            }
        }

        return dp[0][1];
    }
};