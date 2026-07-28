/* Complejidad:
Temporal: O(n)
Espacial: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

typedef long long ll;
const ll inf = 1e18;

int n;
vector<int> energy; //Complejidad Espacial O(n).
vector<string> words; //Complejidad Espacial O(n).
vector<vector<ll>> memo; //Complejidad Espacial O(n).
//memo[i][0]=f(i,false) devuelve el minimo gasto de energia para que las palabras de entre i a n-1 estén en orden alfabetico si i-1 no está invertida.
//memo[i][1]=f(i,true) devuelve el minimo gasto de energia para que las palabras de entre i a n-1 estén en orden alfabetico si i-1 está invertida.

ll solve(int k, bool lastWordInverted) {
    //Caso Base: Si k=n, no hay más palabras que ordenar, por lo que el gasto de energía es 0 (neutro del problema).
    if (k==n) return 0;

    //Superposición de Estados: Si ya fue calculada esta llamada recursiva, devuelvo el valor almacenado en la estructura de memorización.
    if (memo[k][lastWordInverted] != -1) return memo[k][lastWordInverted];

    //Paso Recursivo.
    string actual = words[k];
    string actual_reversed = words[k];
    reverse(actual_reversed.begin(), actual_reversed.end());
    string lastWord = words[k-1];
    if (lastWordInverted) reverse(lastWord.begin(), lastWord.end());

    if (lastWord > actual) {
        if (lastWord > actual_reversed) {
            memo[k][lastWordInverted] = inf;
        }
        else {
            memo[k][lastWordInverted] = solve(k+1, true);
            if (memo[k][lastWordInverted]!=inf) memo[k][lastWordInverted]+=energy[k]; //No sumo si emo[k][lastWordInverted]==inf para evitar overflow.
        }
    } else {
        ll min_energy = solve(k+1, false);
        if (lastWord > actual_reversed) {
            memo[k][lastWordInverted] = min_energy;
        } else {
            ll min_energy_reversed = solve(k+1, true);
            if (min_energy_reversed!=inf) min_energy_reversed+=energy[k];
            memo[k][lastWordInverted] = min(min_energy, min_energy_reversed);
        }
    }
    return memo[k][lastWordInverted];
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
    energy.resize(n);
    words.resize(n);
    memo.assign(n, vector<ll>(2, -1));
    for (int i=0; i<n; i++) {
        cin >> energy[i];
    }
    for (int i=0; i<n; i++) {
        cin >> words[i];
    }
    
    //Llamado que Resuelve el Problema: Como f(i,lastWordInverted) toma la palabra anterior a i, la llamada es el mínimo de f(1,true) y f(1,false).
    ll answer = min(energy[0]+solve(1, true), solve(1, false));
    if (answer==inf) {
        cout << "-1" << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}