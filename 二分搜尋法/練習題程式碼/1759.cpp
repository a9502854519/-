/* 我們不可能二分搜尋最右邊的燈炮高度，因為利用
 * 最左邊和最右邊的燈泡高度，求其它燈泡的高度，
 * 得解一堆方程式。
 * 利用二分搜尋，尋找第二左邊的燈炮最低高度即可
 */

#include<iostream>
#define EPS 1E-6
#include<cstdio>

using namespace std;

int N;
double A, B;

bool C(double y){
	double z, x = A;
	for(int i = 0; i < N-2; i++){
		z = (y+1)*2-x;
		if(!(z > 0 + EPS)) return false;
		x = y;
		y = z;
	}
	B = z;
	return true;
}
int main(){
	cin>>N>>A;
	double ub = A, lb = 0, mid;
	for(int i = 0; i < 100; i++){
		mid = (ub + lb)/2;
		if(C(mid)) ub = mid;
		else lb = mid;
	}
	printf("%.2f\n", B);
	return 0;
}