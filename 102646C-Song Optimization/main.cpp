/* Complejidad:
Espacial: O(n+k^2)
Temporal: O(n+k^3)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

int n;
int k;
vector<vector<int>> distances; //O(k^2).
vector<int> song; //O(n).

int main() {
    fastio;

    #ifndef ONLINE_JUDGE
        if (!freopen("input.txt", "r", stdin) || !freopen("output.txt", "w", stdout)) {
            cerr << "Create input.txt and output.txt files!\n";
            return 1;
        }
    #endif
    
    cin >> n >> k;
    if (n==1) {
        cout << 0 << '\n';
        return 0;
    }

    distances.resize(k);
    song.resize(n);
    //Initialize matrix --> O(k^2)
    for (int i=0; i<k; i++) {
        distances[i].resize(k);
        for (int j=0; j<k; j++) {
            cin >> distances[i][j];
        }
    }
    //Initialize song --> O(n)
    for (int i=0; i<n; i++) {
        cin >> song[i];
        song[i]--;
    }

    //Calculate minumim distance between nodes.
    //Floyd-Warshall: O(k^3)
    for (int x=0; x<k; x++) {
        for (int y=0; y<k; y++) {
            for (int z=0; z<k; z++) {
                distances[y][z] = min(distances[y][z], distances[y][x]+distances[x][z]);
            }
        }
    }

    //Calculate time requiered to play song without changing chords --> O(n)
    ll songTime = 0;
    for (int i=0; i<n-1; i++) {
        songTime += distances[song[i]][song[i+1]];
    }
    
    //Calculate maximum time saved for changing only the cord of song[i] to song[i+1] for all cords in the song --> O(n)
    ll maxTimeSavedChanging = distances[song[0]][song[1]];
    maxTimeSavedChanging = max(maxTimeSavedChanging, (ll)distances[song[n-2]][song[n-1]]);
    for (int i=1; i<n-1; i++) {
        ll saved = distances[song[i-1]][song[i]]+distances[song[i]][song[i+1]]-distances[song[i-1]][song[i+1]];
        maxTimeSavedChanging = max(maxTimeSavedChanging, saved);
    }
    
    cout << songTime-maxTimeSavedChanging << '\n';
    
    return 0;
}