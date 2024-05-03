#include <iostream>
#include <string>

using namespace std;

// 노드 구조체 정의
struct Node {
    string value;
    Node* next;

    Node(string val) : value(val), next(nullptr) {}
};

// 링크드리스트 클래스 정의
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 리스트의 앞에 새로운 노드 추가
    void prepend(string value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 리스트에서 특정 값을 탐색하는 함수
    bool search(string value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value) {
                cout << value << "을(를) 찾았습니다." << endl;
                return true;
            }
            current = current->next;
        }
        cout << value << "이(가) 리스트에 없습니다." << endl;
        return false;
    }

    // 두 리스트를 합치는 함수
    void concatenate(LinkedList& other) {
        if (head == nullptr) {
            head = other.head;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = other.head;
        }
        other.head = nullptr; // 다른 리스트가 빈 상태가 되도록 함
    }

    // 리스트를 역순으로 만드는 함수
    void reverse() {
        Node* prev = nullptr, * current = head, * next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // 리스트의 모든 요소를 출력하는 함수
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // 소멸자
    ~LinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }
};

int main() {
    LinkedList list1;
    list1.prepend("APPLE");
    list1.print();
    list1.prepend("KIWI");
    list1.print();
    list1.prepend("BANANA");
    list1.print(); // BANANA->KIWI->APPLE->NULL 출력
    
    printf("\n");

    list1.search("BANANA"); // BANANA을(를) 찾았습니다.
    list1.search("LEMON");

    printf("\n");

    printf("2개의 리스트를 합하는 함수\n\n");
    printf("1번째리스트\n");
    LinkedList list2;
    list2.prepend("10");
    list2.prepend("20");
    list2.prepend("30");
    list2.print(); // 30->20->10->NULL 출력
    printf("2번째리스트\n");
    LinkedList list3;
    list3.prepend("40");
    list3.prepend("50");
    list3.print(); // 50->40->NULL 출력

    printf("\n병합된 결과\n");
    list2.concatenate(list3);
    list2.print(); // 30->20->10->50->40->NULL 출력

    printf("\n역순의 리스트를 리턴하는 함수\n");
    list2.reverse();
    list2.print(); // 40->50->10->20->30->NULL 출력

    return 0;
}
