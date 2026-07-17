class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // exact[g] = number of pairs whose gcd is exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long cnt = 0;
            for (int m = g; m <= mx; m += g)
                cnt += freq[m];

            exact[g] = cnt * (cnt - 1) / 2;

            for (int m = g + g; m <= mx; m += g)
                exact[g] -= exact[m];
        }

        // prefix[g] = number of pairs with gcd <= g
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {
            // first gcd value whose prefix count > q
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};