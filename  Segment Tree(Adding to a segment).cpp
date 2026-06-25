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
ll a[N], t[N * 4], lz[N * 4];
pair <ll, ll> p[N];
map <ll, ll> mp;
ll b[N], ans[N];
ll n, q;
void push(ll v = 1, ll tl = 1, ll tr = n){
  ll tm = (tl + tr) / 2;
  if (lz[v] != 0){
    t[v + v] += (tm - tl + 1) * lz[v];
    t[v + v + 1] += (tr - tm) * lz[v];
    lz[v + v] += lz[v];
    lz[v + v + 1] += lz[v];
    lz[v] = 0;
  }
}
void build(ll v = 1, ll tl = 1, ll tr = n){
  if (tl == tr){t[v] = a[tl];return;}
    ll tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = t[v + v] + t[v + v + 1];
}
void upd(ll l,ll r,ll x, ll v = 1, ll tl = 1, ll tr = n){
  if(l<=tl && tr<=r){
    t[v] +=(tr-tl+1)*x;
    lz[v] += x;
    return;
  }
  if(tr<l or r<tl)return ;
  ll tm = (tl + tr) / 2;
  push(v, tl, tr);
  upd(l,r, x, v + v, tl, tm);
  upd(l,r, x, v + v + 1, tm + 1, tr);
  t[v] = t[v + v] + t[v + v + 1];
}
ll get(ll x, ll v = 1, ll tl = 1, ll tr = n){
  if (tl == tr){return t[v];}
  ll tm = (tl + tr) / 2;
  push(v, tl, tr);
  if (x <= tm)return get(x, v + v, tl, tm);
  else return get(x, v + v + 1, tm + 1, tr);
}
void solve(){
  cin >> n >> q;
  while (q --){
    ll num;
    cin >> num;
    if (num == 1){
      ll l, r, x;
      cin >> l >> r >> x;
      upd(l + 1, r, x);
    }else{
      ll x;
      cin >> x;
      cout << get(x + 1) <<"\n";  
    }
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
