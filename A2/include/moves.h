#ifndef MOVES_H
#define MOVES_H

#include <vector>
#define pb push_back
using namespace std;

enum MoveType { Place, Move, RemoveRun, RemoveRing };
struct moves {
	enum MoveType type;
	vector<int> coord; // set of coordinates for different moves;
};

#endif;