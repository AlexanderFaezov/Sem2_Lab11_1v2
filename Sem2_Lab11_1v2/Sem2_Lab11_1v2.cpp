#include<iostream>
using namespace std;

struct Node {
    char key;
    Node* next;
};

struct List {
    Node* head_node = nullptr;
    Node* tail_node = nullptr;
};

void pushBack(List& list, char key) {
    Node* new_node = new Node;
    new_node->key = key;
    new_node->next = nullptr;
    if (list.head_node == nullptr) {
        list.head_node = new_node;
    }
    else {
        Node* current = list.head_node;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    list.tail_node = new_node;
}

void removeNode(List& list, char key) {
    Node* current = list.head_node;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                list.head_node = current->next;
            }
            else {
                prev->next = current->next;
            }

            if (current == list.tail_node) {
                list.tail_node = prev;
            }

            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void insertAfter(List& list, char key, char new_key, int k) {
    Node* current = list.head_node;

    while (current != nullptr) {
        if (current->key == key) {
            for (int i = 0; i < k; i++) {
                Node* new_node = new Node;
                new_node->key = new_key;
                new_node->next = current->next;
                current->next = new_node;

                if (current == list.tail_node) {
                    list.tail_node = new_node;
                }

                current = current->next;
            }
            return;
        }
        current = current->next;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    List list;
    cout << "Введите размер списка:" << endl;
    int n;
    cin >> n;
    cout << endl << "Введите элементы списка:" << endl;
    char k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        pushBack(list, k);
    }

    Node* current_node = list.head_node;
    while (current_node != nullptr) {
        cout << current_node->key << ' ';
        current_node = current_node->next;
    }

    cout << endl << "Введите ключ элемента, который нужно удалить: ";
    cin >> k;
    removeNode(list, k);

    cout << "Введите ключ элемента, после которого нужно добавить элементы: ";
    char g;
    cin >> g;
    cout << "Введите новый элемент: ";
    char b;
    cin >> b;
    cout << "Введите количество элементов для вставки: ";
    int numToInsert;
    cin >> numToInsert;
    insertAfter(list, g, b, numToInsert);

    current_node = list.head_node;
    cout << "Список после удаления и вставки: ";
    while (current_node != nullptr) {
        cout << current_node->key << ' ';
        current_node = current_node->next;
    }

    return 0;
}