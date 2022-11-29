#include <iostream>

using namespace std;

int map[5][5];
bool visit[1000000];
int inx[4] = {0, 1, 0, -1};
int iny[4] = {1, 0, -1, 0};
int ans = 0;

void dfs(int x, int y, int sum, int loop){
	if(loop==5) {
		if(visit[sum] == false) {
			visit[sum] = true;
			ans++;
		}
		return;
	}
	for(int i=0; i<4; i++){
		int nextx = x+inx[i];
		int nexty = y+iny[i];
		if(nextx>=0 && nextx<5 && nexty>=0 && nexty<5){
			dfs(nextx, nexty, sum*10+map[nextx][nexty], loop+1);
		}
	}	
}
int main(){
	cin.tie(NULL); ios::sync_with_stdio(false);	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cin >> map[i][j];
		}
	}
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			dfs(i, j, map[i][j], 0);
		}
	}
	cout << ans;
	return 0;
}
