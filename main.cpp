#include <iostream>

using namespace std;
class Node {
    public:
    int value;
    Node* next;

    Node() {
        value =0;
        next = nullptr;
    }

    Node(int val){
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

        void add(Node* n){
            if (head == nullptr){
                head = n;
            }else{
                Node* temp = head;
                while (temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = n;
            }
        }

        Node* get(int index) {
            if (index <0) return nullptr;
            Node* temp = head;
            int count = 0;
            while (temp != nullptr){
                if (count == index){
                    return temp;
                }
                count++;
                temp = temp->next;
            }
            return nullptr;
        }

        Node* search(int value){
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->value == value) {
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }
    
    Node* getHead() {
        return head;
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

    Node* result = nullptr;
    for (Node* temp = list.getHead(); temp != nullptr; temp = temp->next) {
        if (temp->value == 0) {
            result = temp;
            break;
        }
    }


    if (result != nullptr) {
        cout << "Znaleziono wzel z wartoscia: " << result->value << endl;
    }else{
        cout << "Wezel z wartoscia nie zostalznaleziony" << endl;
    }

    return 0;

}