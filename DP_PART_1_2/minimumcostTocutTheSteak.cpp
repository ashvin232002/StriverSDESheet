#include <bits/stdc++.h>
using namespace std;

// RECURSION
class Solution
{
public:
    int recursion(vector<int> &cuts, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int index = i; index <= j; index++)
        {
            int curr = cuts[j + 1] - cuts[i - 1] + recursion(cuts, i, index - 1) + recursion(cuts, index + 1, j);
            ans = min(ans, curr);
        }
        return ans;
    }
    int minCost(int n, vector<int> &cuts)
    {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return recursion(cuts, 1, cuts.size() - 2);
    }
};

// MEMOIZATION
class Solution
{
public:
    long long dp[105][105];
    long long recursion(vector<int> &cuts, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        long long ans = INT_MAX;
        for (int index = i; index <= j; index++)
        {
            long long curr = cuts[j + 1] - cuts[i - 1] + recursion(cuts, i, index - 1) + recursion(cuts, index + 1, j);
            ans = min(ans, curr);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int> &cuts)
    {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        for (int i = 0; i < 105; i++)
        {
            for (int j = 0; j < 105; j++)
            {
                dp[i][j] = -1;
            }
        }
        return recursion(cuts, 1, cuts.size() - 2);
    }
};

class Solution
{
public:
    int cost(int n, int c, vector<int> &cuts)
    {

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--)
        {
            for (int j = 1; j <= c; j++)
            {

                if (i > j)
                    continue;

                int mini = INT_MAX;

                for (int ind = i; ind <= j; ind++)
                {

                    int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                    mini = min(mini, ans);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }

    int minCost(int n, vector<int> &cuts)
    {

        return cost(n, cuts.size(), cuts);
    }
};