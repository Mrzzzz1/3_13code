//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//int in[105];//储存入度条数
//struct node1{
//	int num, c;
//};
//struct edge{
//	int to;
//	int weight;
//};
//int node[105];//每点的c
//vector<edge> out[105];//储存出度
//vector<int>ans;
//queue <int>q;
//int now = 0,n,p,cnt;
//int cmp(int a, int b){
//	return a < b;
//}
//int main(){
//	cin >> n >> p;
//	int sta, u;
//	for (int i = 1; i <= n; i++){
//		cin >> sta >> u;
//		if (sta){
//			node[i] = sta;
//			q.push(i);
//			cnt--;
//		}
//		else{
//			node[i] = -u;
//		}
//	}
//		int f, t, w;
//		for (int i = 1; i <= p; i++){
//			cin >> f >> t >> w;
//			out[f].push_back(edge({ t, w }));
//			in[t]++;
//		}
//		while (!q.empty()){
//			int nodeNow = q.front();
//			if (out[nodeNow].size() == 0 && node[nodeNow]>0)ans.push_back(nodeNow);
//			else for (int i = 0; i < out[nodeNow].size(); i++){
//				if (node[nodeNow]>0)node[out[nodeNow][i].to] += node[nodeNow] * out[nodeNow][i].weight;
//				in[out[nodeNow][i].to]--;
//				if (in[out[nodeNow][i].to] == 0){
//					q.push(out[nodeNow][i].to);
//				}
//			}
//			q.pop();
//		}
//		sort(ans.begin(), ans.end(), cmp);
//		if (ans.size() == 0)cout << "NULL";
//		else for (int i = 0; i < ans.size(); i++)cout << ans[i] <<" "<< node[ans[i]]<<endl;
//
//}
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int in[1005]; // 储存
vector<int>out[1005];
int ci[1005][1005];
queue <int>q;
int n, m;
int main(){
	cin >> n >> m;
	int num, stop;
	for (int i = 1; i <= m; i++){
		cin >> num;
		
		for (int j = 1; j <= num; j++){
			cin >> stop;
			if (j == 1)ci[i][0] = stop;
			if (j == num)ci[i][1005] = stop;
			ci[i][stop] = 1;
		}
		for (int k = ci[i][0]; k <= ci[i][1005]; k++){
			if (ci[i][k])out[k].push_back(i);
			else in[k]+=num;
		}
	}
	for (int i = 1; i <= n; i++){
		if (in[i] == 0)q.push(i);
	}
	int ans=0;
    while (!q.empty()){
		ans++;
	    while (!q.empty()){
			int now = q.front();
			in[now]--;
			for (int i = 0; i < out[now].size(); i++){
				for (int j = ci[out[now][i]][0]; j <= ci[out[now][i]][1005]; j++){
					if (ci[out[now][i]][j] == 0)
						in[j]--;
				}
			}
			q.pop();
	   }
		for (int i = 1; i <= n; i++){
			if (in[i] == 0)q.push(i);
		}
	} 
	cout << ans;
}



