#include <iostream>
using namespace std;

// дефиниране на структура за елемент на списък
struct Node {
    int data; // данни на елемента
    Node* next; // указател към следващия елемент
};

// функция за добавяне на елемент в края на списъка
void push_back(Node*& START, int value) {
    if (START == nullptr) { // ако списъкът е празен
        START = new Node; // създава се нов елемент
        START->data = value; // записват се данните на елемента
        START->next = nullptr; // следващият елемент е нулев указател
    }
    else { // ако списъкът не е празен
        Node* current = START; // установяване на маркер за текущия елемент
        while (current->next != nullptr) { // обхождане на списъка до последния елемент
            current = current->next;
        }
        current->next = new Node; // създава се нов елемент
        current->next->data = value; // записват се данните на елемента
        current->next->next = nullptr; // следващият елемент е нулев указател
    }
}

// функция за извеждане на стойностите на елементите на списъка
void printList(Node* START) {
    Node* current = START; // установяване на маркер за текущия елемент
    while (current != nullptr) { // обхождане на списъка
        cout << current->data << " "; // извеждане на стойността на елемента
        current = current->next; // преминаване към следващия елемент
    }
    cout << endl; // извеждане на нов ред
}

// функция за намиране на повтарящите се елементи на списъка
void findDuplicates(Node* START) {
    Node* current1 = START; // установяване на маркер за текущия елемент
    while (current1 != nullptr) { // обхождане на списъка
        Node* current2 = current1->next; // установяване на маркер за следващия елемент
        while (current2 != nullptr) { // обхождане на списъка от следващия елемент на текущия до края
            if (current1->data == current2->data) { // ако има повтарящи се стойности на елементите
                cout << current1->data << " "; // извеждане на стойността на повтарящия се елемент
                break; // прекратяване на обхождането от текущия елемент до края
            }
            current2 = current2->next; // преминаване към следващия елемент
        }
        current1 = current1->next; // преминаване към следващия елемент от списъка
    }
}

int main() {
    Node* START = nullptr; // указател към началото на списъка
    push_back(START, 2); // добавяне на елемент в края на списъка
    push_back(START, 5); // добавяне на елемент в края на списъка
    push_back(START, 9); // добавяне на елемент в края на списъка
    push_back(START, 5); // добавяне на елемент в края на списъка
    push_back(START, 12); // добавяне на елемент в края на списъка
    push_back(START, 9); // добавяне на елемент в края на списъка
    cout << "Елементите на списъка са: ";
    printList(START); // извеждане на списъка
    cout << "Повтарящите се елементи на списъка са: ";
    findDuplicates(START); // намиране на повтарящите се елементи на списъка
    cout << endl; // извеждане на нов ред
    return 0;
}