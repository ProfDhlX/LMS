
class Library {
public:
    void addBook(const string &title, const string &author, const string &category, int quantity) {
        for (int i = 0; i < quantity; ++i) {
            books.push_back(Book(title, author, quantity));
        }
        updateCategoryFile(category, title, author, quantity);
    }

    void deleteBook(const string &title, const string &category) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                break;
            }
        }
        removeBookFromCategory(category, title);
    }

    void displayInventory() const {
        cout << "Library Inventory:\n";
        cout << setw(30) << left << "Book Name" << setw(25) << left << "Available Stocks" << "Author" << "\n";

        for (const auto &book : books) {
            cout << setw(30) << left << book.getTitle() << setw(25) << left << book.getAvailableStock() << book.getAuthor() << "\n";
        }
    }

    void displayRecords() const {
        // for displaying records
    }

    const vector<Book> &getBooks() const {
        return books;
    }

private:
    vector<Book> books;

    void updateCategoryFile(const string &category, const string &title, const string &author, int quantity) {
        ofstream file(category + ".txt", ios::app);
        if (file.is_open()) {
            file << "Book Name: " << title << ", Available Stocks: " << quantity << ", Author: " << author << "\n";
            file.close();
        }
        else {
            cout << "Unable to open the category file for writing.\n";
        }
    }

    void removeBookFromCategory(const string &category, const string &title) {
        string line;
        ifstream inFile(category + ".txt");
        ofstream outFile(category + "_temp.txt");

        if (!inFile.is_open() || !outFile.is_open()) {
            cout << "Error: Unable to open category file for reading or writing.\n";
            return;
        }

        while (getline(inFile, line)) {
            if (line.find("Book Name: " + title) == string::npos) {
                outFile << line << "\n";
            }
        }

        inFile.close();
        outFile.close();
        remove((category + ".txt").c_str());
        rename((category + "_temp.txt").c_str(), (category + ".txt").c_str());
    }
};