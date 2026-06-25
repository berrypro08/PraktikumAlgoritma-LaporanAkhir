#include "double_linked_list.h"
#include <iostream>
using namespace std;

int main() {
    int n, r;
    if (!(cin >> n >> r)) return 0;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < n; i++) {
        char karakter;
        cin >> karakter;
        list.add_back(karakter);
    }

    if (list.is_empty()) {
        cout << "EMPTY" << endl;
        return 0;
    }

    Node* p1 = list.head;
    Node* p2 = list.tail;

    for (int i = 0; i < r; i++) {
        long long x, y;
        if (!(cin >> x >> y)) break;
        if (list.is_empty()) break;

        x = x % list.size;
        if (x < 0) x += list.size;
        for (int j = 0; j < x; j++) {
            p1 = (p1->next != nullptr) ? p1->next : list.head;
        }

        y = y % list.size;
        if (y < 0) y += list.size;
        for (int j = 0; j < y; j++) {
            p2 = (p2->prev != nullptr) ? p2->prev : list.tail;
        }

        if (p1 == p2) {
            Node* target = p1;
            Node* next_p1 = nullptr;
            Node* next_p2 = nullptr;

            if (list.size > 1) {
                next_p1 = (target->next != nullptr) ? target->next : list.head;
                next_p2 = (target->prev != nullptr) ? target->prev : list.tail;
            }

            int idx = 0;
            Node* curr = list.head;
            while (curr != target) {
                curr = curr->next;
                idx++;
            }

            list.delete_idx(idx);

            if (list.is_empty()) {
                p1 = p2 = nullptr;
            } else {
                p1 = next_p1;
                p2 = next_p2;
            }
        }
        else if (list.size >= 2) {
            bool adjacent = false;
            if (p1->next == p2 || p2->next == p1) {
                adjacent = true;
            } 
            else if ((p1 == list.head && p2 == list.tail) || (p1 == list.tail && p2 == list.head)) {
                adjacent = true;
            }

            if (adjacent) {
                char temp = p1->data;
                p1->data = p2->data;
                p2->data = temp;
            }
        }
    }

    if (list.is_empty()) {
        cout << "EMPTY" << endl;
    } else {
        Node* curr = list.head;
        while (curr != nullptr) {
            cout << curr->data;
            curr = curr->next;
        }
        cout << endl;
    }

    return 0;
}
