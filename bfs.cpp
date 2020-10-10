int vis[],dis[];//vis is visiting array and dis is distance array and adj is adjacency matrix
void bfs(int src)
{
	vis[src]=1;
	dis[src]=0;
	queue<int>q;
	q.push(src);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int child:adj[cur])
		{
			if(vis[child]==0)
			{
				vis[child]=1;
				dis[child]=dis[cur]+1;
				q.push(child);
			}
		}
	}
}