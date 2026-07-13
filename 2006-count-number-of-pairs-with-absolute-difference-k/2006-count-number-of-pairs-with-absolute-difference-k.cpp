class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> freq(101, 0);
        int ans = 0;

        for (int num : nums) {
            if (num - k >= 1)
                ans += freq[num - k];

            if (num + k <= 100)
                ans += freq[num + k];

            freq[num]++;
        }

        return ans;
    }
};