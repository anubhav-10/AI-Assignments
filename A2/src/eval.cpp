// #include "game.h"
// #include <iostream>
// #include <cmath>
// using namespace std;
// vector<int> hue1, hue2;

// void game::markerScore(int player){
// 	hue1.clear();
// 	hue2.clear();
// 	for(int i=0;i<8;i++){
// 		hue1.pb(0);
// 		hue2.pb(0);
// 	}
// 	markerScoreDown(player);
// 	markerScoreSE(player);
// 	markerScoreSW(player);
// }

// void game::markerScoreDown(int player){
// 	if(nor == 5){
// 		markerScoreDownUtil(player, 5, 1, 4);
// 		markerScoreDownUtil(player, 5, 26, 29);
// 		markerScoreDownUtil(player, 4, 0, 0);
// 	}
// 	else{
// 		markerScoreDownUtil(player, 6, 1, 5);
// 		markerScoreDownUtil(player, 6, 31, 35);
// 		markerScoreDownUtil(player, 5, 0, 0);
// 		markerScoreDownUtil(player, 6, 7, 7);
// 		markerScoreDownUtil(player, 6, 29, 29);
// 	}
// }

// void game::markerScoreDownUtil(int player, int startx, int a, int b){
//     int opponent = (player==1)?2:1;
//     int mymarker = (player == 1)?3:4;
//     int oppmarker = (player == 1)?4:3;
// 	int x;
// 	int y;
// 	int count = 0;
//     int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
//     bool b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//     int c1 = 0, c2 = 0, m3r2_1 = 0, m3r2_2 = 0;

//     for(int i=a;i<b;i++){
//     	x = startx;
//     	y = i;
//         count = 0;
//         count1 = 0; count2 = 0; count3 = 0; count4 = 0; count5 = 0;
//         b1 = 0; b2 = 0; c1 = 0; c2 = 0;
//     	while(state[x][y]!=1){
// 	        // k markers in row
//             if(state[x][y] == mymarker){
//                 count++;
//             }
//             else{
//                 hue1[count-1]++;
//                 count = 0;
//             }
//             if(count == nom){
//                 hue1[count-1]++;
//                 count--;
//             }
//             // opponent
//             if(state[x][y] == mymarker){
//                 count1++;
//             }
//             else{
//                 hue2[count1-1]++;
//                 count1 = 0;
//             }
//             if(count1 == nom){
//                 hue2[count1-1]++;
//                 count1--;
//             }


//             // four m's and 1 ring // mine
//             if(state[x][y] == mymarker){
//             	count2++;
//             }
//             else if(state[x][y] == player && !b1){
//             	count2++;
//             	b1 = 1;
//             }
//             else{
//             	count2 = 0;
//             	b1 = 0;
//             }
//             if(count2 == nom){
//             	hue1[6]++;
//             }
//             // four m's and 1 ring // opponent
//             if(state[x][y] == oppmarker){
//             	count3++;
//             }
//             else if(state[x][y] == opponent && !b2){
//             	count3++;
//             	b2 = 1;
//             }
//             else{
//             	count3 = 0;
//             	b2 = 0;
//             }
//             if(count3 == nom){
//             	hue2[6]++;
//             }

//             // 3 m's and 2 r's // mine
//             if(state[x][y] == mymarker){
//             	count4++;
//             }
//             else if(state[x][y] == player && c1<2){
//             	count4++;
//             	c1 += 1;
//             }
//             else{
//             	count4 = 0;
//             	c1 = 0;
//             }
//             if(count4 == nom && c1 == 2){
//             	hue1[7]++;
//             }
//             // 3 m's and 2 r's // opponent
//             if(state[x][y] == oppmarker){
//             	count5++;
//             }
//             else if(state[x][y] == opponent && c2<2){
//             	count5++;
//             	c2 += 1;
//             }
//             else{
//             	count5 = 0;
//             	c2 = 0;
//             }
//             if(count5 == nom && c2 == 2){
//             	hue2[7]++;
//             }

// 			pair<int, int> p = get3(x, y);
// 			x = p.first; y = p.second;            
//     	}
//     }
// }

// void game::markerScoreSE(int player){
// 	if(nor == 5){
// 		markerScoreSEUtil(player, 5, 21, 24);
// 		markerScoreSEUtil(player, 5, 26, 29);
// 		markerScoreSEUtil(player, 4, 20, 20);
// 	}
// 	else{
// 		markerScoreSEUtil(player, 6, 25, 29);
// 		markerScoreSEUtil(player, 6, 31, 35);
// 		markerScoreSEUtil(player, 5, 25, 25);
// 		markerScoreSEUtil(player, 6, 1, 1);
// 		markerScoreSEUtil(player, 6, 23, 23);
// 	}
// }

// void game::markerScoreSEUtil(int player, int startx, int a, int b){
//     int opponent = (player==1)?2:1;
//     int mymarker = (player == 1)?3:4;
//     int oppmarker = (player == 1)?4:3;
// 	int x;
// 	int y;
// 	int count = 0;
//     int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
//     bool b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//     int c1 = 0, c2 = 0, m3r2_1 = 0, m3r2_2 = 0;

//     for(int i=a;i<b;i++){
//     	x = startx;
//     	y = i;
//         count = 0;
//         count1 = 0; count2 = 0; count3 = 0; count4 = 0; count5 = 0;
//         b1 = 0; b2 = 0; c1 = 0; c2 = 0;
//     	while(state[x][y]!=1){
// 	        // k markers in row
//             if(state[x][y] == mymarker){
//                 count++;
//             }
//             else{
//                 hue1[count-1]++;
//                 count = 0;
//             }
//             if(count == nom){
//                 hue1[count-1]++;
//                 count--;
//             }
//             // opponent
//             if(state[x][y] == mymarker){
//                 count1++;
//             }
//             else{
//                 hue2[count1-1]++;
//                 count1 = 0;
//             }
//             if(count1 == nom){
//                 hue2[count1-1]++;
//                 count1--;
//             }


