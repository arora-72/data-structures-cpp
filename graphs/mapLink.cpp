#include<bits/stdc++.h>
using namespace std;
vector<int> path(int** edges,bool* visited,int n,int sv,int ev)
{
  queue<int> q;
  q.push(sv);
  visited[sv]=true;
  map<int,int> m;
  while(!q.empty() && q.front()!=ev)
  {
    
    int ele=q.front();
    for(int i=0;i<n;i++)
    {
      if(i==ele)
        continue;
      if(edges[ele][i]==1)
      {
        if(visited[i])
          continue;
        m[i]=ele;
        q.push(i);
        visited[i]=true;
      }
    }
    q.pop();
  }
  
  if(q.empty())
  {
    vector<int> v;
    return v;
  }
  else
  {vector<int> v;
  int h=m[ev];
  v.push_back(ev);
  while(h!=sv)
  {
    v.push_back(h);
    h=m[h];
  }
  v.push_back(sv);
  return v;
  }
}

int main() {
  int n,e;
  cin>>n>>e;
  int** edges=new int*[n];
  for(int i=0;i<n;i++)
  {
    edges[i]=new int[n];
    for(int j=0;j<n;j++)
      edges[i][j]=0;
  }
  for(int i=0;i<e;i++)
  {
    int f,s;
    cin>>f>>s;
    edges[f][s]=1;
    edges[s][f]=1;
  }
  bool* visited=new bool[n];
  for(int i=0;i<n;i++)
    visited[i]=false;
  int start,end;
  cin>>start>>end;
  vector<int> v=path(edges,visited,n,start,end);
  if(v.size()!=0){
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<endl;}
  return 0;
}

