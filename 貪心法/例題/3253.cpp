/* 將切的過程畫成一個二元樹，就會發現，位置越深的，加權越大。
 * 要將成本最小化，就會希望位置越深的，板子越短越好。
 * 對於最合適的解答來說，最短的板子之節點應該是最深的板子。然
 * 後，該葉子應該會具有深度相同的兄弟節點才對，由於該兄弟節點
 * 的深度也是最深的，所以該節點就是次短板子的節點。
 */
#include<iostream>
#include<cstdio>
#include<queue>
#define MAX_N 20000

using namespace std;
typedef long long ll;

int N;

int main(){
	cin>>N;
	ll ans = 0;
	//優先佇列
	//這是一個min heap
	priority_queue< int, vector<int>, greater<int> > q;
	//如果要宣告max heap，只要這樣宣告即可：
	//priority_queue< data_type > 
	for(int i = 0; i < N; i++){
		int L;
		cin>>L;
		q.push(L);
	}
	while(q.size() > 1){
		int L1 = q.top(); q.pop();
		int L2 = q.top(); q.pop();
		ans += L1+L2;
		q.push(L1+L2);
	}
	printf("%lld\n", ans);
	return 0;
}
		