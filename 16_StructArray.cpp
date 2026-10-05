#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

struct Book
{
    char name[100];
    char author[100];
    char publisher[100];
    char genre[50];
    int year;
    double price;
    int id;
};

void Fill(Book* books, Book data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        books[i] = data[i];
    }
}

void Show(Book* books, int size)
{
	system("cls");
    for (int i = 0; i < size; i++)
    {
        cout << "\nBook " << i + 1 << endl;
        cout << "ID: " << books[i].id << endl;
        cout << "Name: " << books[i].name << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publisher: " << books[i].publisher << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << "Year: " << books[i].year << endl;
        cout << "Price: " << books[i].price << endl;
    }
	cout << "\nPress any key to continue...";
    _getch();
}

void ChangeData(Book* books, int size)
{
    int id;

    cout << "Enter book ID: ";
    cin >> id;

    for (int i = 0; i < size; i++)
    {
        if (books[i].id == id)
        {
            cout << "New name: ";
            cin >> ws;
            cin.getline(books[i].name, 100);

            cout << "New author: ";
            cin.getline(books[i].author, 100);

            cout << "New publisher: ";
            cin.getline(books[i].publisher, 100);

            cout << "New genre: ";
            cin.getline(books[i].genre, 50);

            cout << "New year: ";
            cin >> books[i].year;

            cout << "New price: ";
            cin >> books[i].price;

            cout << "Book updated!" << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}

void SearchAuthor(Book* books, int size)
{
    char author[100];

    cout << "Enter author: ";
    cin >> ws;
    cin.getline(author, 100);
    system("cls");
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].author, author) == 0)
        {
            cout << books[i].name << " | "
                << books[i].author << " | "
                << books[i].price << endl;
        }
    }
    cout << "\nPress any key to continue...";
    _getch();
}

void SearchTitle(Book* books, int size)
{
    char title[100];

    cout << "Enter name: ";
    cin >> ws;
    cin.getline(title, 100);
    system("cls");
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].name, title) == 0)
        {
            cout << "ID: " << books[i].id << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Price: " << books[i].price << endl;
        }
    }
    cout << "\nPress any key to continue...";
    _getch();
}

void SearchPublisher(Book* books, int size)
{
    char publisher[100];

    cout << "Enter publisher: ";
    cin >> ws;
    cin.getline(publisher, 100);
    system("cls");
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].publisher, publisher) == 0)
        {
            cout << books[i].name << " | "
                << books[i].author << endl;
        }
    }
    cout << "\nPress any key to continue...";
    _getch();
}

void SearchGenre(Book* books, int size)
{
    char genre[50];

    cout << "Enter genre: ";
    cin >> ws;
    cin.getline(genre, 50);
    system("cls");
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].genre, genre) == 0)
        {
            cout << books[i].name << " | "
                << books[i].author << endl;
        }
    }
    cout << "\nPress any key to continue...";
    _getch();
}

void ChangePrice(Book* books, int size)
{
    int id;
    double price;

    cout << "Enter book ID: ";
    cin >> id;

    for (int i = 0; i < size; i++)
    {
        if (books[i].id == id)
        {
            cout << "Enter new price: ";
            cin >> price;

            books[i].price = price;

            cout << "Price updated!" << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}

void AddBook(Book*& books, int& size)
{
    Book* newBooks = new Book[size + 1];

    for (int i = 0; i < size; i++)
    {
        newBooks[i] = books[i];
    }

    cout << "Enter ID: ";
    cin >> newBooks[size].id;

    cout << "Enter name: ";
    cin >> ws;
    cin.getline(newBooks[size].name, 100);

    cout << "Enter author: ";
    cin.getline(newBooks[size].author, 100);

    cout << "Enter publisher: ";
    cin.getline(newBooks[size].publisher, 100);

    cout << "Enter genre: ";
    cin.getline(newBooks[size].genre, 50);

    cout << "Enter year: ";
    cin >> newBooks[size].year;

    cout << "Enter price: ";
    cin >> newBooks[size].price;

    delete[] books;

    books = newBooks;
    size++;

    cout << "Book added!" << endl;
}

void DeleteBook(Book*& books, int& size)
{
    int id;

    cout << "Enter ID of the book to delete: ";
    cin >> id;

    int index = -1;

    for (int i = 0; i < size; i++)
    {
        if (books[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Книгу не знайдено!" << endl;
        return;
    }

    Book* newBooks = new Book[size - 1];

    for (int i = 0, j = 0; i < size; i++)
    {
        if (i != index)
        {
            newBooks[j] = books[i];
            j++;
        }
    }

    delete[] books;

    books = newBooks;
    size--;

    cout << "Книгу видалено!" << endl;
}

int main()
{
    int size = 10;

    Book data[10] =
    {
        {"Harry Potter", "J.K. Rowling", "Bloomsbury", "Fantasy", 1997, 350, 1},
        {"The Hobbit", "J.R.R. Tolkien", "Allen & Unwin", "Fantasy", 1937, 400, 2},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopia", 1949, 300, 3},
        {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Novel", 1925, 280, 4},
        {"It", "Stephen King", "Viking Press", "Horror", 1986, 500, 5},
        {"The Alchemist", "Paulo Coelho", "HarperCollins", "Novel", 1988, 320, 6},
        {"Dracula", "Bram Stoker", "Archibald Constable", "Horror", 1897, 270, 7},
        {"Dune", "Frank Herbert", "Chilton Books", "Science Fiction", 1965, 450, 8},
        {"Hamlet", "William Shakespeare", "Penguin", "Drama", 1603, 250, 9},
        {"The Shining", "Stephen King", "Doubleday", "Horror", 1977, 420, 10}
    };

    Book* books = new Book[size];

    Fill(books, data, size);

    int choice;

    do
    {
        system("cls");
        cout << "\n===== LIBRARY =====" << endl;
        cout << "1. Show all books" << endl;
        cout << "2. Edit book" << endl;
        cout << "3. Search by author" << endl;
        cout << "4. Search by name" << endl;
        cout << "5. Search by publisher" << endl;
        cout << "6. Search by genre" << endl;
        cout << "7. Change price" << endl;
        cout << "8. Add book" << endl;
        cout << "9. Delete book" << endl;
        cout << "0. Exit" << endl;

        cout << "Select an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Show(books, size);
            break;

        case 2:
            ChangeData(books, size);
            break;

        case 3:
            SearchAuthor(books, size);
            break;

        case 4:
            SearchTitle(books, size);
            break;

        case 5:
            SearchPublisher(books, size);
            break;

        case 6:
            SearchGenre(books, size);
            break;

        case 7:
            ChangePrice(books, size);
            break;
            
        case 8:
            AddBook(books, size);
            break;

        case 9:
            DeleteBook(books, size);
            break;

        case 0:
            cout << "Exit..." << endl;
            break;

        default:
            cout << "Error choice!" << endl;
        }

    } while (choice != 0);
    delete[] books;
}