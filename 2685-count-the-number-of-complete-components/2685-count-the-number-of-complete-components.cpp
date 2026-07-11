class Solution {
private:
    vector<int> parent;

    int find(int n) {
        return parent[n] == n ? n : parent[n] = find(parent[n]);
    }

    void Union(int n1, int n2) {
        int u = find(n1);
        int v = find(n2);

        if (u == v)
            return;

        parent[u] = v;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        // Build DSU
        for (vector<int>& edge : edges) {
            Union(edge[0], edge[1]);
        }

        vector<int> count(n, 0);
        vector<int> size(n, 0);

        // Count edges in each connected component
        for (vector<int>& edge : edges) {
            int u = find(edge[0]);
            ++count[u];
        }

        // Count vertices in each connected component
        for (int i = 0; i < n; i++) {
            int u = find(i);
            ++size[u];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (size[i] == 0)
                continue;

            int k = size[i];

            // A complete graph with k vertices has k*(k-1)/2 edges
            if (count[i] == (k * (k - 1)) / 2)
                ++ans;
        }

        return ans;
    }
};