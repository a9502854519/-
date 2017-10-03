/* Josephus Problem */
/* 函數solve(int N, int K)會回傳Ｎ個人，每次砍第Ｋ個人時，編號多少
 * 的人類會活下來。
 * 不像k = 2有很漂亮的數學通解，k != 2的情況下沒有數學通解，只能用
 * 遞迴慢慢解。時間複雜度大約為Klog(N)
 */
#include<iostream>
#include<cstdio>

using namespace std;

int solve(int N, int K){
	if(N == 1) return 0;
	if(N < K) return (solve(N-1, K) + K) % N;
	int t = solve(N - N/K, K);
	int r = (t + (N - N % K)) % N;
	if(t >= N % K + K-1) r += r/(K-1);
//	printf("N = %d  r = %d\n", N, r);
        return r;
}	
int main(){
	int  N, K;
	while(cin>>N>>K){
		printf("%d\n", solve(N, K) + 1);
	}
	return 0;
}
