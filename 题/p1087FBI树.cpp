#include<iostream>
using namespace std;
string FBI;
int L;
int preSum[2000];
//后序遍历
void makeTree(int l, int r){
    if(l==r){
        cout << (FBI[l-1]-'0'?'I':'B');
        return;
    }

    int len=(r-l+1)/2;
    makeTree(l,r-len);
    makeTree(l+len,r);
    
    int temp=preSum[r]-preSum[l-1];
    if(temp==0){
        cout << 'B';
    }else if(temp==r-l+1){
        cout << 'I';
    }else{
        cout << 'F';
    }
    return;
}

int main(){
    int N;
    cin>>N>>FBI;
    L=FBI.length();

    for(int i=1;i<=L;i++){
        preSum[i]=preSum[i-1]+FBI[i-1]-'0';
    }
    makeTree(1,L);
    return 0;
}