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
	for(int i = 0; i < N; i++){
		for(int k = K; k >= 1; k--){
			for(int j = 0; j < h.size(); j++){
				if(k > 1){
					for(int m = j - 1; m >= 0; m--){
						dp[j][k] = min(dp[j][k], dp[m][k-1]);
					}
				}
				dp[j][k] += abs(d[i] - h[j]);
		//		printf("dp[%d][%d][%d] = %d\n", i+1, j, k, dp[j][k]);
			}
		}
	}
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

	




