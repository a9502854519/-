/* 利用二分搜尋法，計算最少的時數，問題就變成
 * 如何判斷是否能在某個時間限制內，烘完所有的
 * 衣服?
 * 對於某個時間限制limit，若衣服的水量超過limit
 * ，就代表一定得使用烘乾機。計算總烘乾時數方法
 * 有點抽象，大致上是這樣：若自然乾，則每分鐘會
 * 乾一單位的水量，加入烘乾機，則每分鐘可以多乾
 * k-1單位的水量。因此只要計算自然乾後，剩下的
 * 水量/k-1(無條件進位)，就是該件衣服所需的最少
 * 烘乾時間。全部加總，判斷是否超過時限即可。
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define INF 1E9

using namespace std;
typedef long long int ll;

ll clothes[100000];
ll n,k;//有n件衣服，烘乾機可以在一分鐘內排乾k單位的水

inline ll myceil(ll a, ll b){
	return a/b + (a%b>0 ? 1 : 0);
}


bool C(ll limit){
	ll sum = 0;
	for(ll i = 0; i < n; i++){
		if(clothes[i] > limit){
			//在限制內，盡可能減少烘乾機的使用時數。
			sum += myceil(clothes[i] - limit, k - 1);
		}
		if(sum > limit) return false;
	}
	return true;
}

int main(){
	
	ll lb = 1, ub = 0, mid;	
	scanf("%lld",&n);
	for(ll i = 0; i<n;i++){
		scanf("%lld",&clothes[i]);
		ub = max(ub, clothes[i]);
	}
	scanf("%lld",&k);
	if(k != 1){
		while(ub - lb > 1){
			mid = (ub + lb) / 2;
			if(C(mid)) ub = mid;
			else lb = mid;
		}
	}
	
	cout<<ub<<endl;
	
	return 0;
}
		
	
	