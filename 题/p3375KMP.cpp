#include<iostream>
using namespace std;
//求bordeer就是要验证一个s的前缀子串与s的后缀是否相同
/*不难联想到，kmp的转移数组所对应的恰好就是把符合的最长前缀凑到当前位置之前的后缀位置。
索引0 1 2 3 4 5 6 7 8
如: a b d d c a b c d
   -1 0 0 0 0 0 1 2 0 0
    对于第二个c来说，‘2’在kmp中的意义是：若该处的字符‘c’不符合，则下一个比较的位置就是索引‘2’处，因为[0,1]这个前缀串 与 [5,6]的子字符串是相同的。
那么也就是说，对于第二个‘c’之前[0,6]的字符串，前缀[0,1]与后缀[5,6]是相同的
所以kmp的转移数组每一个位置对应的前缀子串就恰好是前一个位置需要求的border。
*/
string s1,s2;
int kmp_trf[1000005]={-1};//初始化

int KMP(string s);
int main(){
    cin>> s1 >> s2;
    int l1=s1.length(),l2=s2.length();
    //kmp处理
    KMP(s2);
    //开始比较
    int k1=0,k2=0;
    while(k1<l1){
        if(k2==l2){
            cout<< k1-l2+1 << endl;
            k2=kmp_trf[k2];
        }
        while(k2!=-1&&s1[k1]!=s2[k2]){
            k2=kmp_trf[k2];
        }
        //若是s1[k1]=s2[k2]，则继续比较下一个k1+1与k2+1的字符；若是k2=-1退出的，说明当前位置k1不可能满足，所以也要下一个位置，而k2++恰好为0。所以两种情况可以综合在一起
        k1++,k2++;
    }
    //最后由于k1=l1退出，所以还要对结尾判断一次
    if(k2==l2){
            cout<< k1-l2+1 << endl;
        }
    // cout<< "..." <<endl;
    for(int i=1;i<=l2;i++){
        cout << kmp_trf[i] << ' ';
    }
    return 0;
}

int KMP(string s){
    int length=s.length();
    int i=0,j=1;
    for(j;j<length;j++){
        if(s[j]==s[i]){
            kmp_trf[j+1]=i+1;
        }else{
            while(i!=-1&&s[j]!=s[i]){
                i=kmp_trf[i];
            }
            kmp_trf[j+1]=i+1;    
        }
        i++;
    }
    // for(int t=0;t<=length;t++) cout<< kmp_trf[t]<<' ';
    return 1;
}