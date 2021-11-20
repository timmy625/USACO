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
#define fileio freopen("gates.in", "r", stdin), freopen("gates.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int n;
struct point {
    bool vis = false, u = false, r = false;
};
point points[2005][2005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void ff(int a, int b) {
    points[a][b].vis = true;
    FOR(i, 0, 4) {
        int newA = a + dx[i]; 
        int newB = b + dy[i];
        if (newA < 0 || newA >= 2*n + 5 || newB < 0 || newB >= 2*n + 5 || points[newA][newB].vis) {continue;}
        if (i == 0 && points[a][b].u) {continue;}
        else if (i == 1 && points[newA][newB].r) {continue;}
        else if (i == 2 && points[newA][newB].u) {continue;}
        else if (i == 3 && points[a][b].r) {continue;}
        ff(newA, newB);
    }
    return;
}
int main() {
    fastio;
    fileio;
    string s;
    cin >> n >> s;
    pii curr = {n+2, n+2};
    FOR(i, 0, n) {
        if (s[i] == 'N') {
            points[curr.fi][curr.se].u = true;
            curr.se++;
        } else if (s[i] == 'S') {
            curr.se--;
            points[curr.fi][curr.se].u = true;
        } else if (s[i] == 'E') {
            points[curr.fi][curr.se].r = true;
            curr.fi++;
        } else if (s[i] == 'W') {
            curr.fi--;
            points[curr.fi][curr.se].r = true;
        }
    }
   
    int ans = 0;
    for (int i = 0; i < 2*n + 5; i++) {
        for (int j = 0; j < 2*n + 5; j++) {
            if (!points[i][j].vis) {ff(i, j); ans++;}
        }
    }
    cout << --ans << "\n";
    return 0;
}
