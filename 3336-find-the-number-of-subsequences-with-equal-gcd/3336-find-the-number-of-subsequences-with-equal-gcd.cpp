class Solution {
public:
    static constexpr int MOD = 1000000007;

    int subsequencePairCount(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> ndp(m + 1, vector<int>(m + 1, 0));

            for (int g1 = 0; g1 <= m; g1++) {
                for (int g2 = 0; g2 <= m; g2++) {
                    int cur = dp[g1][g2];
                    if (cur == 0) continue;

                    // Don't take x
                    ndp[g1][g2] = (ndp[g1][g2] + cur) % MOD;

                    // Put x into seq1
                    int ng1 = std::gcd(g1, x);
                    ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD;

                    // Put x into seq2
                    int ng2 = std::gcd(g2, x);
                    ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;
        for (int g = 1; g <= m; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return (int)ans;
    }
};