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
ll n, q, m, cnt;
ll was[N], dp[N];
vector <ll> g[N];
void bfs(ll v){
  for (int i = 1; i <= n; i++)dp[i] = LLONG_MAX;
  queue <ll> q;
  q.push(v);
  dp[v] = 0;
  while (q.sz()){
    ll p = q.front();
    q.pop();
    for (auto to : g[p]){
      if (!was[to]){
        q.push(to);
        was[to] = 1;
        dp[to] = dp[p] + 1;
      }
    }
  }
}
void solve(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      ll x;
      cin >> x;
      if (x){
        g[i].pb(j);
        g[j].pb(i);
      }
    }
  }
  ll x, y;
  cin >> x >> y;
  bfs(x);
  if (dp[y] == LLONG_MAX)dp[y] = -1;
  if (x == y)dp[y] = 0;
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
