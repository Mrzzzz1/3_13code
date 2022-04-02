//P3719
//#include<stdio.h>
//int max(int a, int b){
//	if (a > b)return a;
//	else return b;
//}
//int ans(int k){
//	char c;
//	while (scanf("%c", &c),c != '\n'){
//		if (c == 'a')k++;
//		else if (c == '|')return max(k, ans(0));
//		else if (c == '(')k += ans(0);
//		else return k;
//	}
//	return k;
//}
//int main(){
//	printf(ans(0));
//	return 0;
//}
//P3375 KMP
//#define maxn 1000005
//#include<stdio.h>
//#include<string.h>
//char a[maxn], b[maxn];
//int next[maxn];
//void findNext(int n){
//	next[1] = 0;
//	int k;
//	for (int i = 2; i <= n; i++){
//		k = next[i - 1];
//		if (b[k] == b[i - 1])next[i] = k + 1;
//		else {k = next[k];
//			while (k > 0){
//				
//				if (b[i - 1] != b[k])k = next[k];
//				else break;
//			}next[i] = k + 1;
//
//		}
//	}
//
//}
//void match(){
//	int i = 1, j = 1;
//	while (a[i] != '\0'){
//		if (b[j] == '\0'){
//			printf("%d\n", i - j + 1);
//			j = next[j];
//		}
//		else if (a[i] == b[j]){
//			i++;
//			j++;
//		}
//		else{
//			if (j == 1)i++;
//			else j = next[j];
//
//		}
//
//	}if (b[j] == '\0')printf("%d\n", i - j + 1);
//}
//int main(){
//	scanf("%s", a + 1);
//	scanf("%s", b + 1);
//	int n = strlen(b + 1);
//	findNext(n + 1);
//	match();
//	for (int i = 1; i <= n; i++){
//		printf("%d ", next[i + 1] - 1);
//	}
//
//
//}
//P1030
//#include<stdio.h>
//char a[10];
//char b[10];
//void dp(int index1, int index2, int index3, int index4){
//	if (index1 > index2)return;
//	char root = b[index4];
//	printf("%c", root);
//	int i;
//	for (i = index1;; i++){
//		if (a[i] == root)break;
//	}
//	dp(index1, i - 1, index3, index3 + i - index1-1);
//	dp(i + 1, index2, index3 + i - index1, index4-1);
//
//
//}
//int main(){
//	
//	scanf("%s", a);
//	scanf("%s", b);
//	int n = strlen(b);
//	dp(0, n - 1, 0, n - 1);
//
//}
//#include<stdio.h>
//#include<math.h>
//char a[1030];
//void print(int index1, int index2){
//	int flag0 = 0, flag1 = 0;
//	for (int i = index1; i <= index2; i++){
//		if (a[i] == '0')flag0 = 1;
//		else flag1 = 1;
//		if (flag0 == 1 && flag1 == 1)break;
//
//	}
//	if (flag0&&flag1)printf("F");
//	else if (flag1)printf("I");
//	else printf("B");
//
//
//}
//void ans(int index1,int index2){
//	if (index2 > index1){
//		ans(index1, index1 + (index2 - index1 + 1) / 2-1);
//		ans(index1 + (index2 - index1 + 1) / 2, index2);
//	}
//	print(index1, index2);
//
//
//}
//
//int main(){
//	int n;
//	scanf("%d", &n);
//	scanf("%s", a+1);
//	n = pow(2, n);
//	ans(1, n);
//
//
//}
//P1131
#include<stdio.h>
#define MAX 1000005
int head[MAX];//head[i]表示输入的最后一条指向i结点的边
typedef struct {
	int next;//与此边同起点的上一条边
	int to;//此边指向的结点
	int dis;//权值
}edge;
 edge edgeN[MAX];
long long max[MAX];//max[i]表示到i结点的子结点的最大权值
long long ans;//答案
int n, s, a, b, t, cnt;
void addEdge(int from, int to,int t){
	edgeN[++cnt].next = head[from];
	edgeN[cnt].to = to;
	edgeN[cnt].dis = t;
	head[from] = cnt;

}
int maxOf(int a, int b){
	if (a > b)return a;
	return b;
}
dfs(int x, int fa){
	for (int i = head[x]; i;i=edgeN[i].next){
		if (edgeN[i].to != fa)dfs(edgeN[i].to, x);
	}//搜索至叶
	for (int i = head[x]; i; i = edgeN[i].next){
		if (edgeN[i].to != fa)max[x] = maxOf(max[x], edgeN[i].dis);
	}//搜索到x的最大权值
	for (int i = head[x]; i; i = edgeN[i].next){
		if (edgeN[i].to != fa)ans += max[x] - edgeN[i].dis;
	}//维护答案
	for (int i = head[fa]; i; i = edgeN[i].next){
		if (edgeN[i].to == x) edgeN[i].dis += max[x];
	}
}
int main(){
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n - 1; i++){
		scanf("%d%d%d", &a, &b, &t);
		addEdge(a, b, t);
		addEdge(b, a, t);
	}
	dfs(s, 0);
	printf("%lld", ans);
}