#define MAX_N 16

int dat[2 * MAX_N - 1];
int n;//the size of the segment tree

void init(int n_){
	n = 1;
	while(n < n_) n *= 2; //The size of the segment tree must be the power of 2
	memset(dat, 0, sizeof(dat));
}
void update(int x, int v){
	int k = x + n - 1;
	dat[k] += v;
	while(k > 0){
		k = (k - 1) / 2;
		dat[k] = dat[2 * k + 1] + dat[2 * k + 2];
	}
}
int query(int a, int b, int k, int l, int r){
	if(b <= l || a >= r) return 0;
	if(a <= l && b >= r){
		return dat[k];
	}
	int v1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
	int v2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
	return v1 + v2;
}
int query(int a, int b){//[a, b)
	return query(a, b, 0, 0, n);
}
