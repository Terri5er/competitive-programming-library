#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define niga ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define F first
#define S second
#define sz() size()
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define bll(a) a.rbegin(), a.rend();
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
/*
  a u t h o r (a b a);

──▒▒▒▒▒────▒▒▒▒▒────▒▒▒▒▒────▄████▄─────
─▒─▄▒─▄▒──▒─▄▒─▄▒──▒─▄▒─▄▒──███▄█▀───────
─▒▒▒▒▒▒▒──▒▒▒▒▒▒▒──▒▒▒▒▒▒▒─▐████─────────
─▒▒▒▒▒▒▒──▒▒▒▒▒▒▒──▒▒▒▒▒▒▒──█████▄───────
─▒─▒─▒─▒──▒─▒─▒─▒──▒─▒─▒─▒───▀████▀─────  

*/
const ll N = 2e3 + 9, mod = 1e9 + 7, LOG = 32, inf = 1e18;
ll a[N][N], was[N];
vector <ll> g[N];
ll n, q, m;
void dfs(ll v){
  was[v] = 1;
  for (auto to : g[v]){
    if (!was[to])dfs(to);
  }
}
void solve(){
  cin >> n >> m;
  for (ll i = 1; i <= n; i ++){
    for (ll j = 1; j <= n; j++){
      ll x;
      cin >> x;
      if (x){
        g[i].pb(j);
        g[j].pb(i);
      }
    }
  }
  dfs(m);
}
signed main(){
  niga;
  ll aba = 1;
  // file("name");
  // cin >> aba;
  while (aba --){
    solve();
  }
return 0;
}
