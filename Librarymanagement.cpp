#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string name;
    string author;
    bool isIssued;
};

int main() {
    Book books[50];
    int count = 0;
    int choice;

    do {
        cout << "\n----- Library Management System -----\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        // 🔴 FIX: handle invalid input (prevents infinite loop)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {

        case 1:
            if (count >= 50) {
                cout << "Library is full!\n";
                break;
            }

            cout << "Enter Book ID: ";
            cin >> books[count].id;

            cin.ignore(); // clear newline
            cout << "Enter Book Name: ";
            getline(cin, books[count].name);

            cout << "Enter Author Name: ";
            getline(cin, books[count].author);

            books[count].isIssued = false;
            count++;

            cout << "Book added successfully!\n";
            break;

        case 2:
            if (count == 0) {
                cout << "No books available!\n";
                break;
            }

            cout << "\n--- Book List ---\n";
            for (int i = 0; i < count; i++) {
                cout << "ID: " << books[i].id
                     << ", Name: " << books[i].name
                     << ", Author: " << books[i].author
                     << ", Status: "
                     << (books[i].isIssued ? "Issued" : "Available") << endl;
            }
            break;

        case 3: {
            int searchId;
            cout << "Enter Book ID to search: ";
            cin >> searchId;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (books[i].id == searchId) {
                    cout << "\nBook Found!\n";
                    cout << "Name: " << books[i].name << endl;
                    cout << "Author: " << books[i].author << endl;
                    cout << "Status: "
                         << (books[i].isIssued ? "Issued" : "Available") << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found!\n";
            break;
        }

        case 4: {
            int issueId;
            cout << "Enter Book ID to issue: ";
            cin >> issueId;

            bool issued = false;
            for (int i = 0; i < count; i++) {
                if (books[i].id == issueId) {
                    if (books[i].isIssued) {
                        cout << "Book already issued!\n";
                    } else {
                        books[i].isIssued = true;
                        cout << "Book issued successfully!\n";
                    }
                    issued = true;
                    break;
                }
            }

            if (!issued)
                cout << "Book not found!\n";
            break;
        }

        case 5: {
            int returnId;
            cout << "Enter Book ID to return: ";
            cin >> returnId;

            bool returned = false;
            for (int i = 0; i < count; i++) {
                if (books[i].id == returnId) {
                    if (!books[i].isIssued) {
                        cout << "Book was not issued!\n";
                    } else {
                        books[i].isIssued = false;
                        cout << "Book returned successfully!\n";
                    }
                    returned = true;
                    break;
                }
            }

            if (!returned)
                cout << "Book not found!\n";
            break;
        }

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
