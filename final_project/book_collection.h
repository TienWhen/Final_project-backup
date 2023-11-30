#include<map>
#include<forward_list>
#include"book.h"

using namespace std;
class bookCollection{
    //Data structures of the book.
    //containing the Link List and MAP.
   private:
       //Take in the book pointers to add it in the collection.
       forward_list < book* > booklist;

       //Take in the ID and the book pointer for quick search.
       map <unsigned int, book*> booksById;

    public:
        //Desciption: This is used for adding books.
        //Parameter: book pointer.
        void Insert(book*);

        //Desciption: This is used for sorting the year of the books.
        //Parameter: none
        //
        forward_list<book*> SortByYear ();

        //Desciption: This is used for searching books by ID.
        //Parameter: ID.
        book* Search (unsigned int id);

        //Desciption: This is used for searching books by tittle.
        //Parameter: string tittle.
        book* Search (string title);

        //Desciption: This is used for deleting books by ID.
        //Parameter: ID.
        bool Delete (unsigned int);
        
};

//Description: To compare book years.
//Parameter: book pointers.
bool compareBookYear(book* , book* );
