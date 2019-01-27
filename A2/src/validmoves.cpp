#include<game.h>
#include <iostream>
using namespace std;

vector<moves> game::validMoves(int player){
	vector<moves> ans;
	if(player==1){
		bool b=0;
		// place a ring
		if(white.size()<nor){
			for(int i=0;i<state.size();i++){
				for(int j=0;j<state[i].size();j++)
					if(state[i][j]==0){
						moves m;
						m.type=Place;
						m.coord.pb(i);
						m.coord.pb(j);
						ans.pb(m);
						b=1;
						break;
					}
				if(b) return ans;
			}
			return ans;
		}
		// check for a run

		// move a ring
	 	for(int i=0;i<nor;i++){
			pair<int,int> ring=white[i];
			int x,y,sx,sy;
			sx=ring.first; sy=ring.second;
			if(sx==-1 && sy==-1) continue;
			vector<moves> v;
			v=getValid0(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid1(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid2(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid3(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid4(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid5(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
 		}
 	}
 	else if(player==2){
		// place a ring
		if(black.size()<nor){
			bool b=0;
			for(int i=0;i<state.size();i++){
				for(int j=0;j<state[i].size();j++)
					if(state[i][j]==0){
						moves m;
						m.type=Place;
						m.coord.pb(i);
						m.coord.pb(j);
						ans.pb(m);
						b=1;
						break;
					}
				if(b) return ans;
			}
			return ans;
		}
		// check for a run

		// move a ring
	 	for(int i=0;i<nor;i++){
			pair<int,int> ring=black[i];
			int x,y,sx,sy;
			sx=ring.first; sy=ring.second;
			if(sx==-1 && sy==-1) continue;
			vector<moves> v;
			v=getValid0(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid1(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid2(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid3(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid4(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
			v=getValid5(sx,sy);
			ans.insert(ans.end(),v.begin(),v.end());
 		}		
 	}
}

vector<moves> game::getValid0(int sx,int sy){
	vector<moves> v;
	// up
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get0(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get0(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get0(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get0(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid1(int sx,int sy){
	vector<moves> v;
	// NE
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get1(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		// cout<<x<<" "<<y<<endl;
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get1(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get1(x,y);
				x=next.first; y=next.second;
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get1(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid2(int sx,int sy){
	vector<moves> v;
	// SE
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get2(x,y);
	x=next.first; y=next.second;
	// cout<<x<<" "<<y<<endl;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get2(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get2(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get2(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid3(int sx,int sy){
	vector<moves> v;
	// Down
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get3(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get0(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get3(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get3(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid4(int sx,int sy){
	vector<moves> v;
	// up
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get4(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get4(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get4(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get4(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::getValid5(int sx,int sy){
	vector<moves> v;
	// up
	int x,y;	
	x=sx;y=sy;
	pair<int,int> next=get5(x,y);
	x=next.first; y=next.second;
	while(state[x][y]!=-1){
		bool b=0;
		if(state[x][y]==0){
			moves m;
			m.type=Move;
			m.coord.pb(sx);
			m.coord.pb(sy);
			m.coord.pb(x);
			m.coord.pb(y);
			v.pb(m);
		}
		else if(state[x][y]==1 || state[x][y]==2 || state[x][y]==-1)
			break;
		else {
			next=get5(x,y);
			x=next.first; y=next.second;
			while(state[x][y]!=-1){
				if(state[x][y]==0){
					moves m;
					m.type=Move;
					m.coord.pb(sx);
					m.coord.pb(sy);
					m.coord.pb(x);
					m.coord.pb(y);
					v.pb(m);
					b=1;
					break;
				}
				if(state[x][y]==-1 || state[x][y]==1 || state[x][y]==2){
					b=1;
					break;
				}
				next=get5(x,y);
				x=next.first; y=next.second;		
			}
		}
		if(b) break;
		if(state[x][y]==-1) break; // if it reached the end of the board
		next=get5(x,y);
		x=next.first; y=next.second;
	}
	return v;	
}

vector<moves> game::validRemoveRing(int player){
	vector<moves> ans;
	if(player==1){
		for(int i=0;i<nor;i++){
			if(white[i]!=make_pair(-1,-1)){
				moves m;
				m.type=RemoveRing;
				m.coord.pb(white[i].first);
				m.coord.pb(white[i].second);
				ans.pb(m);
			}
		}
	}
	else{
		for(int i=0;i<nor;i++){
			if(black[i]!=make_pair(-1,-1)){
				moves m;
				m.type=RemoveRing;
				m.coord.pb(black[i].first);
				m.coord.pb(black[i].second);
				ans.pb(m);
			}
		}		
	}
	return ans;
}

// vector<moves> game::getRun(int player){
// 	vector<moves> ans,v;
// 	ans=getRunDown(player);
// 	v=getRunSE(player);
// 	ans.insert(ans.end(),v.begin(),v.end());
// 	v=getRunSW(player);
// 	ans.insert(ans.end(),v.begin(),v.end());

// 	return ans;
// }
vector<moves> game::getRun(int id){
	vector<moves> ret;

	vector<pair<int, int>> v;
	int myMarker = (id==1)?3:4;
	int start = 0, x1 = -1, x2 = -1, y1 = -1, y2 = -1, count = 0;
	for(auto v: vertical){
		// v = vertical[*itr];
		x1 = v[0].first;
		y1 = v[0].second;
		count = 0;
		for(int i=0;i<v.size();i++){
			x2 = v[i].first;
			y2 = v[i].second;
			if(!count){
				x1 = x2;
				y1 = y2;
				start = i;
			}
			if(state[x2][y2] == myMarker){
				count++;
			}
			else{
				count = 0;
			}

			if (count == nom){
				moves temp;
				temp.type = RemoveRun;
				temp.coord = {x1, y1, x2, y2};
				ret.pb(temp);
				x1 = v[start+1].first;
				y1 = v[start+1].second;
				start++;
				count--;
			}
		}
	}

	start = 0; x1 = -1; x2 = -1; y1 = -1; y2 = -1; count = 0;
	for(auto v: diagonal1){
		// v = m->diagonal1[*itr];
		x1 = v[0].first;
		y1 = v[0].second;
		count = 0;
		for(int i=0;i<v.size();i++){
			x2 = v[i].first;
			y2 = v[i].second;
			if(!count){
				x1 = x2;
				y1 = y2;
				start = i;
			}
			if(state[x2][y2] == myMarker){
				count++;
			}
			else{
				count = 0;
			}

			if (count == nom){
				moves temp;
				temp.type = RemoveRun;
				temp.coord = {x1, y1, x2, y2};
				ret.pb(temp);
				x1 = v[start+1].first;
				y1 = v[start+1].second;
				start++;
				count--;
			}
		}
	}

	start = 0; x1 = -1; x2 = -1; y1 = -1; y2 = -1; count = 0;
	for(auto v: diagonal2){
		// v = m->diagonal2[*itr];
		x1 = v[0].first;
		y1 = v[0].second;
		count = 0;
		for(int i=0;i<v.size();i++){
			x2 = v[i].first;
			y2 = v[i].second;
			if(!count){
				x1 = x2;
				y1 = y2;
				start = i;
			}
			if(state[x2][y2] == myMarker){
				count++;
			}
			else{
				count = 0;
			}

			if (count == nom){
				moves temp;
				temp.type = RemoveRun;
				temp.coord = {x1, y1, x2, y2};
				ret.pb(temp);
				x1 = v[start+1].first;
				y1 = v[start+1].second;
				start++;
				count--;
			}
		}
	}
	// for(auto u: ret){
	// 	cout<<(u.type)<<" ";
	// 	for(auto v: u.coord)
	// 		cout<<(v)<<" ";
	// 	cout<<endl;
	// }

	return ret;
}

vector<moves> game::getRunDown(int player){
	vector<moves> ans,v;
	// Down
	if(nor == 5){
		ans=getRunDownUtil(player,5,1,4);
		v=getRunDownUtil(player,5,26,29);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunDownUtil(player,4,0,0);
		ans.insert(ans.end(),v.begin(),v.end());
	}
	else{
		ans=getRunDownUtil(player,6,1,5);
		v=getRunDownUtil(player,6,31,35);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunDownUtil(player,5,0,0);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunDownUtil(player,6,7,7);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunDownUtil(player,6,29,29);
		ans.insert(ans.end(),v.begin(),v.end());
	}

	return ans;
}

vector<moves> game::getRunDownUtil(int player,int startx,int a,int b){
	int c=(player==1)?3:4;
	vector<moves> v;
	// Down
	for(int i=a;i<=b;i++){
		int sx=startx,sy=i,x,y;
		int l=0;
		x=sx;y=sy;
		while(state[x][y]!=-1){
			if(state[x][y]==c){
				l=1;
				pair<int,int> p=get3(x,y);
				x=p.first; y=p.second;
				// cout<<sx<<" "<<sy<<endl;
				// cout<<x<<" "<<y<<endl;
				while(state[x][y]==c){
					l++;
					if(l==nom){
						// add in vector
						moves m;
						m.type = RemoveRun;
						// cout<<sx<<" "<<sy<<endl;
						m.coord.pb(sx);
						m.coord.pb(sy);
						m.coord.pb(x);
						m.coord.pb(y);
						v.pb(m);
						l=nom-1;
						pair<int,int> temp=get3(sx,sy);
						sx=temp.first; sy=temp.second;
					}
					pair<int,int> p=get3(x,y);
					x=p.first; y=p.second;
				}
				sx=x;sy=y;
				if(state[x][y]==-1) break;
			}
					// cout<<x<<" "<<y<<endl;
			pair<int,int> temp=get3(sx,sy);
			sx=temp.first; sy=temp.second;
			pair<int,int> p=get3(x,y);
			x=p.first; y=p.second;
		}
	}
	return v;
}
vector<moves> game::getRunSE(int player){
	vector<moves> ans,v;
	// SE
	if(nor == 5){
		ans=getRunSEUtil(player,5,21,24);
		v=getRunSEUtil(player,5,26,29);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunSEUtil(player,4,20,20);
		ans.insert(ans.end(),v.begin(),v.end());
	}
	else{
		ans=getRunSEUtil(player,6,25,29);
		v=getRunSEUtil(player,6,31,35);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunSEUtil(player,5,25,25);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunSEUtil(player,6,1,1);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunSEUtil(player,6,23,23);
		ans.insert(ans.end(),v.begin(),v.end());
	}
	return ans;
}

vector<moves> game::getRunSEUtil(int player,int startx,int a,int b){
	int c=(player==1)?3:4;
	vector<moves> v;
	// SE
	for(int i=a;i<=b;i++){
		int sx=startx,sy=i,x,y;
		int l=0;
		x=sx;y=sy;
		while(state[x][y]!=-1){
			if(state[x][y]==c){
				l=1;
				pair<int,int> p=get2(x,y);
				x=p.first; y=p.second;
				while(state[x][y]==c){
					l++;
					if(l==nom){
						// add in vector
						moves m;
						m.type = RemoveRun;
						m.coord.pb(sx);
						m.coord.pb(sy);
						m.coord.pb(x);
						m.coord.pb(y);
						v.pb(m);
						l=nom-1;
						pair<int,int> temp=get2(sx,sy);
						sx=temp.first; sy=temp.second;
					}
					pair<int,int> p=get2(x,y);
					x=p.first; y=p.second;
				}
				sx=x;sy=y;
				if(state[x][y]==-1) break;
			}
			pair<int,int> temp=get2(sx,sy);
			sx=temp.first; sy=temp.second;
			pair<int,int> p=get2(x,y);
			x=p.first; y=p.second;
		}
	}
	return v;
}
vector<moves> game::getRunSW(int player){
	vector<moves> ans,v;
	// SW
	if(nor == 5){
		ans=getRunSWUtil(player,5,1,4);
		v=getRunSWUtil(player,5,6,9);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunSWUtil(player,4,4,4);
		ans.insert(ans.end(),v.begin(),v.end());
	}
	else{
		ans=getRunSWUtil(player,6,1,5);
		v=getRunSWUtil(player,6,7,11);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunSWUtil(player,5,5,5);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunSWUtil(player,6,35,35);
		ans.insert(ans.end(),v.begin(),v.end());
		v=getRunSWUtil(player,6,13,13);
		ans.insert(ans.end(),v.begin(),v.end());
	}

	return ans;
}

vector<moves> game::getRunSWUtil(int player,int startx,int a,int b){
	int c=(player==1)?3:4;
	vector<moves> v;
	// SE
	for(int i=a;i<=b;i++){
		int sx=startx,sy=i,x,y;
		int l=0;
		x=sx;y=sy;
		while(state[x][y]!=-1){
			if(state[x][y]==c){
				l=1;
				pair<int,int> p=get4(x,y);
				x=p.first; y=p.second;
				while(state[x][y]==c){
					l++;
					if(l==nom){
						// add in vector
						moves m;
						m.type = RemoveRun;
						m.coord.pb(sx);
						m.coord.pb(sy);
						m.coord.pb(x);
						m.coord.pb(y);
						v.pb(m);
						l=nom-1;
						pair<int,int> temp=get4(sx,sy);
						sx=temp.first; sy=temp.second;
					}
					pair<int,int> p=get4(x,y);
					x=p.first; y=p.second;
				}
				sx=x;sy=y;
				if(state[x][y]==-1) break;
			}
			pair<int,int> temp=get4(sx,sy);
			sx=temp.first; sy=temp.second;
			pair<int,int> p=get4(x,y);
			x=p.first; y=p.second;
		}
	}
	return v;
}