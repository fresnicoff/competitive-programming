#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

string s; //String de entrada.
int n; //Longitud de s.

int solve(int izq, int der, char k) { //O(n) -> 2 subproblemas de tamaño n/2 con costo de combinación O(1).
    //k es el caracter para el cual el substring evaluado debe ser k-lindo.

    //Caso Base: Si evaluo un solo caracter, si coindice con k entonces no debo modificarlo. Sino debo realizar una modificación (cambiarlo por k).
    if (izq==der) return s[izq]!=k;

    //Divide: Divido el string en dos mitades iguales (siempre n=2^k).
    int medio = (izq+der)/2;
    
    //Conquer: Calculo la cantidad de cambios de caracteres que debería realizar a cada mitad para que el string sea k-lindo.
    //Nota: Debo evaluar dos casos de tamaño n/2.
        //1) Que la primera mitad tenga todos los caracteres iguales a k y la segunda sea k+1-linda.
    int cambios_izq_k_linda = 0;
    for (int i = izq; i <= medio; i++) {
        if (s[i] != k) cambios_izq_k_linda++;
    }
    int cambios_der_k1_linda = solve(medio+1, der, k+1);
        //2) Que la primera mitad sea k+1-linda y que la segunda tenga todos los caracteres iguales a k.
    int cambios_izq_k1_linda = solve(izq, medio, k+1);
    int cambios_der_k_linda = 0;
    for (int i = medio+1; i <= der; i++) {
        if (s[i] != k) cambios_der_k_linda++;
    }

    //Combine: La cantidad mínima de cambios es igual a la cantidad mínima de cambios del caso con menos cambios en ambas mitades.
    return min(cambios_izq_k_linda+cambios_der_k1_linda, cambios_izq_k1_linda+cambios_der_k_linda);
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        cout << solve(0, n-1, 'a') << "\n";
    }

    return 0;
}