#include <stdio.h>

int main()
{
    int n = 0; // 入力される数字の数
    scanf("%d", &n);

    int minval = 0;//最大利益
    int maxval = 0;//為替の最小値

    int chart[200000];

    for (int i = 0; i < 2; i++)//最初の2まで読み込む
    {
        scanf("%d", &chart[i]);
    }

    minval = chart[0];//最小値に数値を代入
    maxval = chart[1] - chart[0];//差額の差分
    if (chart[1] < minval)//最小値の更新
    {
        minval = chart[1];
    }


    for (int i = 2; i < n; i++)//t=2以降の為替の読み込み
    {
        scanf("%d", &chart[i]);


        if (maxval < (chart[i] - minval))//差額で最大のが見つかった場合、更新する
        {
            maxval = chart[i] - minval;
        }

        if (minval > chart[i])//最小値も同様に更新する
        {
            minval = chart[i];
        }
    }

    printf("%d\n", maxval);//結果の更新

    return 0;
}
