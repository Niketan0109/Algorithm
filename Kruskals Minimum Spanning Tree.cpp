#include <iostream>
using namespace std;

#define V 6
#define INFINITY 99999

int graph[V][V] = {
	{0, 4, 1, 4, INFINITY, INFINITY},
	{4, 0, 3, 8, 3, INFINITY},
	{1, 3, 0, INFINITY, 1, INFINITY},
	{4, 8, INFINITY, 0, 5, 7},
	{INFINITY, 3, 1, 5, 0, INFINITY},
	{INFINITY, INFINITY, INFINITY, 7, INFINITY, 0}};

void findMinimumEdge()
{
	for (int i = 0; i < V; i++)
	{
		int min = INFINITY;
		int minIndex = 0;
		for (int j = 0; j < V; j++)
		{
			if (graph[i][j] != 0 && graph[i][j] < min)
			{
				min = graph[i][j];
				minIndex = j;
			}
		}
		cout << i << "  -  " << minIndex << "\t" << graph[i][minIndex] << "\n";
	}
}

int main()
{
	findMinimumEdge();
	return 0;
}

# another code
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
vector<int>parent(N);
vector<int> sz(N);

void make_set(int v)
{
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v)
{
    if(v==parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a,int b)
{
  a = find_set(a);
  b = find_set(b);
  if(a!=b)
  {
      if(sz[a]<sz[b])
      {
          swap(a,b);
      }
      parent[b]=a;
      sz[a]+=sz[b];
  }
}
int main()
{
    for(int i=0;i<N;i++)
    {
        make_set(i);
    }
    int n,m,cost=0;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
       edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    for(auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];

        int x = find_set(u);
        int y = find_set(v);

        if(x==y)
        {
            continue;
        }
        else{
            cout<<u<<" "<<v<<"\n";
            cost+=w;
            union_set(u,v);
        }
    }
    cout<<cost;
    return 0;
}
