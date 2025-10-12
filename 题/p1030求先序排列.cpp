#include<iostream>
using namespace std;

string InOrder,PostOrder;
int post_l,in_l;
string PreOrder="";
int post_tail;
//用递归解
string Solve(int in_l,int in_r){
    //注意递归的退出条件：要么l>r说明当前枝处理完毕；要么tail<0说明整棵树处理完毕
    if(in_l>in_r||post_tail<0) return "";
    char in=PostOrder[post_tail];
    post_tail--;
    int in_index=InOrder.find(in);
    string post=Solve(in_index+1,in_r);
    string pre=Solve(in_l,in_index-1);
    return in+pre+post;
}
/*tips:这里用一个全局变量来控制从后序排列不断取子树的根节点，而因为后序排列是左右中，所以是优先处理右子树
如果想先处理左子树，那么可以让函数多传递控制后序排列的处理区间的两个边界参数
中序排列的处理区间易解，那后序排列的处理区间如何得到？
利用当前处理区间以及根结点的index算出当前根结点的左右子树长度，子树长度就是处理区间长度，从而可以得到接下去要处理的两个后序排列对应的处理区间的左右边界
*/

int main(){
    cin>> InOrder >> PostOrder;
    in_l=InOrder.length(),post_l=PostOrder.length();
    post_tail=post_l-1;
    PreOrder=Solve(0,in_l-1);
    cout<< PreOrder <<endl;
    return 0;
}