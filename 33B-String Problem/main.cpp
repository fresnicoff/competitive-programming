/* Complejidad:
Temporal: O(s + letters^3)
Espacial: O(s)
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
const int inf = 1e9;
const int letters = 26;

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    string a,b; //O(s)
    vector<vector<int>> distances(letters, vector<int>(letters, inf)); //O(letters^2)
    cin >> a >> b;

    int s = (int) a.size();
    if (s != (int) b.size()) {
        cout << -1 << '\n';
        return 0;
    }

    int n;
    cin >> n;
    while (n--) {
        char x, y;
        int cost;
        cin >> x >> y >> cost;
        distances[x-'a'][y-'a'] = min(distances[x-'a'][y-'a'], cost);
    }
    for (int i=0; i<letters; i++) {
        distances[i][i]= 0;
    }

    //Calculate minimum cost of changing letters between all of them.
    //Floyd-Warshall: O(letters^3)
    for (int k=0; k<letters; k++) {
        for (int i=0; i<letters; i++) {
            for (int j=0; j<letters; j++) {
                distances[i][j] = min(distances[i][j], distances[i][k]+distances[k][j]);
            }
        }
    }

    //Calculate minimum cost so that a and b are equal.
    int cost = 0;
    string word;
    for (int i=0; i<s; i++) { //Iterate through every letter in a and b --> O(s)
        //Iterate through every possible letter in the alphabeth and mantain letter that minimizes the cost of changing a[i] and b[i] to that letter.
        char actualLetter;
        int actualLetterCost = inf;
        for (int j=0; j<letters; j++) { //O(letters)
            int distance = distances[a[i]-'a'][j] + distances[b[i]-'a'][j];
            if (actualLetterCost > distance) {
                actualLetterCost = distance;
                actualLetter = (char) j+'a';
            }
        }
        //If there is no way of making these letters equal, it is impossible to make a and b equal.
        if (actualLetterCost==inf) {
            cout << -1 << '\n';
            return 0;
        }
        cost += actualLetterCost;
        word += actualLetter;
    }
    cout << cost << '\n';
    cout << word << '\n';
    return 0;
}