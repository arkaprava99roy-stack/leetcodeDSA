class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s) totalOnes += (c == '1');

        string t = "1" + s + "1";
        vector<pair<char,int>> runs;

        // Run-length encoding of augmented string
        for (char c : t) {
            if (runs.empty() || runs.back().first != c)
                runs.push_back({c, 1});
            else
                runs.back().second++;
        }

        int ans = totalOnes;

        // Eligible 1-runs are those surrounded by 0-runs
        for (int i = 1; i + 1 < (int)runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                int gain = runs[i - 1].second + runs[i + 1].second;
                ans = max(ans, totalOnes + gain);
            }
        }

        return ans;
    }
};