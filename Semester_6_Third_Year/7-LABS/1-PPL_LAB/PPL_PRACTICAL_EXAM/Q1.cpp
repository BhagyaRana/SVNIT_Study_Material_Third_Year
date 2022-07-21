// U19CS012 - BHAGYA VINOD RANA

#include <bits/stdc++.h>
using namespace std;

// For Statistical Analysis of Transactions in Library
static int success = 0;
static int failure = 0;

// Book Class
class book
{
public:
    string author, title, publisher;
    int price, stock;

    // Book Constructor

    // Default Constructor
    book() {}
    // Paramaterized Constructor
    book(string author, string title, string publisher, int price, int stock)
    {
        this->author = author;
        this->title = title;
        this->publisher = publisher;
        this->price = price;
        this->stock = stock;
    }

    // To Check if Stock is Available or Not
    bool is_available()
    {
        return (stock > 0);
    }

    // Function to Check if Match of Title and Author is Found or Not
    bool match(string title, string author)
    {
        return this->title == title and this->author == author;
    }

    // Returns the Price if Stock is Available
    float available(int copies)
    {
        if (stock >= copies)
        {
            stock -= copies;
            return (copies * price);
        }
        else
        {
            return -1;
        }
    }

    // F(x) to Update the Price
    void update_price(int price)
    {
        this->price = price;
    }

    // F(x) to Update the Stock
    void update_stock(int stock)
    {
        this->stock += stock;
    }
};

// Library Class - Library to Store the Books
class Library
{
    vector<book *> books;

public:
    // F(x) to add Book
    void add_book(book *b)
    {
        books.emplace_back(b);
        success++;
    }

    // F(x) to Search for Particular Book [Linear Search]
    bool search_book(string title, string author)
    {
        for (int i = 0; i < books.size(); i++)
            if (books[i]->match(title, author))
                return true;
        return false;
    }

    // F(x) to issue Book
    bool issue_book(string title, string author, int copies)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i]->match(title, author))
            {
                if (books[i]->is_available())
                {
                    float cost = books[i]->available(copies);
                    if (cost != -1)
                    {
                        cout << "Book Issued Successfully! Cost : " << cost << endl;
                        // Increment the Success Transaction
                        success++;
                        return true;
                    }
                    else
                    {
                        cout << "Not Enough Copies Available. No Book Issued!" << endl;
                        // Increment the Failure Transaction
                        failure++;
                        return false;
                    }
                }
                else
                {
                    cout << "Book Not Available." << endl;
                    failure++;
                    return false;
                }
            }
        }

        failure++;
        cout << "Book Not Found." << endl;
        return false;
    }

    // F(x) to Update the Price
    void update_price(string title, string author, int price)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i]->match(title, author))
            {
                books[i]->update_price(price);
                cout << "Price Updated." << endl;
                success++;
                return;
            }
        }

        failure++;
        cout << "Book Not Found." << endl;
    }

    // F(x) to Update the Stock of Book
    void update_stock(string title, string author, int stock)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i]->match(title, author))
            {
                books[i]->update_stock(stock);
                cout << "Stock Updated." << endl;
                success++;
                return;
            }
        }
        failure++;
        cout << "Book Not Found." << endl;
    }
};

// F(x) to Print the Menu Options in Library
void menu()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "1 -> Add Book to Library" << endl;
    cout << "2 -> Search Book in Library" << endl;
    cout << "3 -> Issue Book in Library" << endl;
    cout << "4 -> Update Book Price in Library" << endl;
    cout << "5 -> Update Book Stock in Library" << endl;
    cout << "6 -> Statistical Analysis of Transactions" << endl;
    cout << "7 -> Exit the Library" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

int main()
{
    // Class to Store all the Books
    Library store;

    book tmp_book;
    string author, title, publisher;
    int price, stock, copies;
    int cost, choice = 0;

    while (choice != 7)
    {
        menu();
        cout << "Enter your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Author : ";
            cin >> author;
            cout << "Enter Title : ";
            cin >> title;
            cout << "Enter Publisher : ";
            cin >> publisher;
            cout << "Enter Price : ";
            cin >> price;
            cout << "Enter Stock : ";
            cin >> stock;

            tmp_book = book(author, title, publisher, price, stock);

            store.add_book(new book(tmp_book));

            cout << "Book Added Successfully." << endl;
            break;
        }
        case 2:
        {
            cout << "Enter Author : ";
            cin >> author;
            cout << "Enter Title : ";
            cin >> title;

            if (store.search_book(title, author))
            {
                cout << "Book Found." << endl;
            }
            else
            {
                cout << "Book Not Found." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Enter Author : ";
            cin >> author;
            cout << "Enter Title : ";
            cin >> title;
            cout << "Enter No. of Copies: ";
            cin >> copies;

            store.issue_book(title, author, copies);
            break;
        }
        case 4:
        {
            cout << "Enter Author : ";
            cin >> author;
            cout << "Enter Title : ";
            cin >> title;
            cout << "Enter New Price : ";
            cin >> price;

            store.update_price(title, author, price);
            break;
        }
        case 5:
        {
            cout << "Enter Author : ";
            cin >> author;
            cout << "Enter Title : ";
            cin >> title;
            cout << "Enter Stock to be Added : ";
            cin >> stock;

            store.update_stock(title, author, stock);
            break;
        }
        case 6:
        {
            cout << "Successful Transactions : " << success << endl;
            cout << "Failure Transactions    : " << failure << endl;
            break;
        }
        case 7:
        {
            cout << "Thank You for Visiting Our Library!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice Entered." << endl;
            break;
        }
        }
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    return 0;
}
