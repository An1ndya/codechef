//same as fireEscaperoute just do the time optimization
#include <bits/stdc++.h>
using namespace std;
unsigned int mod =1000000007;
vector<bool> isVisited;
vector<vector<int>> graph;


int main() {

	int n,e,a,u,v,w,q;
    long long int x;
    cin>>n>>e>>a;
	cin>>t;
 
    graph.clear();
    graph.resize(n);
    
    isVisited.assign(n, false);
    //isVisited[0]=true;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        // cout<<"come";
        graph[v-1].push_back(u-1);
        //cout<<i<<endl;
        
    }

}
