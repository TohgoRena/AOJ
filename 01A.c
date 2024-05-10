#include <stdio.h>

void insert(int *a, int *b)
{
    if (*a > *b)
    {
        int x = 0;
        x = *a;
        *a = *b;
        *b = x;
    }

    else
    {
    }
}

int main()
{
    int a[100]; // 保管する配列
    int n = 0;  // 出力されるNの保管
    scanf("%d", &n);

    for (int i = 0; i < n; i++) // 数字のスキャン
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) // 数字の表示
    {
        if (i < n - 1)
        {
            printf("%d ", a[i]);
        }

        else
        {
            printf("%d\n", a[i]);
        }
    }

    for (int i = 1; i < n; i++) // 挿入ソート開始
    {
        for (int t = i; t > 0; t--)
        {
            insert(&a[t - 1], &a[t]);
        }

        for (int x = 0; x < n; x++) // 数字の表示
        {
            if (x < n - 1)
            {
                printf("%d ", a[x]);
            }

            else
            {
                printf("%d\n", a[x]);
            }
        }
    }

    return 0;
}
