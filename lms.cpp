#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

//declarations of classes
class User;
class Admin;
class Student;
void clear(){
    system("cls");
}

class Book
{
public:
    Book(const string &title, const string &author) : title(title), author(author) {}

    const string &getTitle() const
    {
        return title;
    }

    const string &getAuthor() const
    {
        return author;
    }

private:
    string title;
    string author;
};

class Library
{
public:
    void addBook(const string &title, const string &author, const string &category)
    {
        books.push_back(Book(title, author));
        updateCategoryFile(category, title, author);
    }

    void deleteBook(const string &title, const string &category)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (it->getTitle() == title)
            {
                books.erase(it);
                break;
            }
        }
        removeBookFromCategory(category, title);
    }

    void displayInventory() const
    {
        cout << "Library Inventory:\n";
        for (const auto &book : books)
        {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << "\n";
        }
    }

    void displayRecords() const
    {
        //for displaying records
    }

private:
    vector<Book> books;

    void updateCategoryFile(const string &category, const string &title, const string &author)
    {
        ofstream file(category + ".txt", ios::app);
        if (file.is_open())
        {
            file << "Title: " << title << ", Author: " << author << "\n";
            file.close();
        }
        else
        {
            cout << "Unable to open the category file for writing.\n";
        }
    }

    void removeBookFromCategory(const string &category, const string &title)
    {
        string line;
        ifstream inFile(category + ".txt");
        ofstream outFile(category + "_temp.txt");

        if (!inFile.is_open() || !outFile.is_open())
        {
            cout << "Error: Unable to open category file for reading or writing.\n";
            return;
        }

        while (getline(inFile, line))
        {
            if (line.find("Title: " + title) == string::npos)
            {
                outFile << line << "\n";
            }
        }

        inFile.close();
        outFile.close();
        remove((category + ".txt").c_str());
        rename((category + "_temp.txt").c_str(), (category + ".txt").c_str());
    }
};

class User
{
public:
    User(const string &username) : username(username) {}

    const string &getUsername() const
    {
        return username;
    }

private:
    string username;
};

class Admin : public User
{
public:
    Admin(const string &username, const string &password) : User(username), password(password) {}

    bool authenticate(const string &enteredPassword) const
    {
        return enteredPassword == password;
    }

    void adminMenu(Library &library)
    {
        while (true)
        {
            cout << "\nAdmin Menu:\n";
            cout << "1. Add Book\n";
            cout << "2. Delete Book\n";
            cout << "3. Display Inventory\n";
            cout << "4. Display Records\n";
            cout << "5. Logout\n";
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string title, author, category;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                chooseCategory(category);
                library.addBook(title, author, category);
                break;
            }
            case 2:
            {
                string title, category;
                cout << "Enter the title of the book to delete: ";
                cin.ignore();
                getline(cin, title);
                chooseCategory(category);
                library.deleteBook(title, category);
                break;
            }
            case 3:
                library.displayInventory();
                break;
            case 4:
                library.displayRecords();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Try again.\n";
            }
            clear();
        }
    }

// CATEGORY DELCARATION
    void chooseCategory(string &category)
    {
        cout << " ******************Please choose a category****************** \n";
        cout << "1. Story\n";
        cout << "2. Poetry\n";
        cout << "3. Course Book\n";
        cout << "4. Novel\n";
        cout << "5. Drama\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        category = "Story";
        break;
        case 2:
        category = "Poetry";
        break;
        case 3:
        category = "Course Book";
        break;
        case 4:
        category = "Novel";
        break;
        case 5:
        category = "Drama";
        break;
        default:
            cout << "Invalid category choice. Setting category to 'Other'.\n";
            category = "Other";
        }
    }

private:
    string password;
};

class Student : public User
{
public:
    Student(const string &username) : User(username) {}

    void studentMenu(Library &library)
    {
        while (true)
        {
            cout << "\nStudent Menu:\n";
            cout << "1. View Category\n";
            cout << "2. Borrow Book\n";
            cout << "3. Return Book\n";
            cout << "4. Logout\n";
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                //viewing category
                break;
            case 2:
                //borrowing a book
                break;
            case 3:
                //returning a book
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        }
    }
};

int main()
{
    Library library;
    Admin admin("admin", "admin");
    Student student("student123");

    string username, password;
    cout << "\n                    -------------------WELCOME TO LIBRARY MANAGEMENT SYSTEM------------------------\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    if (username == "admin" && admin.authenticate(password))
    {
        admin.adminMenu(library);
    }
    else if (username == "student123")
    {
        student.studentMenu(library);
    }
    else
    {
        cout << "Invalid username or password. Exiting...\n";
    }

    return 0;
}