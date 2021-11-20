#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("herding.in", "r", stdin), freopen("herding.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
        
    int A[3];
    FOR(i, 0, 3) {cin >> A[i];}
    sort(A, A + 3);
    if ((A[2] - A[0] == 2)) {cout << 0 << "\n";}
    else if ((A[2]-A[1]==2) || (A[1]-A[0]==2)) {cout << 1 << "\n";}
    else {cout << 2 << "\n";}
    cout << max(A[2]-A[1], A[1]-A[0])-1 << "\n";
    return 0;
}
