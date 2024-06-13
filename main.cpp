#include <iostream>

using namespace std;
class Node {
public:
    int value;
    Node* next;

    Node() {
        value = 0;
        next = nullptr;
    }

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void add(Node* n) {
        if (head == nullptr) {
            head = n;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    bool insertAt(Node* n, int index) {
        if (index < 0) return false;

        if (index == 0) {
            n->next = head;
            head = n;
            return true;
        }

        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) return false;

        n->next = temp->next;
        temp->next = n;
        return true;
    }

    int count() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void sort() {
        if (head == nullptr || head->next == nullptr) return;

        Node* current = head;
        Node* index = nullptr;
        int temp;

        while (current != nullptr) {
            index = current->next;

            while (index != nullptr) {
                if (current->value > index->value) {
                    temp = current->value;
                    current->value = index->value;
                    index->value = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    Node* getHead() {
        return head;
    }

    Node* get(int index) {
        if (index < 0) return nullptr;
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index) {
                return temp;
            }
            count++;
            temp = temp->next;
        }
        return nullptr; 
    }

    Node* search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->value == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; 
    }
};

int main() {
    LinkedList list;

    
    list.add(new Node(1));
    list.add(new Node(2));
    list.add(new Node(3));
    list.add(new Node(7));
    list.add(new Node(8));
    list.add(new Node(12));

    
    std::cout << "Lista przed sortowaniem:" << std::endl;
    for (Node* temp = list.getHead(); temp != nullptr; temp = temp->next) {
        std::cout << temp->value << " ";
    }
    std::cout << std::endl;

    
    list.sort();

    
    std::cout << "Lista po sortowaniu:" << std::endl;
    for (Node* temp = list.getHead(); temp != nullptr; temp = temp->next) {
        std::cout << temp->value << " ";
    }
    std::cout << std::endl;

    
    Node* newNode = new Node(4);
    bool inserted = list.insertAt(newNode, 1);
    if (inserted) {
        std::cout << "Wstawiono nowy węzeł na indeksie 1." << std::endl;
    } else {
        std::cout << "Nie udało się wstawić nowego węzła." << std::endl;
    }

    std::cout << "Lista po wstawieniu:" << std::endl;
    for (Node* temp = list.getHead(); temp != nullptr; temp = temp->next) {
        std::cout << temp->value << " ";
    }
    std::cout << std::endl;

    return 0;
}