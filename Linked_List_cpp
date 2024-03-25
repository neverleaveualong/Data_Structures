#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100 // 리스트의 최대크기
typedef int element; // 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 리스트 초기화 함수
void init(ArrayListType* L) {
	L->size = 0;
}
// 리스트가 비어 있으면 true를 반환, 그렇지 않으면 false를 반환
bool is_empty(ArrayListType* L) {
	return L->size == 0;
}
// 리스트가 가득 차 있으면 true를 반환, 그렇지 않으면 false를 반환
bool is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

//리스트 L에서 pos 위치의 값 리턴
element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	//pos가 음수거나 배열 크기를 넘어선 값일 경우
	//오류 발생
	return L->array[pos];
}
// 리스트 출력
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

//맨 끝에 item을 삽입
void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

//pos 위치에 아이템을 삽입하고
//원래 pos위치~맨 뒤에 있는 아이템들은 한 칸씩 밀림
void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}

//pos위치에 있는 아이템을 삭제하고
//pos위치 바로 뒤~맨 뒤에 있는 아이템들은 한 칸씩 앞으로 옴
element remove(ArrayListType* L, int pos) {
	element item;
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}

int main() {
	// ArrayListType를 정적으로 생성하고 ArrayListType를 가리키는 포인터를 함수의 매개변수로 전달한다.
	ArrayListType list;
	init(&list);
	insert(&list, 0, 10);
	print_list(&list);// 0번째 위치에 10 추가
	insert(&list, 0, 20);
	print_list(&list);// 0번째 위치에 20 추가
	insert(&list, 0, 30);
	print_list(&list);// 0번째 위치에 30 추가
	insert_last(&list, 40);
	print_list(&list);// 맨 끝에 40 추가
	remove(&list, 0);
	print_list(&list);// 0번째 항목 삭제
	return 0;
}
