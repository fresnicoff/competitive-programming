/* Complejidad:
Temporal: O(m log m)
Espacial: O(m)
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
const int inf = 1e9;

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    int n, m;
    cin >> n >> m;
    if (m<=n) {
        cout << n-m << '\n';
        return 0;
    }

    vector<int> distances(2*m, inf); //O(m)
    distances[n] = 0;
    queue<int> q; //O(m)
    q.push(n);
    while (!q.empty()) { //O(m)
        int actual = q.front();
        q.pop(); //O(log m)
        if ((actual<m) && (distances[2*actual] > distances[actual]+1)) {
            distances[2*actual] = distances[actual]+1;
            if (2*actual == m) {
                cout << distances[2*actual] << '\n';
                return 0;
            }
            q.push(2*actual); //O(log m)
        }
        if ((0<actual) && (distances[actual-1] > distances[actual]+1)) {
            distances[actual-1] = distances[actual]+1;
            if (actual-1 == m) {
                cout << distances[actual-1] << '\n';
                return 0;
            }
            q.push(actual-1); //O(log m)
        }
    }
    return 0;
}