#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element; // 요소의 타입
typedef struct QueueNode { // 큐의 노드의 타입
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct {
    QueueNode* front, * rear;
} LinkedQueueType;

// 오류 함수
void error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
// 큐 초기화
void init_queue(LinkedQueueType* q) {
    q->front = NULL;
    q->rear = NULL;
}
// 비었는지 확인
int is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}
void queue_print(LinkedQueueType* q) {
    printf(" | ");
    for (QueueNode* p = q->front; p != NULL; p = p->link) {
        printf("%d | ", p->data);
    }
    printf("\n");
}

// 삽입 함수
void enqueue(LinkedQueueType* q, element data){
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    if (temp == NULL)
        error("메모리 할당 에러");
    temp->data = data; // 데이터 저장
    temp->link = NULL; // 링크 필드를 NULL
    if (is_empty(q)) { // 큐가 공백이면
        q->front = temp;
        q->rear = temp;
    }
    else { // 큐가 공백이 아니면
        q->rear->link = temp; // 순서가 중요
        q->rear = temp;
    }
}

// 삭제 함수
element dequeue(LinkedQueueType* q){
    QueueNode* temp = q->front;
    element data;

    if (is_empty(q)) {// 공백상태
        error("큐가 공백상태입니다.");
    }
    data = temp->data; // 데이터를 꺼낸다.
    q->front = q->front->link; // front로 다음노드

    if (q->front == NULL) // 큐가 비었다면
        q->rear = NULL;

    free(temp); // 동적 메모리 해제

    return data; // 데이터 반환
}

int main(){
    LinkedQueueType q;
    init_queue(&q); // 큐 초기화
    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);
    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
    dequeue(&q); queue_print(&q);
    return 0;
}




