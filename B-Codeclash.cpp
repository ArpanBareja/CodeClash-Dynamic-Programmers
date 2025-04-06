#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent;
public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main() {
	vector<vector<int>> mat(10,vector<int>(10,0));
	for(int i=0;i<10;i++){
	    for(int j=0;j<10;j++){
	        cin>>mat[i][j];
	    }
	}
	
	DSU d(100);
	for(int i=0;i<10;i++){
	    for(int j=0;j<10;j++){
	        if(mat[i][j]==0){
	            if(i+1<10&&mat[i+1][j]==0){
	                d.unionByRank(i*10+j,(i+1)*10+j);
	            }
	            if(j+1<10&&mat[i][j+1]==0){
	                d.unionByRank(i*10+j,(i)*10+j+1);
	            }
	            if(i-1>=0&&mat[i-1][j]==0){
	                d.unionByRank(i*10+j,(i-1)*10+j);
	            }
	            if(j-1>=0&&mat[i][j-1]==0){
	                d.unionByRank(i*10+j,(i)*10+j-1);
	            }
	        }
	    }
	}
	
	unordered_map<int,int> mpp;
	for(int i=0;i<10;i++){
	    for(int j=0;j<10;j++){
	        if(mat[i][j]==0){
	            mpp[d.findUPar(i*10+j)]++;
	        }
	    }
	}
	
	cout<<mpp.size()<<endl;
	for(auto it: mpp){
	    cout<<it.second<<endl;
	}
	
	

}
