// アルゴリズムとデータ構造　第7回　演習課題　6322087 三笠悠太郎
// 演習課題3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 配列ベタ詰めによるqueueを実装
#define MAX_SIZE 100

typedef int Element;
typedef struct {
    Element value[MAX_SIZE];
    int front; // queueの先頭のインデックス
    int rear;  // queueの末尾のインデックス
} Queue;

// データeをqueueの末尾に追加
int EnQueue(Queue *Q, Element e) {
    if (Q->rear >= MAX_SIZE - 1) {
        return 0;
    }
    Q->rear++;
    Q->value[Q->rear] = e;
    return 1;
}

// キューQの先頭要素を削除
int DeQueue(Queue *Q) {
    if (Q->front > Q->rear) {
        return 0;
    }
    Q->front++;
    return 1;
}

// キューQの先頭要素の値を変数vに格納
int Retrieve(Queue *Q, Element *v) {
    if (Q->front > Q->rear) {
        return 0;
    }
    *v = Q->value[Q->front];
    return 1;
}

// キューQが空なら1を返す
int isEmpty(Queue *Q) {
    return Q->front > Q->rear;
}

// 新規空キューを作成
void Create(Queue *Q) {
    Q->front = 0;
    Q->rear = -1;
}

#include <stdio.h>

int main() {
    Queue Q;
    Element e;

    // キューの作成
    Create(&Q);

    // 要素の追加
    printf("キューに10, 20, 30を追加\n");
    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);

    // 先頭要素の取得
    Retrieve(&Q, &e);
    printf("先頭要素: %d\n", e); // 10が出力されるはず

    // 要素の削除
    DeQueue(&Q);
    printf("先頭要素を削除\n");

    // 先頭要素の取得
    Retrieve(&Q, &e);
    printf("先頭要素: %d\n", e); // 20が出力されるはず

    // さらに要素の削除
    DeQueue(&Q);
    DeQueue(&Q);
    printf("要素を2つ削除\n");


    // 空の確認
    if (isEmpty(&Q)) {
        printf("キューは空です\n");
    } else {
        printf("キューは空ではありません\n"); // ここは空なので、"キューは空です" が出力されるはず
    }

        // 空のキューからRetrieveを試みる
    if (Retrieve(&Q, &e)) {
        printf("取得成功: %d\n", e);
    } else {
        printf("取得失敗（キューは空）\n"); // ここは失敗するので、"取得失敗（キューは空）" が出力されるはず
    }


    return 0;
}
