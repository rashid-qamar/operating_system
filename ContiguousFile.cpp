#include<iostream>
using namespace std;

#define disk_size 20

struct File {
    char name[50];
    int start;
    int size;
};

string block_status[disk_size];        //Array for check status
void initialize_block() {
    for(int i=0; i<disk_size; i++) {
        block_status[i] = "F";
    }
}

void create_file() {
    struct File new_file;
    cout << "\nEnter file name: ";
    cin >> new_file.name;

    cout << "Enter starting block: ";
    cin >> new_file.start;

    cout << "Enter file size: ";
    cin >> new_file.size;

    for(int i=new_file.start; i<new_file.start + new_file.size; i++) {
        if(block_status[i] != "F") {
            cout << "Block are in use";
            return;
        }
        else if(i >= disk_size) {
            cout << "Out of bound";
            return;
        }
        else {
            block_status[i] = new_file.name;
        }
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
        cout << "\nOptions: ";
        cout << "\n--------------";
        cout << "\n1. Create file";
        cout << "\n2. Delete file";
        cout << "\n3. Display Allocation Table";
        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: 
                create_file(); 
                break;
            
            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid input";
        }

    }
}