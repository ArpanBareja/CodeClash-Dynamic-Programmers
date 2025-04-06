#include <bits/stdc++.h>
using namespace std;

bool temp=true;
int solve(){
    int m;
	cin>>m;
    if(m==0){
        temp=false;
        return 0;
    }
	vector<int> d(m,0);
	for(int i=0;i<m;i++) cin>>d[i];
	
	int narrow=d[0];
	int broad=2*d[0];
	
	string help="";

	for(int i=0;i<m;i++){
	    if((abs(d[i]-narrow)/narrow)*100>5&&(abs(d[i]-broad)/broad)*100>5){
	        cout<<"bad code"<<endl;
	        return 0;
	    }
	    if(abs(d[i]-narrow)<abs(d[i]-broad)){
	        help.push_back('0');
	    }
	    else{
	        help.push_back('1');
	    }
	}
	
	
	unordered_map<string, string> mpp = {
        {"00001", "0"},
        {"10001", "1"},
        {"01001", "2"},
        {"11000", "3"},
        {"00101", "4"},
        {"10100", "5"},
        {"01100", "6"},
        {"00011", "7"},
        {"10010", "8"},
        {"10000", "9"},
        {"00100", "-"},
        {"00110", "S"}
    };
    
    unordered_map<string, string> mpp2 = {
    {"10000", "0"},
    {"10001", "1"},
    {"10010", "2"},
    {"00011", "3"},
    {"10100", "4"},
    {"00101", "5"},
    {"00110", "6"},
    {"11000", "7"},
    {"01001", "8"},
    {"00001", "9"},
    {"00100", "-"},
    {"01100", "S"}
};
    
    unordered_map<char, int> w = {
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'0', 0},
        {'-', 10},

    };
	
    if((m+1)%6!=0){
        cout<<"bad code"<<endl;
        return 0;
    }
	

	
	
	
	if(help.substr(0,5)=="00110"&&help.substr(help.size()-5,5)=="00110"){

	}
	else if(help.substr(0,5)=="01100"&&help.substr(help.size()-5,5)=="01100"){
	    reverse(help.begin(),help.end());
	}
	else{
	    cout<<"bad code"<<endl;
	    return 0;
	}

    if(5<help.size()&&help[5]!='0'){
        cout<<"bad code"<<endl;
        return 0;
    }
	
	
	int i=6;
	
	
	
	string res="";
	
	while(i<help.size()-6){
	    string str=help.substr(i,5);
	    if(mpp.find(str)==mpp.end()){
	        cout<<"bad code"<<endl;
	        return 0;
	    }
	    res.push_back(mpp[str][0]);
	    if(i+5<help.size()){
	        if(help[i+5]!='0'){
	            cout<<"bad code"<<endl;
	            return 0;
	        }
	    }
	    i+=6;
	}
	
	int C=res[res.size()-2]-'0';
	int K=res[res.size()-1]-'0';
	
	int n1=0,n2=0;
	int len=res.size()-2;
	

	
	for(int i=0;i<res.size()-2;i++){
	    n1+=(((((len-(i+1))%10)+1)*w[res[i]]));
	    n2+=((((len-(i+1)+1)%9)+1)*w[res[i]]);
	}
	
	
	
	n1=n1%11;
	char c='0'+n1;
	n2+=w[c];
	
	
	
	n2=n2%11;
	
	
	if(n1!=C){
	    cout<<"bad C"<<endl;
	    return 0;
	}
	
	if(n2!=K){
	    cout<<"bad K"<<endl;
	    return 0;
	}
	
	cout<<res.substr(0,res.size()-2)<<endl;

    return 0;
}

int main() {
	while(temp){
        solve();
    }



    return 0;
}
