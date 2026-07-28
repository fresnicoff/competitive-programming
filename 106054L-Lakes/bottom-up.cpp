/* Complejidad:
Espacial: O(n)
Temporal: O(n^(3/2))
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

typedef long long ll;
const ll inf = 1e18;

//n = Amount of cells.
//g = Benefit of placing a boat.
//b = Maximum amount of boats that can be placed in n cells.
int n, g, b;
//costs[i] = Cost of excavating the cell i.
vector<int> costs; //O(n)
//added_costs[i] = Cost of excavating all the cells between 0 and i-1.
vector<ll> added_costs; //O(n)
//memo[i][j] = Maximum possible benefit of placing in the first j cells all/some/none of the boats of lengths 1 to i.
vector<vector<ll>> memo; //O(n)

void solve() {
    //Base Cases: If I consider 0 cells or 0 boats, maximum benefit is 0.
    for (int i=0; i<=n; i++) { //O(n)
        memo[0][i] = 0;
    }
    memo[1][0] = 0;

    for (int i=1; i<=b; i++) { //O(n^(1/2))
        for (int j=1; j<=n; j++) { //O(n)
            int actual = i%2;
            int prev = (i-1)%2;
            ll res = max(memo[actual][j-1], memo[prev][j]); //Do not place a boat on the cell j or do not consider placing the boat of length i.
            if ((j-i>=0)&&(memo[prev][j-i] != -inf)) {
                res = max(res, memo[prev][j-i]+g-(added_costs[j]-added_costs[j-i])); //Place the i boat on cells j-i+1 to j.
            }
            memo[actual][j] = res;
        }
    }
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    cin >> n >> g;
    costs.resize(n);
    added_costs.resize(n+1);
    added_costs[0] = 0;
    for (int i=0; i<n; i++) {
        cin >> costs[i];
        added_costs[i+1] = added_costs[i]+costs[i];
    }
    
    b = (int) floor((sqrt(1 + 8.0*n)-1)/2);
    memo.resize(2, vector<ll>(n+1, -inf));
    solve();

    cout << memo[(b%2)][n] << '\n';

    return 0;
}