#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct IndexTable {
    int index;
    int start;
} IndexTable;

#define SIZE 8
#define INDEX_TABLE_SIZE 4
int arr[] = { 12, 23, 34, 54, 77, 78, 88, 89 };

IndexTable index_table[] = {
    {12, 0},
    {34, 2},
    {77, 4},
    {88, 6}
};

int indexed_sequential_search(int key) {
    int i;
    // 색인 테이블을 이용하여 적절한 섹션 찾기
    for (i = 0; i < INDEX_TABLE_SIZE - 1; i++) {
        if (key < index_table[i + 1].index) {
            break;
        }
    }
    // 해당 섹션에서 순차 탐색 수행
    for (int j = index_table[i].start; j < SIZE && (i == INDEX_TABLE_SIZE - 1 || j < index_table[i + 1].start); j++) {
        if (arr[j] == key) {
            return j; // 탐색 성공
        }
    }
    return -1;
}

int main() {
    int key, result;

    printf("검색할 키 값을 입력하세요: ");
    scanf("%d", &key);

    result = indexed_sequential_search(key);
    if (result == -1)
        printf("요소를 찾지 못했습니다.\n");
    else
        printf("요소가 배열의 %d번째 인덱스에 있습니다.\n", result);
        
    return 0;
}