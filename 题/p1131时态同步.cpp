#include<iostream>
#include<algorithm>
using namespace std;
/*思考点：1、怎么构建传输过程？2、怎么去求要增加多少？
对于1：传输过程可以看作‘树形’传播
对于2：思考为什么会造成两个‘终止结点’时间不同？
    根据题意，任何两个结点间有且仅有一条通路，这极大得简化了问题！！！因为这说明对于从开始到终止结点只有一条路，信号对于该路是单向传播的，不存在有多条通路竞争的情况，那么对于‘某两个终止结点’造成不同的原因就是由于它俩不同的那些导线（根据树状图，显然相同的导线无影响）
因此，要想时态同步，就要把树的其余‘枝’补长到与最长枝相同
而又因为修改次数要最少，所以就要考虑从公共枝上增加，不妨考虑树形dp，从叶子结点（也就是终止结点）不断向根dp

总之，该题本质就是对树形数据结构的操作，树形dp即可
*/
int N,S;
//建树有两种选择：直接二维数组点对点；或者链表以边为主
//这次试试静态链表以边为主，因为边少，但是因为这是无向图，要开双向边，所以开数组记得在原数据规模上×2
int edge[1000005][2],next_edge[1000005],k;//edge第一个代表指向的结点，第二个代表耗时；next_edge存储的是下一条边的index（即邻接边）
int edge_head[500005];//存储邻接表头结点

long long dp[500005];//存每个结点的深度结果
long long sum;

void Add(int a, int b, int t){
    k++;
    edge[k][0]=b,edge[k][1]=t;
    //头插入
    next_edge[k]=edge_head[a];
    edge_head[a]=k;
}
void DpTree(int a,int a_fa){
    long long max_time=0;
    for(int i=edge_head[a];i!=0;i=next_edge[i]){
        if(edge[i][0]==a_fa) continue;
        DpTree(edge[i][0],a);
        max_time=max(dp[edge[i][0]]+edge[i][1],max_time);
    }
    for(int i=edge_head[a];i!=0;i=next_edge[i]){
        if(edge[i][0]==a_fa) continue;
        sum+=max_time-dp[edge[i][0]]-edge[i][1];//累加增长的结果
    }
    dp[a]=max_time;
}

int main(){
    cin>>N >> S;
    for(int i=0,a,b,t;i<N-1;i++){
        cin>> a >> b >> t;
        Add(a,b,t);
        Add(b,a,t);
    }
    DpTree(S,0);
    cout << sum <<endl;
    return 0;
}