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
struct mo{
  ll l, r, ind;
}q[N];
ll a[N], res[N], n, m, ans = 0, k, p = 1, cnt[N], pr[N];
ll block = 600;
set <ll> st;
bool cmp(mo x, mo y){
  if (x.l / block != y.l / block)return x.l < y.l;
  else return x.r < y.r;
}
void add(ll x){
  ans -= (cnt[x] * cnt[x] * x);
  cnt[x]++;
  ans += (cnt[x] * cnt[x] * x);
}
void del(ll x){
  ans -= (cnt[x] * cnt[x] * x);
  cnt[x]--;
  ans += (cnt[x] * cnt[x] * x);
}
void solve(){
  cin >> n >> m;
  pr[0] = 0;
  for (int i = 1; i <= n; i++){cin >> a[i];}
  for (int i = 1; i <= m; i++){
    cin >> q[i].l >> q[i].r;
    q[i].ind = i;
  }
  sort(q + 1, q + m + 1, cmp);
  ll L = 1, R = 0;
  for (int i = 1; i <= m; i++){
    while(R < q[i].r) add(a[++R]);
    while(L > q[i].l) add(a[--L]);
    while(R > q[i].r) del(a[R--]);
    while(L < q[i].l) del(a[L++]);
    res[q[i].ind] = ans;
  }
  for (int i = 1; i <= m; i++)cout << res[i] <<"\n";
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
