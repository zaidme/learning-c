#include "book.h"

struct Book* create_book(const char* title, const char* author, int year){
    struct Book* book =(struct Book*)malloc(sizeof(struct Book));

    strcpy(book->title, title);
    strcpy(book->author,author);
    book->year=year;
    book->connection_count=0;

    return book;
    
};

int connect_books(struct Book* book1, struct Book* book2, int weight){
    if(book1->connection_count>=4 || book2->connection_count>=4){
        return -1;
    }

    book1->connections[book1->connection_count].weight = weight;
    book2->connections[book2->connection_count].weight = weight;


    book1->connections[book1->connection_count].book = book2;
    book2->connections[book2->connection_count].book = book1;

    book1->connection_count++;    
    book2->connection_count++;    

    return 0; 
};

void display_connections(const struct Book* book){
    if(book->connection_count==0){
        printf("no connections\n");
    };

    for(int i = 0 ; i < book->connection_count; i++){
    printf("Connected to %s by %s, RI: %d\n",
    book->connections[i].book->title,
    book->connections[i].book->author,
    book->connections[i].weight);


    
    }
}