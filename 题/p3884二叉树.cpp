#include<iostream>
#include<queue>
using namespace std;
int fa[105],node[105][2];
int max_width,depth;
//用于回溯确定公共父结点
int reach[105],dis[105];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>> u>> v;
        fa[v]=u;
        if(node[u][0]) node[u][1]=v;
        else node[u][0]=v;
    }
    //初始化
    max_width=1,depth=0;
    int width=1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int temp=0;
        for(int i=0;i<width;i++){
            int x=q.front();
            q.pop();
            if(node[x][0]) q.push(node[x][0]),temp++;
            if(node[x][1]) q.push(node[x][1]),temp++;
        }
        if(temp>max_width) max_width=temp;
        width=temp;
        depth++;
    }
    cout<< depth << endl<< max_width << endl;
    int x,y;
    cin >> x >> y;
    //先x往根移动
    reach[x]=1;
    int x_dis=0,y_dis=0;
    while(!reach[fa[x]]){
        x_dis++;
        x=fa[x];
        reach[x]=1,dis[x]=x_dis;
    }
    //再动y
    if(!reach[y]){
        while(!reach[fa[y]]){
            y_dis++;
            y=fa[y];
            reach[y]=1,dis[y]=y_dis;
        }
        cout << y_dis+1+dis[fa[y]]*2 << endl;
    }else{//即若y是x的祖先结点之一
        cout << dis[y]*2 << endl; 
    } 
    return 0;
}