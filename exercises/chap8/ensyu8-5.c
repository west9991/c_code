#include<stdio.h>

enum sex {man, woman, invalid};

int main(void)
{
    enum sex sexual;
    printf("性別を入力してください;man:0 woman:1 no answer:2");
    scanf("%d", &sexual);

    switch(sexual) {
        case     man : puts("あなたは男性なのですね。"); break;
        case   woman : puts("あなたは女性なのですね。"); break;
        case invalid : puts("わかったわ。"); break;
        default      : puts("あなたは、誰ですか。"); break;
    }

    return 0;
}

//これを使わないとできないことってあるかな。
//オブジェクト形式マクロを一括で、宣言できる
//不正値の発見(この処理系では無意味)