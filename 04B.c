#include <stdio.h>
#include <string.h>
#define N 100000
#define Q 50000

/*
１行目にn、２行目にSを表すn個の整数、３行目にq、４行目にTを表すq個の整数が与えられます。
*/

int bi_find(int n, int num, int *array) // 数値numを探索する
{
    
    if (n <= 0)
    {
        return 0;// 配列のサイズが0以下の場合は探索終了
    }
        

    int start = 0;   // 配列の開始位置
    int goal = n - 1; // 配列の終了位置
    int flag_num = (start + goal) / 2; // 配列の中央位置

    // 中央位置の値をチェックして再帰的に探索
    if (array[flag_num] < num)//中央要素が探しているものより大きい場合
    {
        return bi_find(goal - flag_num, num, &array[flag_num + 1]);
    }
        
    else if (array[flag_num] > num)//中央要素がnumより小さい場合
    {
        return bi_find(flag_num, num, array);
    }
        
    else//中央要素がnumの場合
    {
        return 1;
    }
        
}

int bi_all_check(int n, int q, int *s, int *t)//数列Tの要素を数列Sから探索する
{
    int count = 0; // カウント回数を記録

    for (int i = 0; i < q; i++)
    {
        // T[i]がS[0]からS[n-1]の範囲にある場合のみ探索
        if (t[i] >= s[0] && t[i] <= s[n - 1])
        {
            count += bi_find(n, t[i], s); // カウント回数を加算
        }
    }

    return count;
}

int main()
{
    int n = 0;    // 1行目の数列Sの長さn
    int s[N];     // 2行目の数列Sの格納
    int q = 0;    // 3行目の数列Tの長さq
    int t[Q];     // 4行目の数列Tの格納
    int count = 0; // 数列Sに存在する数列Tの要素数

    // 入力を受け取る
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

    
    count = bi_all_check(n, q, s, t);// 数列Tの要素が数列Sに存在するかチェックし、カウントする

   
    printf("%d\n", count); // 結果を出力

    return 0;
}
