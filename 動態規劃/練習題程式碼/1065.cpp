/* 照著重量或是長度（假設是重量好了）排序後，問題就變成求
　* 長度的LIS的個數
　*/

#include<iostream>
#include<algorithm>
#include<utility>
#include<cstring>
#define MAX_N 5000

using namespace std;

pair<int, int> WS[MAX_N];
bool dp[MAX_N]; //dp[i] --> 代表第i個是否已經被加入某個LIS中
int m;

void solve(){
	sort(WS,WS+m);
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	for(int i = 0; i < m ;i++){
		if(!dp[i]){//如果還沒被加入任何LIS中
			int last = WS[i].second;
			ans++; 
			for(int j = i + 1; j < m; j++){
				if(!dp[j] && WS[j].second >= last){
					last = WS[j].second;
					dp[j] = true;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	int n, last;
	cin>>n;
	while(n--){
		cin>>m;	
		for(int j = 0; j < m; j++){
			cin>>WS[j].first>>WS[j].second;  
		}
		solve();
	}
	return 0;
}
