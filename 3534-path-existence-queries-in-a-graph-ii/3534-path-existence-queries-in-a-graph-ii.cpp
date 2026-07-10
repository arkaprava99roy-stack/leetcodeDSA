class Solution {
    inline static int group[100001][18] = {0};

public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int, int>> G(n);

        for (int i = 0; i < n; ++i)
            G[i] = {nums[i], i};

        sort(G.begin(), G.end());

        vector<int> I(n);

        for (int i = 0; i < n; ++i)
            I[G[i].second] = i;

        int r = 0;

        for (int i = 0; i < n; ++i) {
            if (r < i)
                r = i;

            while (r + 1 < n && G[r + 1].first - G[i].first <= maxDiff)
                ++r;

            group[i][0] = r;
        }

        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i < n; ++i) {
                group[i][j] = group[group[i][j - 1]][j - 1];
            }
        }

        int m = queries.size();
        vector<int> ans(m, -1);

        for (int i = 0; i < m; ++i) {
            int u = I[queries[i][0]];
            int v = I[queries[i][1]];

            if (u > v)
                swap(u, v);

            if (u == v) {
                ans[i] = 0;
                continue;
            }

            int curr = u;
            int steps = 0;

            for (int j = 17; j >= 0; --j) {
                if (group[curr][j] < v) {
                    curr = group[curr][j];
                    steps += (1 << j);
                }
            }

            ans[i] = (group[curr][0] >= v) ? steps + 1 : -1;
        }

        return ans;
    }
};