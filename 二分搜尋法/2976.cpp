/* 給定一個x，如果能判斷 sigma(ai)/sigma(bi) >= x，就
 * 能用二分搜尋了。將不等式移項後，可得
 *         sigma(ai) - x*sigma(bi) >= 0
 * 計算出所有的ai - x*bi，然後排序，拋棄
 * 掉最小的k個，若剩下的總和 >= 0，代表答案有可能是x，
 * 也有可能大於x，因此繼續往上二分搜，反之往下。
 *
 * 因為這題是浮點數，不像整數，在某個區間內，浮點數有
 * 無限多個，理論上我們是無法找到真正的答案，只能無限
 * 逼近答案。而每一此二分的「輪迴」結束後，區間都會被
 * 砍半，也就是(1/2)，「輪迴」一百次後，區間的寬度就會
 * 只有原來的(1/2) ^ 100，大約為10^-31。這精度對幾乎所
 * 有的題目來說已足夠。所以浮點數的二分的結束條件依據，
 * 就是二分的次數超過100次時(詳見程式碼)。
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
	for(int i = 0; i < 100; i++){
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