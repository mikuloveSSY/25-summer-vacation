#include<iostream>
#include<cmath>
using namespace std;
//可以用递归
// int repeat[100000];
// int k;
int calculate();

int main(){    
    cout<< abs(calculate());
    return 0;
}

int calculate(){
    char command;
    string remain;
    int sum=0,step=0;
    //当遇到输入流结尾或者‘]’时，说明当前层内的计算可以结束了
    while(cin>>command&&command!=']'){
        //‘cin>> remain >> step;’这句若统一放外面写，则要针对REPEAT的数字后的‘[’判断一下，防止被cin输入到remain里
        if(command=='F'){
            cin>> remain >> step;
            sum+=step;
        }else if(command=='B'){
            cin>> remain >> step;
            sum-=step;
        }else if(command=='R'){
            cin>> remain >> step;
            sum+=step*calculate();
        }
    }
    return sum;
}