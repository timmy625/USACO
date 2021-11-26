//Timothy Mathew (timmy625)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
#define fileio freopen("rental.in", "r", stdin), freopen("rental.out", "w", stdout);
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    fileio;
    int n, m, r;
    cin >> n >> m >> r;

    ll c[n];
    FOR(i, 0, n) {cin >> c[i];}
    sort(c, c + n, greater<ll>());
    ll milk[n+1];
    milk[0] = 0;
    FOR(i, 1, n+1) {milk[i] = milk[i-1] + c[i-1];}

    pair<ll, ll> buy[m];
    FOR(i, 0, m) {cin >> buy[i].se >> buy[i].fi;}
    sort(buy, buy + m, greater< pair<ll, ll> >());
    ll totalMilk[m+1], milkMoney[m+1];
    totalMilk[0] = 0, milkMoney[0] = 0;;
    FOR(i, 1, m+1) {
        totalMilk[i] = totalMilk[i-1] + buy[i-1].se;
        milkMoney[i] = milkMoney[i-1] + buy[i-1].fi * buy[i-1].se;
    }

    ll rent[r];
    FOR(i, 0, r) {cin >> rent[i];}
    sort(rent, rent + r, greater<ll>());
    ll totalRent[r+1];
    totalRent[0] = 0;
    FOR(i, 1, r+1) {totalRent[i] = totalRent[i-1] + rent[i-1];}
    
    ll ans = 0;
    int shopsUsed = 0;
    FOR(i, 0, n+1) {
        ll currMoney = milkMoney[max(0, shopsUsed-1)]; 
        while (milk[i] > totalMilk[shopsUsed] && shopsUsed < m) {
            currMoney = milkMoney[shopsUsed];
            shopsUsed++;
        }
        currMoney += min(milk[i]-totalMilk[max(0, shopsUsed-1)], buy[max(0, shopsUsed-1)].se) * buy[max(0, shopsUsed-1)].fi;
        currMoney += totalRent[min(n-i, r)];
        ans = max(ans, currMoney);
    }
    cout << ans << "\n";
    return 0;
}
