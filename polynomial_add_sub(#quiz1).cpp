#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
#define MAX_TERMS 101

typedef struct { // 다항식 구조체 타입 선언
	int degree;// 다항식의 차수
	float coef[MAX_DEGREE];// 다항식의 계수
} polynomial;

typedef struct {
	float coef;
	int expon;
} polynomial2;

polynomial2 terms[MAX_TERMS] = { { 8,3 },{ 7,1 },{ 1,0 },{ 10,3 },{ 3,2 },{ 1,0 } };
int avail = 6;

char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

polynomial poly_add1(polynomial A, polynomial B)
{// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다. 
	polynomial C;// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {// B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void poly_add2(int Astart, int Aend, int Bstart, int Bend, int* Cstart, int* Cend) {
	float tempcoef;
	*Cstart = avail;
	while (Astart <= Aend && Bstart <= Bend) {
		switch (compare(terms[Astart].expon, terms[Bstart].expon)) {
		case '>': // A의 차수 > B의 차수
			attach(terms[Astart].coef, terms[Astart].expon);
			Astart++;
			break;
		case '=': // A의 차수 == B의 차수
			tempcoef = terms[Astart].coef + terms[Bstart].coef;
			if (tempcoef)
				attach(tempcoef, terms[Astart].expon);
			Astart++;
			Bstart++;
			break;
		case '<': // A의 차수 < B의 차수
			attach(terms[Bstart].coef, terms[Bstart].expon);
			Bstart++;
			break;
		}
	}
	// A의 나머지 항들을 이동함
	for (; Astart <= Aend; Astart++)
		attach(terms[Astart].coef, terms[Astart].expon);
	// B의 나머지 항들을 이동함
	for (; Bstart <= Bend; Bstart++)
		attach(terms[Bstart].coef, terms[Bstart].expon);
	*Cend = avail - 1;
}


polynomial poly_sub1(polynomial A, polynomial B)
{// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다. 
	polynomial D;// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	D.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { // A항 > B항
			D.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { // A항 == B항
			D.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {// B항 > A항
			D.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return D;
}

void poly_sub2(int Astart, int Aend, int Bstart, int Bend, int* Cstart, int* Cend) {
	float tempcoef;
	*Cstart = avail;
	while (Astart <= Aend && Bstart <= Bend) {
		switch (compare(terms[Astart].expon, terms[Bstart].expon)) {
		case '>': // A의 차수 > B의 차수
			attach(terms[Astart].coef, terms[Astart].expon);
			Astart++;
			break;
		case '=': // A의 차수 == B의 차수
			tempcoef = terms[Astart].coef - terms[Bstart].coef;
			if (tempcoef)
				attach(tempcoef, terms[Astart].expon);
			Astart++;
			Bstart++;
			break;
		case '<': // A의 차수 < B의 차수
			attach(-terms[Bstart].coef, terms[Bstart].expon);
			Bstart++;
			break;
		}
	}
	// A의 나머지 항들을 이동함
	for (; Astart <= Aend; Astart++)
		attach(terms[Astart].coef, terms[Astart].expon);
	// B의 나머지 항들을 이동함
	for (; Bstart <= Bend; Bstart++)
		attach(-terms[Bstart].coef, terms[Bstart].expon);
	*Cend = avail - 1;
}

void print_poly1(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

void print_poly2(int start, int end)
{
	for (int i = start; i < end; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[end].coef, terms[end].expon);
}

int main(void)
{
	printf("poly_add1--------------------------------------------------------------------\n");
	polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
	polynomial b = { 4,{ 7, 0, 5, 0, 1 } };
	polynomial c;
	print_poly1(a);
	print_poly1(b);
	c = poly_add1(a, b);
	printf("-----------------------------------------------------------------------------\n");
	print_poly1(c);

	printf("\n\n\n");


	printf("poly_sub1--------------------------------------------------------------------\n");
	polynomial d;
	print_poly1(a);
	print_poly1(b);
	d = poly_sub1(a, b);
	printf("-----------------------------------------------------------------------------\n");
	print_poly1(d);


	printf("\n\n\n");


	printf("poly_add2--------------------------------------------------------------------\n");
	int Astart = 0, Aend = 2, Bstart = 3, Bend = 5, Cstart, Cend;
	poly_add2(Astart, Aend, Bstart, Bend, &Cstart, &Cend);
	print_poly2(Astart, Aend);
	print_poly2(Bstart, Bend);
	printf("-----------------------------------------------------------------------------\n");
	print_poly2(Cstart, Cend);

	printf("\n\n\n");

	printf("poly_sub2--------------------------------------------------------------------\n");
	poly_sub2(Astart, Aend, Bstart, Bend, &Cstart, &Cend);
	print_poly2(Astart, Aend);
	print_poly2(Bstart, Bend);
	printf("-----------------------------------------------------------------------------\n");
	print_poly2(Cstart, Cend);

	return 0;
}
