#include <iostream>

template<typename T>
struct Node {
    T data{};    // Содержимое узла
    Node *prev{};    // Указатель на предыдущий узел
    Node *next{};    // Указатель на следующий узел
};

template<typename T>
class LinkedList {

private:

    Node<T> *first;    // Указатель на первый узел списка
    Node<T> *last;    // Указатель на последний узел списка
    int size{};        // Размер списка

public:

    LinkedList();

    ~LinkedList();

    void Add(const T &data);

    void Delete();

    Node<T> *operator[](int idx);

    void show();

    void sort(Node<T> *first_m, Node<T> *last_m);

    void swap(Node<T> *node1, Node<T> *node2);

    void qs();

};

template<typename T>
LinkedList<T>::LinkedList() : first(nullptr), last(nullptr) {}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *tmp;
    while (first) {
        tmp = first;
        first = first->next;
        delete tmp;
    }
    size = 0;
}

template<typename T>
void LinkedList<T>::Add(const T &data) {
    auto *newNode = new Node<T>;
    newNode->data = data;
    newNode->prev = last;
    if (first == nullptr) {
        first = newNode;
    }
    if (last != nullptr) {
        last->next = newNode;
    }
    size++;
    last = newNode;
}

template<typename T>
void LinkedList<T>::show() {
    Node<T> *tmp;
    tmp = first;
    while (tmp) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

template<typename T>
void LinkedList<T>::Delete() {
    if (last == nullptr) {
        return;
    }
    Node<T> *tmp = last;
    last = last->prev;
    if (last != nullptr) {
        last->next = nullptr;
    }
    size--;
    delete tmp;
}

template<typename T>
Node<T> *LinkedList<T>::operator[](int idx) {
    int cnt = 0;
    Node<T> *curr = first;
    while (curr) {
        if (cnt == idx) {
            return curr;
        }
        curr = curr->next;
        ++cnt;
    }
    return nullptr;
}

template<typename T>
void LinkedList<T>::swap(Node<T> *node1, Node<T> *node2) {
    std::swap(node1->data, node2->data);
}

template<typename T>
void LinkedList<T>::sort(Node<T> *first_m, Node<T> *last_m) {
    int size_m = 1;
    Node<T> *cnt3 = first_m;
    Node<T> *i = first_m;
    Node<T> *j = last_m;
    while (cnt3 != last_m) {
        cnt3 = cnt3->next;
        size_m++;
    }
    int cnt1 = 1, cnt2 = size_m;
    for (int k = 1; k <= size_m / 2; k++) {
        cnt3 = cnt3->prev;
    }
    T x = cnt3->data;
    do {
        while (i->data < x) {
            i = i->next;
            cnt1++;
        }
        while (j->data > x) {
            j = j->prev;
            cnt2--;
        }

        if (cnt1 <= cnt2) {
            if (i->data > j->data) {
                swap(i, j);
            }
            i = i->next;
            cnt1++;
            j = j->prev;
            cnt2--;
        }
    } while (cnt1 <= cnt2);
    if (cnt1 < size_m)
        sort(i, last_m);
    if (1 < cnt2)
        sort(first_m, j);
}

template<typename T>
void LinkedList<T>::qs() {
    sort(this->first, this->last);
}

int main() {
    LinkedList<int> list;
    list.Add(1);
    list.Add(2);
    list.Add(4);
    list.Add(8);
    list.Add(7);
    list.Add(5);
    list.Add(14);
    list.Delete();
    list.Add(9);
    list.Add(6);
    list.Add(3);
    list.Add(10);
    list.qs();
    list.show();
    return 0;
}
