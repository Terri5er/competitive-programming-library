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
const ll N = 2e5 + 9, mod = 1e9 + 7, LOG = 32, inf = 1e18;
vector <pair <ll, ll>> g[N];
ll d[N];
void dx(ll v){
  set <pair <ll, ll>> st;
  d[v] = 0;
  st.insert({0, v});
  while (st.sz()){
    ll cur = st.begin()->S;
    st.erase(st.begin());
    for (auto to : g[cur]){
      if (d[to.F] > d[cur] + to.S){
        st.erase({d[to.F], to.F});
        d[to.F] = d[cur] + to.S;
        st.insert({d[to.F], to.F});
      }
    }
  }
}
void solve(){
  ll n, s, f;
  cin >> n >> s>> f;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      ll x;
      cin >> x;
      if (i != j and x >= 0){
        g[i].pb({j, x});
      }
    }
  }
  for (int i = 1; i <= n; i++)d[i] = inf;
  dx(s);
  if (d[f] == inf){
    cout << "-1\n";
  }else{
    cout << d[f] <<"\n";
  }
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
