
#include<bits/stdc++.h>
using namespace std;

const int SIZE= 100000+10;



struct edge{
    int a,b,w;
};


edge ar[100005];
int par[100005];



bool comp(edge a,edge b){
    return a.w<b.w;
}


int find(int x){
    if(x==par[x]) return x;
    else return par[x]=find(par[x]);
}



void unite(int x,int y){
    x=find(x);
    y=find(y);
    par[x]=y;
}



int main(){
// n is no of nodes
// m is no of edges
int n,m;
cin>>n>>m;

for(int i=0;i<m;i++){
    cin>>ar[i].a>>ar[i].b>>ar[i].w;
}
int sum=0;
sort(ar,ar+m,comp);

for(int i=1;i<n+1;i++) par[i]=i;

for(int i=0;i<m;i++){
    int x=ar[i].a;
    int y=ar[i].b;
    if(find(x)!=find(y)){
        unite(x,y);
        sum+=ar[i].w;
    }
}

cout<<sum<<endl;
 
return 0;
}
