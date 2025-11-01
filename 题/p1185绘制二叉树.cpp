// 总结：第一次遇到画图题，关键在于‘找到递推关系’确定位置
#include <iostream>
using namespace std;
// 首先，根据题目已知，这是按层有序的满二叉树，其存储可以直接一维数组，因为满二叉树下结点间的连接关系可以直接算，所以不用记录父结点或者子结点
/*
其次，对于画布的大小，可以提前算出大小：
最多10层，最下面有2^10个叶子，也就是说最宽要512*5+（512-1）=3061位
另外，根据对称可以发现，从下往上的树枝长度=(子树宽-1)/2=sum(前面的枝长)+前面结点数-1
（试想一个父结点在中间连接两个子树，而两个子树间又要空一格，父结点刚好在空的这一格上方，那么一条连接子树的枝恰好就是子树的半边宽）

得到的递推方程：L[i+1]=L[i]*2+1，从i=2开始

这样，通过层数就易得各层树枝长，也便于确定树的总高度
所以画布宽应该>3061，高大约>1500
*/
char map[1500][3070];
int dele[2050]; // 记录结点是否删除

int L[15] = {1, 2};
int two2[15] = {0, 1};

void draw(int x, int y, int num, int l);

int main()
{
    // 提前处理好枝长与2的幂次
    for (int i = 2; i < 15; i++)
    {
        L[i] = 2 * L[i - 1] + 1;
        two2[i] = 2 * two2[i - 1];
    }

    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        dele[two2[x] + y - 1] = 1;
    }

    // 根节点开始遍历（因为都是是在k=1斜率的线上，所以根结点的y就等于树的高）
    draw(0, L[m - 1], 1, m - 2);
    // 输出图
    for (int i = 0; i <= L[m - 1]; i++)
    {
        for (int j = 0; j < 3070; j++)
        {
            if (map[i][j] != '\\' && map[i][j] != '/' && map[i][j] != 'o')
                cout << ' ';
            else
                cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}

void draw(int x, int y, int num, int l)
{
    // cout << x << ' ' << y << endl;
    map[x][y] = 'o';
    if (l < 0)
        return;
    int i;
    if (!dele[num * 2])
    {

        for (i = 1; i <= L[l]; i++)
        {
            map[x + i][y - i] = '/';
        }
        draw(x + L[l] + 1, y - L[l] - 1, num * 2, l - 1);
    }
    if (!dele[num * 2 + 1])
    {
        for (i = 1; i <= L[l]; i++)
        {
            map[x + i][y + i] = '\\';
        }
        draw(x + L[l] + 1, y + L[l] + 1, num * 2 + 1, l - 1);
    }
    return;
}