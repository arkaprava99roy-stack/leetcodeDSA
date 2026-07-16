class Solution {
public:
    vector<string> ans;

    void backtrack(string &s, int idx, int parts, string curr) {
        if (parts == 4) {
            if (idx == s.size()) {
                curr.pop_back();          // remove last '.'
                ans.push_back(curr);
            }
            return;
        }

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);

            // Leading zero check
            if (part.size() > 1 && part[0] == '0')
                break;

            int val = stoi(part);
            if (val > 255)
                continue;

            backtrack(s, idx + len, parts + 1, curr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        if (s.size() < 4 || s.size() > 12)
            return ans;

        backtrack(s, 0, 0, "");

        return ans;
    }
};