#include <stdio.h>

int euclidfunc(int x,int y)//再帰を用いたユークリッドの互除法
{
    if(x%y==0)
    {
        return y;
    }

    else
    {
        int remain=0;//剰余の変数

        remain=x%y;

        euclidfunc(y,remain);
    }
}

int main()
{
    int a=0;//挿入用の変数定義
    int b=0;

    scanf("%d %d",&a,&b);//変数のスキャン

    if(a<b)//計算しやすくするようa>bにする
    {
        int x=0;
        x=a;
        a=b;
        b=x;
    }

    else//安全性の観点から記入している
    {

    }

    int ans=0;//解答用変数

    ans=euclidfunc(a,b);

    printf("%d\n",ans);

    return 0;
}
