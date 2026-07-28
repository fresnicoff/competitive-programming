#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
typedef long long ll;

//Devuelvo el largo de la cadena final que se deriva de n.
ll largo_descomposicion(ll n) { //O(log n).
    if (n<2) return 1;
    return 2*largo_descomposicion(n/2) + 1;
}

//Devuelvo la cantidad de 1s que hay en la cadena final que se deriva de n.
ll descomposicion(ll n) { //O(log n).
    if (n==0) return 0;
    if (n==1) return 1;
    return 2*descomposicion(n/2) + (n%2);
}

ll solve(ll n, ll l, ll r) { //O(n) -> f(n) = log(n) y divido en el peor caso en 2 subproblemas de tamaño n/2.
    //Casos Base: Si n=0 o n=1, devuelvo n. Si los punteros están cruzados, devuelvo 0 (terminé de cubrir el rango).
    if ((l>r) || (n==0)) return 0;
    if (n==1) return 1;

    //Divide: O(log n) -> Divido la longitud de la cadena final en mitades.
    ll largo = largo_descomposicion(n);
    ll medio = largo/2;

    //Conquer: 2*T(n/2) -> En el peor caso (si el rango está en las dos mitades y no abarca toda la cadena final) analizo dos subproblemas de tamaño n/2.
    //Si el rango abarca toda la cadena final, devuelvo el resultado de descomponer n (pruneo el arbol de decisión ya que hago una llamada recursiva en vez de dos).
    if (r==largo) {
        return descomposicion(n);
    }
    //Si el rango está en las dos mitades y no abarca toda la cadena final, analizo ambas y sumo el medio.
    if ((l < medio) && (medio < r)) {
        return solve(n/2, l, medio-1) + (n%2) + solve(n/2, 0, r-medio-1);
    }
    //Si el rango está solo en la mitad izquierda, analizo solo esa mitad.
    if (l < medio) {
        if (r==medio) {
            r--;
            return solve(n/2, l, r) + (n%2);
        }
        return solve(n/2, l, r);
    }
    //Si el rango está solo en la mitad derecha, analizo solo esa mitad.
    if (medio < r) {
        if (l==medio) {
            l++;
            return solve(n/2, l-medio-1, r-medio-1) + (n%2);
        }
        return solve(n/2, l-medio-1, r-medio-1);
    }
    //Si el rango no está en ninguna mitad, significa que ambos punteros apuntan al medio.
    return n%2;

    //Combine: O(1) -> Devolver los resultados y sumarlos en caso de que sea necesario.
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    ll n, l, r;
    cin >> n >> l >> r;
    cout << solve(n, l-1, r-1) << "\n"; //Indexo el rango a partir de 0.

    return 0;
}