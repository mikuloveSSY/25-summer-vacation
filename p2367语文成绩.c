#include<stdio.h>
#include<stdlib.h>
//差分
int cj[5000005];
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    cj[0]=0;
    int now,pre=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        cj[i]=now-pre;
        pre=now;
    }
    for(int i=0;i<p;i++){
        int x,y,add;
        scanf("%d %d %d",&x,&y,&add);
        cj[x]+=add;
        cj[y+1]-=add;
    }
    int min=cj[1];
    int sum=cj[1];
    for(int i=2;i<=n;i++){
        sum+=cj[i];
        min=min>sum?sum:min;
    }
    printf("%d",min);
    return 0;
}