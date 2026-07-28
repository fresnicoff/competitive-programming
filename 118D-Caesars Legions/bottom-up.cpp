/* Complejidad:
Espacial: O(n1*n2)
Temporal: O(n1*n2*max(min(n1, k1), min(n2, k2)))
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

const int MOD = 1e8;

/*
n1 = Total amount of footmen.
n2 = Total amount of horsemen.
k1 = Maximum amount of footmen standing successively.
k2 = Maximum amount of horsemen standing successively.
*/
int n1, n2, k1, k2;
//memo[i][j][k] = Possible ways of forming a line in which there are i footmen and j horsemen and the next troop to be put in the line is not k.
vector<vector<vector<int>>> memo; //O(n1*n2)

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    cin >> n1 >> n2 >> k1 >> k2;
    memo.resize(n1+1, vector<vector<int>>(n2+1, vector<int>(2, 0)));

    /* lastTroop=k:
    k=0 -> lastTroop = footmen.
    k=1 -> lastTroop = horsemen.
    */

    for (int i=0; i<=n1; i++) { //Footmen.
        for (int j=0; j<=n2; j++) { //Horsemen.
            for (int lastTroop=0; lastTroop<=1; lastTroop++) {
                int res = 0;
                if (i+j==0) {
                    res = 1;
                } else if (lastTroop==0) {
                    for (int k=1; k<=min(j, k2); k++) {
                        res = (res+memo[i][j-k][1]) % MOD;
                    }
                } else {
                    for (int k=1; k<=min(i, k1); k++) {
                        res = (res+memo[i-k][j][0]) % MOD;
                    }
                }
                memo[i][j][lastTroop] = res;
            }
        }
    }

    cout << (memo[n1][n2][0]+memo[n1][n2][1]) % MOD << '\n';
    
    return 0;
}