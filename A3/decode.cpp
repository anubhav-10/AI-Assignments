#include<iostream>
#include<fstream>
using namespace std;

int main(){
	int V,E,K;
	cin>>V>>E>>K;
	string s;
	cin>>s;
	if(s=="UNSAT"){
		cout<<0<<endl;
		return 0;
	}
	for(int k=0;k<K;k++){
		string ans="";
		int count=0;
		for(int i=0;i<V;i++){
			int x;
			cin>>x;
			if(x>0){
				ans+=to_string(i+1)+" ";
				count++;
			}
		}
		cout<<"#"<<to_string(k+1)<<" "<<count<<endl;
		ans = ans.substr(0, ans.size()-1);
		cout<<ans<<endl;
	}

}
