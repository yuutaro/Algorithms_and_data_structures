// アルゴリズムとデータ構造　第7回　演習課題　6322087 三笠悠太郎
// 演習課題1,2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 配列ベタ詰めによるスタックを実装
#define MAX_SIZE 100

// スタックの要素の型
typedef char Element;

typedef struct {
    Element value[MAX_SIZE];
    int top; // スタックのトップのインデックス
} Stack;

// スタックに要素を追加
int PushDown(Stack *S, Element e) {
    if (S->top >= MAX_SIZE - 1) {
        return 0;
    }
    S->top++;
    S->value[S->top] = e;
    return 1;
}

// スタックから要素を取り出す
int PopUp(Stack *S, Element *e) {
    if (S->top < 0) {
        return 0;
    }
    *e = S->value[S->top];
    S->top--;
    return 1;
}

// スタックの先頭要素の値を変数vに格納
int Retrieve(Stack *S, Element *v) {
    if (S->top < 0) {
        return 0;
    }
    *v = S->value[S->top];
    return 1;
}

// スタック*Sが空なら1を返す
int Enpty(Stack *S) {
    return S->top < 0;
}

// 新規空スタックを作成
void Create(Stack *S) {
    S->top = -1;
}

// 行編集プログラムを作成
void Edit(){
    Stack S, T;
    Element e;
    char line[MAX_SIZE + 1]; // 入力文字列を格納する配列 (NULL文字を含む)

    Create(&S);

    fgets(line, sizeof(line), stdin); // 1行入力

    for (int i = 0; line[i] != '\n' && line[i] != '\0'; i++) { // 終端文字までループ
        char c = line[i];
        if (c == '#') {
            if (!PopUp(&S, &e)) {
                fprintf(stderr, "PopUp Error\n");
                return;
            }
        } else if (c == '@') {
            Create(&S);
        } else {
            if (!PushDown(&S, c)) {
                fprintf(stderr, "PushDown Error\n");
                return;
            }
        }
    }

    Create(&T);
    while (!Enpty(&S)) {
        Retrieve(&S, &e);
        PushDown(&T, e);
        PopUp(&S, &e);
    }
    while (!Enpty(&T)) {
        Retrieve(&T, &e);
        printf("%c", e);
        PopUp(&T, &e);
    }
    printf("\n");
}

int main() {
    printf("文字列を入力してください（#で1文字削除、@で全削除、改行で終了）: ");
    fflush(stdout);
    Edit();
    return 0;
}