#include<iostream>
#include<algorithm>
using namespace std;
//考虑到有括号层层嵌套，依然用递归
int sumlength();

int main(){
    cout<< sumlength();
    return 0;
}

int sumlength(){
    char c;
    int max_length=0;
    int length=0;
    while(cin>>c&&c!=')'){
        if(c=='a'){
            length++;
        }else if(c=='('){
            length+=sumlength();
        }else if(c=='|'){
            max_length=max(max_length,length);
            length=0;
        }
    }
    return max(max_length,length);
}