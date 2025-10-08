#include<iostream>
using namespace std;
/*
本题是一个低配版的表达式求值
可以用栈来实现 复杂的四则运算（带括号）的表达式求值，经典方法
虽然这里未必用栈
*/
//洛谷评测显然不适合c。。。沟槽的不规范输入，c语言这种想精确处理非常困难，根本不知道是哪出错了
long long stack[100005];
char OP[100005];
int t=0,k=0;

void calculate(char choose){
    if(t==0||t==1) return;
    long long num1=stack[t-2]%10000;
    long long num2=stack[t-1]%10000;
    t-=2;
    k-=1;
    if(choose=='+'){
        stack[t++]=(num1+num2)%10000;
    }else{
        stack[t++]=(num1*num2)%10000;
    }
}

int main(){
    char c;
    long long num=0;
    cin>> stack[t++];
    while(cin>>c>>num){
        if(k&&OP[k-1]=='*'){
            calculate('*');
        }
        stack[t++]=num;
        OP[k++]=c;
    }
    while(k){
        calculate(OP[k-1]);
    }
    printf("%d",stack[t-1]%10000);
    return 0;
}