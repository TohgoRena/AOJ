#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// スタックを用いて逆ポーランド記法で与えられた数式を計算する

void stack_func(int stack[], char temp[]) // 演算をする関数
{
    // スタックの一番上にある2つの値を取り出す
    int a = stack[stack[0] - 1]; // 一番上
    int b = stack[stack[0] - 2]; // その下

    // 演算と結果の格納
    if (temp[0] == '+')
    {
        stack[stack[0] - 2] = b + a;
    }
    else if (temp[0] == '-')
    {
        stack[stack[0] - 2] = b - a;
    }
    else if (temp[0] == '*')
    {
        stack[stack[0] - 2] = b * a;
    }

    stack[0]--; // スタックの先頭位置を修正
}

void stack_add(int stack[], int num) // スタックに数値を追加する関数
{

    stack[stack[0]] = num; // スタックの一番上に数値を追加し
    stack[0]++;            // 先頭位置を追加
}


void stack_decider(int stack[], char temp[])//スキャンした文字列が演算子か数字か判断する関数
{
    
    if (temp[0] < '0')//文字コードを比較し、数字時以外の場合
    {
       
        stack_func(stack, temp); //計算をする関数
    }
    else
    {
        // 文字列を整数に変換し、数値をスタックに追加する
        char *endptr;// トークンが数字の場合、数値をスタックに追加する
        long num = strtol(temp, &endptr, 10);// strtolがエラーを返した場合は、不正な入力としてエラーメッセージを表示して終了する
        stack_add(stack, (int)num);//ごめんなさい、文字を整数に変換する方法が分からないのでAIを使用しました。
    }
}

int main()
{

    int num_stack[101]; // 数値を記録するスタック

    char all_save[200]; // 入力された文字列を比較する配列

    num_stack[0] = 1; // スタックの先頭位置を記録

    while (scanf("%s", all_save) != EOF) // EOFまでスキャンを繰り返すお決まりの関数
    {
        stack_decider(num_stack, all_save);
    }

    printf("%d\n", num_stack[num_stack[0] - 1]);// 演算結果を出力

    return 0;
}
