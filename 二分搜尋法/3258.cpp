/* 如果能判斷最短距離是否能增加到d，就能用二分搜尋法了。
 * 如果兩兩石頭間的距離超過d，則移除一其中一個就行，因為
 * 第一個石頭不能移除，為了方便，我們移除比較後面的那個。
 * 最後只要判斷最後一個石頭 跟 倒數第二個石頭之間的距離是
 * 否大於等於d就行了。 
 */



#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int N, M ,L;
int rock[50002];

bool C(int d){
	int count = 0,last = 0;
	for(int i = 1; i <= N;i++){
		if(rock[i] - last >= d){
			last = rock[i];
		}else{
			if(++count > M) return false;
		}
	}
	if(rock[N+1] - last < d) return false;
	return true;
}
int solve(){
	sort(rock, rock+N+1);
	int lb = 0, ub = L, mid;
	while(ub - lb > 1){
		mid = (ub + lb) / 2;
		if(C(mid)) lb = mid;
		else ub = mid;
	}
	if(N == 0) return L;
	else return lb;
}
int main(){
	cin>>L>>N>>M;
	rock[0] = 0;
	rock[N+1] = L;
	for(int i = 1; i <= N; i++){
		cin>>rock[i];
	}
	printf("%d\n", solve());
	return 0;
}