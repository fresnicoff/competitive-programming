/* Complejidad:
Temporal: O(k^2*n^2).
Espacial: O(k*n^2).
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

int n, k;
vector<int> happiness; //Complejidad Espacial O(k).

//amountCard[i] = Cantidad de cartas con valor i.
map<int, int> amountCard; //Complejidad Espacial O(n*k) -> Todas cartas diferentes.

//amountFavouriteCard[i] = Cantidad de personas con i como su carta favorita.
map<int, int> amountFavouriteCard; //Complejidad Espacial O(n*k) -> Todas cartas diferentes.

//memo[i][j] = Máxima felicidad de dar i cartas a j personas.
//Importante: Siempre i <= amountCard[v] y j <= amountFavouriteCard[v] para todo valor de carta v.
//Siempre se guarda en el peor caso la máxima felicidad de dar todas las cartas de valor v a todas las personas que tienen a v como su carta favorita.
vector<vector<int>> memo; //Complejidad Espacial O(k*n^2).

int solve(int amount, int persons) { //O(n*k) en el peor caso.
    //Casos Base: Devuelvo el valor neutro del problema (happiness[0]).
    if (amount==0) return 0;
    if (persons==0) return 0;

    //Memorización.
    if (memo[amount][persons]!=-1) return memo[amount][persons];

    //Itero por todas las posibles cantidades de cartas favoritas que le puedo dar a la persona "persons" (a lo sumo k).
    //La respuesta es la máxima felicidad obtenida de entre todos los casos de darle a persons-1 la cantidad de cartas favoritas que quedan + beneficio obtenido por dar las cartas favoritas a la persona "persons".
    int res = 0;
    for (int j=0; j<=min(k, amount); j++) {
        res = max(res, happiness[j]+solve(amount-j, persons-1));
    }

    //Memorización.
    return memo[amount][persons] = res;
}

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    cin >> n >> k;
    happiness.resize(k+1);

    int maxCard = 0;
    int maxPerson = 0;
    for (int i=0; i<n*k; i++) {
        int card;
        cin >> card;
        amountCard[card]++;
        maxCard = max(maxCard, amountCard[card]);
    }
    for (int i=0; i<n; i++) {
        int favouriteCard;
        cin >> favouriteCard;
        amountFavouriteCard[favouriteCard]++;
        maxPerson = max(maxPerson, amountFavouriteCard[favouriteCard]);
    }
    //Nota: El tamaño de memo es la mayor cantidad de cartas iguales * la mayor cantidad de personas con la misma carta favorita.
    //memo es inicializado con -1 (valor inválido del problema).
    memo.resize(maxCard+1, vector<int>(maxPerson+1, -1));

    happiness[0] = 0;
    for (int i=1; i<k+1; i++) {
        cin >> happiness[i];
    }

    int maxHappiness = 0;
    //Itero sobre todos los valores distintos de cartas.
    //Calculo la máxima felicidad obtenida por dar todas las cartas de ese valor a todas las personas que tienen esa carta como favorita.
    //Importante: El resultado de solve es independiente del valor de la carta (solo importa la cantidad de cartas con el valor y la cantidad de personas que tienen esa carta como favorita).
    for (auto &p : amountCard) { //O(n*k)
        int value = p.first;
        maxHappiness+=solve(amountCard[value], amountFavouriteCard[value]); //O(n*k).
    }
    cout << maxHappiness << '\n';
    
    return 0;
}