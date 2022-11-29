#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[10001]; // 전역변수는 선언시 자동초기화  
vector<int> input[10001]; 
int ans[10001] = {0,};

int dfs(int node){
	int ans = 1;
	check[node] = true;
	for(int j=0; j<input[node].size(); j++){
		int temp = input[node][j];
		if(check[temp] == false){
			ans += dfs(temp);
		}
	}
	return ans;
}
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		int t1, t2;
		cin >> t1 >> t2;
		input[t2].push_back(t1);
	}
	
	for(int i=1; i<=N; i++){
		ans[i] = dfs(i);
		for(int j=1; j<=N; j++){
			if(check[j] == true) check[j] = false;
		}
	}
	int maxx = 0;
	int answer;
	vector <int> total;
	for(int i=1; i<=N; i++){
		if(ans[i] > maxx){
			answer = i;
			maxx = ans[i];
		}
	}
	total.push_back(answer);
	for(int i=1; i<=N; i++){
		if(ans[i] == maxx && i!=answer){
			total.push_back(i);
		}
	}
	sort(total.begin(), total.end());
	for(int i=0; i<total.size(); i++){
		cout << total[i] << " ";
	}
	return 0;
}
