
//P1160
//#include<stdio.h>
//int stu[100001][3];//0为号码，1为左边同学号码，2为右边
//int main(){
//	int n,m;
//	scanf("%d", &n);
//	stu[1][0] = 1;
//	for (int i = 2; i <= n; i++){
//		int locat, direc;
//		scanf("%d %d", &locat, &direc);
//		stu[i][0] = i;
//		if (direc){
//			stu[i][1] = locat;
//			stu[i][2] = stu[locat][2];
//			stu[stu[locat][2]][1] = i;
//			stu[locat][2] = i;
//		}
//		else{
//			stu[i][2] = locat;
//			stu[i][1] = stu[locat][1];
//			stu[stu[locat][1]][2] = i;
//			stu[locat][1] = i;
//		}
//	}
//	scanf("%d", &m);
//	for (int i = 1; i <= m; i++){
//		int stu1;
//		scanf("%d", &stu1);
//		if (stu[stu1][0]){
//			stu[stu1][0] = 0;
//			stu[stu[stu1][1]][2] = stu[stu1][2];
//				stu[stu[stu1][2]][1] = stu[stu1][1];
//		}
//	}
//	int now = stu[0][2];
//	//while (stu[now][0] == 0&&now)now = stu[now][2];
//	while (stu[now][0] ){
//		printf("%d ", stu[now][0]);
//		now = stu[now][2];
//	}
//}
//P1044 DFS......TLE代码
//#include<stdio.h>
//int ans = 0,n;
//void dfs(int num0, int num1){//0入栈，1出栈
//	if (num1 == n){
//		ans++;
//
//	}
//	else if (num0 == n || num0 == num1){
//		dfs(num0 , num1+1);
//	}
//	else{
//		dfs(num0 + 1, num1);
//		dfs(num0, num1 + 1);
//	}
//}
//int main(){
//	scanf("%d", &n);
//	dfs(0, 0);
//	printf("%d", ans);
//}


//AC代码
//#include<stdio.h>
//int  n;
//int arr[20][20];
//int dfs(int i, int j){
//	if (i == 0)return 1;
//	if (arr[i][j])return arr[i][j];
//	if (j>0)arr[i][j] += dfs(i, j - 1);
//	arr[i][j] += dfs(i - 1, j + 1);
//	return arr[i][j];
//}
//int main(){
//	scanf("%d", &n);
//	printf("%d",dfs(n, 0) );
//}

//P1449 后缀表达式
//#include<stdio.h>
//int main(){
//	int arr[1000], p=-1,p1=0;
//	char a, b[100];
//	while ((a = getchar()) != '@'){
//		if (a == '+'){
//			arr[p - 1] = arr[p] + arr[p - 1];
//			p--;
//		}
//		else if (a == '-'){
//			arr[p - 1] = arr[p-1] - arr[p];
//			p--;
//		}
//		else if (a == '*'){
//			arr[p - 1] = arr[p] *arr[p - 1];
//			p--;
//		}
//		else if (a == '/'){
//			arr[p - 1] = arr[p-1] / arr[p];
//			p--;
//		}
//		else {
//			b[p1++] = a;
//			while ((a = getchar()) != '.')b[p1++] = a;
//			int sum = 0,wei=1;
//			for (int i = p1 - 1; i >= 0; i--){
//				sum += (b[i]-'0') * wei;
//				wei *= 10;
//			}
//			arr[++p] = sum;
//			p1 = 0;
//		}
//	}
//	printf("%d", arr[0]);
//}
