#include <stdio.h>
#include "book.h"

int main() {
    // TODO: make a bunch of books manually for now
    struct Book* book1 = create_book("Dune","Frank Herbert", 1965);

    struct Book* book2 =create_book("Digital Minimalism", "Cal Newport", 2019);

    struct Book* book3 = create_book("How to Train Your Dragon", "Cressida Cowell", 2003);

    struct Book* book4  =create_book("Dune Messiah", "Frank Herbert", 1969);

    struct Book* book5 = create_book("How to be a Pirate", "Cressida Cowell", 2005);

    struct Book* book6 = create_book("Flowers for Algernon", "Daniel Keyes", 1959);

    struct Book* book7 = create_book("Of Mice & Men", "John Steinbeck", 1937);
    
    
    // TODO: Create connections between the books from before


    connect_books(book1,book4, 99);
    connect_books(book3,book5, 90);
    connect_books(book7, book6, 75);
    connect_books(book2,book6,70);
    
    // TODO: Display the connections cuz its so cool
    display_connections(book6);
    display_connections(book4);
    // TODO: free memorysusss
    free(book1);
    free(book2);
    free(book3);
    free(book4);
    free(book5);
    free(book6);
    free(book7);
    return 0;
}