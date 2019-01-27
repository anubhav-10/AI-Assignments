#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define pb push_back

float get_soft(vector<vector<float>> soft,int n,int x){
	if (n==x) 
		return 1;
	if (n>16)
		return 0;
	return soft[n-11][x-17];
}

float get_val(vector<vector<float>> hard2to16,int n,int x){
	if (n==x)
		return 1;
	else if (n>16)
		return 0;
	return hard2to16[n-2][x-17];
}

vector<vector<float>> dealer(float p){
	vector<vector<float>> hard;
	for(int i=0;i<15;i++){
		vector<float> v(7, 0);
		hard.pb(v);
	}
	float p_dash = (1 - p)/9.0;
	vector<float> v(5,p_dash);
	hard[14] = v;
	hard[14].pb(4*p_dash + p);
	hard[14].pb(0);
	
	for(int i=15;i>10;i--){
		for(int j=17;j<22;j++){
			hard[i-2][j-17] = p*get_val(hard, i+10, j);
			float sum = 0;
			for(int k=1;k<10;k++){
				sum += get_val(hard, i+k, j);
			}
			hard[i-2][j-17] += p_dash*sum;
		}
	}
	vector<vector<float>> soft;
	for(int i=0;i<6;i++){
		vector<float> v(7, 0);
		soft.pb(v);
	}
	for(int i=16;i>10;i--){
		for(int j=17;j<22;j++){
			if(i==11){
				float sum=0;
				for(int k=1;k<10;k++)
					sum+=get_soft(soft, i+k, j);
				soft[i-11][j-17]=p_dash*sum;
			}
			else{
				float sum=0;
				for(int k=1;k<21-i+1;k++)
					sum+=get_soft(soft, i+k, j);
				for(int k=21-i+1;k<10;k++)
					sum+=get_val(hard, i+k-10, j);
				soft[i-11][j-17]=p_dash*sum + p*get_val(hard, i, j);
			}
		}
	}
	for(int i=10;i>1;i--){
		for(int j=17;j<22;j++){
			float sum=0;
			for(int k=2;k<10;k++)
				sum+=get_val(hard, i+k, j);
			hard[i-2][j-17]=p_dash*sum + p*get_val(hard, i+10, j) + p_dash*get_soft(soft, i+11, j);
		}
	}
	
	vector<vector<float>> out;
	for(int i=0;i<9;i++)
		out.pb(hard[i]);
	out.pb(soft[0]);
	out[8][5] = p_dash;
	out[9][5] = p;
	out[8][4] -= p_dash;

	for(int i=0; i<out.size(); i++){
		float s = 0;
		for(int y=0;y<6;y++)
			s+=out.at(i).at(y);
		out.at(i).at(6) = 1-s;
	}
	return out;
}

