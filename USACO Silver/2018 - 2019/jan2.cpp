#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("perimeter.in", "r", stdin), freopen("perimeter.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int n;
char c[1005][1005];
bool vis[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

pii floodfill(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {return mp(0, 0);}
    vis[x][y] = true;
    if (c[x][y] == '.') {return mp(0, 0);}
    int area = 1, perim = 0;
    FOR(i, 0, 4) {
        if (x+dx[i] < 0 || x+dx[i] >= n || y+dy[i] < 0 || y+dy[i] >= n) {perim++; continue;}
        if (c[x+dx[i]][y+dy[i]] == '.') {perim++;}   
    }
    FOR(i, 0, 4) {
        if (!vis[x+dx[i]][y+dy[i]]) {
            pii result = floodfill(x+dx[i], y+dy[i]);
            area += result.fi; 
            perim += result.se;
        }
    }
    return mp(area, perim);
}

int main() {
    fastio;
    fileio;
    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> c[i][j];
            vis[i][j] = false;
        }
    }
    int bestArea = 0, bestPerim = 0;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            pii result;
            if (!vis[i][j] && c[i][j] == '#') {result = floodfill(i, j);}
            if ((result.fi == bestArea && result.se < bestPerim) || (result.fi > bestArea)) {
                bestArea = result.fi;
                bestPerim = result.se;
            }
        }
    }
    cout << bestArea << " " << bestPerim << "\n";
    return 0;
}
 