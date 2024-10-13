#include <stdio.h>

// 1. 構造体と共用体
//   1.1 構造体を作ってみる
//   1.2 共用体を作ってみる
// 　1.3 構造体と共用体の差を確認する
// 2. ポインタ
//   2.1 値呼び（値渡し）と参照呼び（参照渡し）の関数を作ってみる
//   2.2 ポインタ変数とピリオドで、構造体の要素を参照する
//   2.3 アロー演算子で、構造体の参照を行ってみる

struct Person {
    char name[20];
    int age;
    float height;
};

union Data {
    int i;
    float f;
    char str[20];
};

void callByValue(int x) {
    x = 10;
}

void callByReference(int *x) {
    *x = 10;
}

int main() {
    struct Person person;
    union Data data;

    // 修正: %zu を使用して sizeof の結果を表示
    printf("Size of Person: %zu\n", sizeof(person));
    printf("Size of Data: %zu\n", sizeof(data));

    int x = 5;
    callByValue(x);
    printf("callByValue: %d\n", x);

    callByReference(&x);
    printf("callByReference: %d\n", x);

    struct Person *p = &person;
    p->age = 20;
    printf("Person age: %d\n", person.age);
}

// 構造体Personと共用体Dataを作成した。
// 構造体と共用体を作成し、それぞれのサイズを確認した。

// callByValue と callByReference を作成し、それぞれの関数で値を変更することができることを確認した。
// 構造体のポインタ変数を作成し、ピリオドで要素を参照することができることを確認した。
// アロー演算子を使って、構造体の参照を行うことができることを確認した。