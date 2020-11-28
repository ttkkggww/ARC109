#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using ll = long long;
string s;
string t;
int N,K;
int mp(int n){
	int res = 1;
	for(int i = 0;i<n;i++){
		res *= 2;
		res %= N;
	}
	return res;
}
char memo[1000][1000];

char dfs(int idx,int depth){
	if(memo[idx][depth]!=0)return memo[idx][depth];
	if(depth==0){
		return s[idx];
	}
	string tmp;
	tmp.push_back(dfs(idx,                depth-1));
	tmp.push_back(dfs((idx+mp(depth-1))%N,depth-1));
	sort(tmp.begin(),tmp.end());
	char res=tmp[0];
	if(tmp=="PR")res='P';
	if(tmp=="PS")res='S';
	if(tmp=="RS")res='R';
	//cout<<'a'<<endl;
	return memo[idx][depth]= res;
}

int main()
{
	cin >> N >> K;
	cin >> s;
	cout<<dfs(0,K)<<endl;
}
