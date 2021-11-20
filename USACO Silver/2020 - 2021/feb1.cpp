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
#define fileio freopen("template.in", "r", stdin), freopen("template.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

bool cows[2005][2005];
pii noCow = {-1, -1};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool comf(pii p) {
    noCow = {-1, -1};
    int others = 0;
    FOR(i, 0, 4) {
        pii p2 = {p.fi + dx[i], p.se + dy[i]};
        if (cows[p2.fi][p2.se]) {others++;}
        else {noCow = p2;}
    }
    return (others == 3);
}
int main() {
    fastio;
    int n;
    cin >> n;
    set<pii> S;
    stack<pii> adding;
    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;
        a += 1000; b += 1000;
        pii p = {a, b};
        if (S.count(p)) {S.erase(p);}
        else {adding.push(p);}
        while (adding.size()) {
            pii q = adding.top();
            adding.pop();
            cows[q.fi][q.se] = true;
            if (comf(q) && !S.count(noCow)) {
                S.insert(noCow);
                adding.push(noCow);
            }
            FOR(i, 0, 4) {
                if (comf({q.fi + dx[i], q.se + dy[i]}) && cows[q.fi + dx[i]][q.se + dy[i]] && !S.count(noCow)) {
                    S.insert(noCow);
                    adding.push(noCow);
                }
            }
        }
        cout << S.size() << "\n";
    }
    return 0;
}
