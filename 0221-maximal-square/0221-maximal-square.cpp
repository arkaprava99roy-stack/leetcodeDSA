class Solution {
public:
    int maximalSquare (vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        vector<int> dp(n, 0);
        int pre;

        for(int r = 0; r < m; ++r) {

            for(int c = 0; c < n; ++c){
                int temp = dp[c];
                if(!r || !c || matrix[r][c] == '0') dp[c] = matrix[r][c] - '0';
                else{
                    dp[c] = min({pre, dp[c], dp[c - 1]}) + 1;
                }
                maxArea = max(maxArea, dp[c]); 
                pre = temp;
            }
        }
        return maxArea * maxArea;
    }
};