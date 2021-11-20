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
#define fileio freopen("lifeguards.in", "r", stdin), freopen("lifeguards.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    int alone[n];
    vector<pii> endpoints;
    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;
        endpoints.pb(mp(a, i));
        endpoints.pb(mp(b, i));
        alone[i] = 0;
    }
    sort(endpoints.begin(), endpoints.end());
    int total = 0;
    set<int> S;
    int prevTime = 0;
    FOR(i, 0, 2*n) {
        if (S.size()) {
            int time = endpoints[i].fi - prevTime;
            if (S.size() == 1) {
                alone[*S.begin()] += time;
            } 
            total += time;
        }
        if (S.count(endpoints[i].se)) {
            S.erase(endpoints[i].se);
        } else {S.insert(endpoints[i].se);}
        prevTime = endpoints[i].fi;
    }
    int remove = INT_MAX;
    for (int value : alone) {remove = min(remove, value);}
    cout << total - max(remove, 0) << "\n";
    return 0;
}
