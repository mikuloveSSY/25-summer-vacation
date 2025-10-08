#include<iostream>
using namespace std;
char num[25];
int head,tail;
int symbol=-1;

int main(){
    char c;
    while(cin>>c){
        if(c=='/'||c=='%'||c=='.') symbol=tail;
        num[tail++]=c;
    }
    //让整数也有符号位的意义
    if(symbol==-1) symbol=tail;
    //去除前半的首部0
    int j=symbol-1;
    while(j>=head&&num[j]=='0'){
        j--;
    }
    //特判符号前面若只有一个0
    if(j<head){
        cout<< 0;
    }
    //输出前半
    for(int k=j;k>=head;k--){
        cout<< num[k];
    }
    //输出符号
    if(symbol!=tail) cout<< num[symbol];
    //去除后半首部0(注意小数去除的是后面的0，分母去除的是前面的0)
    j=symbol+1;
    while(j<tail&&num[j]=='0'){
        j++;
    }
    while(j<tail&&num[tail-1]=='0'){
        tail--;
    }
    //特判符号后面是否留一个0
    if(symbol!=-1&&num[symbol]!='%'&&j==tail){
        cout<<0;
    }
    //输出后半
    for(int k=tail-1;k>=j;k--){
        cout<< num[k];
    }

    return 0;
}