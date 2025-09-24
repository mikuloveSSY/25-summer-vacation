#include<iostream>
// #include<stack>
using namespace std;
//如题，模板
// stack<int> nextmax; 
//注意模板手写，不然会TLE
int stack[3000005]={0};
int t=0;
int num[3000005]={0};
int f[3000005]={0};

int main(){
    int n,pre_i;
    cin>> n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        while(t&&num[i]>num[stack[t-1]]){
            pre_i=stack[t-1];
            f[pre_i]=i;
            t--;
        }
        stack[t++]=i;
    }
    // while(!nextmax.empty()){
    //     f[nextmax.top()]=0;
    //     nextmax.pop();
    // }  由于本题无naxtmax则设为0，即默认值，所以不用再去出栈
    for(int i=1;i<=n;i++){
        cout<< f[i] << " ";
    }
    return 0;
}