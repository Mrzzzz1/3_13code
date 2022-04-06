//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
// struct edge{
//	int from, to;
//};
//
// vector <int> e[100001]; 
// vector <edge> s;
// bool flag1[100001] = { 0 }, flag2[100001] = { 0 };
// bool cmp(edge a, edge b){  
//	 if (a.to==b.to)
//		 return a.from<b.from;
//	 else return a.to<b.to;
// }
//
// void dfs(int x){  
//	 flag1[x] = 1;
//	 cout << x << " ";
//	 for (int i = 0; i<e[x].size(); i++){
//		 int point = s[e[x][i]].to;
//		 if (!flag1[point]){
//			 dfs(point);
//		 }
//	 }
// }
// void bfs(int x){  
//	   queue <int> q;
//	  q.push(x);
//	    cout << x << " ";
//
//	   flag2[x] = 1;
//	   while (!q.empty()){
//		  int from = q.front();
//		    for (int i = 0; i<e[from].size(); i++){
//
//			     int p = s[e[from][i]].to;
//			     if (!flag2[p]){
//				 q.push(p);
//				 cout << p << " ";
//				 flag2[p] = 1;
//			 }
//		 }
//		 q.pop();
//	 }
// }
// int main(){
//	 int n, m;  
//	 cin >> n >> m;
//	 for (int i = 0; i<m; i++){
//		 int from, to;
//		 cin >> from >> to;
//		 s.push_back(edge({ from, to }));
//	 }
//	 sort(s.begin(), s.end(), cmp);  
//	 for (int i = 0; i<m; i++)
//		 e[s[i].from].push_back(i);
//	 dfs(1);  
//	 cout << endl;
//	 bfs(1);  
// }
//P3956 DFS+剪枝
//#include<iostream>
//using namespace std;
//int col[105][105];
//int flag[105][105];
//int min1[105][105][2];
//int m, n;
//int ans=-1;
// void dfs(int row, int line, int color, int flag1,int now){
//	 if (col[row][line]){
//		 flag1 = 0;
//		 if (col[row][line] != color)now += 1;
//		 
//	 }
//	 else{
//		 if (flag1 == 0){
//			 now += 2;
//			 flag1 = 1;
//		 }
//		 else return;
//	 }
//	 if (row == m&&line == m){
//		 if (ans > 0)ans = ans < now ? ans : now;
//		 else ans = now;
//		 return;
//	 }
//	 if (min1[row][line][flag1]){
//		 if (min1[row][line][flag1] <= now)return;
//		 
//	 }
//	 min1[row][line][flag1] = now;
//
//	 if (flag1 == 0)color = col[row][line];
//		 if (row - 1 > 0 && flag[row - 1][line] == 0){
//			 flag[row - 1][line] = 1;
//			 dfs(row - 1, line, color, flag1, now);
//			 flag[row - 1][line] = 0;
//		 }
//		 if (row + 1 <= m && flag[row + 1][line] == 0){
//			 flag[row + 1][line] = 1;
//			 dfs(row + 1, line, color, flag1, now);
//			 flag[row + 1][line] = 0;
//		 }
//		 if (line - 1 > 0 && flag[row][line-1] == 0){
//			 flag[row ][line- 1] = 1;
//			 dfs(row , line- 1, color, flag1, now);
//			 flag[row][line - 1] = 0;
//		 }
//		 if (line + 1 <= m  && flag[row][line + 1] == 0){
//			 flag[row][line + 1] = 1;
//			 dfs(row, line + 1, color, flag1, now);
//			 flag[row][line + 1] = 0;
//		 }
//
//	 
//}
//int main(){
//	cin >> m >> n;
//	int row, line,color;
//	for (int i = 0; i < n; i++){
//		cin >> row >> line >> color;
//		if (color)col[row][line] = 1;
//		else col[row][line] = 2;
//	}
//	if (m == 1){
//		cout << m;
//		return 0;
//
//	}
//		
//	flag[1][1] = 1;
//	dfs(1, 2, col[1][1], 0,0);
//	dfs(2, 1, col[1][1], 0,0);
//	cout << ans;
//}
//P3371 最短路径Dijkstra算法
//#include<iostream>
//#include<vector>
//using namespace std;
//struct edge{
//	int to, dis;
//};
//vector <edge> node[100001];
//int disnow[10004];
//int ans[10004];
//int visit[10004];//是否已有答案
//int n, m, s;
//int from,now;
//void bfs(){
//	for (int i = 0; i<node[from].size(); i++){
//		if (disnow[node[from][i].to] > now + node[from][i].dis)
//			disnow[node[from][i].to] = now + node[from][i].dis;
//			 }
//	 int minn = 2147483647;
//	 int from1=from;
//	for (int i = 1; i <= n; i++)
//	{
//		if (!visit[i] && minn>disnow[i])//取新的最小值
//		{
//			minn = disnow[i];
//			from1 = i;
//		}
//	}
//	if (from1 != from){
//		from = from1;
//		ans[from] = minn;
//		now = minn;
//	}
//	
//	
//	
//
//
//}
//int main(){
//	cin >> n >> m >> s;
//	int from1, to, dis;
//	for (int i = 0; i < m; i++){
//		cin >> from1 >> to >> dis;
//		node[from1].push_back(edge({ to, dis }));
//	}
//	for (int i = 1; i <= n; i++)disnow[i] = 0x7fffffff;
//	from = s;
//	disnow[s] = 0;
//	
//	while (!visit[from]){
//		visit[from] = 1;
//		bfs();
//	}
//	for (int i = 1; i <= n; i++){
//		if (i == s)cout << 0 << " ";
//		else {
//			if (ans[i]==0)cout <<  0X7fffffff<<" ";
//			else cout << ans[i]<<" ";
//			
//		}
//	}
//}
//P2910 最短路径Floyd算法
//#include<iostream>
//using namespace std;
//int d[105][105];
////int p[105][105];
//int to[10005];
//int n, m,ans;
//int min(int a, int b){
//	if (a > b)return b;
//	else return a;
//}
//int main(){
//	cin >> n >> m;
//	int num;
//	for (int i = 1; i <= m; i++){
//		cin >> to[i];
//	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			cin >> d[i][j];
//			//p[i][j] = j;
//		}
//	}
//	for (int k = 1; k <= n; k++)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
//			
//			}
//		}
//	}
//	for (int i = 1; i < m; i++){
//		ans += d[to[i]][to[i + 1]];
//	}
//	if (to[1] != 1)ans += d[1][to[1]];
//	if (to[m] != n)ans += d[to[m]][n];
//	cout << ans;
//	
//
//}
//P3367 路径压缩
//#include<iostream>
//using namespace std;
//int p[10005];
//int get(int k){
//	if (p[k] == k)return k;
//	else return p[k] = get(p[k]);
//}
//int main(){
//	int n,m;
//	cin >> n>> m;
//	for (int i = 1; i <= n; i++)p[i] = i;
//	int z, x, y;
//	for (int i = 1; i <= m; i++){
//		cin >> z >> x >> y;
//		if (z == 1)p[get(x)] = get(y);
//	
//	else {
//		if (get(x) == get(y))cout << 'Y' << endl;
//		else cout << 'N' << endl;
//	 }
//	}
//	
//
//
//}
//P3366	【模板】最小生成树prim
//#include<iostream>
//#include<vector>
//using namespace std;
//struct edge{
//	int to, dis;
//};
//vector <edge> node[100001];
//int disnow[10004];
//int ans[10004];
//int visit[10004];//是否已有答案
//int n, m, s=1;
//int from;
//void bfs(){
//	for (int i = 0; i<node[from].size(); i++){
//		if (disnow[node[from][i].to] >  node[from][i].dis)
//			disnow[node[from][i].to] =  node[from][i].dis;
//			 }
//	 int minn = 0x7fffffff;
//	 int from1=from;
//	for (int i = 1; i <= n; i++)
//	{
//		if (!visit[i] && minn>disnow[i])//取新的最小值
//		{
//			minn = disnow[i];
//			from1 = i;
//		}
//	}
//	if (from1 != from){
//		from = from1;
//		ans[from] = minn;
//	}
//	
//	
//	
//
//
//}
//int main(){
//	int answer = 0;
//	cin >> n >> m ;
//	int from1, to, dis;
//	for (int i = 0; i < m; i++){
//		cin >> from1 >> to >> dis;
//			node[from1].push_back(edge({ to, dis }));
//			node[to].push_back(edge({ from1, dis }));
//		
//		
//	}
//	for (int i = 1; i <= n; i++)disnow[i] = 0x7fffffff;
//	from = s;
//	disnow[s] = 0;
//	
//	while (!visit[from]){
//		visit[from] = 1;
//		bfs();
//	}
//	for (int i = 2; i <= n; i++){
//		 if (ans[i] == 0){
//			cout << "orz";
//			return 0;
//		}
//		else {
//			answer += ans[i];
//			
//		}
//	}
//	cout << answer;
//}

