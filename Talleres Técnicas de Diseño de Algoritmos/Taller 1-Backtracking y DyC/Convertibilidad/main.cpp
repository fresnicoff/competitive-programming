#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

list<bool> solution; //Cadena en donde 0 representa 2*x y 1 representa 10*x+1.

bool solve(int x, int y) {
    if (x==y) return true;
    //Como la menor forma de aumentar x es multiplicándolo por 2, si este resultado es mayor a y este nunca se podrá alcanzar.
    if (2*x > y) return false;
    //Si el último dígito de y es 3, 5, 7 o 9, no se puede llegar a y multiplicando por 2 ni agregando un 1 al final.
    if (((y%10)%2 == 1) && (y%10 != 1)) return false;

    //Si el último dígito de y es un 1, y solo puede alcanzarse haciendo 10*k+1, por lo que y=k.
    if (y%10 == 1) {
        solution.push_front(1);
        return  solve(x, y/10);
    }
    //Sino pasa nada de esto, y es múltiplo de 2, por lo que lo divido.
    solution.push_front(0);
    return solve(x, y/2);
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    int x, y;
    cin >> x >> y;

    if (solve(x,y)) {
        cout << "YES" << "\n";
        cout << solution.size()+1 << "\n";
        cout << x << " ";
        for (auto it = solution.begin(); it != solution.end(); it++) {
            if (*it) {
                x = 10*x+1;
            } else {
                x = 2*x;
            }
            cout << x << " ";
        }
    } else {
        cout << "NO" << "\n";
    }
    
    return 0;
}