#include <stdio.h>
#include <stdbool.h>
#define maxsize 100

// C言語でBAGの抽象型を完成させなさい。
// BAGの構造体、insert, serach, deleteは授業内容と同じでよい。
// empty, is_element, is_emptyの処理を自身で考える
// main関数内で各関数を適当に動かす（ひな形通り＋α）

// 【注意】
// • C言語は抽象型を作成できません
// • ここまでの実装が抽象型である事を意識してください
// • 隠蔽機能もないので，隠蔽してる気持ちを持ってください

struct BAG {
    int data[maxsize];
    int size;
};

typedef struct BAG BAG;

BAG insert(int e, BAG B){
    if(B.size < maxsize){
        B.data[B.size] = e;
        B.size++;
    }
    return B;
}

int search(int e, BAG *B){
    for(int i = 0; i < B->size; i++){
        if(B->data[i] == e){
            return i;
        }
    }
    return -1;
}

BAG delete(int e, BAG B){
    int i = search(e, &B);
    if(i != -1){
        for(int j = i; j < B.size - 1; j++){
            B.data[j] = B.data[j + 1];
        }
        B.size--;
    }
    return B;
}

// 空のBAGを返す
BAG empty(){
    BAG B;
    B.size = 0;
    return B;
}

bool is_element(int e, BAG *B){
    for(int i = 0; i < B->size; i++){
        if(B->data[i] == e){
            return true;
        }
    }
    return false;
}

bool is_empty(BAG *B){
    if(B->size == 0){
        return true;
    }
    return false;
}

// trueなら　trueという文字を返すように書き換えました。
int main(){
    BAG B = empty();
    printf("is empty? : %s\n", is_empty(&B) ? "true" : "false");
    B = insert(3, B);
    B = insert(2, B);
    B = insert(3, B);
    printf("is empty? : %s\n", is_empty(&B) ? "true" : "false");
    B = delete(3, B);
    printf("is element? : %s\n", is_element(3, &B) ? "true" : "false");
    printf("is element? : %s\n", is_element(2, &B) ? "true" : "false");
    printf("is element? : %s\n", is_element(1, &B) ? "true" : "false");
    return 0;
}