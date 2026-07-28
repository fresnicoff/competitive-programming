/* Complejidad:
Espacial: O(n*k + m)
Temporal: O(n*k + m * log m * log k)
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
typedef long long ll;
const ll inf = 1e18;

int n, m;
vector<vector<pair<int,int>>> portals; //O(n+m)
vector<vector<int>> arrivals; //O(n*k)
vector<ll> distances; //O(n)

ll timeToArrive(int v, ll time) { //O(kv) en el peor caso (generalmente O(log kv)).
    auto it = lower_bound(arrivals[v].begin(), arrivals[v].end(), time); //O(log kv)
    while (it != arrivals[v].end() && *it==time) { //O(kv)
        ++it;
        time++;
    }
    return time;
}

void dijkstra(int v) { //O(m * log m * log k)
    priority_queue<pair<ll, int>> q; //O(m)
    q.push({0,v});
    while (!q.empty()) { //O(m)
        auto [time, u] = q.top();
        q.pop(); //O(log m)
        if (distances[u] != inf) continue;
        time*=-1;
        distances[u] = time;
        if (u==n-1) return;
        ll departureTime = timeToArrive(u, time); //O(log ku)
        for (int i=0; i<(int)portals[u].size(); i++) { //O(m) en total.
            auto [destiny, transferTime] = portals[u][i];
            if (distances[destiny] == inf) {
                q.push({-(departureTime+transferTime), destiny}); //O(log m)
            }
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
    
    cin >> n >> m;
    portals.resize(n);
    arrivals.resize(n);
    distances.resize(n, inf);
    for (int i=0; i<m; i++) { //O(m)
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        portals[a].push_back({b,c});
        portals[b].push_back({a,c});
    }
    for (int i=0; i<n; i++) { //O(n*k)
        int k;
        cin >> k;
        while (k--) {
            int t;
            cin >> t;
            arrivals[i].push_back(t);
        }
    }
    
    dijkstra(0);
    if (distances[n-1] == inf) {
        cout << -1 << '\n';
    } else {
        cout << distances[n-1] << '\n';
    }
    return 0;
}