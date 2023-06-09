#include <iostream>
#include <string>
using namespace std; 

class Node {
public:
    int rollNumber;
    string name;
    Node* next;
};

class CircularLinkedList {
private:
    Node* LAST;
public:
    CircularLinkedList() {
        LAST = NULL;
    }
    void addNode();
    bool search(int rollno, Node** ariya, Node** rezza);
    bool listEmpty();
    bool delNode();
    void traverse();

}; 

void CircularLinkedList::addNode() { //write your answer here 
    //a
    Node* newNode = new Node();     //step 1a
    cout << "Masukkan nomor Roll: ";
    cin >> newNode->rollNumber;     //step 2a
    cout << "Masukkan nama Roll: ";
    cin >> newNode->name;           // step 2a


    if (listEmpty()) {              
        newNode->next = newNode;    //step 3a
        LAST = newNode;             //step 4a
    }
    else {
        //b
        Node* rezza = LAST->next;     //step 1b
        Node* ariya = NULL;          //step 2b
        while (rezza->rollNumber > newNode->rollNumber || ariya == LAST) {  //step 3b
            ariya = rezza;         //step 4b
            rezza = rezza->next;    //step 5b
        }
    }
    cout << "Roll berhasil ditambahkan" << endl;
}

bool CircularLinkedList::search(int rollno, Node** ariya, Node** rezza) {
    *ariya = LAST->next;
    *rezza = LAST->next;
    while (*rezza != LAST) {
        if (rollno == (*rezza)->rollNumber) {
            return true;
        }
        *ariya = *rezza;
        *rezza = (*rezza)->next;
    }      if (rollno == LAST->rollNumber) {
        return true;
    }
    else {
        return false;
    }
}

bool CircularLinkedList::listEmpty() {
    return LAST == NULL;

}  

bool CircularLinkedList::delNode() { //write your answer here 

    if (listEmpty()) {
        cout << "Daftar kosong. Penghapusan gagal." << endl;
        return false;
    }

    int rollno;
    cout << "Masukkan nomor roll yang akan dihapus: ";
    cin >> rollno;
    cout << "Roll berhasil dihapus" << endl;

    Node* ariya = NULL;
    Node* rezza = NULL;
    bool found = search(rollno, &ariya, &rezza);

    if (found) {
       
        if (rezza == LAST->next) {  //step 2
            if (rezza == LAST) {  //step 1
                LAST = NULL;    //step 1a
                delete rezza;   //step 4
                return true;
            }
            else {
                LAST->next = rezza->next;
                delete rezza;
                return true;
            }
        }
        
        else if (rezza == LAST) {
            ariya->next = LAST->next;
            LAST = ariya;
            delete rezza;
            return true;
        }
       
        else {
            ariya->next = rezza->next;
            delete rezza;
            return true;
        }
    }
    else {
        cout << "Data tidak ditemukan. Penghapusan gagal." << endl;
        return false;
    }
}

void CircularLinkedList::traverse() {
    if (listEmpty()) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "\nRecords in the list are:\n";
        Node* rezzaNode = LAST->next;
        while (rezzaNode != LAST) {
            cout << rezzaNode->rollNumber << "   " << rezzaNode->name << endl;
            rezzaNode = rezzaNode->next;
        }
        cout << LAST->rollNumber << "   " << LAST->name << endl;
    }
}

int main() {
    
    CircularLinkedList obj;
    while (true) {
        try {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list" << endl;
            cout << "3. View all the records in the list" << endl;
            cout << "4. Exit" << endl;
            cout << "\nEnter your choice (1-5): ";
            char ch;
            cin >> ch;
            switch (ch) {
            case '1': {
                obj.addNode();
                break;
            }
            case '2': {
                obj.delNode();
                break;
            }
            case '3': {
                obj.traverse();
                break;
            }
            case '4': {
                return 0;
            }
            default: {
                cout << "Invalid option" << endl;
                break;
            }
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
