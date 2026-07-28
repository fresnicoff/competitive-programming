/* Complejidad:
Espacial: O(n + m)
Temporal: O(n + m log n + m*α(n))
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

class DSU {
private:
    vector<int> parent; //O(n)
    vector<int> size; //O(n)

public:
    DSU(int n) { //O(n)
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }

    int find_set(int v) { //Path Compression -> O(α(n))
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) { //Union by Size -> O(α(n))
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif

    int n, m;
    vector<tuple<int, int, int>> edges; //O(m)

    cin >> n >> m;
    if (m==0) {
        cout << 0 << '\n';
        return 0;
    }
    edges.resize(m);

    for (int i=0; i<m; i++) { //O(m)
        int u,v,w;
        cin >> u >> v >> w;
        edges[i] = {w, u-1, v-1};
    }

    //Ordeno las aristas por peso de menor a mayor -> O(m log m) = O(m log n) ya que m<n^2.
    sort(edges.begin(), edges.end());
    
    //Kruskal -> O(m * α(n))
    DSU dsu(n);
    int startW=0;
    int actualW = get<0>(edges[0]);
    int changes = 0;
    for (int i=0; i<=m; i++) { //O(m)
        int w = 0;
        if (i!=m) w=get<0>(edges[i]);

        //Para cada conjunto de aristas de mismo peso.
        if ((i==m) || (actualW!=w)) {
            int posiblesAGM=0;
            int enAGM=0;

            //Identifico aquellas que pueden formar parte del AGM.
            for (int j=startW; j<i; j++) {
                auto [_, u, v] = edges[j];
                if (dsu.find_set(u)!=dsu.find_set(v)) { //O(α(n))
                    posiblesAGM++;
                }
            }

            //Utilizo la mayor cantidad posible para generar AGM.
            for (int j=startW; j<i; j++) {
                auto [_, u, v] = edges[j];
                if (dsu.find_set(u)!=dsu.find_set(v)) { //O(α(n))
                    dsu.union_sets(u, v); //O(α(n))
                    enAGM++;
                }
            }
            //Las aristas que no puedo utilizar debo aumentarlas de peso solo una vez.
            changes+=posiblesAGM-enAGM;
            startW = i;
            actualW = w;
        }
    }

    cout << changes << '\n';
    return 0;
}