//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//unsigned long long base = 233;
//unsigned long long a[10005];
//char s[10005];
//int ans = 0;
//unsigned long long hashstring(char s[])
//{
//	int len = strlen(s);
//	unsigned long long ans = 0;
//	for (int i = 0; i<len; i++)
//		ans = ans*base + (unsigned long long)s[i];
//	return ans & 0x7fffffff;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%s", s);
//		a[i] = hashstring(s);
//	}
//	sort(a + 1, a + n + 1);
//	for (int i = 2; i <= n; i++)
//		if (a[i] != a[i - 1])
//			ans++;
//	printf("%d\n", ans+1);
//}
//#include<bits/stdc++.h>
//#include<map>
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//map<string, int>num;
//map<string, bool>tag;
//string s[100001],str;
//int main(){
//	int n,ans1=0,ans2=0;
//	cin >> n;
//	for (int i = 0; i < n; i++){
//		cin >> str;
//		tag[str] = 1;
//	}
//	int m, left=1;
//	cin >> m;
//	for (int i = 1; i <= m; i++){
//		cin >> s[i];
//		if (tag[s[i]])num[s[i]]++;
//		if (num[s[i]] == 1)ans1++, ans2 = i - left + 1;
//		while (left <= i){
//			if (!tag[s[left]]){
//				left++;
//			    continue;
//			}
//			if (num[s[left]] >= 2){ 
//				num[s[left]]--;
//				left++;
//				continue;
//			}
//			break;
//		}
//		ans2 = min(ans2, i - left + 1);
//	}
//	cout << ans1 << endl << ans2 << endl;
//
//
//}
//#include<iostream>
//using namespace std;
//int n, a[5000005], b[5000005];
//long long ans;
//void Msort(int left, int right){
//	if (left == right)return;
//	int mid = (left + right) / 2;
//	Msort(left, mid);
//	Msort(mid + 1, right);
//	int i = left;
//	int j = mid + 1;
//	int now = left;
//	while (i <= mid && j <= right)
//	{
//		if (a[i] > a[j])
//		{
//			ans += mid - i + 1;
//			b[now++] = a[j++];
//		}
//		else
//		{
//			b[now++] = a[i++];
//		}
//	}
//	while (i <= mid)
//	{
//		b[now++] = a[i];
//		++i;
//	}
//	while (j <= right)
//	{
//		b[now++] = a[j];
//		++j;
//	}
//	for ( int i = left; i <= right; ++i)
//	{
//		a[i] = b[i];
//	}
//	return;
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for ( int i = 1; i <= n; ++i)
//	{
//		cin >> a[i];
//	}
//	Msort(1, n);
//	printf("%lld", ans);
//	return 0;
//}
//#include <bits/stdc++.h>
//#include<iostream>
//#define maxn 200005
//using namespace std;
//typedef struct Per{
//	int num;
//	int mask;
//}Per;
//Per a[maxn];
//Per b[maxn / 2];
//Per c[maxn / 2];
//int powe[maxn];
//int n, r, q;
//bool cmp(Per a, Per b)
//{
//	if (a.mask == b.mask)
//		return a.num<b.num;
//	return a.mask>b.mask;
//}
//void Msort(){
//	int i = 1, j = 1, k = 1;
//	while (i <= n && j <= n)
//	{
//		if (b[i].mask > c[j].mask || (b[i].mask == c[j].mask && b[i].num < b[j].num))
//		{
//			a[k].mask = b[i].mask;
//			a[k++].num = b[i++].num;
//		}
//		else{
//			a[k].mask = c[j].mask;
//			a[k++].num = c[j++].num;
//		}
//	}
//	while (i <= n)
//	{
//		a[k].mask = b[i].mask;
//		a[k++].num = b[i++].num;
//	}
//	while (j <= n)
//	{
//		a[k].mask = c[j].mask;
//		a[k++].num = c[j++].num;
//	}
//}
//int main(){
//	cin >> n >> r >> q;
//	for (int i = 1; i <= 2 * n; i++){
//		a[i].num = i;
//		cin >> a[i].mask;
//	}
//	for (int i = 1; i <= 2 * n; i++)cin >> powe[i];
//	sort(a + 1, a + 2*n + 1, cmp);
//	for (int k = 1; k <= r; k++)
//	{
//		int now = 1;
//		for (int i = 1; i<2 * n; i += 2)
//		{
//			if (powe[a[i].num]>powe[a[i + 1].num])
//			{
//				b[now].mask = a[i].mask + 1;
//				b[now].num = a[i].num;
//				c[now].mask = a[i + 1].mask;
//				c[now].num = a[i + 1].num;
//				now++;
//			} else {
//				b[now].mask = a[i + 1].mask + 1;
//				b[now].num = a[i + 1].num;
//				c[now].mask = a[i].mask;
//				c[now].num = a[i].num;
//				now++;
//			}
//		}
//		Msort();
//	}
//	cout << a[q].num;
//	return 0;
//
//}
//#include<bits/stdc++.h>
//using namespace std;
//int n, x, ans;
//priority_queue<int>q;
//int main(){
//	cin >> n;
//	for (int i = 1; i <= n; i++){
//		cin >> x;
//		q.push(x);
//	} 
//	while (q.size() >1){
//		int a = q.top();
//		q.pop();
//		int b = q.top();
//		q.pop();
//		ans += a + b;
//		q.push(ans);
//	}
//	cout << ans;
//	return 0;
//}
#include<map>
#include<iostream>
using namespace std;
map<int, int>map1;
int main(){
	int a,m,n,q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		cin >> a;
		map1[a] = i+1;
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		scanf("%d", &m);
		printf("%d\n", map1[m]);
	}
}