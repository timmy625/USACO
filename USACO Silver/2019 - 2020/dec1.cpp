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
#define fileio freopen("moobuzz.in", "r", stdin), freopen("moobuzz.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n;
    cin >> n;
    int cycles = n/8;
    cycles--;
    int spoken = 8*cycles;
    int curr = 15*cycles;
    while (spoken < n) {
        curr++;
        if (curr % 3 == 0 || curr % 5 == 0) {continue;}
        spoken++;
    }
    cout << curr << "\n";
    return 0;
}
