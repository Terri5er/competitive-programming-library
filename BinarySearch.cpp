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
ll a[N], b[N];
void solve(){
    ll n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)cin>>a[i];
    for(int j=0;j<m;j++)cin>>b[j];
    for (int j=0;j<m;j++){
      ll l=0,r=n-1,res=0;
      while (l<=r){
        ll md=(l+r)/2;
        if (a[md]<=b[j]){
          l=md+1;
          res=md+1;
      }else{
        r=md-1;
        }
      }
      cout<<res<<endl;
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
