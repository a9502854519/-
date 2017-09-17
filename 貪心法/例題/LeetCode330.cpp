/* 假設數列的總和為m。再假設我們能保證[1, m]中所
 * 有的數字能被組成，則下一個要添加的數字必為m+1
 * 添加了m+1後，問題就變成，能不能確保[m+1, 2m+1]
 * 中所有的數字能不能被組成？將其減去m+1後，就變
 * 成[0, m]，答案是：可以的。
 * 用數學歸納法證明，大致上如下
 * (1)證明m = 1時成立
 *      m = 1時，區間[1, 1]間所有的數字都可以被組
 *      成。則下一個要添加的數字為2，添加後，[2, 3]
 *      之間的數字可以被組成。m = 1時成立。
 * (2)假設m = k時，區間[1, k]間所有的數字都可以被組成
 *      則下一個要添加的數字為k+1....巴拉巴拉，上
 *      面都寫了，我懶得再打一次。得證。
 */
int minPatches(int* nums, int numsSize, int n) {
	long long int sum = 0;//總和
	int index = 0;
	int count = 0;
	while(sum < n){
			if(sum+1 >= nums[index] && index < numsSize){
				//如果陣列中的數字小於等於sum+1，代表不用
				//添加新的數字
				sum+=(long long)nums[index++];
			}
			else{
				//反之，添加一個sum+1，計數+1。
				sum = 2*sum+1;
				count++;
			}
	}
	return count;
}