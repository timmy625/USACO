#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(long long i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("moocast.in", "r", stdin), freopen("moocast.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

struct cow {int x, y, p;};
vi adj[205];
bool visited[205];

int dfs(int u, int total) {
    visited[u] = true;
    total++;
    for (int v : adj[u]) {
        if (!visited[v]) {total = max(total, dfs(v, total));}
    }
    return total;
}

int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    cow cows[n];
    FOR(i, 0, n) {
        cin >> cows[i].x >> cows[i].y >> cows[i].p;
    }
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (i == j) {continue;}
            int distX = abs(cows[i].x - cows[j].x) * abs(cows[i].x - cows[j].x);
            int distY = abs(cows[i].y - cows[j].y) * abs(cows[i].y - cows[j].y);
            int power = cows[i].p * cows[i].p;
            if (distX + distY < power) {
                adj[i].pb(j);
            }
        }
    }
    int best = 0;
    FOR(i, 0, n) {
        FOR(j, 0, n) {visited[j] = false;}
        best = max(best, dfs(i, 0));
    }
    cout << best << "\n";
    return 0;
}
