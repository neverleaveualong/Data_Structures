#include <stdio.h>
#include <stdlib.h>

int main()
{
    double* p1; // 포인터 선언
    p1 = (double*)malloc(sizeof(double)); // double 타입의 크기만큼 메모리 할당 후, 할당된 메모리의 주소를 p1에 저장. 타입 캐스팅을 double*로 변경
    if (p1 == NULL) { // 메모리 할당 실패 시
        printf("Memory allocation failed\n");
        return 1; // 비정상 종료
    }
    *p1 = 23.92; // 할당된 메모리 주소에 값을 저장. p1은 주소를 저장하므로, 값을 저장하기 위해서는 역참조 연산자(*)를 사용해야 함

    printf("%f\n", *p1); // 저장된 값 출력

    free(p1); // 할당된 메모리 해제
    return 0; // 정상 종료
}
