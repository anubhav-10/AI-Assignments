#include<game.h>
#include <iostream>
using namespace std;

/*
	0 -> empty
	-1 -> no point
	1 -> WR or P1
	2 -> BR or P2
	3 -> WM or P1
	4 -> BM or P2
*/

game::game(){
	for(int i=0;i<=nor+1;i++){
		vector<int> v;
		if(i==0) v.push_back(0);
		for(int j=0;j<6*i;j++){
			if(i==5 && j%5==0 && nor == 5) v.pb(-1);
			else if(i == 6 && j%6==0 && nor == 6) v.pb(-1);
			else if(i==nor+1) v.pb(-1);
			else v.pb(0);
		}
		state.pb(v);
	}
	removedWhite=0;
	removedBlack=0;
}
	
void game::print(){
	for(int i=0;i<state.size();i++){
		for(int j=0;j<state[i].size();j++)
			cout<<state[i][j]<<" ";
		cout<<endl;
	}	
}

void game::undoMove(moves m, int player){
	if(m.type == Place){
		unplace(player, m.coord[0], m.coord[1]);
	}
	else if(m.type == Move){
		unmove(player, m.coord[0], m.coord[1], m.coord[2], m.coord[3]);
	}
	else if(m.type == RemoveRun){
		placeRun(player, m.coord[0], m.coord[1], m.coord[2], m.coord[3]);
	}
	else{
		reinsertring(player, m.coord[0], m.coord[1]);
	}
}

void game::unmove(int player, int sx, int sy, int ex, int ey){
	state[sx][sy] = state[ex][ey];
	if(player == 1){
		for(int i=0;i<nor;i++){
			if(white[i]==make_pair(ex,ey)){
				white[i]=make_pair(sx,sy);
				break;
			}
		}
	}
	else if(player == 2){
		for(int i=0;i<nor;i++){
			if(black[i]==make_pair(ex,ey)){
				black[i]=make_pair(sx,sy);
				break;
			}
		}
	}
	state[ex][ey] = 0;
	int z = getDirection(sx, sy, ex, ey);
	flip(sx, sy, ex, ey, z);
}

void game::placeRun(int player, int sx,int sy,int ex,int ey){
	int z = getDirection(sx,sy,ex,ey);
	int marker = (player == 1)?3:4;
	state[sx][sy]=marker;
	pair<int,int> d=make_pair(ex,ey);
	if(z==0){
		pair<int,int> p=get0(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=marker;
			p=get0(sx,sy);
		}
	}
	else if(z==1){
		pair<int,int> p=get1(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=marker;
			p=get1(sx,sy);
		}
	}
	else if(z==2){
		pair<int,int> p=get2(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=marker;
			p=get2(sx,sy);
		}
	}
	else if(z==3){
		pair<int,int> p=get3(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=marker;
			p=get3(sx,sy);
		}
	}
	else if(z==4){
		pair<int,int> p=get4(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=marker;
			p=get4(sx,sy);
		}
	}
	else if(z==5){
		pair<int,int> p=get5(sx,sy);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			state[sx][sy]=marker;
			p=get5(sx,sy);
		}
	}
	state[ex][ey]=marker;
}

void game::reinsertring(int player, int x, int y){
	state[x][y] = player;
	if(player == 1){
		for(int i=0;i<nor;i++){
			if(white[i] == make_pair(-1, -1)){
				white[i] = {x, y};
				break;
			}
		}
		removedWhite--;
	}
	else{
		for(int i=0;i<nor;i++){
			if(black[i] == make_pair(-1, -1)){
				black[i] = {x, y};
				break;
			}
		}
		removedBlack--;
	}
}

void game::unplace(int player, int x, int y){
	state[x][y] = 0;
	if(player == 1){
		white.pop_back();
	}
	else{
		black.pop_back();
	}
}