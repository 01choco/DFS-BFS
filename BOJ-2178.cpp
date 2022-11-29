#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool check[101][101];
int route[101][101];
char map[101][101];
int inx[4] = {0, 1, 0, -1};
int iny[4] = {1, 0, -1, 0};


void bfs(int x, int y){
	check[101][101] = true;
	queue <pair<int,int> > q;
	q.push(make_pair(x, y));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nextx = x+inx[i];
			int nexty = y+iny[i];
			if(check[nextx][nexty] == false && map[nextx][nexty] == '1'){
				check[nextx][nexty] = true;
				route[nextx][nexty] = route[x][y] + 1;
				q.push(make_pair(nextx, nexty));
			}
		}
	}
	
}
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		string temp;
		cin >> temp;
		for(int j=0; j<M; j++){
			map[i][j] = temp[j];
		}
	}	
	bfs(0, 0);
	cout << route[N-1][M-1] + 1;
	return 0;
}
