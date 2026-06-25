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
ll t[N*4],a[N];
ll n,q;
void build(ll v=1,ll tl=0,ll tr=n-1){
	if(tl==tr){
		t[v]=a[tl];
		return ;
	}
	ll tm=(tl+tr)/2;
	build(v+v,tl,tm);
	build(v+v+1,tm+1,tr);
	t[v]=t[v+v]+t[v+v+1];
}
void upd(ll x,ll sum,ll v=1,ll tl=0,ll tr=n-1){
	if(tl==tr){
		t[v]=sum;
		return ;
	}
	ll tm=(tl+tr)/2;
	if(x<=tm)upd(x,sum,v+v,tl,tm);
	else upd(x,sum,v+v+1,tm+1,tr);
	t[v]=t[v+v]+t[v+v+1];
}
ll get(ll l,ll r,ll v=1,ll tl=0,ll tr=n-1){
	if(l<=tl && tr<=r){
		return t[v];
	}
	if(tr<l || r<tl)return 0;
	ll tm=(tl+tr)/2;
	return get(l,r,v+v,tl,tm)+get(l,r,v+v+1,tm+1,tr);
}
void solve(){
  cin>>n>>q;
	for(ll i=0;i<n;i++)cin>>a[i];
	build();
	while(q--){
		ll num;
		cin>>num;
		if(num==2){
			ll l,r;
			cin>>l>>r;
			cout<<get(l,r-1)<<"\n";
		}
		else {
			ll x,sum;
			cin>>x>>sum;
			upd(x,sum);
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
