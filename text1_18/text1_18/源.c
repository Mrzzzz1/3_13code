//#include<stdio.h>
//int main(){
//	char a[5];
//	scanf("%s", a);
//	for (int i = 3; i >= 0; i--)
//		printf("%c", a[i]);
//}
#include<stdio.h>
#include<math.h>
int find(int, int);
//int main(){
//	int n, x,sum=0;
//	scanf("%d %d", &n, &x);
//	int b=0;
//	for (int a=n; a = a / 10;)b++;
//	for (int i = 0; i <= b; i++){
//		int c = n / (int)pow(10, i), d = 0;
//		if (c % 10 > x){
//			d++;
//			if (x == 0)d--;
//			d += c / 10;
//			sum +=d*(int)pow(10, i);
//		}
//		else if (c % 10 == x){
//			d += c / 10;
//			if (x == 0){
//				d--;
//				if (i == b)break;
//			}
//			
//			sum += d*(int)pow(10, i);
//			sum += n % (int)pow(10, i) + 1;
//		}
//		else{
//			if (x == 0)d--;
//			d += c / 10;
//			sum += d*(int)pow(10, i);
//		}
//	}
//	printf("%d", sum);
//}
//
//#include<stdio.h>
//int main(){
//	int budget, sum = 0, save = 0, i;
//	for (i = 1; i <= 12; i++){
//		scanf("%d", &budget);
//		if (budget>300+sum){
//			i = -i;
//			printf("%d", i);
//			break;
//		}
//		sum += 300 - budget;
//		save += sum / 100;
//		sum = sum % 100;
//	}
//	if (i == 12)printf("%d", sum + save * 120);
//
//}
//#include<stdio.h>
//int main(){
//	int N, i, j, k;
//	scanf("%d", &N);
//	int a[40][40] = { 0 };
//	a[0][N / 2] = 1;
//	for (k = 2, i = 0, j = N / 2; k <= N*N; k++){
//		if (i == 0 && j != N - 1){
//			i = N - 1; j = j + 1;
//		}
//		else if (j == N - 1 && i != 0){
//			j = 0; i = i - 1;
//		}
//		else if (i == 0 && j == N - 1){
//			i = 1; j = N - 1;
//		}
//		else if (a[i - 1][j + 1] == 0){
//			i = i - 1; j = j + 1;
//		}
//		else i = i + 1;
//		a[i][j] = k;
//	}
//	for (i = 0; i < N; i++){
//		for (j = 0; j < N; j++){
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//#include<stdio.h>
//int main(){
//	int n, i, j = 1, sum = 0;
//	scanf("%d", &n);
//		for (i = 0; sum<=n; i++){
//			for (;j++; ){
//				if (iszs(j))break;
//			}
//			sum += j;
//			if (sum <= n)printf("%d\n", j);
//		}
//		printf("%d", i);
//}
//
//int iszs(int x){
//	for (int i = 2; i <= x / 2; i++){
//		if (x%i == 0)return 0;
//	}
//	return 1;
//}
//#include<stdio.h>
//#include<string.h>
//void reverse(int a[], int b[], int n);
//int add(int a[], int b[], int sum[], int n, int m);
//int isPalindrome(int arr[], int len);
//
//int main(){
//	int n, i;
//	scanf("%d", &n);
//	char tmp[100];
//	int a[100], b[100], c[200] = { 0 };
//	scanf("%s", tmp);
//	int len = strlen(tmp);
//	for (i = 0; i<len; i++){
//		if (tmp[i] >= '0'&&tmp[i] <= '9')a[i] = tmp[i] - '0';
//		else if (tmp[i] >= 'a'&&tmp[i] <= 'f')a[i] = tmp[i] - 'a' + 10;
//		else a[i] = tmp[i] - 'A' + 10;
//		b[len - i - 1] = a[i];
//
//	}
//	for (i = 0; i <= 30; i++){
//		if (isPalindrome(a,len)){
//			printf("STEP=%d", i);
//			return 0;
//		}
//
//		len = add(a, b, c, len, n);
//		reverse(c, b, len);
//		reverse(b, a, len);
//
//	}
//	printf("Impossible!");
//}
//void reverse(int a[], int b[], int n){
//	for (int i = 0; i<n; i++){
//		b[i] = a[n - i - 1];
//	}
//}
//int add(int a[], int b[], int sum[], int n,int m){
//	for (int i = 0; i<n; i++)
//		sum[i] = a[i] + b[i];
//	int i = 0;
//	while (i<n || sum[i] != 0){
//		if (sum[i] >= m){
//			sum[i + 1] += sum[i] / m;
//			sum[i] = sum[i] % m;
//		}
//		i++;
//	}
//	return i;
//}
//int isPalindrome(int arr[], int len){
//	if (len <= 1)
//		return 1;
//	if (arr[0] != arr[len - 1])
//		return 0;
//	return(isPalindrome(arr + 1, len - 2));
//}
//#include<stdio.h>
//#include<string.h>
//int main(){
//	int a, b, c;
//	char arr[200] = { 0 }, arr1[10000] = { 0 };
//	scanf("%d %d %d", &a, &b, &c);
//	scanf("%s", arr);
//	int len = strlen(arr);
//	int i = 0, j = 0;
//	for (; i<len;){
//		if (arr[i + 1] == '-' && ((arr[i] <= '9'&&arr[i] >= '0'&&arr[i + 2] <= '9'&&arr[i + 2] >= '0'&&arr[i]<arr[i + 2]) || (arr[i] <= 'z'&&arr[i] >= 'a'&&arr[i + 2] <= 'z'&&arr[i + 2] >= 'a'&&arr[i]<arr[i + 2])))
//		{
//			arr1[j++] = arr[i];
//			if (arr[i] <= '9'&&arr[i] >= '0'){
//
//				for (int x = 1; arr[i] + x<arr[i + 2]; x++){
//					for (int y = 0; y<b; y++){
//						if (a == 3)arr1[j++] = '*';
//						else {
//							if (c == 1)arr1[j++] = arr[i] + x;
//							else arr1[j++] = arr[i + 2] - x;
//
//						}
//					}
//				}
//			}
//			else{
//				for (int x = 1; arr[i] + x<arr[i + 2]; x++){
//					for (int y = 0; y<b; y++){
//						if (a == 3)arr1[j++] = '*';
//						else if (a == 1){
//							if (c == 1)arr1[j++] = arr[i] + x;
//							else arr1[j++] = arr[i + 2] - x;
//
//						}
//						else{
//							if (c == 1)arr1[j++] = arr[i] - 'a' + 'A' + x;
//							else arr1[j++] = arr[i + 2] - x - 'a' + 'A';
//
//						}
//					}
//				}
//
//			}
//			i+=2;
//		}
//		else{
//			arr1[j++] = arr[i++];
//		}
//	}
//	arr1[j] = 0;
//	printf("%s", arr1);
//
//}
//#include<stdio.h>
//#include<string.h>
//int main(){
//	char a[101], b[1001], c[1001];
//	scanf("%s %s", a, b);
//	int lenb = strlen(b);
//	int lena = strlen(a), j = 0, i;
//	for (i = 0; i<lenb; i++){
//		if (a[j] >= 'a'&&a[j] <= 'z'){
//            c[i] = b[i] - (a[j] - 'a');
//			if (b[i] >= 'a'&&c[i]<'a' || b[i]>='A'&&c[i] < 'A')
//				c[i] += 26;
//		}
//			
//		else {
//			c[i] = b[i] - (a[j] - 'A');
//			if (b[i] >= 'a'&&c[i]<'a' || b[i]>='A'&&c[i] < 'A')
//				c[i] += 26;
//		}
//		j++;
//		if (j == lena)j = 0;
//	}
//	c[i] = 0;
//	printf("%s", c);
//}
//#include<stdio.h>
//#include<string.h>
//void mySort(char a[], int n);
//
//int main(){
//	int n, m;
//	char a[100], b[100], c[100];
//	scanf("%d", &n);
//	scanf("%s", a);
//	scanf("%d", &m);
//	m = m - 1;
//	for (int i = 0; i <= n; i++)b[i] = a[i];
//	mySort(a, n);
//	for (int k = 0; k<n; k++){
//		if (a[k] == b[m]){
//			m = k;
//			break;
//		}
//	}
//	for (int i = n-1; i >= 0; i--){
//		c[i] = b[m];
//		a[m] = 0;
//		for (int j = n - 1; j >= 0; j--){
//			if (a[j] == b[m]){
//				m = j;
//				break;
//			}
//		}
//	}
//	c[n] = 0;
//	printf("%s", c);
//
//}
//void mySort(char a[], int n){
//	for (int i = 0; i<n - 1; i++){
//		for (int j = 0; j<n - 1 - i; j++){
//			if (a[j] > a[j + 1]){
//				char tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//}
#include<stdio.h>
struct student{
	int num;
	int chi;
	int math;
	int eng;
	int sum;
};
int main(){
	int n;
	scanf("%d", &n);
	struct student stu[100];
	for (int i = 0; i<n; i++){
		stu[i].num = i + 1;
		scanf("%d %d %d", &stu[i].chi, &stu[i].math, &stu[i].eng);
		stu[i].sum = stu[i].chi + stu[i].math + stu[i].eng;
	}
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if ((stu[j].sum < stu[j + 1].sum) || (stu[j].sum == stu[j + 1].sum&&stu[j].chi<stu[j + 1].chi)){
				struct student tmp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = tmp;
				}
		}
	}
	for (int i = 0; i < 5; i++){
		printf("%d %d\n", stu[i].num, stu[i].sum);
	}
}