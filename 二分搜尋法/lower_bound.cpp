#include<iostream>
#include<cstdio>
//#include<algorithm>
//#include<vector>

using namespace std;

int* lower_bound(int* lb, int *ub, int v){
	int* mid; ub--; lb--;
	while(ub - lb > 1){
		mid = lb+(ub-lb)/2;
		if(*mid >= v) ub = mid;
		else lb = mid;
	}
	return ub;
}
int* upper_bound(int* lb, int* ub, int v){
	int* mid; ub--; lb--;
	while(ub - lb > 1){
		mid = lb+(ub-lb)/2;
		if(*mid > v) ub = mid;
		else lb = mid;
	}
	return ub;
}
int main(){
	const int N = 10;
	int d[N] = {1,1,2,2,2,3,3,4,5,6};
	return 0;
}