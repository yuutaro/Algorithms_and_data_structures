// • C言語でリストをつくりなさい
//   • どの実現アルゴリズムでもOK
// • 複数作ってもOK 最低１つは作ってください
//   • いろいろな種類を作ると勉強になりますよ
//   • 以下のアルゴリズム以外でもOK
//   • 配列ベタ詰め
//   • 構造体とポインタ
//   • 一方向連結リスト（第1版）
//   • 一方向連結リスト（第2版）
//   • 双方向連結リスト
//   • 配列とインデックスを用いた連結リスト（一方向第2版）

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 配列ベタ詰めによるリストを実装した。

#define MAX_SIZE 100

typedef int Element;

typedef struct {
    Element value[MAX_SIZE];
    int current; // カレント要素のインデックス
    int last;    // 末尾の要素のインデックス
} List;

// リストのサイズを取得
int Size(List *L) {
    return L->last + 1;
}

// カレント要素の位置を取得
int CurPos(List *L) {
    return L->current;
}

// リストを生成
void Create(List *L) {
    L->current = -1;
    L->last = -1;
}

// カレント要素を設定
int Findith(List *L, int n) {
    if (n < 0 || n > L->last) {
        return 0;
    }
    L->current = n;
    return 1;
}

// 現カレント要素の右隣を新カレント要素に設定
int FindRight(List *L) {
    if (L->current < 0 || L->current >= L->last) {
        return 0;
    }
    L->current++;
    return 1;
}

// 現カレント要素の左隣を新カレント要素に設定
int FindLeft(List *L) {
    if (L->current <= 0 || L->current > L->last) {
        return 0;
    }
    L->current--;
    return 1;
}

// 変数vにカレント要素の値を代入
int Retrieve(List *L, Element *v) {
    if (L->current < 0 || L->current > L->last) {
        return 0;
    }
    *v = L->value[L->current];
    return 1;
}

// カレント要素の値をeに設定
int Update(List *L, Element e) {
    if (L->current < 0 || L->current > L->last) {
        return 0;
    }
    L->value[L->current] = e;
    return 1;
}

// カレント要素の左に要素を挿入
int InsertLeft(List *L, Element e) {
    if (L->last >= MAX_SIZE - 1) {
        return 0;
    }
    
    // リストが空の場合
    if (L->last == -1) {
        L->value[0] = e;
        L->last = 0;
        L->current = 0;
        return 1;
    }
    
    if (L->current < 0) {
        return 0;
    }
    
    for (int i = L->last; i >= L->current; i--) {
        L->value[i + 1] = L->value[i];
    }
    L->value[L->current] = e;
    L->last++;
    return 1;
}

// カレント要素の右に要素を挿入
int InsertRight(List *L, Element e) {
    if (L->last >= MAX_SIZE - 1) {
        return 0;
    }
    
    // リストが空の場合
    if (L->last == -1) {
        L->value[0] = e;
        L->last = 0;
        L->current = 0;
        return 1;
    }
    
    if (L->current < 0) {
        return 0;
    }
    
    for (int i = L->last; i > L->current; i--) {
        L->value[i + 1] = L->value[i];
    }
    L->value[L->current + 1] = e;
    L->current++; // カレント位置を挿入した要素に移動
    L->last++;
    return 1;
}

// カレント要素を削除
int Delete(List *L) {
    if (L->current < 0 || L->current > L->last) {
        return 0;
    }
    
    for (int i = L->current; i < L->last; i++) {
        L->value[i] = L->value[i + 1];
    }
    L->last--;
    
    if (L->last < 0) {
        L->current = -1;
    }
    else if (L->current > L->last) {
        L->current = L->last;
    }
    return 1;
}

// リストのコピー
void Copy(List *L1, List *L2) {
    L2->current = L1->current;
    L2->last = L1->last;
    for (int i = 0; i <= L1->last; i++) {
        L2->value[i] = L1->value[i];
    }
}

// リストの比較
int Equal(List *L1, List *L2) {
    if (L1->last != L2->last) {
        return 0;
    }
    for (int i = 0; i <= L1->last; i++) {
        if (L1->value[i] != L2->value[i]) {
            return 0;
        }
    }
    return 1;
}

// リストの全要素を表示
void Display(List *L) {
    printf("[");
    for (int i = 0; i <= L->last; i++) {
        printf("%d", L->value[i]);
        if (i < L->last) {
            printf(", ");
        }
    }
    printf("]\n");
}

// リストのカレント要素のインデックスと値を表示
void DisplayCurrent(List *L) {
    if (L->current < 0 || L->current > L->last) {
        printf("Current: %d, No current element\n", L->current);
    } else {
        printf("Current: %d, Value: %d\n", L->current, L->value[L->current]);
    }
}

int main() {
    List L1, L2;
    Element x;

    // リストを初期化
    Create(&L1);
    printf("リスト初期化完了。\n");
    Display(&L1);

    // 要素の挿入
    printf("\n要素を挿入:\n");
    InsertRight(&L1, 10);
    Display(&L1);
    DisplayCurrent(&L1);
    
    InsertRight(&L1, 20);
    Display(&L1);
    DisplayCurrent(&L1);
    
    InsertRight(&L1, 30);
    Display(&L1);
    DisplayCurrent(&L1);

    // カレント要素の設定と移動
    printf("\nカレント要素を2番目に設定:\n");
    Findith(&L1, 1);
    DisplayCurrent(&L1);

    printf("\nカレント要素を右に移動:\n");
    FindRight(&L1);
    DisplayCurrent(&L1);

    printf("\nカレント要素を左に移動:\n");
    FindLeft(&L1);
    DisplayCurrent(&L1);

    // 更新
    printf("\nカレント要素を更新:\n");
    Update(&L1, 25);
    Display(&L1);
    DisplayCurrent(&L1);

    // カレント左に挿入
    printf("\nカレントの左に挿入:\n");
    InsertLeft(&L1, 15);
    Display(&L1);
    DisplayCurrent(&L1);

    // カレント削除
    printf("\nカレント要素を削除:\n");
    Delete(&L1);
    Display(&L1);
    DisplayCurrent(&L1);

    // リストのコピー
    Copy(&L1, &L2);
    printf("\nリストをコピー (L1 -> L2):\n");
    Display(&L2);

    // 比較
    printf("\nリスト比較:\n");
    if (Equal(&L1, &L2)) {
        printf("L1とL2は等しいです。\n");
    } else {
        printf("L1とL2は等しくありません。\n");
    }

    return 0;
}