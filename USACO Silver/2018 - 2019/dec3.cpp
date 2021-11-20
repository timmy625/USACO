//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("mooyomooyo.in", "r", stdin), freopen("mooyomooyo.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int n, k;
bool vis[105][12];
int grid[105][12];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int currSize;
vector<pii> cells;
vector<pii> blank;
void ff(int a, int b) {
    vis[a][b] = true;
    currSize++;
    cells.pb({a, b});
    FOR(i, 0, 4) {
        int nextA = a + dx[i];
        int nextB = b + dy[i];
        if (nextA < 0 || nextA >= n || nextB < 0 || nextB >= 10 || vis[nextA][nextB] || (grid[a][b] != grid[nextA][nextB])) {continue;}
        ff(nextA, nextB);
    }
    return;
}
bool checkComps() {
    bool ok = false;
    FOR(i, 0, n) {FOR(j, 0, 10) {vis[i][j] = false;}}
    FOR(i, 0, n) {
        FOR(j, 0, 10) {
            if (!vis[i][j] && grid[i][j]) {
                currSize = 0;
                cells = blank;
                ff(i, j);
                if(currSize >= k) {
                    ok = true;
                    for (pii p : cells) {grid[p.fi][p.se] = 0;}
                }
            }
        }
    }
    return ok;
}
void gravity() {
    FOR(i, 0, 10) {
        int zeros = 0;
        for (int j = n-1; j >= 0; j--) {
            if (grid[j][i] == 0 && zeros >= 0) {zeros++; continue;}
            grid[j+zeros][i] = grid[j][i];
        }
        FOR(j, 0, zeros) {grid[j][i] = 0;}
    }
}
int main() {
    fileio;
    fastio;
    cin >> n >> k;
    FOR(i, 0, n) {
        string s;
        cin >> s;
        FOR(j, 0, 10) {
            grid[i][j] = s[j] - '0';
        }
    }
    while (checkComps()) {
        gravity();
    } 
    FOR(i, 0, n) {
        FOR(j, 0, 10) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}
