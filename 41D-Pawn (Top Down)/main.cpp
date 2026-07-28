/* Complejidad:
Espacial: O(n*m*k)
Temporal: O(n*m*k)
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

typedef long long ll;

int n, m, k;
vector<vector<int>> peas; //O(n*m)
vector<vector<vector<ll>>> memo; //O(n*m*k)
//memo[i][j][k] = Mayor cantidad de peras que se pueden recolectar desde la posición (i,j) teniendo k peras (en mod k+1) antes de entrar a la celda para que al terminar el recorrido la cantidad sea 0 mod k+1.
//Nota: Está inicializado en -2 ya que -1 indica que no existe tal cantidad de peras.

ll maxPeas(int r, int c, int peasMod) {
    //Casos Base: Si me voy del terreno, solución inválida.
    if ((c<0) || (c>m-1)) return -1;

    //Memorización.
    if (memo[r][c][peasMod] != -2) return memo[r][c][peasMod];

    int collected = peas[r][c];
    int collectedMod = (peasMod+collected) % (k+1);

    //Caso Base: Si llego al final, devuelvo lo que recolecté si es una solución válida. Sino, devuelvo -1 (valor inválido del problema).
    if (r==0) {
        if (collectedMod == 0) return memo[r][c][peasMod] = collected;
        return memo[r][c][peasMod] = -1;
    }

    //Paso Recurisvo: Calculo ambas posibilidades y devuelvo la mejor.
    ll res = max(maxPeas(r-1, c-1, collectedMod),  maxPeas(r-1, c+1, collectedMod));
    if (res!=-1) res += collected;
    return memo[r][c][peasMod] = res;
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    cin >> n >> m >> k;
    peas.resize(n, vector<int>(m));
    memo.resize(n, vector<vector<ll>>(m, vector<ll>(k+1, -2)));

    for (int i=0; i<n; i++) {
        string line;
        cin >> line;
        for (int j=0; j<m; j++) {
            peas[i][j] = line[j] - '0';
        }
    }

    //Itero por todas las posibles celdas por las que puedo empezar y devuelvo el mejor resultado.
    ll res = -1;
    int column = -1;
    for (int i=0; i<m; i++) {
        ll ans = maxPeas(n-1, i, 0);
        if (ans > res) {
            res = ans;
            column = i;
        }
    }

    cout << res << '\n';

    if (res==-1) return 0;
    cout << column+1 << '\n';

    //Reconstruyo camino.
    string bestPath;
    int pos = column;
    int actualMod = 0;
    for (int i=n-1; i>0; i--) {
        int newMod = (actualMod+peas[i][pos]) % (k+1);
        if ((pos!=0) && (memo[i][pos][actualMod]-peas[i][pos] == memo[i-1][pos-1][newMod])) {
            bestPath+='L';
            pos--;
        } else {
            bestPath+='R';
            pos++;
        }
        actualMod = newMod;
    }
    cout << bestPath << '\n';

    return 0;
}