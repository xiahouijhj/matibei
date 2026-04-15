#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647;
int n,m,s,cnt=0,dis[100030],vis[100030],head[100030];
struct node
{
	int w,now;
	inline bool operator <(const node &x)const
	{
		return w>x.w;
	}
};
priority_queue<node> q;
struct ad
{
	int v,w,next;
}e[500003];
inline void add(int u,int v,int w) 
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void js()
{
	int a,b,c;
	for(a=1;a<=n;a++)
	{
		dis[a]=INF;
	}
	dis[s]=0;
	q.push((node){0,s});
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		int u=x.now;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		 {
		 	int v=e[i].v;
		 	if(dis[v]>dis[u]+e[i].w)
		 	{
		 		dis[v]=dis[u]+e[i].w;
		 		q.push((node){dis[v],v});
			 }
		 }		 
	}
}
int main()
{
	int a,b,c,d;
	memset(vis,0,sizeof(vis));
	scanf("%d %d %d",&n,&m,&s);
	for(a=0;a<m;a++)
	{
		scanf("%d %d %d",&b,&c,&d);
		add(b,c,d); 
	}
	js();
	for(a=1;a<=n;a++)
	{
		printf("%d ",dis[a]);
	 }
	 return 0;
}
