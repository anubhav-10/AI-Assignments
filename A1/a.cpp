#include<iostream>
#include<cmath>
#include <random>
#include<algorithm>
#include<ctime>
#include<chrono>
#define swap(a,b) a^=b^=a^=b
using namespace std;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::steady_clock;
float PT,C;
int K,P,T,N;
float D[10000][10000];
int ARR[10000];

float good(){
	float score=0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(i/(P * K) !=j/(P * K)){
				continue;
			} 
			if(i/K==j/K){
				score+=1-D[ARR[i]][ARR[j]];
			}
			else{
				score+=C*D[ARR[i]][ARR[j]];
			}
		}
	}

	return score;
}
string convert_to_string(int *arr){
	string s="";
	int x=0,y=0;
	for(int i=0;i<N;i++){
		s+=to_string(arr[i]);
		s+=" ";
		x++;
		y++;
		if(y==P*K){
			s+="\n";
			y=0;
			x=0;
		}
		if(x==K){
			s+="| ";
			x=0;
		}
	}
	return s;
}
float goodness(){
	float score=0;
	for(int _t=0;_t<T;_t++){
		for(int i=0;i<P * K;i++){
			for(int j = i + 1; j < P * K; ++j){
				if((i + _t*P*K)/K == (j + _t*P*K)/K){
					score+=1-D[ARR[i+_t*P*K]][ARR[j+_t*P*K]];
				} else {
					score += C*D[ARR[i+_t*P*K]][ARR[j+_t*P*K]];
				}
			}
		}
	}

	return score;
}
float delta_goodness(int a,int b){
	int t1=a/(P*K),t2=b/(P*K);
	int s1=a/K,s2=b/K;
	float delta=0;
	if(t1==t2){
		if(s1==s2) return 0;
		else{			
			for(int i=s1*K;i<(s1+1)*K;i++){
				if(i==a) continue;
				// delta-=1-D[ARR[i]][ARR[a]];
				delta+=(C+1)*(D[ARR[i]][ARR[a]]-D[ARR[i]][ARR[b]]);

				// delta-=(C+1)*D[ARR[i]][ARR[b]];
				// delta+=1-D[ARR[i]][ARR[b]];
			}
			for(int i=s2*K;i<(s2+1)*K;i++){
				if(i==b) continue;
				// delta-=1-D[ARR[i]][ARR[b]];
				delta+=(C+1)*(D[ARR[i]][ARR[b]]-D[ARR[i]][ARR[a]]);

				// delta-=(C+1)*D[ARR[i]][ARR[a]];
				// delta+=1-D[ARR[i]][ARR[a]];
			}
		}
	}
	else{
		for(int i=0;i<P*K;i++){
			int index=i+t1*P*K;
			if(index/K==s1){
				if(index==a) continue;
				// delta-=1-D[ARR[index]][ARR[a]];

				delta+=D[ARR[index]][ARR[a]]-D[ARR[index]][ARR[b]];
			}
			else{
				// delta-=C*D[ARR[index]][ARR[a]];
				delta+=C*(D[ARR[index]][ARR[b]]-D[ARR[index]][ARR[a]]);
			}
		}
		for(int i=0;i<P*K;i++){
			int index=i+t2*P*K;
			if(index/K==s2){
				if(index==b) continue;
				// delta-=1-D[ARR[index]][ARR[b]];

				delta+=D[ARR[index]][ARR[b]]-D[ARR[index]][ARR[a]];
			}
			else{
				// delta-=C*D[ARR[index]][ARR[b]];
				delta+=C*(D[ARR[index]][ARR[a]]-D[ARR[index]][ARR[b]]);
			}
		}
	}
	return delta;
}


void random_restart(){
	random_shuffle(&ARR[0],&ARR[N]);
}
bool best_swap(float curr_good,int &a,int &b){
	int max=0;
	// cout<<"abc"<<endl;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			float delta=delta_goodness(i,j);
			if(delta>max){
				max=delta;
				a=i;
				b=j;
			}
		}
	}
	return (max>0)?1:0;
}
float session_delta(int a,int b){
	int t1=a/P,t2=b/P;
	// cout<<a<<" "<<b<<endl;
	float delta=0;
	for(int i=t1*P*K;i<t1*(P+1)*K;i++){
		for(int j=0;j<P*K;j++){
			int index1=j+t1*P*K;
			int index2=j+t2*P*K;
			if(index1/K!=a){ 
				delta-=C*D[ARR[index1]][ARR[i]];
			}
			if(index2/K!=b){
				delta+=C*D[ARR[index2]][ARR[i]];
			}
		}
	}
	for(int i=t2*P*K;i<t2*(P+1)*K;i++){
		for(int j=0;j<P*K;j++){
			int index1=j+t2*P*K;
			int index2=j+t1*P*K;
			if(index1/K!=b){ 
				delta-=C*D[ARR[index1]][ARR[i]];
			}
			if(index2/K!=a){
				delta+=C*D[ARR[index2]][ARR[i]];
			}
		}
	}
	return delta;
}

bool best_session_swap(int &a,int &b){
	int max=0;
	// cout<<"abc"<<endl;
	for(int i=0;i<P*T;i++){
		for(int j=i+1;j<P*T;j++){
			float delta=session_delta(i,j);
			if(delta>max){
				max=delta;
				a=i;
				b=j;
			}
		}
	}
	return (max>0)?1:0;
}

bool random_swap(float curr_good,int &a,int &b){
	int max=0;

	int i=rand()%N;
	int j=rand()%N;
	int z=0;
	while(z<20){
		float delta=delta_goodness(i,j);
		if(delta>0){
			a=i;
			b=j;
			return 1;
		}
		z++;
	}
	return 0;
}
void random_walk(){
}
int main(){
	cin>>PT>>K>>P>>T>>C;
	steady_clock::time_point t1=steady_clock::now();
	N=K*P*T;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>D[i][j];
		}
	for(int i=0;i<N;i++){
		ARR[i]=i;
	}
	random_shuffle(&ARR[0],&ARR[N]);
	string ans=convert_to_string(ARR);
	float max=0;
	max=goodness();
	steady_clock::time_point t2=steady_clock::now();
	float duration=(float)duration_cast<nanoseconds>(t2-t1).count()/1000000000;
	float greedy_prob=(rand()%100)/(float)100,walk_prob=(rand()%100)/(float)100;
	double Temp = 10000000;
	double alpha = 10;
	int counter=1;
	PT-=1/(float)60;
	while(1){
		Temp/=(1+alpha*log(counter));
		// alpha++;
		counter++;
		if(Temp==0.000001){
			break;
			// random_restart();
		}
		int a=rand()%(N);
		int b=rand()%(N);
		float delta=delta_goodness(a,b);

		if(delta>0){
			int y=ARR[a];
			ARR[a]=ARR[b];
			ARR[b]=y;
			// swap(ARR[a],ARR[b]);
			max=goodness();
			ans=convert_to_string(ARR);
		}
		else if((exp(delta/Temp))>0.7){
			int y=ARR[a];
			ARR[a]=ARR[b];
			ARR[b]=y;
			// swap(ARR[a],ARR[b]);
		}

		steady_clock::time_point t2=steady_clock::now();
		float duration=(float)duration_cast<nanoseconds>(t2-t1).count()/1000000000;
		// cout<<duration<<endl;
		if(duration>PT*60) break;
	}
	// cout<<counter<<endl;	
	cout<<ans;
	return 0;
}
