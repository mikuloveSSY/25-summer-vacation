#include<iostream>
#include<stack>
using namespace std;
//对于记录最大值，想到单调栈.这里需要最大值，所以用递增序列
stack<int> up;
stack<int> warehouse;

int main(){
    int N,op,x;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> op;
        if(op==0){
            cin>> x;
            warehouse.push(x);
            if(up.empty()||x>=up.top()) up.push(x);
        }else if(op==1){
            if(warehouse.empty()) continue;
            int temp=warehouse.top();
            // printf("%d\n",temp);
            if(temp==up.top()) up.pop();
            warehouse.pop();
        }else{
            if(warehouse.empty()){
                printf("0\n");
                continue;
            }
            int temp=up.top();
            printf("%d\n",temp);
        }
    }
    return 0;
}