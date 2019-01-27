#include<game.h>
#include <iostream>
#include <iterator>
using namespace std;

map<tuple<int,int,int,int>,int> direct;

void game::flip(int sx,int sy,int ex,int ey,int direction){
	if(direction==0){
		pair<int,int> p=get0(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=get0(sx,sy); 
		}
	}
	else if(direction==1){
		pair<int,int> p=get1(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=get1(sx,sy); 
		}		
	}
	else if(direction==2){
		pair<int,int> p=get2(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=get2(sx,sy); 
		}		
	}
	else if(direction==3){
		pair<int,int> p=get3(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=get3(sx,sy); 
		}		
	}
	else if(direction==4){
		pair<int,int> p=get4(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=get4(sx,sy); 
		}		
	}
	else if(direction==5){
		pair<int,int> p=get5(sx,sy);
		pair<int,int> d=make_pair(ex,ey);
		while(p!=d){
			sx=p.first;
			sy=p.second;
			if(state[sx][sy]==3) state[sx][sy]=4;
			else if(state[sx][sy]==4) state[sx][sy]=3;
			p=get5(sx,sy); 
		}		
	}
}

int game::getDirection(int sx,int sy,int ex,int ey){
	int z=0;
	/*
		0 -> up
		1 -> ne
		2 -> se
		3 -> down
		4 -> sw
		5 -> nw
	*/
	// map<tuple<int,int,int,int>,int>::iterator itr;
	// // cerr<<sx<<endl;
	// // cerr<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
	// itr = direct.find(make_tuple(sx,sy,ex,ey));
	// // cerr<<(itr==direct.end())<<endl;
	// return itr->second;
	pair<int,int> dest=make_pair(ex,ey);
	int x,y;
	pair<int,int>p;

	x=sx;y=sy;
	p=get0(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 0;
		x = p.first; y = p.second;
		p=get0(x,y);
	}

	x=sx;y=sy;
	p=get1(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 1;
		x = p.first; y = p.second;
		p=get1(x,y);
	}

	x=sx;y=sy;
	p=get2(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 2;
		x = p.first; y = p.second;
		p=get2(x,y);
	}

	x=sx;y=sy;
	p=get3(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 3;
		x = p.first; y = p.second;
		p=get3(x,y);
	}
	x=sx;y=sy;
	p=get4(x,y);
	while(state[x][y]!=-1){
		if(dest==p) return 4;
		x = p.first; y = p.second;
		p=get4(x,y);
	}

	return 5;
}

// int game::getRegion(int x,int y){
// /*
// 	0 -> origin
// 	1 - 6
// 	7 -> N
// 	8 -> S
// 	9 -> NE
// 	10 -> SW
// 	11 -> NW
// 	12 -> SE
// */
// 	if(x==0 && y==0)
// 		return 0;
// 	else if(y==0)
// 		return 7;
// 	else if(y<x)
// 		return 1;
// 	else if(y==x)
// 		return 9;
// 	else if(y<2*x && y>x)
// 		return 2;
// 	else if(y==2*x)
// 		return 12;
// 	else if(y<3*x && y>2*x)
// 		return 3;
// 	else if(y==3*x)
// 		return 8;
// 	else if(y<4*x && y>3*x)
// 		return 4;
// 	else if(y==4*x)
// 		return 10;
// 	else if(y<5*x && y>4*x)
// 		return 5;
// 	else if(y==5*x)
// 		return 11;
	
// 	return 6;
// }
// pair<int,int> game::get0(int x,int y){ // UP or N
// 	int z = getRegion(x,y);
// 	if(z==0 || z==1 || z==7 || z==9)
// 		return make_pair(x+1,y);
// 	else if(z==2 || z==12)
// 		return make_pair(x,y-1);
// 	else if(z==3 || z==4 || z==8)
// 		return make_pair(x-1,y-3);
// 	else if(z==5 || z==10)
// 		return make_pair(x,y+1);
	
// 	return make_pair(x+1,y+6);
// }

// pair<int,int> game::get1(int x,int y){ // NE
// 	int z = getRegion(x,y);
// 	if(z==1 || z==2 || z==7 || z==9 || z==12 || z==0)
// 		return make_pair(x+1,y+1);
// 	else if(z==3 || z==8)
// 		return make_pair(x,y-1);
// 	else if(z==4 || z==5 || z==10)
// 		return make_pair(x-1,y-4);

