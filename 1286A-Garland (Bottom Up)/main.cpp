/* Complejidad:
Espacial: O(n)
Temporal: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

const int inf = 1e9;

int n; //Cantidad total de números.
int amount_odd; //Cantidad de números impares diferentes que se pueden colocar en posiciones con 0.
int amount_even; //Cantidad de números pares diferentes que se pueden colocar en posiciones con 0.
//bulbs[i] = Número asignado a la posición i.
vector<int> bulbs; //O(n)
//memo[i][e][p] = Costo mínimo desde la posición i hasta n-1 habiendo usado e números pares hasta i y siendo p la paridad del último elemento.
vector<vector<vector<int>>> memo; //O(n)
//cantZeros[i] = Cantidad de ceros que hay entre bulbs[0] y bulbs[i].
vector<int> cantZeros; //O(n)

void solve() {
    memo[n%2][amount_even][0] = 0;
    memo[n%2][amount_even][1] = 0;

    for (int i=n-1; i>=0; i--) { //O(n) -> Itero del final al principio ya que f(i) depende de f(i+1).
        for (int j=0; j<=amount_even; j++) { //O(n)
            for (int lastPar=0; lastPar<=1; lastPar++) { //O(1)
                int next = (i+1)%2;
                int best = inf;

                auto updateBest = [&](int next_par, int next_e) {
                    if (next_e > amount_even) return;
                    if (memo[next][next_e][next_par] == inf) return;
                    int add = (i==0 ? 0 : (next_par != lastPar));
                    best = min(best, add+memo[next][next_e][next_par]);
                };

                if (bulbs[i]!=0) {
                    updateBest(bulbs[i]%2, j);
                } else {
                    int zeros_before = (i==0 ? 0 : cantZeros[i-1]);
                    int amount_even_left = amount_even-j;
                    int amount_odd_left = amount_odd-(zeros_before-j);
                    if (0 < amount_even_left) {
                        updateBest(0, j+1);
                    }
                    if (0 < amount_odd_left) {
                        updateBest(1, j);
                    }
                }
                memo[(i%2)][j][lastPar] = best;
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
    
    cin >> n;
    amount_even = n/2;
    amount_odd = n/2;
    if (n%2==1) amount_odd++;

    bulbs.resize(n);
    cantZeros.resize(n);
    int zeros = 0;
    for (int i=0; i<n; i++) { //O(n)
        cin >> bulbs[i];
        if (bulbs[i]!=0) {
            if ((bulbs[i]%2)==0) {
                amount_even--;
            } else {
                amount_odd--;
            }
        } else {
            zeros++;
        }
        cantZeros[i] = zeros;
    }

    memo.resize(2, vector<vector<int>>(amount_even+1, vector<int>(2, inf)));
    
    solve();

    cout << min(memo[0][0][0], memo[0][0][1]) << '\n';

    return 0;
}