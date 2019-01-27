#include <allvalidmoves.h>
#include <iostream>
using namespace std;

void allvalidmoves::getAllMoves(int player,game g,vector<moves> v,bool moveMade){
	if(g.terminal()){
		allMoves.pb(make_pair(v,g.eval(player)));
		return;
	}

	vector<moves> runs=g.getRun(player);
	for(int i=0;i<runs.size();i++){
		game a=g;
		a.performMove(runs[i],player);
		vector<moves> b=v;
		b.pb(runs[i]);
		vector<moves> removes=a.validRemoveRing(player);
		for(int j=0;j<removes.size();j++){
			game c=a;
			c.performMove(removes[j],player);
			vector<moves> d=b;
			d.pb(removes[j]);
			// cout<<"abc";
			getAllMoves(player,c,d,moveMade);
		}
	}
	if(runs.size()>0){
		return;
	}
	if(moveMade){
		allMoves.pb(make_pair(v,g.eval(player)));
		return;
	}

	vector<moves> possibleMoves=g.validMoves(player);
	for(int i=0;i<possibleMoves.size();i++){
		game a=g;
		a.performMove(possibleMoves[i],player);
		vector<moves> b=v;
		b.pb(possibleMoves[i]);
		getAllMoves(player,a,b,1);
	}
}

void allvalidmoves::completeMove(int player, game g, vector<moves> v){
	if(g.terminal()){
		complete.pb({v, g.eval(player)});
		cerr << "sucess return " << endl;
		return;
	}
	cerr << "entered" << endl;
	vector<moves> runs=g.getRun(player);
	cerr << "found runs" << endl;
	for(int i=0;i<runs.size();i++){
		game a=g;
		a.performMove(runs[i],player);
		cerr << "run removes " << endl;
		vector<moves> b=v;
		b.pb(runs[i]);
		vector<moves> removes=a.validRemoveRing(player);
		cerr << "found removes rings " << endl;
		for(int j=0;j<removes.size();j++){
			game c=a;
			c.performMove(removes[j],player);
			cerr << "rings removes " << endl;
			vector<moves> d=b;
			d.pb(removes[j]);
			completeMove(player, c, d);
		}
	}
	if(runs.size()>0){
		return;
	}	
}

void allvalidmoves::print(){
	cout<<allMoves.size()<<endl;
	for(int i=0;i<allMoves.size();i++){
		for(int j=0;j<allMoves[i].first.size();j++){
			cout<<allMoves[i].first[j].type<<" ";
			for(int k=0;k<allMoves[i].first[j].coord.size();k++)
				cout<<allMoves[i].first[j].coord[k]<<" ";
		}
		cout<<endl;
	}
}
