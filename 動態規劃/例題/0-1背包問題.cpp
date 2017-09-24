#define MAX_N 100
#define MAX_W 10000
#define INF 1E9

int w[MAX_N+1], v[MAX_N+1];
int dp[MAX_N+1][MAX_W+1];
int n, W;
//輸入

void solve(){
	memset(dp[0], 0, sizeof(dp[0]));//前零個物品，價值為0
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= W; j++){
			dp[i][j] = dp[i-1][j];
			if(j-w[i] >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
			}
		}
	}
	cout<<dp[n][W]<<endl;
}