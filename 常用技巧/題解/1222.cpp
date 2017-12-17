/* 決定第一排的狀態後，能影響到第一排的，就只剩第
 * 二排了。舉例：假設第一排的狀態為：
 *   000101
 *   ...x.x
 * 能動到那兩個1的開關，就只剩那兩個x了。
 * 因此枚舉第一排的狀態後，後面的開關按法也就跟著
 * 決定了。最後只需判斷最後一排是否全被關掉即可。
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 5
#define M 6
using namespace std;


int puzzle[5][6];
int f[5][6];
int x1[5] = {-1, 1, 0, 0, 0};
int y1[5] = { 0, 0, 0, 1,-1};
int get(int a, int b){
	int count = 0;
	for(int i = 0; i < 5; i++){
		int x = a + x1[i], y = b + y1[i];
		if(x >= 0 && x < N && y >= 0 && y < M){
			count += f[x][y];
		}
	}
	return (count % 2) ^ puzzle[a][b];
}
void solve(int m){
	for(int s = 0; s < (1 << M); s++){
		memset(f, 0, sizeof(f));
		for(int i = 0; i < M; i++){
			f[0][i] = ((s>>(M - i - 1)) & 1);
		}
		for(int i = 1; i < N; i++){
			for(int j = 0; j < M; j++){
				if(get(i - 1, j) == 1){ // i-1, j沒被翻轉
					f[i][j] = 1;
				}
			}
		}
		bool k = true;
		for(int i = 0; i < 6; i++){
			if(get(N - 1, i) != 0) k = false;
		}
		if(k){
			printf("PUZZLE #%d\n",m); 
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 6; j++){
					printf("%d ",f[i][j]);
				}
				printf("\n");
			}
			return;
		}
	}
}	
int main(){
	int n;
	cin>>n;
	for(int s = 1; s <= n; s++){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 6; j++){
				scanf("%d", &puzzle[i][j]);
			}
		}
		solve(s);
	}
	return 0;
}
	