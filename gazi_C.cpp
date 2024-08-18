#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;
const int MOD = 1e9 + 7;

int R, C, K, dp[MAXN][MAXN];

int main()
{
    cin >> R >> C >> K;
    for(int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        dp[r+1][c+1] = MOD;
    }

    dp[2][2] = 1;
    for(int r = 2; r <= R+1; r++) {
        for(int c = 2; c <= C+1; c++) {
            if(dp[r][c] == MOD) continue;
            dp[r][c] += (dp[r-1][c] + dp[r][c-1]) % MOD;
        }
    }
    cout << dp[R+1][C+1];
}