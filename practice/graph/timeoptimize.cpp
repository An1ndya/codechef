//same as fireEscaperoute just do the time optimization
#include <bits/stdc++.h>
using namespace std;
unsigned int mod =1000000007;
vector<bool> isVisited;
vector<vector<int>> graph;
int DFS(int n)
{
    //cout<<n<<"->";
    isVisited[n] = true;
    int NumberOfNode = 1; //start with one beacuse each node have one node :D
    for(int i=0;i<graph[n].size();i++)
    {
        if(isVisited[graph[n][i]]==false)
        {
             NumberOfNode = NumberOfNode + DFS(graph[n][i]);
        }
    }
    return NumberOfNode;

}

int main() {

	int t;
	cin>>t;
    for(int k=0;k<t;k++)
	{
	    int n,m;
	    cin>>n>>m;
        graph.clear();
	    graph.resize(n);
        
        isVisited.assign(n, false);
        //isVisited[0]=true;
	    for(int i=0;i<m;i++)
	    {
	        int u, v;
	        cin>>u>>v;
            graph[u-1].push_back(v-1);
           // cout<<"come";
            graph[v-1].push_back(u-1);
            //cout<<i<<endl;
	       
	    }

        long long int permutationofCaptain = 1;
        int numberofFireRoute = 0;
        for(int i=0;i<n;i++)
        {
            //int noOfNode;
            //cout<<i<<" "<<isVisited[i]<<endl;
            if(isVisited[i]==false)
            {
                int noOfNode = DFS(i);
                numberofFireRoute++;
                permutationofCaptain = (permutationofCaptain*(noOfNode%mod))%mod;
                //cout<<isVisited[i]<<endl;

            }
        }
	    
	    cout<<numberofFireRoute<<" "<<permutationofCaptain<<endl;
	}
	return 0;
}
