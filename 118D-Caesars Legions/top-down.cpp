#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

/* last_troop=k:
k=0 -> last_troop = footmen.
k=1 -> last_troop = horsemen.
*/

const int MOD = 1e8;
int k1, k2;

int solve(int f_left, int h_left, bool last_troop, int amount_last_troop, vector<vector<vector<vector<int>>>>& memo) {
    if (f_left < 0 || h_left < 0) return 0;
    if (!last_troop && k1 < amount_last_troop) return 0;
    if (last_troop && k2 < amount_last_troop) return 0;
    if (f_left==0 && h_left==0) return 1;

    if (memo[f_left][h_left][last_troop][amount_last_troop] != -1) return memo[f_left][h_left][last_troop][amount_last_troop];

    if (!last_troop) {
        memo[f_left][h_left][last_troop][amount_last_troop] = (solve(f_left-1, h_left, last_troop, amount_last_troop+1, memo) + solve(f_left, h_left-1, !last_troop, 1, memo)) % MOD;
    } else {
        memo[f_left][h_left][last_troop][amount_last_troop] = (solve(f_left, h_left-1, last_troop, amount_last_troop+1, memo) + solve(f_left-1, h_left, !last_troop, 1, memo)) % MOD;
    }
    return memo[f_left][h_left][last_troop][amount_last_troop];
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif

    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;

    vector<vector<vector<vector<int>>>> memo(
        n1+1, vector<vector<vector<int>>>(
            n2+1, vector<vector<int>>(
                2, vector<int>(max(k1, k2)+1, -1)
            )
        )
    );

    cout << solve(n1, n2, 0, 0, memo) << '\n';
    
    return 0;
}