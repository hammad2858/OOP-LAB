#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void displayBooksAfterYear(Book* books, int count, int year) {
    cout << "Books published after " << year << ":\n";
    for (int i = 0; i < count; ++i) {
        if (books[i].year > year) {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << "\n";
        }
    }
}

int main() {
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;

    Book* books = new Book[numBooks];

    for (int i = 0; i < numBooks; ++i) {
        cout << "Enter details for book " << i + 1 << ":\n";
        cout << "Title: ";
        cin.ignore();
        getline(cin, books[i].title); // used getline for whitespace characters
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Year: ";
        cin >> books[i].year;
    }

    int specificYear;
    cout << "Enter the year to display books published after it: ";
    cin >> specificYear;

    displayBooksAfterYear(books, numBooks, specificYear);

    delete[] books;

    return 0;
}