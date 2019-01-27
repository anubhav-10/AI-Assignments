#ifndef GAME_H
#define GAME_H

#include <vector>
#include <moves.h>
#include <map>
#include <tuple>
#include <iostream>
#define pb push_back
using namespace std;
extern map<tuple<int,int,int,int>,int> direct;
extern int no_of_moves, nor, nom;
extern vector<vector<pair<int,int>>> vertical, diagonal1, diagonal2;
extern vector<double> weights1;
extern vector<int> features, hue1, hue2;

class game{
	vector<vector<int>> state;
	vector<pair<int,int>> white,black;
	// int removedWhite,removedBlack;
	public:
	int removedWhite,removedBlack;
		game();
		void initialize();
		void placeMarker(int x,int y,int e); // for testing purposes
		void insertRing(int x,int y,int element);
		void removeRing(int x,int y);
		void moveRing(int sx,int sy,int ex,int ey); 
		void removeRun(int sx,int sy,int ex,int ey); // for executing opponent's move
		bool terminal();
		void performMove(moves m,int player);
		void undoMove(moves m, int player);

		void unmove(int player, int sx, int sy, int ex, int ey);
		void placeRun(int player, int sx, int sy, int ex, int ey);
		void reinsertring(int player, int x, int y);
		void unplace(int player, int x, int y);
		// Auxiliary functions
		void flip(int sx,int sy,int ex,int ey,int direction);
		int getDirection(int sx,int sy,int ex,int ey);
		int getRegion(int x,int y){
			if(x==0 && y==0)
				return 0;
			else if(y==0)
				return 7;
			else if(y<x)
				return 1;
			else if(y==x)
				return 9;
			else if(y<2*x && y>x)
				return 2;
			else if(y==2*x)
				return 12;
			else if(y<3*x && y>2*x)
				return 3;
			else if(y==3*x)
				return 8;
			else if(y<4*x && y>3*x)
				return 4;
			else if(y==4*x)
				return 10;
			else if(y<5*x && y>4*x)
				return 5;
			else if(y==5*x)
				return 11;
			
			return 6;			
		}

		pair<int,int> get0(int x,int y){
			int z = getRegion(x,y);
			if(z==0 || z==1 || z==7 || z==9)
				return make_pair(x+1,y);
			else if(z==2 || z==12)
				return make_pair(x,y-1);
			else if(z==3 || z==4 || z==8)
				return make_pair(x-1,y-3);
			else if(z==5 || z==10)
				return make_pair(x,y+1);
			
			return make_pair(x+1,y+6);
		}

		pair<int,int> get1(int x,int y){
			int z = getRegion(x,y);
			if(z==1 || z==2 || z==7 || z==9 || z==12 || z==0)
				return make_pair(x+1,y+1);
			else if(z==3 || z==8)
				return make_pair(x,y-1);
			else if(z==4 || z==5 || z==10)
				return make_pair(x-1,y-4);

			return make_pair(x,(y+1)%(6*x));
		}
		pair<int,int> get2(int x,int y){
			int z = getRegion(x,y);
			if(z==4 || z==10)
				return make_pair(x,y-1);
			else if(z==2 || z==3 || z==8 || z==9 || z==12 || z==0)
				return make_pair(x+1,y+2);
			else if(z==6 && y==6*x-1)
				return make_pair(x-1,0);
			else if(z==5 || z==6 || z==11)
				return make_pair(x-1,y-5);

			return make_pair(x,y+1);	
		}
		pair<int,int> get3(int x,int y){
			int z = getRegion(x,y);
			if(z==1 || z==7)
				return make_pair(x-1,y);
			else if(z==2 || z==9)
				return make_pair(x,y+1);
			else if(z==3 || z==4 || z==8 || z==12 || z==0 || z==10)
				return make_pair(x+1,y+3);
			else if(z==5 || z==11)
				return make_pair(x,y-1);
			
			return make_pair(x-1,y-6);	
		}
		pair<int,int> get4(int x,int y){
		int z = getRegion(x,y);
			if(z==1 || z==2 || z==9)
				return make_pair(x-1,y-1);
			else if(z==3 || z==12)
				return make_pair(x,y+1);
			else if(z==4 || z==5 || z==8 || z==10 || z==11 || z==0)
				return make_pair(x+1,y+4);
			else if(z==6)
				return make_pair(x,y-1);

			return make_pair(x,6*x-1);
		}
		pair<int,int> get5(int x,int y){
			int z = getRegion(x,y);
			if(z==4 || z==8)
				return make_pair(x,y+1);
			else if(z==2 || z==3 || z==12)
				return make_pair(x-1,y-2);
			else if(z==5 || z==6 || z==10 || z==11 || z==0)
				return make_pair(x+1,y+5);
			else if(z==7)
				return make_pair(x+1,(x+1)*6 -1);

			return make_pair(x,y-1);
		}
		// valid moves
		vector<moves> validMoves(int player);		
		vector<moves> getValid0(int sx,int sy);
		vector<moves> getValid1(int sx,int sy);
		vector<moves> getValid2(int sx,int sy);
		vector<moves> getValid3(int sx,int sy);
		vector<moves> getValid4(int sx,int sy);
		vector<moves> getValid5(int sx,int sy);
		vector<moves> validRemoveRing(int player);
		vector<moves> getRun(int player);
		vector<moves> getRunDown(int player);
		vector<moves> getRunDownUtil(int player,int startx,int a,int b);
		vector<moves> getRunSE(int player);
		vector<moves> getRunSEUtil(int player,int startx,int a,int b);
		vector<moves> getRunSW(int player);
		vector<moves> getRunSWUtil(int player,int startx,int a,int b);
		// evaluation function
		vector<int> get_features(int player);
		vector<int> get_features_new(int player);
		void markerScore(int player);
		void markerScoreDown(int player);
		void markerScoreDownUtil(int player,int startx,int a,int b);
		void markerScoreSE(int player);
		void markerScoreSEUtil(int player,int startx,int a,int b);
		void markerScoreSW(int player);
		void markerScoreSWUtil(int player,int startx,int a,int b);

		double flippedScore(int player);
		int flippedUtilUP(int player,int x,int y);
		int flippedUtilDown(int player,int x,int y);
		int flippedUtilSE(int player,int x,int y);
		int flippedUtilSW(int player,int x,int y);
		int flippedUtilNE(int player,int x,int y);
		int flippedUtilNW(int player,int x,int y);

		double countMarkers(int player);

		double mobilityScore(int player);
		int mobilityUtilUP(int player,int x,int y);
		int mobilityUtilDown(int player,int x,int y);
		int mobilityUtilSE(int player,int x,int y);
		int mobilityUtilSW(int player,int x,int y);
		int mobilityUtilNE(int player,int x,int y);
		int mobilityUtilNW(int player,int x,int y);
		
		double eval(int player);

		void print();
};

#endif