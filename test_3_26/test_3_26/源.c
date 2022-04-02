//#include<stdio.h>
//#include<string.h>
//int ans = 0;
//int fd(){
//	int a;
//	scanf("%d", &a);
//	return a;
//}
//int bk(){
//	int a;
//	scanf("%d", &a);
//	return a;
//}
//int repeat(){
//	char a, b[10];
//	int c, now = 0,i=0;
//	scanf("%d", &c);
//	
//	
//	while ((a = getchar()) != ']'){
//		scanf("%s", b);
//		switch (b[0]){
//		case'F':now += fd();
//			break;
//		case'B':now -= bk();
//			break;
//		case'R':now += repeat();
//			break;
//		default:goto q;
//		}
//	}
//
//q:	return now*c;
//}
//int main(){
//	char a=0;
//	char b[10];
//	 while (a != '\n'){
//		scanf("%s", b);
//		switch (b[0]){
//		case'F':ans += fd();
//			break;
//		case'B':ans -= bk();
//			break;
//		case'R':ans += repeat();
//			break;
//		default:printf("%d", ans);
//			return 0;
//		}a = getchar();
//
//	}
//	printf("%d", ans);
//}
//#include<stdio.h>
//#include<string.h>
//int ans = 0;
//int fd(){
//	int a;
//	scanf("%d", &a);
//	return a;
//}
//int bk(){
//	int a;
//	scanf("%d", &a);
//	return a;
//}
//int repeat(){
//	char a, b[10];
//	int c, now = 0, i = 0;
//	scanf("%d", &c);
//
//
//	while ((a = getchar()) == ' ' || a == '['){
//		scanf("%s", b);
//		switch (b[0]){
//		case'F':now += fd();
//			break;
//		case'B':now -= bk();
//			break;
//		case'R':now += repeat();
//			break;
//		default:goto q;
//		}
//	}
//
//q:	return now*c;
//}
//int main(){
//	char a = ' ';
//	char b[10];
//	while (a != '\n'){
//		scanf("%s", b);
//		switch (b[0]){
//		case'F':ans += fd();
//			break;
//		case'B':ans -= bk();
//			break;
//		case'R':ans += repeat();
//			break;
//		}a = getchar();
//
//	}
//	printf("%d", ans);
//}