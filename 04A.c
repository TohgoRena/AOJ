#include <stdio.h>
#include <string.h>
#define N 10000
#define Q 500

/*
１行目にn、２行目にSを表すn個の整数、３行目にq、４行目にTを表すq個の整数が与えられます。
*/

int check_array(int n, int num, int *array) // 数字numが配列array内に存在すれば1を、さもなくば0を返す関数
{
    for (int i = 0; i < n; i++) // 数列S内を1度しか探索しない
    {
        if (array[i] == num)
        {
            return 1;
        }
    }

    return 0;
}

int all_check(int n, int q, int *s, int *t) // check_arrayをtの全ての格納された数字に対して実行する
{
    int count = 0;//カウント回数を記録

    for (int i = 0; i < q; i++)
    {
        count += check_array(n, t[i], s);//カウント回数を加算
    }

    return count;
}

int main()
{
    int n = 0; // 1行目の数列Sの長さn
    int s[N];  // 2行目の数列Sの格納

    int q = 0; // 3行目の数列Tの長さq
    int t[Q];  // 4行目の数列Tの格納

    int count = 0; // 数列Sに存在する数列Tの要素数

    scanf("%d", &n); // nのスキャン

    for (int i = 0; i < n; i++) // 数列Sの格納
    {
        scanf("%d", &s[i]);
    }

    scanf("%d", &q); // qのスキャン

    for (int i = 0; i < q; i++) // 数列Sの格納
    {
        scanf("%d", &t[i]);
    }

    count = all_check(n, q, s, t);

    printf("%d\n", count);

    return 0;
}
