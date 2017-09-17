#include<iostream>
#include<algorithm>
#define INF 1E9

using namespace std;
/* 這題用二分搜尋法是脫褲子放屁，只要將力量+重量由小到大排序，
 * 計算每頭牛的風險值，最大的就會是答案了。證明如下：
 * 假設有兩頭牛A和B，其中A.s+A.w < B.s+B.w。再假設A和B兩頭牛上
 * 面的牛總重為m。若將A放於B之上，則A和B的風險值為：
 * riskA1 = m - A.s
 * riskB1 = m + A.w - B.s
 * 若反過來放，則風險值為：
 * riskA2 = m + B.w - A.s
 * riskB2 = m - B.s
 * 來比較一下riskA2和riskB1，移項後可以發現riskA2 > riskB1。因
 * 此原來的放法才是最佳的。
 */
struct cow{
	int w;
	int s;
	//重載運算子
	//這部份應該會放在物件導向的部份(如果沒有，就把那本書拿去燒了)
	bool operator < (cow& other){
		return w+s < other.w+other.s;
	}
};
cow Cow[50000];
int main(){
	int N,total = 0,risk;
	cin>>N;
	for(int i = 0; i < N; i++){
		cin>>Cow[i].w>>Cow[i].s;
		total += Cow[i].w;
	}
	sort(Cow, Cow+N);
	risk  = -INF;
	for(int i = N-1; i >= 0; i--){
		total -=Cow[i].w;
		risk = max(risk, total - Cow[i].s);
	}
	cout<<risk<<endl;
	
}
	