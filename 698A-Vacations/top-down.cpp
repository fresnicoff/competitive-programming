#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

/*
prev_act=k: In the previous day.
k=0 -> Rest.
k=1 -> Gym.
k=2 -> Code.

activities[i]=k: On the i-th day of vacations.
k=0 -> Gym closed and contest is not carried out.
k=1 -> Gym closed, but contest is carried out.
k=2 -> Gym open and contest is not carried out.
k=3 -> Gym is open and contest is carried out.
*/

int solve (int day, int prev_act, int days, int activities[], int memo[][3]) {
    if (day==days) return 0;
    if (memo[day][prev_act] != -1) return memo[day][prev_act];

    int day_activities = activities[day];
    int min_rest = 1 + solve(day+1, 0, days, activities, memo);
    if (prev_act!=2) {
        if (day_activities==1 || day_activities==3) {
            min_rest = min(min_rest, solve(day+1, 2, days, activities, memo));
        }
    }
    if (prev_act!=1) {
        if (day_activities==2 || day_activities==3) {
            min_rest = min(min_rest, solve(day+1, 1, days, activities, memo));
        }
    }

    memo[day][prev_act] = min_rest;
    return min_rest;
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
    cin >> n;
    int activities[n];
    int minimum_rest[n][3];

    for (int i = 0; i < n; i++) {
        cin >> activities[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            minimum_rest[i][j] = -1;
        }
    }

    cout << solve(0, 0, n, activities, minimum_rest) << '\n';
    
    return 0;
}