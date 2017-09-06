/* 給定一個x，如果能判斷 sigma(ai)/sigma(bi) >= x，就
 * 能用二分搜尋了。將不等式移項後，可得
 *         sigma(ai) - x*sigma(bi) >= 0
 * 計算出所有的sigma(ai) - x*sigma(bi)，然後排序，拋棄
 * 掉最小的k個，若剩下的總和 >= 0，就繼續往上二分搜，
 * 反之往下。
 */
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int n, k;
int a[1000], b[1000];
double temp[1000];
bool C(double x){
	for(int i = 0; i < n; i++){
		temp[i] = a[i] - b[i]*x;
	}
	sort(temp, temp+n);
	double sum = 0;
	for(int i = 0; i < n - k; i++){
		sum+=temp[n-1-i];
	}
	return sum >= 0;
}
int solve(){
	double ub = 1.0, lb = 0.0, mid;
	int res;
	for(int i = 0; i <100; i++){
		mid = (ub+lb)/2;
		if(C(mid))lb = mid;
		else ub = mid;
	}
	lb*=100;
	res = (int)lb;
	if(lb - (int)lb > 0.5) res++; //四捨五入
	return res;
}
int main(){
	while(cin>>n>>k){
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		for(int i = 0; i < n; i++){
			cin>>b[i];
		}
		printf("%d\n", solve());
	}
	return 0;
}