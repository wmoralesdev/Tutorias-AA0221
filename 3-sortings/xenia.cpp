#include <iostream>
#include <string>
using namespace std;

struct node {
    int data;
    node *next;

    node() { next = NULL; }

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(node *elements) {
    while (elements != NULL) {
        cout << elements->data << " ";
        elements = elements->next;
    }
    cout << endl;
}

node* getSeparated(string s) {
    node* head = NULL;

    for (int i = 0; i < s.length(); i++) {
        if(s[i] != '+') {
            int num = s[i] == '1' ? 1 : s[i] == '2' ? 2 : 3;

            node* newNode = new node(num);
            newNode->next = head;
            head = newNode;
        }
    }

    return head;
}

void enqueue(node** queue, int data) {
    node* newNode = new node(data);

    if(!*queue) {
        *queue = newNode;
    }
    else {
        // Encontrar el ultimo elemento
        node* last = *queue;

        // 1 -> 2 -> 3 -> 4 -> NULL

        while(last->next) {
            last = last->next;
        }

        // El siguiente al ultimo sea el nuevo
        last->next = newNode;
    }
}

string format(node* elements) {
    string s = "";

    while (elements != NULL) {
        s += to_string(elements->data) + "+";
        elements = elements->next;
    }

    return s.substr(0, s.length() - 1) + "\n";
}

int size(node *elements) {
    int count = 0;

    while (elements != NULL) {
        count++;
        elements = elements->next;
    }
    return count;
}

node* merge(node *left, node *right) {
    node *result = NULL;

    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            enqueue(&result, left->data);
            left = left->next;
        } else {
            enqueue(&result, right->data);
            right = right->next;
        }
    }

    while(left != NULL) {
        enqueue(&result, left->data);
        left = left->next;
    }

    while(right != NULL) {
        enqueue(&result, right->data);
        right = right->next;
    }

    return result;
}

node* mergeSort(node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    int listSize = size(head);

    node *left = NULL;
    node *right = NULL;

    for(int i = 0; i < listSize / 2; i++) {
        enqueue(&left, head->data);
        head = head->next;
    }

    for(int i = (listSize / 2); i < listSize; i++) {
        enqueue(&right, head->data);
        head = head->next;
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main(void) {
    string s;
    cin >> s;

    node *elements = getSeparated(s);
    elements = mergeSort(elements);

    cout << format(elements);

    return 0;
}