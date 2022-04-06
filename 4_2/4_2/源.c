//P3884
//#include<stdio.h>
//int deep[105], wid[105];//每根结点的深度和每层的宽度
//typedef struct{
//	int next, to;//根节点的上一根树枝和这跟树枝指向
//}edge;
//edge edgeN[105];
//int cnt;//边数
//int head[105];//每个结点的最后一根树枝
//int fa[105];//存放每个节点的父节点
//int deepmax,widmax;
//void addEdge(int from, int to){
//	edgeN[++cnt].next = head[from];
//	edgeN[cnt].to = to;
//	head[from] = cnt;
//}
//int main(){
//	int n;
//	scanf("%d", &n);
//	deep[1] = 1;
//	wid[1] = 1;
//	int from, to;
//	for (int i = 1; i < n; i++){
//		scanf("%d%d", &from, &to);
//		addEdge(from, to);
//		deep[to] = deep[from] + 1;
//		deepmax = deepmax > deep[to] ? deepmax : deep[to];
//		wid[deep[to]]++;
//		fa[to] = from;
//	}
//	printf("%d\n", deepmax);
//	int j = 0;
//	while (wid[++j])widmax = widmax > wid[j] ? widmax : wid[j];
//	printf("%d\n", widmax);
//	int u, v;
//	scanf("%d%d", &u, &v);
//	int bothFa,deepu=deep[u],deepv=deep[v];
//	while (u!=v){
//		if (deep[u]>deep[v])u = fa[u];
//		else if (deep[u] > deep[v])v = fa[v];
//		else {
//			u = fa[u]; v = fa[v];
//		}
//	}bothFa = u;
//	int dis = (deepu - deep[bothFa]) * 2 + deepv - deep[bothFa];
//	printf("%d", dis);
//	
//}
//P1827
//#include<stdio.h>
//#include<string.h>
//char a[30],b[30];
//char Root[30];
//int cnt;
//void findRoot(int index1, int index2, int index3, int index4){
//	if (index1 > index2)return;
//	char root = b[index3];
//	Root[cnt--] = root;
//	int i;
//	for (i = index1;; i++){
//		if (a[i] == root)break;
//	}findRoot(i + 1, index2, index4 - (index2 - 1 - i), index4);
//	findRoot(index1, i - 1, index3 + 1, index3 + i - index1);
//	
//}
//int main()
//{
//	scanf("%s%s", a, b);
//	int n = strlen(a);
//	cnt = n - 1;
//	findRoot(0, n - 1,0,n-1);
//	printf("%s", Root);
//}
//P4913
//#include<stdio.h>
//int sub[1000005][2];
//int deep[1000005];
//int max = 1; void dfs(int root, int step){
//	if (root == 0) return;//如果该节点为0（即上它的爸爸没有这个儿子），返回
//	max = max>step?max:step;//记录最大值
//	dfs(sub[root][0], step + 1);//搜索它的左儿子
//	dfs(sub[root][1], step + 1);//搜索它的右儿子
//}
//void findDeep(int fa){
//	if (sub[fa][0]){
//		deep[sub[fa][0]] = deep[fa] + 1;
//		max = max > deep[sub[fa][0]] ? max : deep[sub[fa][0]];
//		findDeep(sub[fa][0]);
//	}
//	if (sub[fa][1]){
//		deep[sub[fa][0]] = deep[fa] + 1;
//		max = max > deep[sub[fa][1]] ? max : deep[sub[fa][1]];
//		findDeep(sub[fa][1]);
//	}
//	
//	
//}
//int main(){
//	int n;
//	scanf("%d", &n);
//	deep[1] = 1;
//	int a, b;
//	for (int i = 1; i <=n; i++){
//		scanf("%d%d", &a, &b);
//		sub[i][0] = a;
//		sub[i][1] = b;
//	}
//	dfs(1,1);
//	printf("%d", max);
//
//}
//P1185
//#include<stdio.h>
//#include<math.h>
//char tree[800][1600];
//int flag[11][521];
//int m, n;
//int large(int n){
//	if (n == 1)return 1;
//	else return 3*pow(2,n-2);
//}
//draw(int i, int j, int row, int line){
//	tree[i][j] = 'o';
//	if (row == m)return;
//	if (!flag[row + 1][line * 2 - 1]){
//		int k;
//		for (k = 1; k < large(m-row+1) - large(m-row); k++){
//			tree[i + k][j - k] = '/';
//		}
//		draw(i + k, j - k, row + 1, line * 2 - 1);
//	}
//	if (!flag[row + 1][line * 2]){
//		int k;
//		for (k = 1; k < large(m-row+1) - large(m-row); k++){
//			tree[i + k][j + k] = '\\';
//		}
//		draw(i + k, j + k, row + 1, line * 2 );
//	}
//}
//int main(){
//	scanf("%d%d", &m, &n);
//	int i, j;
//	for (int k = 0; k < n; k++){
//		scanf("%d%d", &i, &j);
//		flag[i][j] = 1;
//	}
//	for (int i = 0; i < large(m); i++)
//		for (int j = 0; j < 6*pow(2,m-2)-1; j++)
//			tree[i][j] = ' ';
//	draw(0, large(m)-1, 1, 1);
//	for (int i = 0; i <= large(m); i++){
//		printf("%s\n", tree[i]);
//	}
//}
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int to;
	struct node *next, *front;
}node;
node* a[100005];
int n, m;
int flag[100005];
void insert(int from, int to){
	if (a[from] == NULL){
		node *p = (node*)malloc(sizeof(node));
		p->to = to;
		p->front = NULL;
		p->next = NULL;
		a[from] = p;
	}
	else{
		node** p1 = &a[from];
		while ((*p1)->next != NULL){
			if ((*p1)->to <= to)
				*p1 = (*p1)->next;
		}
	}

}
int main(){
	scanf("%d", &n, &m);
	int from, to;
	for (int i = 1; i <= m; i++){
		scanf("%d%d", &from, &to);
		insert(from, to);
	}

}