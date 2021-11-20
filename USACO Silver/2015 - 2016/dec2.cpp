#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("highcard.in", "r", stdin), freopen("highcard.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int n;
    cin >> n;
    bool A[2*n];
    FOR(i, 0, 2*n) {A[i] = false;}
    FOR(i, 0, n) {int x; cin >> x; A[--x] = true;}
    vi elsie, bessie;
    FOR(i, 0, 2*n) {A[i] ? elsie.pb(i+1) : bessie.pb(i+1);}

    int i = 0, j = 0;
    while (i < n) {
        while (j < n) {
            if (bessie[j] > elsie[i]) {break;}
            j++;
        }
        if (j == n) {break;}
        i++; j++;
    }   
    cout << i << "\n";
    return 0;
}
