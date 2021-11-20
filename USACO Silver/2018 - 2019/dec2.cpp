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
#define fileio freopen("convention2.in", "r", stdin), freopen("convention2.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

struct cow {int a, t, s;};
bool cmpArr(cow a, cow b) {return a.a < b.a;}
int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    cow cows[n];
    int start[n];
    FOR(i, 0, n) {
        cin >> cows[i].a >> cows[i].t;
        cows[i].s = i;
    }
    sort(cows, cows + n, cmpArr);
    int ans = 0;
    int curr = 0;
    int time = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>> pq;
    while (curr < n) {
        cerr << time << " ";
        while (time >= cows[curr].a || pq.empty()) {
            pair<int, pii> p = {-cows[curr].s, {cows[curr].a, cows[curr].t}};
            pq.push(p);
            curr++;
            if (curr >= n) {break;}
        }
        pair<int, pii> p = pq.top();
        pq.pop();
        time = max(time, p.se.fi);
        ans = max(ans, time - p.se.fi);
        time += p.se.se;
    }
    cout << ans << "\n";
    return 0;
}
