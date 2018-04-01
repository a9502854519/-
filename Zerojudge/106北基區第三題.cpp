#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX_N 11
#define MAX_K 5
#define INF 1E9

using namespace std;

int dp[MAX_N][MAX_K+1];
vector<int> d;
vector<int> h;
int N, K;

void init(){
	d.clear();
	h.clear();
	memset(dp, 0, sizeof(dp));
}
void solve(){
	for(int i = 0; i < d.size(); i++){
		h.push_back(d[i]);
	}
	sort(d.begin(), d.end());
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());
	//把d離散化，這樣可以避免重複計算
	//舉例 d = {1, 1, 2, 2, 2}
	//經過上面的處理後，h = {1, 2}
	for(int i = 0; i < N; i++){
		for(int k = K; k >= 1; k--){
			for(int j = 0; j < h.size(); j++){
				if(k > 1){//如果k = 1，那上一個人就沒有「更前面的人」可以選了
					for(int m = j - 1; m >= 0; m--){
						dp[j][k] = min(dp[j][k], dp[m][k-1]);
					}
				}
				dp[j][k] += abs(d[i] - h[j]);
		//		printf("dp[%d][%d][%d] = %d\n", i+1, j, k, dp[j][k]);
			}
		}
	}
	//dp(i, j, k) = min(dp(i-1, j, k), dp(i-1, j', k-1)) + |d[i] - d[j]| 可以簡化成上述滾動陣列的形式
	int res = INF;
	for(int j = 0; j < h.size(); j++){
		res = min(res, dp[j][K]);
	}
	printf("%d\n", res);
}

int main(){
	while(cin>>N>>K){
		init();
		for(int i = 0; i < N; i++){
			int a; cin>>a;
			d.push_back(a);
		}
		solve();
	}
	return 0;
}

	




