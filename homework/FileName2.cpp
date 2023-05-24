#include <iostream>
using namespace std;

// ���������� �� ��������� �� ������� �� ������
struct Node {
    int data; // ����� �� ��������
    Node* next; // �������� ��� ��������� �������
};

// ������� �� �������� �� ������� � ���� �� �������
void push_back(Node*& START, int value) {
    if (START == nullptr) { // ��� �������� � ������
        START = new Node; // ������� �� ��� �������
        START->data = value; // �������� �� ������� �� ��������
        START->next = nullptr; // ���������� ������� � ����� ��������
    }
    else { // ��� �������� �� � ������
        Node* current = START; // ������������ �� ������ �� ������� �������
        while (current->next != nullptr) { // ��������� �� ������� �� ��������� �������
            current = current->next;
        }
        current->next = new Node; // ������� �� ��� �������
        current->next->data = value; // �������� �� ������� �� ��������
        current->next->next = nullptr; // ���������� ������� � ����� ��������
    }
}

// ������� �� ��������� �� ����������� �� ���������� �� �������
void printList(Node* START) {
    Node* current = START; // ������������ �� ������ �� ������� �������
    while (current != nullptr) { // ��������� �� �������
        cout << current->data << " "; // ��������� �� ���������� �� ��������
        current = current->next; // ����������� ��� ��������� �������
    }
    cout << endl; // ��������� �� ��� ���
}

// ������� �� �������� �� ����������� �� �������� �� �������
void findDuplicates(Node* START) {
    Node* current1 = START; // ������������ �� ������ �� ������� �������
    while (current1 != nullptr) { // ��������� �� �������
        Node* current2 = current1->next; // ������������ �� ������ �� ��������� �������
        while (current2 != nullptr) { // ��������� �� ������� �� ��������� ������� �� ������� �� ����
            if (current1->data == current2->data) { // ��� ��� ��������� �� ��������� �� ����������
                cout << current1->data << " "; // ��������� �� ���������� �� ���������� �� �������
                break; // ������������ �� ����������� �� ������� ������� �� ����
            }
            current2 = current2->next; // ����������� ��� ��������� �������
        }
        current1 = current1->next; // ����������� ��� ��������� ������� �� �������
    }
}

int main() {
    Node* START = nullptr; // �������� ��� �������� �� �������
    push_back(START, 2); // �������� �� ������� � ���� �� �������
    push_back(START, 5); // �������� �� ������� � ���� �� �������
    push_back(START, 9); // �������� �� ������� � ���� �� �������
    push_back(START, 5); // �������� �� ������� � ���� �� �������
    push_back(START, 12); // �������� �� ������� � ���� �� �������
    push_back(START, 9); // �������� �� ������� � ���� �� �������
    cout << "���������� �� ������� ��: ";
    printList(START); // ��������� �� �������
    cout << "����������� �� �������� �� ������� ��: ";
    findDuplicates(START); // �������� �� ����������� �� �������� �� �������
    cout << endl; // ��������� �� ��� ���
    return 0;
}