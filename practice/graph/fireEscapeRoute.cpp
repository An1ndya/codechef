#include <bits/stdc++.h>
using namespace std;
unsigned int mod =1000000007;
int DFS(vector<vector<int>> graph,vector<bool> &isVisited,int n)
{
    isVisited[n] = true;
    int NumberOfNode = 1; //start with one beacuse each node have one node :D
    for(int i=0;i<graph[n].size();i++)
    {
        if(isVisited[graph[n][i]]==false)
        {
             NumberOfNode = NumberOfNode + DFS(graph,isVisited,graph[n][i]);
        }
    }
    return NumberOfNode;
}

int main()
{
    //faster input output
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
	int t;
	cin>>t;
    for(int k=0;k<t;k++)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> graph(n+1);
        vector<bool> isVisited;
        isVisited.assign(n+1, false);
	    for(int i=0;i<m;i++)
	    {
	        int u, v;
	        cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);  
	    }
        long long int permutationofCaptain = 1;
        int numberofFireRoute = 0;
        for(int i=1;i<=n;i++)
        {
            if(isVisited[i]==false)
            {
                int noOfNode = DFS(graph,isVisited,i);
                numberofFireRoute++;
                permutationofCaptain = (permutationofCaptain*(noOfNode%mod))%mod;
            }
        }  
	    cout<<numberofFireRoute<<" "<<permutationofCaptain<<endl;
	}
	return 0;
}
