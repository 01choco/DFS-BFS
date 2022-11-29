#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[100001];   
vector<int> input[100001]; 
int temp = 1;
int answer[100001] = {0, };
queue <int> q;

void bfs(int node){
	check[node] = true;
	answer[node] = temp;
	temp++;
	q.push(node);	
	while(!q.empty()){
		int here = q.front();
		q.pop();
		for(int i=0; i<input[here].size(); i++){
			if(check[input[here][i]] == false){
				check[input[here][i]] = true;
				answer[input[here][i]] = temp;
				temp++;
				q.push(input[here][i]);
			}
		}	
	}
}
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N, M, R;
	cin >> N >> M >> R;
	
	for(int i=0; i<M; i++){
		int t1, t2;
		cin >> t1 >> t2;
		input[t1].push_back(t2);
		input[t2].push_back(t1);
	}
	for(int i=1; i<=N; i++){
		sort(input[i].begin(), input[i].end());
	}
	int ans = 0;
	bfs(R);
	for(int i=1; i<=N; i++){
		cout << answer[i] << "\n";
	}
	return 0;
}
