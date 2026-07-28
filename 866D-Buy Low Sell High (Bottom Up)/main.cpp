/* PROBLEMA NO SE RESUELVE CON DP!
Complejidad:
Espacial: O(n)
Temporal: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

typedef long long ll;
const ll inf = 1e18;

int n, m; //m = Cantidad máxima de asteroides que podemos tener en cualquier momento (acotada por n/2 ya que solución óptima finaliza con 0 asteroides).
//prices[i] = Precio del asteroide en el día i.
vector<int> prices; //O(n)
//memo[i][j] = Máximo beneficio que podemos obtener teniendo j cantidad de asteroides al finalizar el día i+1.
vector<vector<ll>> memo; //O(n)

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    cin >> n;
    m = n/2; m++;
    prices.resize(n);
    for (int i=0; i<n; i++) {
        cin >> prices[i];
    }

    memo.resize(2, vector<ll>(m, -inf));
    memo[0][0] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<m; j++) {
            int prev = (i-1)%2;
            ll res = memo[prev][j]; //No hacer nada.
            if ((j!=0)&&(memo[prev][j-1] != -inf)) {
                res = max(res, memo[prev][j-1]-prices[i-1]); //Comprar asteroide.
            }
            if ((j!=m-1)&&(memo[prev][j+1] != inf)) {
                res = max(res, memo[prev][j+1]+prices[i-1]); //Vender asteroide.
            }
            memo[(i%2)][j] = res;
        }
    }

    cout << memo[(n%2)][0] << '\n';
    
    return 0;
}