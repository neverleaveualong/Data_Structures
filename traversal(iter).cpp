#include <stdio.h>
#include <stdlib.h>

    typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

#define SIZE 100

int top = -1;
TreeNode* stack[SIZE]; //노드들을 쌓는 스택 선언
void push(TreeNode* p) {
    if (top < SIZE - 1)
        stack[++top] = p;
}
TreeNode* pop() {
    if (top >= 0)
        return stack[top--];
    return NULL; // 스택에 아무것도 없으면 NULL 리턴
}

void postorder_iter(TreeNode* p) {
    TreeNode* last_visited = NULL;
    while (1) {
    // 리프노드의 left는 NULL이므로
    // 왼쪽으로 쭉 가다가 리프 노드까지만 push하고 중단
    for (; p; p = p->left)
        push(p);
    p = pop();
    // (1) 스택에 들어있는 것이 있어 pop으로 노드 리턴을 받았고
    // (2) 리턴 받은 노드의 오른쪽 자식 노드가 없거나, 마지막으로 방문했을 경우
    while (p && (p->right == NULL || p->right == last_visited)) {
        printf("[%d] ", p->data);
        last_visited = p;
        p = pop();
        if (!p) break; // 스택에 아무것도 없을 때 break
    }
    if (!p) break; // 스택에 아무것도 없을 때 break
    push(p);
    p = p->right;
    }
}

int main() {
    TreeNode n1 = { 1, NULL, NULL };
    TreeNode n2 = { 4, &n1, NULL };
    TreeNode n3 = { 16, NULL, NULL };
    TreeNode n4 = { 25, NULL, NULL };
    TreeNode n5 = { 20, &n3, &n4 };
    TreeNode n6 = { 15, &n2, &n5 };
    TreeNode* root = &n6;
    printf("후위 순회= ");
    postorder_iter(root);
    printf("\n");
    return 0;
}