//             // four m's and 1 ring // mine
//             if(state[x][y] == mymarker){
//             	count2++;
//             }
//             else if(state[x][y] == player && !b1){
//             	count2++;
//             	b1 = 1;
//             }
//             else{
//             	count2 = 0;
//             	b1 = 0;
//             }
//             if(count2 == nom){
//             	hue1[6]++;
//             }
//             // four m's and 1 ring // opponent
//             if(state[x][y] == oppmarker){
//             	count3++;
//             }
//             else if(state[x][y] == opponent && !b2){
//             	count3++;
//             	b2 = 1;
//             }
//             else{
//             	count3 = 0;
//             	b2 = 0;
//             }
//             if(count3 == nom){
//             	hue2[6]++;
//             }

//             // 3 m's and 2 r's // mine
//             if(state[x][y] == mymarker){
//             	count4++;
//             }
//             else if(state[x][y] == player && c1<2){
//             	count4++;
//             	c1 += 1;
//             }
//             else{
//             	count4 = 0;
//             	c1 = 0;
//             }
//             if(count4 == nom && c1 == 2){
//             	hue1[7]++;
//             }
//             // 3 m's and 2 r's // opponent
//             if(state[x][y] == oppmarker){
//             	count5++;
//             }
//             else if(state[x][y] == opponent && c2<2){
//             	count5++;
//             	c2 += 1;
//             }
//             else{
//             	count5 = 0;
//             	c2 = 0;
//             }
//             if(count5 == nom && c2 == 2){
//             	hue2[7]++;
//             }

// 			pair<int, int> p = get2(x, y);
// 			x = p.first; y = p.second;            
//     	}
//     }
// }

// void game::markerScoreSW(int player){
// 	if(nor == 5){
// 		markerScoreDownUtil(player, 5, 1, 4);
// 		markerScoreDownUtil(player, 5, 6, 9);
// 		markerScoreDownUtil(player, 4, 4, 4);
// 	}
// 	else{
// 		markerScoreDownUtil(player, 6, 1, 5);
// 		markerScoreDownUtil(player, 6, 7, 11);
// 		markerScoreDownUtil(player, 5, 5, 5);
// 		markerScoreDownUtil(player, 6, 35, 35);
// 		markerScoreDownUtil(player, 6, 13, 13);
// 	}
// }

// void game::markerScoreSWUtil(int player, int startx, int a, int b){
//     int opponent = (player==1)?2:1;
//     int mymarker = (player == 1)?3:4;
//     int oppmarker = (player == 1)?4:3;
// 	int x;
// 	int y;
// 	int count = 0;
//     int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
//     bool b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//     int c1 = 0, c2 = 0, m3r2_1 = 0, m3r2_2 = 0;

//     for(int i=a;i<b;i++){
//     	x = startx;
//     	y = i;
//         count = 0;
//         count1 = 0; count2 = 0; count3 = 0; count4 = 0; count5 = 0;
//         b1 = 0; b2 = 0; c1 = 0; c2 = 0;
//     	while(state[x][y]!=1){
// 	        // k markers in row
//             if(state[x][y] == mymarker){
//                 count++;
//             }
//             else{
//                 hue1[count-1]++;
//                 count = 0;
//             }
//             if(count == nom){
//                 hue1[count-1]++;
//                 count--;
//             }
//             // opponent
//             if(state[x][y] == mymarker){
//                 count1++;
//             }
//             else{
//                 hue2[count1-1]++;
//                 count1 = 0;
//             }
//             if(count1 == nom){
//                 hue2[count1-1]++;
//                 count1--;
//             }


//             // four m's and 1 ring // mine
//             if(state[x][y] == mymarker){
//             	count2++;
//             }
//             else if(state[x][y] == player && !b1){
//             	count2++;
//             	b1 = 1;
//             }
//             else{
//             	count2 = 0;
//             	b1 = 0;
//             }
//             if(count2 == nom){
//             	hue1[6]++;
//             }
//             // four m's and 1 ring // opponent
//             if(state[x][y] == oppmarker){
//             	count3++;
//             }
//             else if(state[x][y] == opponent && !b2){
//             	count3++;
//             	b2 = 1;
//             }
//             else{
//             	count3 = 0;
//             	b2 = 0;
//             }
//             if(count3 == nom){
//             	hue2[6]++;
//             }

//             // 3 m's and 2 r's // mine
//             if(state[x][y] == mymarker){
//             	count4++;
//             }
//             else if(state[x][y] == player && c1<2){
//             	count4++;
//             	c1 += 1;
//             }
//             else{
//             	count4 = 0;
//             	c1 = 0;
//             }
//             if(count4 == nom && c1 == 2){
//             	hue1[7]++;
//             }
//             // 3 m's and 2 r's // opponent
//             if(state[x][y] == oppmarker){
//             	count5++;
//             }
//             else if(state[x][y] == opponent && c2<2){
//             	count5++;
//             	c2 += 1;
//             }
//             else{
//             	count5 = 0;
//             	c2 = 0;
//             }
//             if(count5 == nom && c2 == 2){
//             	hue2[7]++;
//             }

// 			pair<int, int> p = get4(x, y);
// 			x = p.first; y = p.second;            
//     	}
//     }
// }