#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int knapsack(int w[], int v[], int n, int W)
{
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n = 4, W = 7;
    int w[] = {1, 3, 4, 5};
    int v[] = {1, 4, 5, 7};
    int maxVal = knapsack(w, v, n, W);
    cout << "Maximum value: " << maxVal << endl;
    return 0;
}
