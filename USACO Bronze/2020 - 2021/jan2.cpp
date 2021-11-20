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

int main() {
    fastio;
    int n;
    cin >> n;
    int cows[n];
    int evenNum = 0, oddNum = 0;
    FOR(i, 0, n) {cin >> cows[i]; odd(cows[i]) ? oddNum++ : evenNum++;}
    int groups = 0;
    while (evenNum > 0 || oddNum > 0) {
        if (!odd(groups)) {
            if (evenNum) {evenNum--; groups++;}
            else if (oddNum >= 2) {oddNum -= 2; groups++;}
            else {groups--; oddNum--;}
        } else {
            if (oddNum) {
                oddNum--; 
                groups++;
            } else {
                evenNum = 0;
            }
        }
    }
    cout << groups << "\n";
    return 0;
}
