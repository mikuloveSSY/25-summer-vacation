#include<stdio.h>
#include<stdlib.h>

int stack[55];
int t=0;

int main(){
    char c;
    int num=0;
    while((c=getchar())!='@'){
        // for(int i=0;i<t;i++){
        //     printf("%d ",stack[i]);
        // }printf("\n");
        
        if(c>='0'&&c<='9'){
            num=num*10+c-'0';
        }else{
            if(c=='.'){
                stack[t++]=num;
                num=0;
            }else{
                int temp2=stack[--t];
                int temp1=stack[--t];
                switch(c){
                case '+':
                    stack[t++]=temp1+temp2;
                    break;
                case '-':
                    stack[t++]=temp1-temp2;
                    break;
                case '*':
                    stack[t++]=temp1*temp2;
                    break;
                case '/':
                    stack[t++]=temp1/temp2;
                }
            }
        }
    }
    printf("%d",stack[--t]);
    return 0;
}