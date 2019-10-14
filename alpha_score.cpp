#include <bits/stdc++.h>
using namespace std;
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
map<int,int> bit;
int nn=1000000007;
int m = 1000000007;
int n;
void update(int inc,int i){
	while(i<=nn){
		bit[i]=(bit[i]+inc)%m;
		i+=i&(-i);
	}
}
int query(int i){
	int ans=0;
	while(i>0){
		ans=(ans+bit[i])%m;
		i-=i&(-i);
	}
	return ans;
}
int32_t main()
{	
	Fast_IO
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w",stdout);
	#endif
	// int n;
	cin>>n;
	int a[n];
	int alphascore=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)
			update(a[i],a[i]);
		// cout<<query(a[i]-1);
		alphascore = (alphascore+query(a[i]-1))%m;
	}	
	cout<<alphascore;


}