#include <stdio.h>

int primefunc(int x) // 素数判定関数
{
    if (x == 2)
    {
        return (1);
    }

    else if (x % 2 == 0)
    {
        return (0);
    }

    for (int i = 2; i*i <= x; i++)//オーダー数削減のために平方根までの約数を比較. O(n^(1/2))
    {
        if (x % i == 0)
        {
            return (0);
        }
    }

    return (1);
}

int main()
{
    int n = 0;     // 入力される数字の数
    int count = 0; // 素数の個数カウント

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int temp = 0; // 一時的な素数格納変数

        scanf("%d", &temp);
        count += primefunc(temp);//素数なら1を足す
    }

    printf("%d\n", count);

    return 0;
}

