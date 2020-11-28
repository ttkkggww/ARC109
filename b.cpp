#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	ll x;
	cin >> x;
	ll l = 0,r=x+1;
	while(r-l>1){
		ll m = (l+r)/2;
		if((m+1)>LLONG_MAX/m){
			r=m;
			continue;
		}
		ll sum = m*(m+1)/2;
		if(sum>(x+1)){
			r =m;
		}
		else{
			l=m;
		}
	}
	//cout<<l<<endl;
	//cout<<r<<endl;
	cout<<x-l+1<<endl;
}
