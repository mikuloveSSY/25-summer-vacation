#include<iostream>
using namespace std;
//单调队列就类似单调栈多了前面一个出口
#define N 1000005
int a[N];
int q_min[N],q_max[N];
int h_n=0,t_n=0,h_x=0,t_x=0;
int outmin[N],outmax[N];

int main(){
    int n,k;
    cin>>n>>k;
    int i,j;
    for(i=1,j=1;j<=k;j++){
        cin>>a[j];
        //单调增队列，队首记录最小
        while(t_n>h_n&&a[j]<a[q_min[t_n-1]]){
            t_n--;
        }
        q_min[t_n++]=j;
        //单调减队列，队首记录最大
        while(t_x>h_x&&a[j]>a[q_max[t_x-1]]){
            t_x--;
        }
        q_max[t_x++]=j;
    }
    outmin[i]=q_min[h_n],outmax[i]=q_max[h_x];

    for(;j<=n;i++,j++){
        //判断是否离开窗口区域，离开的要出队
        if(i==q_min[h_n]) h_n++;
        if(i==q_max[h_x]) h_x++;
        cin>>a[j];
        //单调增队列，队首记录最小
        while(t_n>h_n&&a[j]<a[q_min[t_n-1]]){
            t_n--;
        }
        q_min[t_n++]=j;
        //单调减队列，队首记录最大
        while(t_x>h_x&&a[j]>a[q_max[t_x-1]]){
            t_x--;
        }
        q_max[t_x++]=j;
        outmin[i+1]=q_min[h_n],outmax[i+1]=q_max[h_x];
    }
    // cout<< a[j-1] <<endl;
    for(int h=1;h<=n-k+1;h++){
        cout << a[outmin[h]] << " ";
    }
    cout<<endl;
    for(int h=1;h<=n-k+1;h++){
        cout << a[outmax[h]] << " ";
    }
    return 0;
}