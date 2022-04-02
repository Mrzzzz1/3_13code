//P1553
//#include<stdio.h>
//int main(){
//	char d[35], e[35];
//	char c, a;
//	int n = -1;
//	while (c = getchar()){
//		if (c >= '0'&&c <= '9')d[++n] = c;
//		else break;
//	}
//	int i = 0;
//	while (d[n] == '0' && n > i)n--;
//	if (c != '\n'&&c != '%'){
//		int m = -1;
//		while ((a = getchar()) >= '0'&&a <= '9')e[++m] = a;
//		int j = 0;
//		if (c == '.')while (e[j] == '0' && j < m)j++;
//		else while (e[m] == '0' && m > 0)m--;
//		while (i <= n)printf("%c", d[n--]);
//		printf("%c", c);
//		while (j <= m)printf("%c", e[m--]);
//
//	}
//	else{
//		while (i <= n)printf("%c", d[n--]);
//		if (c == '%')
//			printf("%c", c);
//
//	}
//}
//	
#include<stdio.h>
int ans = 0;
int fd(){
	int a;
		scanf("%d", &a);
		return a;
}
int bk(){
	int a;
	scanf("%d", &a);
	return a;
}
int repeat(){
	char a,b[10];
	int c,now=0;
	scanf("%d", &c); 
	while ((a = getchar()) != ']'){
		scanf("%s", b);
		switch (b[0]){
		    case'F':now += fd();
			break;
			case'B':now -= bk();
				break;
			case'R':now += repeat();
		}
	}
	return now*c;
}
int main(){
	char a=1;
	char b[10];
	while (a != '\n');{
		scanf("%s", b);
		switch (b[0]){
		case'F':ans += fd();
			break;
		case'B':ans -= bk();
			break;
		case'R':ans += repeat();
		}
		a = getchar();
	} //
	printf("%d", ans);
}