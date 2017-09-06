/* 假設中位數的個數為m。如果一個數字x是中位數，則
 * 大於等於x的數字個數一定超過 m/2(因為題目要求的
 * 關係，如果m為奇數則取下限)。在這基礎上，就可以
 * 使用二分搜尋法了。
 */


#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int X[50000];
int n,m;

bool C(int k){
	int sum = 0, temp;
	for(int i = 0; i < n; i++){
		int val = X[i] + k;//大於等於這數字的，其與X[i]的差必大於等於k。
		temp = n - (lower_bound(X, X + n, val) - X);//尋找大於等於val的數字個數
		if(temp == 0) break;//如果找不到，再往下找也不會有了。
		sum += temp;
	}
	return sum > m/2;
}
int solve(){
	sort(X, X+n);
	int ub = X[n-1] - X[0] + 1, lb = 0, mid;
	m = (n-1)*n/2; //中位數的個數
	while(ub - lb > 1){
		mid  = (ub + lb) / 2;
		if(C(mid)) lb = mid;
		else ub = mid;
	}
	return lb;
}
int main(){
	while(cin>>n){
		for(int i = 0; i<n; i++){
			scanf("%d", &X[i]);
		}
		printf("%d\n", solve());
	}		
	
	return 0;
}