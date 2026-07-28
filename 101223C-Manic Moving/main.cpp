/* Complejidad:
Temporal: O(m + k + n^3)
Espacial: O(k + n^2)
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
typedef long long ll;
const ll inf = 1e17;

ll solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> distances(n, vector<ll>(n, inf)); //O(n^2)
    for (int i=0; i<m; i++) { //O(m)
        ll a, b, g;
        cin >> a >> b >> g;
        a--; b--;
        distances[a][b] = min(distances[a][b], g);
        distances[b][a] = distances[a][b];
    }
    for (int i=0; i<n; i++) {
        distances[i][i] = 0; //Distance between any town to itself is 0.
    }

    //Calculate minimum distance between any two towns.
    //Floyd-Warshall: O(n^3)
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            for (int z=0; z<n; z++) {
                distances[y][z] = min(distances[y][z], distances[y][x]+distances[x][z]);
            }
        }
    }

    vector<pair<int,int>> families(k); //O(k)
    for (int i=0; i<k; i++) { //O(k)
        int s, d;
        cin >> s >> d;
        s--; d--;
        families[i] = {s, d};
    }

    //memo[i][0] stores minimum amount of gas needed to complete all tasks from i to end from having delivered family i-1 and without loading family i belongings.
    //memo[i][1] stores minimum amount of gas needed to complete all tasks from i to end from having delivered family i-1 and having loaded family i belongings.
    vector<vector<ll>> memo(k, vector<ll>(2, inf)); //O(k)
    for (int i=k-1; i>=0; i--) { //O(k)
        int tS = families[i].first;
        int tD = families[i].second;
        int tTruck;
        if (i==0) {
            tTruck = 0;
        } else {
            tTruck = families[i-1].second;
        }

        if (i==k-1) {
            memo[i][0] = distances[tTruck][tS]+distances[tS][tD]; //Load & Unload k-1.
            memo[i][1] = distances[tTruck][tD]; //Just unload k-1.
        } else {
            int tSNext = families[i+1].first;
            memo[i][0] = min(distances[tTruck][tS]+distances[tS][tD]+memo[i+1][0], //Load  & Unload i.
                            distances[tTruck][tS]+distances[tS][tSNext]+distances[tSNext][tD]+memo[i+1][1]); //Load i & Load i+1 & Unload i.
            memo[i][1] = min(distances[tTruck][tD]+memo[i+1][0], //Unload i.
                            distances[tTruck][tSNext]+distances[tSNext][tD]+memo[i+1][1]); //Load i+1 & Unload i.
        }
        if (memo[i][0] > inf) memo[i][0] = inf;
        if (memo[i][1] > inf) memo[i][1] = inf;
    }

    if (memo[0][0] == inf) {
        return -1;
    }
    return memo[0][0];
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        cout << "Case #" << i << ": " << solve() << '\n';
    }
    return 0;
}