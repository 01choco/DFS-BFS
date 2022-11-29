#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[300001]; 
vector<int> input[300001]; 
int temp = 0;
vector <pair<int, int> > answer;
queue <pair<int, int> > q;

void bfs(int node){
	check[node] = true;
	answer.push_back(make_pair(node, temp));
	q.push(make_pair(node, temp));
	while(!q.empty()){
		int here = q.front().first;
		int num = q.front().second;
		q.pop();
		for(int i=0; i<input[here].size(); i++){
			if(check[input[here][i]] == false){
				check[input[here][i]] = true;
				answer.push_back(make_pair(input[here][i], num+1)); 
				q.push(make_pair(input[here][i], num+1)); 
			}
		}	
	}
}
bool cmp(pair <int, int> p1, pair <int, int> p2){
	return p1.first < p2.first;
}
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	
	for(int i=0; i<M; i++){
		int t1, t2;
		cin >> t1 >> t2;
		input[t1].push_back(t2);
	}
	int ans = 0;
	bfs(X);
	sort(answer.begin(), answer.end(), cmp);
	bool exist = false;
	for(int i=0; i<answer.size(); i++){
		if(answer[i].second == K) {
			cout << answer[i].first <<"\n";
			exist = true;
		}
	}
	if(exist == false) cout << "-1\n";
	return 0;
}
