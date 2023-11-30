#include<iostream>
#include<string>
#include "book.h" 
#include "book_collection.h"

//Description: To let the user interact with the options.
void userInterface (){

    //Values declared
    string t;  //Title
    string g;  //Genre
    unsigned int id; //ID
    unsigned int y;  //Year
    book* b;  //Book pointer
    bookCollection collection; //Book Collection
    int choice;  //User choices

  do {

    //Display the users options for the program.
    cout << "1) Add a book." << endl;
    cout << "2) Delete a book." << endl;
    cout << "3) Display all books." << endl;
    cout << "4) Search for a book by title: " << endl;
    cout << "5) Search for a book by ID: "<< endl;
    cout << "6) Quit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice; //User put in the valid desired choice here.

   switch (choice)
  {
       
      case 1: //User enter in the book informations in order to add the book into the collection.

        cout << "Enter the book name: " << endl;
          getline(cin.ignore(), t);
          
        cout << "Enter the genre: "<<endl;
          getline(cin, g);

        cout << "Enter the year: "<<endl;
          cin >> y;

          b = new book (t, g, y);
      
        cout << "Book ID: " << b->getId()<< ":"<< b->getGenre() << ":" << b->getTitle() <<endl;

        collection.Insert(b);

          break;

      case 2: //User enter in the book ID to delete a book.
          cout<<"Enter in the book ID to delete: "<<endl;
          cin >> id;

          if (collection.Delete(id))
          {
            cout << "Book deleted."<<endl;
          }
          else
          {
            cout << "Book was not found to delete."<<endl;
          }
          break;

      case 3: //Display the books that has been in the book collection.
      {
          forward_list<book*> sortedBook = collection.SortByYear();
          for (book* b : sortedBook)
          {
            cout<< b->getYear()<< " " << b->getTitle()<< " " << b->getId()<< " "<< b->getGenre()<<" "<< endl;
          }
      }
      break;

      case 4: //User enter in the title of the book to search the desired book.
        cout<<"Enter the title of a book: "<<endl;
        getline(cin.ignore(), t);
        b = collection.Search(t);
        if (b != nullptr)
        {
          cout<< b->getTitle()<< " " << b->getYear()<< " " << b->getId()<< " "<< b->getGenre()<<" "<< endl;
        }
        else
        {
          cout<<"Book not found"<<endl;
        }
          break;

      case 5: //User enter in the ID of the book to search the desired book.
        cout<<"Enter the ID of a book: "<<endl;
        cin >> id;
        b = collection.Search(id);
        if (b != nullptr)
        {
          cout<< b->getId()<< " " << b->getTitle()<< " " << b->getYear()<< " "<< b->getGenre()<<" "<< endl;
        }
        else 
        {
          cout<<"Book not found"<<endl;
        }
          break;

  } 
} while (choice < 6); //Quit the program if user enter option 6.
}

//Description: Call in the interface.
int main()
{
  //Function for the user interface declared in the main.
  userInterface ();
  return 0;
}