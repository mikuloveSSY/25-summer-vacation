#include<iostream>
#include<utility>
#include<queue>
using namespace std;
/*思考连通性：圈内的0是互相连通的；反之，圈外的0也应该是连通的
再考虑边界，由于边界，所以圈会造成外面的圈隔断，那不妨另边界扩大一格，从而让外面的0都连通
于是，只要标记出外面的0，就等同于知道了内部的0
*/
//tips：利用bfs的层层搜索的性质
queue<pair<int,int>> bfs;
int map[35][35]={0};
int outside[35][35]={0};

int add[4][2]={{1,0},{-1,0},{0,1},{0,-1}};//四个方向移动

int main(){
    int n;
    cin>> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    pair<int,int> now,next;
    bfs.push({0,0});
    outside[0][0]=-1;
    while(!bfs.empty()){
        now=bfs.front();
        for(int i=0;i<4;i++){
            next.first=now.first+add[i][0];
            next.second=now.second+add[i][1];
            //若已经到达过，或者遇到原图上的1，或者过界，都要跳过
            if(outside[next.first][next.second]==-1||map[next.first][next.second]||next.first<0||next.first>n+1||next.second<0||next.second>n+1){
                continue;
            }
            outside[next.first][next.second]=-1;
            bfs.push(next);
        }
        bfs.pop();
    }

    // cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(outside[i][j]!=-1&&map[i][j]!=1){
                cout<< "2 ";
            }else{
                cout<<map[i][j] <<" ";
            }
        }
        cout << endl;
    }
    
    return 0;
}