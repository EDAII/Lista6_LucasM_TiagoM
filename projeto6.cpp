#include<bits/stdc++.h>

using namespace std;

int tabuleiro [9][9];
pair<int, int> jogadas[9][9];

void bfs(pair<int, int> pos){

	queue<pair<int, int>> que;

	memset(tabuleiro, -1, sizeof(tabuleiro));

	que.push(pos);

	while(!que.empty()){
	
		auto v = que.front();
		pair<int, int> aux;
		que.pop();

		if(v.first+3 <= 8 and v.second+2 <= 8 and tabuleiro[v.first+3][v.second+2] != -1){
			tabuleiro[v.first+3][v.second+2] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first+3][v.second+2] = v;
			aux.first = v.first+3;
			aux.second = v.second+2;
			que.push(aux);
		}

		if(v.first+3 <= 8 and v.second-2 >= 1 and tabuleiro[v.first+3][v.second-2] != -1){
			tabuleiro[v.first+3][v.second-2] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first+3][v.second-2] = v;
			aux.first = v.first+3;
			aux.second = v.second-2;
			que.push(aux);
		}

		if(v.first-3 >= 1 and v.second+2 <= 8 and tabuleiro[v.first-3][v.second+2] != -1){
			tabuleiro[v.first-3][v.second+2] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first-3][v.second+2] = v;
			aux.first = v.first-3;
			aux.second = v.second+2;
			que.push(aux);
		}

		if(v.first-3 >= 1 and v.second-2 >= 1 and tabuleiro[v.first-3][v.second-2] != -1){
			tabuleiro[v.first-3][v.second-2] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first-3][v.second-2] = v;
			aux.first = v.first-3;
			aux.second = v.second-2;
			que.push(aux);
		}

		if(v.first+2 <= 8 and v.second+3 <= 8 and tabuleiro[v.first+2][v.second+3] != -1){
			tabuleiro[v.first+2][v.second+3] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first+2][v.second+3] = v;
			aux.first = v.first+2;
			aux.second = v.second+3;
			que.push(aux);
		}

		if(v.first+2 <= 8 and v.second-3 >= 1 and tabuleiro[v.first+2][v.second-3] != -1){
			tabuleiro[v.first+2][v.second-3] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first+2][v.second-3] = v;
			aux.first = v.first+2;
			aux.second = v.second-3;
			que.push(aux);
		}

		if(v.first-2 >= 1 and v.second+3 <= 8 and tabuleiro[v.first-2][v.second+3] != -1){
			tabuleiro[v.first-2][v.second+3] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first-2][v.second+3] = v;
			aux.first = v.first-2;
			aux.second = v.second+3;
			que.push(aux);
		}

		if(v.first-2 >= 1 and v.second-3 >= 1 and tabuleiro[v.first-2][v.second-3] != -1){
			tabuleiro[v.first-2][v.second-3] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first-2][v.second-3] = v;
			aux.first = v.first-2;
			aux.second = v.second-3;
			que.push(aux);
		}
	}
}

int main() {

	pair<int, int> in;




	return 0;
}
