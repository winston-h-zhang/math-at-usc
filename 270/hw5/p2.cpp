#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, string> step;

pair<int, vector<string>> min_distance(string x, string y, int A, int B, int c) {
    int n = x.length();
    int m = y.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<step>> prev(n + 1, vector<step>(m + 1, {{-1, -1}, "none"}));

    for (int i = 1; i <= n; ++i) {
        if (A >= c) {
            dp[i][0] = A + c * (i - 1);
            prev[i][0] = {{0, 0}, 
                "delete at " + to_string(0) + ".." + to_string(i - 1)};
        } else {
            dp[i][0] = A * i;
            prev[i][0] = {{i - 1, 0}, 
                "delete at " + to_string(i - 1)};
        }
    }
    for (int j = 1; j <= m; ++j) {
        if (A >= c) {
            dp[0][j] = A + c * (j - 1);
            prev[0][j] = {{0, 0}, 
                "insert at " + to_string(0) + ".." + to_string(j - 1)};
        } else {
            dp[0][j] = A * j;
            prev[0][j] = {{0, j - 1}, 
                "insert at " + to_string(0) + ".." + to_string(j - 1)};
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pair<int, int> min_ij = {INT_MAX, INT_MAX};
            int min_cost = INT_MAX; 
            // must be either "none", "insert", "delete", or "substitute"
            string operation = "";
            int cost = INT_MAX;
            for (int k = 1; k <= i; ++k) {
                cost = dp[i - k][j] + A + c * (k - 1);
                if (cost < min_cost) {
                    min_ij = {i - k, j};
                    min_cost = cost;
                    operation = "delete at " + 
                        to_string(i - k) + ".." + to_string(i - 1);
                }
            }
            for (int k = 1; k <= j; ++k) {
                cost = dp[i][j - k] + A + c * (k - 1);
                if (cost < min_cost) {
                    min_ij = {i, j - k};
                    min_cost = cost;
                    operation = "insert at " + 
                        to_string(j - k) + ".." + to_string(j - 1);
                }
            }
            cost = dp[i - 1][j - 1] + (B ? x[i - 1] == y[j - 1] : 0);
            if (cost < min_cost) {
                min_ij = {i - 1, j - 1};
                min_cost = cost;
                operation = "substitute " + 
                    to_string(i - 1) + " -> " + to_string(j - 1);
            }
            dp[i][j] = min_cost;
            prev[i][j] = {{min_ij.first, min_ij.second}, operation};
        }
    }

    vector<string> ans;
    int prev_x = prev[n][m].first.first;
    int prev_y = prev[n][m].first.second;
    string prev_descr = prev[n][m].second;
    // if we hit (-1, -1), then the previous iteration was
    // (0, 0) and we're done
    while (prev_x != -1 && prev_y != -1) {
        if (prev_descr != "none")
            ans.push_back(prev_descr);
        prev_descr = prev[prev_x][prev_y].second;
        int temp_x = prev_x;
        prev_x = prev[temp_x][prev_y].first.first;
        prev_y = prev[temp_x][prev_y].first.second;
    }
    reverse(ans.begin(), ans.end());
    return {dp[n][m], ans};
}

int main(int argv, char** args) {
    // cout << "min_distance(" << args[1] << ", " << args[2] << ");" << endl;
    auto ans = min_distance("kitten", "sitting", 1, 1, 0);
    cout << ans.first << endl;
    for (string s : ans.second) 
        cout << s << endl;
    return 0;
}