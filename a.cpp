#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int cost[2][100];

int main()
{
	int a,b,x,y;
	cin >> a >> b >> x >> y;
	a--;b--;
	priority_queue<vector<int>,vector<vector<int>>,greater<>> PQ;

	vector<int> fir = {0,0,a};

	PQ.emplace(fir);
	for(int i = 0;i<2;i++){
		for(int j = 0;j<100;j++){
			cost[i][j]=INT_MAX/2;
		}
	}

	cost[0][a]=0;
	while(PQ.size()){
		auto now = PQ.top();
		PQ.pop();
		if(cost[now[1]][now[2]]!=now[0])continue;
		int nextab = 1-now[1];
		if(nextab==1){
			if(cost[nextab][now[2]]>now[0]+x){
				cost[1][now[2]]=now[0]+x;
				vector<int> next = {now[0]+x,nextab,now[2]};
				PQ.emplace(next);
			}
			if(now[2]>0){
				if(cost[nextab][now[2]-1]>now[0]+x){
					cost[1][now[2]-1]=now[0]+x;
					vector<int> next = {now[0]+x,nextab,now[2]-1};
					PQ.emplace(next);
				}
				if(cost[now[1]][now[2]-1]>now[0]+y){
					cost[now[1]][now[2]-1]=now[0]+y;
					vector<int> next = {now[0]+y,now[1],now[2]-1};
					PQ.emplace(next);
				}
			}
			if(now[2]<99){
				if(cost[now[1]][now[2]+1]>now[0]+y){
					cost[now[1]][now[2]+1]=now[0]+y;
					vector<int> next = {now[0]+y,now[1],now[2]+1};
					PQ.emplace(next);
				}
			}
		}else{
			if(cost[nextab][now[2]]>now[0]+x){
				cost[nextab][now[2]]=now[0]+x;
				vector<int> next = {now[0]+x,nextab,now[2]};
				PQ.emplace(next);
			}
			if(now[2]>0){
				if(cost[now[1]][now[2]-1]>now[0]+y){
					cost[now[1]][now[2]-1]=now[0]+y;
					vector<int> next = {now[0]+y,now[1],now[2]-1};
					PQ.emplace(next);
				}
			}
			if(now[2]<99){
				if(cost[nextab][now[2]+1]>now[0]+x){
					cost[nextab][now[2]+1]=now[0]+x;
					vector<int> next = {now[0]+x,nextab,now[2]+1};
					PQ.emplace(next);
				}
				if(cost[now[1]][now[2]+1]>now[0]+y){
					cost[now[1]][now[2]+1]=now[0]+y;
					vector<int> next = {now[0]+y,now[1],now[2]+1};
					PQ.emplace(next);
				}
			}
		}
	}
	cout<<cost[1][b]<<endl;
}
