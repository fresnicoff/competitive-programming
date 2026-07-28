/* Complejidad:
Temporal: O(n^2) * O(n) = O(n^3).
Espacial: O(n^2).
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

const int inf = 1e9;

string s;
vector<vector<int>> memo; //Compleiidad Espacial O(n^2).
//memo[i][j] = f(i,j) = Menor cantidad de operaciones necesarias para eliminar al substring de s que se encuentra entre las posiciones i a j.

int solve(int begin, int end) { //O(n)
    //Casos Base: Si los indices están invertidos, el substring es vacio. Si son el mismo elemento, lo elimino.
    if (begin>end) return 0;
    if (begin==end) return 1;

    //Memorización.
    if (memo[begin][end] != inf) return memo[begin][end];

    //Paso Recursivo: La respuesta es el mínimo de todos los posibles casos.
    //Si no hay elementos iguales a begin entre begin y end, elimino begin y calculo f(begin+1, end).
    int res = 1+solve(begin+1, end);
    //Itero por todos los elementos de entre begin y end. Si alguno es igual a begin, calculo cuanto cuesta eliminar lo de adentro + eliminar lo que falta.
    for (int i=begin+1; i<=end; i++) {
        if (s[begin]==s[i]) {
            res = min(res, solve(begin+1, i-1) + solve(i, end));
        }
    }
    return memo[begin][end] = res;
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    int n;
    string temp;
    cin >> n >> temp;

    //Comprimo string original para que no me queden letras iguales juntas (resultado es el mismo que si hay letras iguales juntas).
    s=temp[0];
    for (int i=1; i<n; i++) {
        if (temp[i-1]!=temp[i]) s+=temp[i];
    }
    n = (int) s.size();
    memo.resize(n, vector<int>(n,inf));

    //Llamada que Resuelve el Problema.
    cout << solve(0, n-1) << '\n';
    
    return 0;
}