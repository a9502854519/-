/* 將牛以分數排序，考慮一頭牛的成績x.score做為中位數，對於
 * 成績小於等於x.score的牛群集合Cow1，盡可能地選取助學貸款
 * 比較少的N/2頭牛；對於成績大於等於x.score的牛群集合Cow2
 * 也比照辦理，得到總和sum2。計算結果分成以下三種情況
 * (1) sum1 + sum2 + x.aid <= F
 * (2) sum1 > sum2
 * (3) otherwise
 * 對於(1)，很合理地我們會繼續往上找更大的中位數。若(1)不
 * 滿足並且滿足(2)
 */


#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;


struct Data{
	int score;
	int aid;
	bool operator < (const Data& other) const{
		return score < other.score;
	}
};
struct Financial_Aid{
	int aid;
	int id;
	bool operator < (const Financial_Aid& other) const{
		return aid < other.aid;
	}
};
int N, C, F;
Data data[100000];
Financial_Aid f_a[100000];

bool D(int x){
	int sum1 = 0, sum2 = 0, count1 = 0, count2 = 0;
	for(int i = 0; i < C; i++){
		if(f_a[i].id < x && count1 < N/2){
			sum1 += f_a[i].aid;
			count1++;
		}
		if(f_a[i].id > x && count2 < N/2){
			sum2 += f_a[i].aid;
			count2++;
		}
	}
	if(sum1+sum2+data[x].aid <= F || sum1 > sum2) return true;
	return false;
}
int main(){
	cin>>N>>C>>F;
	for(int i = 0; i < C; i++){
		cin>>data[i].score>>data[i].aid;
	}
	sort(data, data + C);
	for(int i = 0; i < C; i++){
		f_a[i].aid = data[i].aid;
		f_a[i].id = i;
	}
	sort(f_a, f_a + C);
	
	int ub = C - (N/2) , lb = (N/2) - 1, mid;
	while(ub - lb > 1){
		mid = (ub + lb) / 2;
		if(D(mid)) lb = mid;
		else ub = mid;
	}
	printf("%d\n", (lb == (N/2)-1 ? -1 : data[lb].score));
	return 0;
}