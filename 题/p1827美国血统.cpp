#include <iostream>
using namespace std;

string qian, zhong;
int len_qian, len_zhong;

void transform(int qian_l, int qian_r, int zhong_l, int zhong_r)
{
    // 之所以有这个判断，是因为下面的递归传入表达式（比如qian_l + 1, qian_l + l_L）会产生qian_l + 1>qian_l + l_L的情况，如果换种表达式，那么就可以直接用==来判断临界条件
    if (qian_l > qian_r)
    {

        return;
    }
    if (qian_l == qian_r)
    {
        cout << qian[qian_l];
        return;
    }

    int temp_i;
    char temp = qian[qian_l];
    for (temp_i = zhong_l; temp_i <= zhong_r; temp_i++)
    {
        if (zhong[temp_i] == temp)
            break;
    }
    int l_L = temp_i - zhong_l;
    int r_L = zhong_r - temp_i;
    transform(qian_l + 1, qian_l + l_L, zhong_l, temp_i - 1);
    transform(qian_r - r_L + 1, qian_r, temp_i + 1, zhong_r);
    cout << temp;
    return;
}

int main()
{
    cin >> zhong >> qian;
    len_qian = qian.length();
    len_zhong = zhong.length();
    transform(0, len_qian - 1, 0, len_zhong - 1);
    return 0;
}