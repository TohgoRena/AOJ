#include <stdio.h>
#include <string.h>
/*
以下の命令を実行する簡易的な「辞書」を実装してください。

insert str: 辞書に strを追加する。
find str: 辞書に strが含まれる場合 'yes'と、含まれない場合 'no'と出力する。
*/

// 配列に塩基配列を挿入する関数
void insert(char sequence[], char dna[])
{
    int num = 0;
    int i = 0;

    // 五進法の数値に変換する
    while (sequence[i] != '\0')
    {
        switch (sequence[i])
        {
        case 'A':
            num = num * 5 + 1;
            break;
        case 'C':
            num = num * 5 + 2;
            break;
        case 'G':
            num = num * 5 + 3;
            break;
        case 'T':
            num = num * 5 + 4;
            break;
        default:
            return;
        }
        i++;
    }

    // 配列に挿入
    dna[num] = 1;
}

// 配列内で塩基配列を探索する関数
void find(char sequence[], char dna[])
{
    int num = 0;
    int i = 0;

    // 五進法の数値に変換する
    while (sequence[i] != '\0')
    {
        switch (sequence[i])
        {
        case 'A':
            num = num * 5 + 1;
            break;
        case 'C':
            num = num * 5 + 2;
            break;
        case 'G':
            num = num * 5 + 3;
            break;
        case 'T':
            num = num * 5 + 4;
            break;
        default:
            return;
        }
        i++;
    }

    // 探索結果を出力
    if (dna[num] == 1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}

int main()
{
    // DNA配列の初期化
    char dna[5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5] = {0};

    int n;//命令数の読み込み
    char command[10];//find,insertの命令文読み込み
    char sequence[10];//DNA塩基配列を読み込む

    scanf("%d", &n);//命令数の読み込み

    for (int i = 0; i < n; i++)//命令の読み込み
    {
        scanf("%s", command);//命令読み込み

        if (strcmp(command, "insert") == 0)//insert時
        {
            scanf("%s", sequence);
            insert(sequence, dna);
        }
        else if (strcmp(command, "find") == 0)//find時
        {
            scanf("%s", sequence);
            find(sequence, dna);
        }
    }

    return 0;
}