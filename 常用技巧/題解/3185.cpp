/* 思路：對於第i個碗而言，如果
 * 第i-1個碗需要被翻動，則第i個
 * 就需要被翻動；反之不用。而問
 * 題在第一個碗到底需不需要被翻
 * 動？所以我們分兩次情形計算：
 * 第一個有被翻動和沒被翻動。
 * 判斷第i-1個碗的狀態：令函數f[i]
 * 表示第i個是否有被翻動，若
 *    f[i-2] + f[i-1]
 * 是奇數，則第i個碗的狀態不變。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 31
using namespace std;

int bowls[21];
int solve(){
	int f[21];
	fill(f, f + 21, 0);
	int count[2];
	for(int k = 0; k < 2; k++){
		f[1] = k;
		count[k] = k;
		for(int i = 2; i <= 20; i++){
			f[i] = ((f[i-1] + f[i-2]) % 2) ^ bowls[i-1];
			if(f[i]) count[k] ++;
		}
		if((((f[19]+f[20]) % 2) ^ bowls[20]) == 1){
			count[k] = INF;
		}
	}
	return min(count[0], count[1]);
}
int main(){
	for(int i = 1; i <= 20; i++) scanf("%d", &bowls[i]);
	printf("%d\n", solve());
	return 0;
}
	
		
	