#include <bits/stdc++.h>
using namespace std;

vector<int> chutes_and_ladders(vector<int> board) {
    int n = board.size();
    vector<int> ans;
    vector<pair<int, int>> prev(n+1, {-1, 0});
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    // dp[i] represents the minimum number of rolls to get to i without dying
    for (int i = 0; i < n; ++i) {
        for (int r = 1; r <= 6; ++r) {
            if (i + r <= n) { // careful, don't roll out of bounds
                if (board[i + r] == 0 && dp[i] + 1 < dp[i + r]) { // update if non-special
                    dp[i + r] = dp[i] + 1;
                    prev[i + r] = {i, r};
                } else if (board[i + r] > 0 && dp[i] + 1 < dp[board[i]]) { // update if ladder
                    dp[board[i]] = dp[i] + 1;
                    prev[board[i]] = {i, r};
                }
            }
        }
    }
    // rebuild rolls
    int prev_ = prev[n].first;
    int roll = prev[n].second;
    while (prev_ != -1) { // while a previous step exists
        ans.push_back(roll);
        if (prev_ == 0) // if prev_ is 0 we're done, just return 
            return ans;
        roll = prev[prev_].second;
        prev_ = prev[prev_].first;
    }
    // if there is no previous step, then we return failure
    return vector<int>();
}