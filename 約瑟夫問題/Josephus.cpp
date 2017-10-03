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
