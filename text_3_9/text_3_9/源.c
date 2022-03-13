//CF44C 
//#include<stdio.h>
//int main(){
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int flower[101] = { 0 };
//	for (int i = 1; i <= m; i++){
//		int start, end;
//		scanf("%d %d", &start, &end);
//		for (int j = start; j <= end; j++)flower[j]++;
//	}
//	for (int i = 1; i < n; i++){
//		if (flower[i] != 1){
//          printf("%d %d", i, flower[i]);
//		  return 0;
//		}
//			
//	}
//	printf("OK");
//}
//P2367 差分
//#include<stdio.h>
//int d[5000002];
//int main(){
//	int n, p, score;
//	scanf("%d %d", &n, &p);
//	scanf("%d", &d[1]);
//	int scoreleft = d[1];
//	for (int i = 2; i <= n; i++){
//		scanf("%d", &score);
//		d[i] = score - scoreleft;
//		scoreleft = score;
//	}
//	for (int i = 1; i <= p; i++){
//		int start, end, add;
//		scanf("%d %d %d", &start, &end, &add);
//		d[start] += add;
//		d[end + 1] -= add;
//	}
//	int min = d[1];
//	score = d[1];
//	for (int i = 2; i <= n; i++){
//		score += d[i];
//		min = min>score ? score : min;
//	}
//	printf("%d", min);
//
//
//}
//P6510 单调栈
#include<stdio.h>
#define amax 100005
int up[amax][2];//单调增栈，存下标和高度
int down[amax][2];//单调减栈
int half(int p1, int left, int right){
	if (up[p1][0] < down[left][0])return down[left][0];
	int mid = (left + right + 1) / 2;
	if (mid >= right)return down[right][0];
	if (up[p1][0] < down[mid][0])return half(p1, left, mid);
	else return half(p1, mid, right);
}
int main(){
	int n;
	scanf("%d", &n);
	int p1 = 1, p2 = 1, ans = 0, now, ansnow;
	scanf("%d", &now);
	up[1][0] = 1;
	up[1][1] = now;
	down[1][0] = 1;
	down[1][1] = now;
	for (int i = 2; i <= n; i++){
		scanf("%d", &now);
		while (up[p1][1] < now&&p1 >= 1)p1--;
		if (p1 < i - 1){

			ansnow = i - half(p1, 1, p2) + 1;
			if (ansnow > ans)ans = ansnow;
		}
		up[++p1][0] = i;
		up[p1][1] = now;
		while (down[p2][1] >= now&&p2>0)p2--;
		down[++p2][0] = i;
		down[p2][1] = now;
	}
	printf("%d", ans);
}