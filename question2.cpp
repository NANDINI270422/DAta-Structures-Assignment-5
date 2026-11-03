
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void countAndDelete(Node *&head, int key) {
    int count = 0;

    // Delete matching nodes from beginning
    while (head != NULL && head->data == key) {
        Node *temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node *temp = head;

    // Delete remaining matching nodes
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
            count++;
        }
        else {
            temp = temp->next;
        }
    }

    cout << "Count: " << count << endl;
}

void display(Node *head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

int main() {
    int a[] = {1, 2, 1, 2, 1, 3, 1};

    Node *head = NULL;
    Node *tail = NULL;

    for (int x : a) {
        Node *n = new Node{x, NULL};

        if (head == NULL)
            head = n;
        else
            tail->next = n;

        tail = n;
    }

    int key = 1;

    countAndDelete(head, key);

    cout << "Updated Linked List: ";
    display(head);

    return 0;
}
