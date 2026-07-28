/* Complejidad:
Temporal: O(n).
Espacial: O(n) pero con mejores constantes que solución Top-Down -> memo es O(1).
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

typedef long long ll;
const ll inf = 1e18;

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif

    int n;
    cin >> n;
    vector<int> energy(n); //Complejidad Espacial O(n).
    vector<string> words(n); //Complejidad Espacial O(n).
    vector<vector<ll>> memo(2, vector<ll>(2, inf)); //Complejidad Espacial O(1).
    //Inicializo todos los valores en inf (valor inválido del problema).
    //memo[i][0]=f(i,false) devuelve el minimo gasto de energia para que las palabras de entre i a n-1 estén en orden alfabetico si i no está invertida.
    //memo[i][1]=f(i,true) devuelve el minimo gasto de energia para que las palabras de entre i a n-1 estén en orden alfabetico si i está invertida.

    for (int i=0; i<n; i++) {
        cin >> energy[i];
    }
    for (int i=0; i<n; i++) {
        cin >> words[i];
    }

    //Casos Base: Si estoy en la última palabra, como no hay una siguiente con la que comparar, el minimo gasto de energia para ordenar las palabras de adelante es 0 (si no invierto la última palabra) o el gasto de invertirla (si la invierto).
    memo[(n-1)%2][0] = 0;
    memo[(n-1)%2][1] = energy[n-1];
    
    //Como f(i) está definido a partir de f(i+1), itero de la anteúltima palabra a la primera.
    for (int i=n-2; i>=0; i--) { //O(n)
        string actual = words[i];
        string actual_r = actual;
        reverse(actual_r.begin(), actual_r.end());
        string next = words[i+1];
        string next_r = next;
        reverse(next_r.begin(), next_r.end());

        int i_actual = i%2; //Índice de f(i).
        int i_next = (i+1)%2; //Índice de f(i+1).

        //Como el índice actual tiene guardados los valores de f(i+2), los reestablezco al valor inválido del problema.
        memo[i_actual][0] = inf;
        memo[i_actual][1] = inf;

        //Casos en los que no invierto la palabra i: Defininen f(i,false)=memo[i][0].
        if (actual <= next) {
            memo[i_actual][0] = min(memo[i_actual][0], memo[i_next][0]);
        }
        if (actual <= next_r) {
            memo[i_actual][0] = min(memo[i_actual][0], memo[i_next][1]);
        }

        //Casos en los que invierto la palabra i: Defininen f(i,true)=memo[i][1].
        if (actual_r <= next) {
            memo[i_actual][1] = min(memo[i_actual][1], memo[i_next][0]);
        }
        if (actual_r <= next_r) {
            memo[i_actual][1] = min(memo[i_actual][1], memo[i_next][1]);
        }
        //Agrego el gasto de invertir la palabra i si es una posibilidad válida.
        if (memo[i_actual][1]!=inf) memo[i_actual][1]+=energy[i];
    }

    //Llamada que Resuelve el Problema.
    ll answer = min(memo[0][0], memo[0][1]);

    if (answer==inf) {
        cout << "-1" << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}