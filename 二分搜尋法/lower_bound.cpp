#include<iostream>
#include<cstdio>
//#include<algorithm>
//#include<vector>

using namespace std;

/*       二分搜尋法的邊界值ub, lb的設定。         */
/* 以這個lower_bound為例，當條件滿足時，ub = mid，
 * 反之lb = mid，可以看出搜尋範圍為(lb, ub]，那一
 * 開始的邊界設定就一定是(lb, ub]，換句話說，(-1, N-1]
 * 嗎 ? 前提是有辦法確定一定有答案。如果一開始就將
 * 邊界設定為(lb, ub]，若數列中的數字都小於v，則
 * 結果為輸出 d[N-1]，很明顯地是錯的。這時若將邊界
 * 設定為(lb, ub)，換句話說，(-1, N)，若發生上述的
 * 情況，則ub會一直停留在N。搜尋完後，我們可以判斷
 * ub的值是否等於N，來確定是否有答案。
 * 所以有沒有一定的規則? 大致上可以這樣判斷 ：
 * (1)先從二分搜尋的模型中確認搜尋區間
 *        以這題為例，若條件滿足，ub = mid，反之
 *        lb = mid。可以確定搜尋區間為(lb, ub]
 * (2)判斷找不到答案的情況
 *        以這題為例，找不到答案時，lb會不斷往上走
 *        因此可以將初始區間設定為(lb, ub)，最後再
 *        用ub的值判斷答案是否存在。
 */
int main(){
	int d[] = {2,2,3,3,4,4,4,4,5,6};
	int N = sizeof(d)/sizeof(int);//陣列的長度
	int ub = N, lb = -1, mid; //(lb, ub)
	int v = 16;
	while(ub - lb > 1){  
		mid = (ub+lb)/2;
		if(d[mid] >= v) ub = mid; //(lb, mid]
		else 			lb = mid; //(mid, ub]
		
	}
	for(int i = 0; i < N; i++){
		printf("%d%c",d[i], (i == N-1 ? '\n' : ' '));
	}
	for(int i = 0; i < ub*2; i++) printf(" ");
	printf("^\n");
	return 0;
}