// 	return make_pair(x,(y+1)%(6*x));
// }

// pair<int,int> game::get2(int x,int y){ // SE
// 	int z = getRegion(x,y);
// 	if(z==4 || z==10)
// 		return make_pair(x,y-1);
// 	else if(z==2 || z==3 || z==8 || z==9 || z==12 || z==0)
// 		return make_pair(x+1,y+2);
// 	else if(z==6 && y==6*x-1)
// 		return make_pair(x-1,0);
// 	else if(z==5 || z==6 || z==11)
// 		return make_pair(x-1,y-5);

// 	return make_pair(x,y+1);
// }

// pair<int,int> game::get3(int x,int y){ // DOWN or S
// 	int z = getRegion(x,y);
// 	if(z==1 || z==7)
// 		return make_pair(x-1,y);
// 	else if(z==2 || z==9)
// 		return make_pair(x,y+1);
// 	else if(z==3 || z==4 || z==8 || z==12 || z==0 || z==10)
// 		return make_pair(x+1,y+3);
// 	else if(z==5 || z==11)
// 		return make_pair(x,y-1);
	
// 	return make_pair(x-1,y-6);
// }

// pair<int,int> game::get4(int x,int y){ // SW
// 	int z = getRegion(x,y);
// 	if(z==1 || z==2 || z==9)
// 		return make_pair(x-1,y-1);
// 	else if(z==3 || z==12)
// 		return make_pair(x,y+1);
// 	else if(z==4 || z==5 || z==8 || z==10 || z==11 || z==0)
// 		return make_pair(x+1,y+4);
// 	else if(z==6)
// 		return make_pair(x,y-1);

// 	return make_pair(x,6*x-1);
// }

// pair<int,int> game::get5(int x,int y){ // NW
// 	int z = getRegion(x,y);
// 	if(z==4 || z==8)
// 		return make_pair(x,y+1);
// 	else if(z==2 || z==3 || z==12)
// 		return make_pair(x-1,y-2);
// 	else if(z==5 || z==6 || z==10 || z==11 || z==0)
// 		return make_pair(x+1,y+5);
// 	else if(z==7)
// 		return make_pair(x+1,(x+1)*6 -1);

// 	return make_pair(x,y-1);
// }

void game::initialize(){
	for(int i=0;i<state.size()-1;i++){
		for(int j=0;j<state[i].size();j++){
			int sx=i,sy=j,x,y;
			// UP
			x=sx,y=sy;
			pair<int,int>p=get0(x,y);
			x=p.first;y=p.second;
			// cout<<x<<" "<<y<<endl;
			while(state[x][y]!=-1){
				direct.insert(make_pair(make_tuple(sx,sy,x,y),0));
				p=get0(x,y);
				x=p.first;y=p.second;
			}
			// Down
			x=sx,y=sy;
			p=get3(x,y);
			x=p.first;y=p.second;
			while(state[x][y]!=-1){
				direct.insert(make_pair(make_tuple(sx,sy,x,y),3));
				p=get3(x,y);
				x=p.first;y=p.second;
			}

			// SE
			x=sx,y=sy;
			p=get2(x,y);
			x=p.first;y=p.second;
			while(state[x][y]!=-1){
				direct.insert(make_pair(make_tuple(sx,sy,x,y),2));
				p=get2(x,y);
				x=p.first;y=p.second;
			}

			// SW
			x=sx,y=sy;
			p=get4(x,y);
			x=p.first;y=p.second;
			while(state[x][y]!=-1){
				direct.insert(make_pair(make_tuple(sx,sy,x,y),4));
				p=get4(x,y);
				x=p.first;y=p.second;
			}

			// NE
			x=sx,y=sy;
			p=get1(x,y);
			x=p.first;y=p.second;
			while(state[x][y]!=-1){
				direct.insert(make_pair(make_tuple(sx,sy,x,y),1));
				p=get1(x,y);
				x=p.first;y=p.second;
			}

			// NW
			x=sx,y=sy;
			p=get5(x,y);
			x=p.first;y=p.second;
			while(state[x][y]!=-1){
				direct.insert(make_pair(make_tuple(sx,sy,x,y),5));
				p=get5(x,y);
				x=p.first;y=p.second;
			}
		}
	}	
}