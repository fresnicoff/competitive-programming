#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

int n;
int max_time = -1;

tuple<int, vector<int>> solve(int element, int time, const vector<tuple<int, int, int, int>> &data, vector<vector<tuple<int, vector<int>>>> &memo) {
    if (element==n) return make_tuple(0, vector<int>{});

    if (get<0>(memo[element][time]) != -1) return memo[element][time];

    auto [time_to_burn, time_to_save, value, i] = data[element];

    memo[element][time] = solve(element+1, time, data, memo);
    if (time+time_to_save < time_to_burn) {
        auto solution_with_element = solve(element+1, time+time_to_save, data, memo);
        get<0>(solution_with_element) += value;
        get<1>(solution_with_element).push_back(i);
        if (get<0>(solution_with_element) > get<0>(memo[element][time])) {
            memo[element][time] = solution_with_element;
        }
    }
    return memo[element][time];
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
    vector<tuple<int, int, int, int>> data(n);

    for (int i=0; i < n; i++) {
        int time_to_save, time_to_burn, value;
        cin >> time_to_save >> time_to_burn >> value;
        data[i] = make_tuple(time_to_burn, time_to_save, value, i);
        max_time = max(max_time, time_to_burn);
    }
    sort(data.begin(), data.end());

    vector<vector<tuple<int,vector<int>>>> memo(
        n, vector<tuple<int,vector<int>>>(
            max_time, tuple<int,vector<int>>(make_tuple(-1, vector<int>{}))
        )
    );
    
    tuple<int, vector<int>> answer = solve(0, 0, data, memo);
    int amount_items = static_cast<int>(get<1>(answer).size());
    cout << get<0>(answer) << '\n';
    cout << amount_items << '\n';
    for (int i=amount_items-1; i >= 0; i--) {
        cout << get<1>(answer)[i]+1 << ' ';
    }

    return 0;
}