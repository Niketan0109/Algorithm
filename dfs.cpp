int vis[];//visiting array and adj is adjacency list
void dfs(int node)
{
	vis[node]=1;
	for(int child:adj[node])
	{
		if(vis[child]==0)
		{
			dfs(child);
		}
	}
}