#ifndef BOOK_H
#define BOOK_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Connection
{
    int weight; //1-100 is the range im thinkin
    struct Book* book; //pointer to connected book 
};


struct Book
{
    //normal stuff
    char title[100];
    char author[100];
    int year;
    struct Connection connections[4]; //ill keep it at 4 connections per book rn
    int connection_count;//used for appending new connections since u cant really do that as easily in c
};

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

#endif