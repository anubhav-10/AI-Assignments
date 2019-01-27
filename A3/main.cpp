#include<iostream>
#include<fstream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;

int V,E,K,count;
vector<vector<bool> > graph;
string inputfile;

void input(int argc, char *argv[]){
	freopen(argv[1],"r",stdin);
	cin >> V >> E >> K;

	for(int i=0;i<V;i++){
		vector<bool> v;
		for(int j=0;j<V;j++)
			v.push_back(0);
		graph.push_back(v);
	}
	int x,y;
	for(int i=0;i<E;i++){
		cin>>x>>y;
		graph[x-1][y-1] = 1;
		graph[y-1][x-1] = 1;
	}
	count = 0;
	fclose(stdin);
}

inline int encode(int i,int k){
	return V * k + i + 1; 
}

inline int encode(int i,int j,int k){
	return V*K + (k*V*(V-1))/2 + V*i - (i*(i+1))/2 + j - i;
	// return V*K + k*V*V + V*i + j + 1;
}

inline int encode(int i,int k1,int k2,int temp){
	return (K*V*(V+1))/2 + i*K*K + K*k1 + k2 + 1 ;
	// return V*K + V*V*K + i*K*K + K*k1 + k2 + 1;
}

void nodeBelong(){
	for(int i=0;i<V;i++){
		for(int j=0;j<K;j++){
			cout<<encode(i,j)<<" ";
		}
		cout<<0<<endl;
		count++;
	}
}

void edgeBelong(){
	for(int i=0;i<V;i++){
		for(int j=i+1;j<V;j++){
			if(graph[i][j]){
				//cout<<i<<" "<<j<<endl;
				for(int k=0;k<K;k++){
					cout<<encode(i,j,k)<<" ";
				}	
				cout<<0<<endl;
				count++;
				for(int k=0;k<K;k++){
					cout<<-encode(i,j,k)<<" "<<encode(i,k)<<" 0"<<endl;
					count++;
					cout<<-encode(i,j,k)<<" "<<encode(j,k)<<" 0"<<endl;
					count++;
					cout<<-encode(i,k)<<" "<<-encode(j,k)<<" "<<encode(i,j,k)<<" 0"<<endl;
					count++;
				}
			}
		}
	}
}

void completeSubGraph(){
	for(int k=0;k<K;k++){
		for(int i=0;i<V;i++){
			for(int j=i+1;j<V;j++){
				if(!graph[i][j]){
					cout<<-encode(i,k)<<" "<<-encode(j,k)<<" "<<0<<endl;
					count++;
				}
			}
		}
	}
}

void notSubset(){
	for(int k1=0;k1<K;k1++){
		for(int k2=0;k2<K;k2++){
			if(k1==k2)
				continue;
			for(int i=0;i<V;i++){
				cout<<encode(i,k1,k2,0)<<" ";
			}
			cout<<0<<endl;
			count++;
			for(int i=0;i<V;i++){
				cout<<-encode(i,k1,k2,0)<<" "<<encode(i,k1)<<" 0"<<endl;
				count++;
				cout<<-encode(i,k1,k2,0)<<" "<<-encode(i,k2)<<" 0"<<endl;
				count++;
				cout<<-encode(i,k1)<<" "<<encode(i,k2)<<" "<<encode(i,k1,k2,0)<<" 0"<<endl;
				count++;
			}
		}
	}	
}

void nonEmpty(){
	for(int k=0;k<K;k++){
		for(int i=0;i<V;i++){
			cout<<encode(i,k)<<" ";
		}
		cout<<0<<endl;
		count++;
	}
} 

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input(argc, argv);
	freopen("file2.txt","w",stdout);
	nodeBelong();
	edgeBelong();
	completeSubGraph();
	notSubset();
	nonEmpty();
	fclose(stdout);
	
	//ofstream file;
	freopen("file1.txt","w",stdout);
	//file.open("file1.txt");
	cout<<"p cnf "<<((K*V*(V+1))/2 + V*K*K)<<" "<<count<<endl; 
	fclose(stdout);

	return 0;
}