unordered_map<string,string> player(float p, vector<float> d){
	unordered_map<string,string> moves;
	float p_dash = (1 - p)/9.0;
	vector<float> stand(18,0);
	
	for(int i=4;i<22;i++){
		if(i<17){
			stand[i-4] = 2*d[6] - 1;
		}
		else{
			float sum=0;
			for(int j=0;j<i-17;j++)
				sum += d[j];
			for(int j=i-16;j<6;j++)
				sum -= d[j];
			sum += d[6];
			stand[i-4] = sum;
		}
	}
		
	float hit;
	vector<float> hard(18,0);
	for(int i=21;i>11;i--){
		float sum = 0;
		for(int j=1;j<22-i;j++)
			sum+=hard[i+j-4];
		for(int j=22-i;j<10;j++)
			sum-=1;
		hit = p_dash*sum - p;
		float sta = stand[i-4];
		if(hit>sta){
			hard[i-4] = hit;
			moves[to_string(i)] = "H";
		}
		else{
			hard[i-4] = sta;
			moves[to_string(i)] = "S";
		}
	}
	float sum=0;
	for(int i=1;i<10;i++)
		sum+=hard[7+i];
	hit = p_dash * sum + p * hard[17];
	float sta = stand[7];
	if(hit>sta){
		hard[7] = hit;
		moves["11"] = "H";
	}
	else{
		hard[7] = sta;
		moves["11"] = "S";
	}
	
	vector<float> soft(10,0);
	for(int i=21;i>11;i--){
		float sum=0;
		for(int j=1;j<22-i;j++)
			sum+=soft[i+j-12];
		for(int j=22-i;j<10;j++)
			sum+=hard[i+j-14];
		hit = p_dash * sum + p * hard[i-4];
		sta = stand[i-4];
		if(hit>sta){
			soft[i-12] = hit;
			moves["A"+to_string(i-11)] = "H";
		}
		else{
			soft[i-12] = sta;	
			moves["A"+to_string(i-11)] = "S";
		}
	}

	for(int i=10;i>3;i--){
		float sum=0;
		for(int j=2;j<10;j++)
			sum += hard[i+j-4];
		hit = p_dash*sum + p*hard[i+6] + p_dash*soft[i-1];
		sta = stand[i-4];
		if(hit>sta){
			hard[i-4] = hit;
			moves[to_string(i)] = "H";
		}
		else{
			hard[i-4] = sta;
			moves[to_string(i)] = "S";
		}
	}

	vector<float> floate(18);
	for(int i=12;i<21;i++){
		float sum=0;
		for(int j=1;j<22-i;j++)
			sum+=stand[i+j-4];
		floate[i-4] = 2*(p_dash*sum - p - p_dash*(10 - 22 + i));
	}
	sum=0;
	for(int i=1;i<10;i++)
		sum+=stand[7+i];
	
	floate[7] = 2*(p_dash*sum + p*stand[17]);
	for(int i=4;i<11;i++){
		float sum=0;
		for(int j=2;j<10;j++)
			sum+=stand[i+j-4];
		floate[i-4] = 2*(p_dash*sum + p*stand[i+10-4] + p_dash*stand[i+11-4]);
	}

	vector<float> float_soft(10);	
	for(int i=12;i<22;i++){
		float sum=0;
		for(int j=1;j<22-i;j++)
			sum+=stand[i+j-4];
		for(int j=22-i;j<10;j++)
			sum+=stand[i+j-10-4];
		float_soft[i-12] = 2*(p_dash*sum + p*stand[i-4]);
	}
	
	vector<float> hard_final(18);
	for(int i=0;i<18;i++){
		if(hard[i]<floate[i]){
			hard_final[i] = floate[i];
			moves[to_string(i+4)] = "D";
		}
		else{
			hard_final[i] = hard[i];
		}
	}
	vector<float> soft_final(10);
	for(int i=0;i<10;i++){
		if(soft[i]<float_soft[i]){
			soft_final[i] = float_soft[i];
			moves["A"+to_string(i+1)] = "D";
		}
		else{
			soft_final[i] = soft[i];
		}
	}
	
	vector<float> pair(10);
	float pairin = 0;
	for(int i=2;i<10;i++){
		float sum=0;
		for(int j=2;j<10;j++)
			if(j!=i)
				sum+=hard_final[i+j-4];
		pairin = 2/(1-2*p_dash)*(p_dash*sum + p_dash*soft_final[i+11-12] + p*hard_final[i+10-4]);
		float har = hard_final[2*i - 4];
		if(har>pairin){
			pair[i-1] = har;
			moves[to_string(i)+to_string(i)] = moves[to_string(2*i)];
		}	
		else{
			pair[i-1] = pairin;
			moves[to_string(i)+to_string(i)] = "P";

		}
	}
	
	sum=0;
	for(int i=1;i<10;i++){
		sum+=stand[11+i-4];
	}
	pairin = 2*p_dash*sum + 2*p*stand[17];
	float sof = soft_final[0];
	if(pairin>sof){
		pair[0] = pairin;
		moves["AA"] = "P";
	}
	else{
		pair[0] = sof;
		moves["AA"] = moves["A1"];
	}
	
	sum = 0;
	for(int i=2;i<10;i++){
		sum+=hard_final[10+i-4];
	}
	pairin = (2*p_dash*sum + 3*p_dash*(1-d[5]))/(1-2*p);
	float har = hard_final[16];
	if(pairin > har){
		pair[9] = pairin;
		moves["1010"] = "P";
	}
	else{
		pair[9] = har;
		moves["1010"] = moves["20"];
	}
	
	return moves;
}

int main(){
	float p;
	cin >> p;
	vector<vector<float>> dealerp = dealer(p);
	
	vector<unordered_map<string,string>> moves;
	for(int i=0;i<10;i++){
		moves.pb(player(p,dealerp[i]));
	}
	
	for(int i=5;i<20;i++){
		cout<<i<<"\t";
		for(auto j:moves){
			
			cout<<j[(to_string(i))]<<" ";
		}
		cout<<endl;
	}

	for(int i=2;i<10;i++){
		cout<<("A"+to_string(i))<<"\t";
		for(auto j:moves){
			cout<<j["A"+to_string(i)]<<" ";
		}
		cout<<endl;
	}
	for(int i=2;i<11;i++){
		cout<<(to_string(i)+to_string(i))<<"\t";
		for(auto j:moves){
			cout<<j[(to_string(i)+to_string(i))]<<" ";
		}
		cout<<endl;
	}
	cout<<"AA\t";
	for(auto j:moves){
		cout<<j["AA"]<<" ";
	}

	return 0;
}	
