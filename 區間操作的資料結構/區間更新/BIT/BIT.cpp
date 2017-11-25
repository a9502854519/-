//[1, n]
int bit0[MAX_N + 1], bit1[MAX_N + 1], n;

int sum(int *bit, int i){
	int s = 0;
	while(i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
int sum(int i){ //[1, i]
	return sum(bit0, i) + sum(bit1, i) * i;
}
int sum(int a, int b){//[a, b]
	return sum(b) - sum(a - 1);
}
void add(int *bit, int i, int x){
	while(i <= n){
		bit[i] += x; 
		i += i & -i;
	}
}
void add(int l, int r){//[a, b]
	add(bit1, x, l);
	add(bit1, -x, r + 1);
	add(bit0, -x * (l - 1), l);
	add(bit0, x * r, r + 1);
}