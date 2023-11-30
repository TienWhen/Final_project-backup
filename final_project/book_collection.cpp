#include<functional>
#include<forward_list>
#include"book_collection.h"

//Description: The compare the book years for sorting.
//Parameter: Poniter of the books that are being compared to.
//Return: True or false.
bool compareBookYear(book* b1, book* b2)
{
    return b1->getYear() < b2->getYear();
}

//Description: To push the book to the front.
//Parameter: Pointer of a book.
//Return: none
void bookCollection::Insert(book* b)
{
    booklist.push_front(b);
    booksById[b->getId()] = b;
}

//Description: To sort the books by years.
//Parameter: none
//Return: Book List.
forward_list<book*> bookCollection::SortByYear()
{
    booklist.sort(compareBookYear);
    return booklist;
}

//Description: To search the book by the title.
//Parameter: String of the book.
//Return: Book pointer.
book* bookCollection::Search(string t)
{
    book* return_b = nullptr;

    for (book* b : booklist)
    {
        if (t == b->getTitle())
        {
            return_b = b;
            break;
        }
    }

    return return_b;
}

//Description: To search for book by the ID.
//Parameter: Int ID.
//Return: Book pointer.
book* bookCollection::Search (unsigned int id)
{
    book* return_b = nullptr;
    auto book_i = booksById.find(id);
    
    // found id
    if (book_i != booksById.end())
    {
        return_b = book_i->second;
    }

    return return_b;
}

//Description: To delete a book by using ID.
//Parameter: Int ID.
//Return: Bool (true or false).
bool bookCollection::Delete (unsigned int id)
{
    bool return_b = false;

    if (booksById.erase(id) == 1)
    {
      return_b = true;
    }
    

    booklist.remove_if(
        [id](const book* bookPtr) 
        {
           return bookPtr->getId() == id;         
        }
    );

    return return_b;



}