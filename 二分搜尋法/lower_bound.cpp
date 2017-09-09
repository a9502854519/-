#include<iostream>
#include<cstdio>
//#include<algorithm>
//#include<vector>

using namespace std;

/*       �G���j�M�k����ɭ�ub, lb���]�w�C         */
/* �H�o��lower_bound���ҡA����󺡨��ɡAub = mid�A
 * �Ϥ�lb = mid�A�i�H�ݥX�j�M�d��(lb, ub]�A���@
 * �}�l����ɳ]�w�N�@�w�O(lb, ub]�A���y�ܻ��A(-1, N-1]
 * �� ? �e���O����k�T�w�@�w�����סC�p�G�@�}�l�N�N
 * ��ɳ]�w��(lb, ub]�A�Y�ƦC�����Ʀr���p��v�A�h
 * ���G����X d[N-1]�A�ܩ���a�O�����C�o�ɭY�N���
 * �]�w��(lb, ub)�A���y�ܻ��A(-1, N)�A�Y�o�ͤW�z��
 * ���p�A�hub�|�@�����d�bN�C�j�M����A�ڭ̥i�H�P�_
 * ub���ȬO�_����N�A�ӽT�w�O�_�����סC
 * �ҥH���S���@�w���W�h? �j�P�W�i�H�o�˧P�_ �G
 * (1)���q�G���j�M���ҫ����T�{�j�M�϶�
 *        �H�o�D���ҡA�Y���󺡨��Aub = mid�A�Ϥ�
 *        lb = mid�C�i�H�T�w�j�M�϶���(lb, ub]
 * (2)�P�_�䤣�쵪�ת����p
 *        �H�o�D���ҡA�䤣�쵪�׮ɡAlb�|���_���W��
 *        �]���i�H�N��l�϶��]�w��(lb, ub)�A�̫�A
 *        ��ub���ȧP�_���׬O�_�s�b�C
 */
int main(){
	int d[] = {2,2,3,3,4,4,4,4,5,6};
	int N = sizeof(d)/sizeof(int);//�}�C������
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