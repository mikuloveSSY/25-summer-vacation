#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    //由于最终使用的是常数组，因此不用指针而是编号当索引也行
    struct node* last;
    struct node* next;
}Node;

Node std[100005];
int head=0;

int main(){
    int N;
    scanf("%d",&N);
    //初始化，std[0]当作头（尾）结点，控制头尾
    std[0].num=-1;
    std[0].next=&std[1];
    std[1].num=1;
    std[1].last=&std[0];
    std[1].next=&std[0];
    
    for(int i = 2; i <= N; i++){
        std[i].num=i;
        int k,p;
        scanf("%d %d",&k,&p);
        if(p==0){
            std[i].next=&std[k];
            std[i].last=std[k].last;
            std[k].last=&std[i];
            std[i].last->next=&std[i];
        }else{
            std[i].last=&std[k];
            std[i].next=std[k].next;
            std[k].next=&std[i];
            std[i].next->last=&std[i];
        }
    }
    int M;
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int n;
        scanf("%d",&n);
        //删结点，且保证只删一次
        if(std[n].num!=0){
            std[n].last->next=std[n].next;
            std[n].next->last=std[n].last;
            std[n].num=0;
        }
    }
    Node* temp=std[0].next;
    while(temp->num!=-1){
        printf("%d ",temp->num);
        temp=temp->next;
    }
    return 0;
}