#include <iostream>
#include <queue>
using namespace std;
int BiTree[1000005][2] = {0};

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        BiTree[i][0] = l, BiTree[i][1] = r;
    }
    queue<int> q;
    q.push(1);
    int depth = 0, sum = 1;
    while (sum != 0)
    {
        depth++;
        int temp = 0;
        for (int i = 0; i < sum; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int x = q.front();
                if (BiTree[x][j])
                {
                    q.push(BiTree[x][j]);
                    temp++;
                }
            }
            q.pop();
        }
        sum = temp;
    }
    cout << depth;
    return 0;
}