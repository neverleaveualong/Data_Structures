#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 100
int heights[MAX_N];
int max_height = 0;
int num_of_candy = 0;
int request = 0;


int find_cutting_height(int key) {
    int low = 0;
    int high = max_height; // 절단기 높이를 막대사탕 최대 높이로 설정
    int result = 0;
    while (low <= high) {
        int total = 0;
        // 잘린 막대사탕 길이의 합 계산
        for (int i = 0; i < num_of_candy; i++) {
            if (heights[i] > key) {
            total += heights[i] - key;
        }
        }
        // 이진 탐색
        if (total == request) {
            return key; // 요청한 길이와 일치하는 경우 바로 반환
        }
        else if (total < request) {
            result = key; // 현재 높이를 기록
            high = key - 1; // 절단기 높이를 낮춤
        }
        else {
            low = key + 1; // 절단기 높이를 높임
        }
        key = (low + high) / 2; // 중간값 갱신
    }
    return result; // 요청한 길이를 넘지 않는 가장 큰 절단기 높이 반환
}

int main() {
    int num_of_tests;
    scanf("%d", &num_of_tests);
    for (int test = 0; test < num_of_tests; test++) {
        scanf("%d %d", &num_of_candy, &request);
        // 입력 받은 막대사탕의 길이와 최대 높이 찾기
        max_height = 0;
        for (int i = 0; i < num_of_candy; i++) {
            scanf("%d", &heights[i]);
            if (heights[i] > max_height) {
                max_height = heights[i];
            }
        }

        // 이진 탐색 실행
        int result = find_cutting_height(max_height);

        // 절단기 높이를 막대 사탕 최대 높이부터 시작
        
        printf("%d\n", result);
    }
    return 0;
}