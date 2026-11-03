
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at beginning
void insertBeginning(int x) {
    Node *n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}

// Insert at end
void insertEnd(int x) {
    Node *n = new Node;
    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

// Insert after a specific node
void insertAfter(int key, int x) {
    Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Node not found!\n";
        return;
    }

    Node *n = new Node;
    n->data = x;
    n->next = temp->next;
    temp->next = n;
}

// Insert before a specific node
void insertBefore(int key, int x) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->data == key) {
        insertBeginning(x);
        return;
    }

    Node *temp = head;

    while (temp->next != NULL &&
           temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Node not found!\n";
        return;
    }

    Node *n = new Node;
    n->data = x;
    n->next = temp->next;
    temp->next = n;
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;

    cout << "First node deleted.\n";
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;

    cout << "Last node deleted.\n";
}

// Delete a specific node
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->data == key) {
        deleteBeginning();
        return;
    }

    Node *temp = head;

    while (temp->next != NULL &&
           temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Node not found!\n";
        return;
    }

    Node *del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node deleted.\n";
}

// Search a node
void search(int key) {
    Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Node found at position "
                 << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;
    }

    cout << "Node not found!\n";
}

// Display list
void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;

    cout << "Linked List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Main menu
int main() {
    int choice, x, key;

    while (true) {
        cout << "\n===== SINGLY LINKED LIST MENU =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search a node\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertBeginning(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insertEnd(x);
                break;

            case 3:
                cout << "Enter existing node value: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> x;
                insertAfter(key, x);
                break;

            case 4:
                cout << "Enter existing node value: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> x;
                insertBefore(key, x);
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteNode(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                search(key);
                break;

            case 9:
                display();
                break;

            case 10:
                cout << "Program terminated.\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
