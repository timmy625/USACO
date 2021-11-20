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
#define fileio freopen("cardgame.in", "r", stdin), freopen("cardgame.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    bool cards[2*n];
    FOR(i, 0, 2*n) {cards[i] = false;}
    vi elsie1, elsie2, bessie;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        cards[--x] = true;
        (i >= n/2) ? elsie2.pb(x) : elsie1.pb(x);
    }
    FOR(i, 0, 2*n) {if (!cards[i]) {bessie.pb(i);}}
    sort(elsie1.begin(), elsie1.end(), greater<int>());
    sort(elsie2.begin(), elsie2.end());
    int ans = 0;
    int card = n-1;
    for (int value : elsie1) {
        if (bessie[card] > value) {ans++; card--;}
    }
    card = 0;
    for (int value : elsie2) {
        if (bessie[card] < value) {ans++; card++;}
    }
    cout << ans << "\n";
    return 0;
}
