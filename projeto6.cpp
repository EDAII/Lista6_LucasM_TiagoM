#include<bits/stdc++.h>

using namespace std;

int tabuleiro [9][9];
pair<int, int> jogadas[9][9];
char rend_tab[9][9];
const std::string red("\033[0;31m");
const std::string reset("\033[0m");

void bfs(pair<int, int> pos){

	queue<pair<int, int>> que;

	memset(tabuleiro, -1, sizeof(tabuleiro));

	tabuleiro[pos.first][pos.second] = 0;

	que.push(pos);

	while(!que.empty()){
	
		auto v = que.front();
		pair<int, int> aux;
		que.pop();

		if(v.first+2 <= 8 and v.second+1 <= 8 and tabuleiro[v.first+2][v.second+1] == -1){
			tabuleiro[v.first+2][v.second+1] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first+2][v.second+1] = v;
			aux.first = v.first+2;
			aux.second = v.second+1;
			que.push(aux);
		}

		if(v.first+2 <= 8 and v.second-1 >= 1 and tabuleiro[v.first+2][v.second-1] == -1){
			tabuleiro[v.first+2][v.second-1] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first+2][v.second-1] = v;
			aux.first = v.first+2;
			aux.second = v.second-1;
			que.push(aux);
		}

		if(v.first-2 >= 1 and v.second+1 <= 8 and tabuleiro[v.first-2][v.second+1] == -1){
			tabuleiro[v.first-2][v.second+1] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first-2][v.second+1] = v;
			aux.first = v.first-2;
			aux.second = v.second+1;
			que.push(aux);
		}

		if(v.first-2 >= 1 and v.second-1 >= 1 and tabuleiro[v.first-2][v.second-1] == -1){
			tabuleiro[v.first-2][v.second-1] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first-2][v.second-1] = v;
			aux.first = v.first-2;
			aux.second = v.second-1;
			que.push(aux);
		}

		if(v.first+1 <= 8 and v.second+2 <= 8 and tabuleiro[v.first+1][v.second+2] == -1){
			tabuleiro[v.first+1][v.second+2] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first+1][v.second+2] = v;
			aux.first = v.first+1;
			aux.second = v.second+2;
			que.push(aux);
		}

		if(v.first+1 <= 8 and v.second-2 >= 1 and tabuleiro[v.first+1][v.second-2] == -1){
			tabuleiro[v.first+1][v.second-2] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first+1][v.second-2] = v;
			aux.first = v.first+1;
			aux.second = v.second-2;
			que.push(aux);
		}

		if(v.first-1 >= 1 and v.second+2 <= 8 and tabuleiro[v.first-1][v.second+2] == -1){
			tabuleiro[v.first-1][v.second+2] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first-1][v.second+2] = v;
			aux.first = v.first-1;
			aux.second = v.second+2;
			que.push(aux);
		}

		if(v.first-1 >= 1 and v.second-2 >= 1 and tabuleiro[v.first-1][v.second-2] == -1){
			tabuleiro[v.first-1][v.second-2] = tabuleiro[v.first][v.second] + 1;
			jogadas[v.first-1][v.second-2] = v;
			aux.first = v.first-1;
			aux.second = v.second-2;
			que.push(aux);
		}
	}
}

void reset_tabuleiro() {

	for(int i=1, k=0; i<9; i++){
		for(int j=1; j<9; j++, k++){
			if(k%2 == 0){
				rend_tab[i][j] = 'o';
			}else{
				rend_tab[i][j] = '#';
			}
		}
		k++;
	}

}

void print_tab(){

	cout << "  1 2 3 4 5 6 7 8" << endl;

	for(int i=1; i<9; i++){
		cout << i << " ";
		for(int j=1; j<9; j++){
			if(rend_tab[i][j] != '#' && rend_tab[i][j] != 'o'){
				cout << red << rend_tab[i][j] << reset <<" ";
			}else {
				cout << rend_tab[i][j] << " ";
			}
		}
		cout << endl;
	}

}

void moves(pair<int, int> end){

	while(tabuleiro[end.first][end.second] != 0){
		rend_tab[end.first][end.second] = (char) (tabuleiro[end.first][end.second] + '0');
		end = jogadas[end.first][end.second];
	}	

}

int main() {

	pair<int, int> in, out;

	while(1){
	
		cout << endl;

		cout << "Insira a posiçao inicial na matriz do tabuleiro: ";

		while(1){
			cin >> in.first >> in.second;
			if (in.first < 1 || in.first > 8 || in.second < 1 || in.second > 8) 
				cout << "** As posiçoes devem ser entre 1 e 8 **" << endl;
			else break;
		};

		reset_tabuleiro();

		rend_tab[in.first][in.second] = 's';

		bfs(in);

		cout << "Insira a posiçao final na matriz do tabuleiro: ";

		while(1){
			cin >> out.first >> out.second;
			if (out.first < 1 || out.first > 8 || out.second < 1 || out.second > 8)
				cout << "** As posiçoes devem ser entre 1 e 8 **" << endl;
			else if(out.first == in.first && out.second == in.second)
				cout << "** A posicao final é a mesma da posiçao inicial **" << endl;
			else break;
		};

		cout << endl;

		moves(out);

		print_tab();

		cout << "Distância até o ponto selecionado: " << tabuleiro[out.first][out.second] << endl;

	}

	print_tab();

	return 0;
}
