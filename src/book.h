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

//declaring the functions for the header file
struct Book* create_book(const char* title, const char* author, int year);
int connect_books(struct Book* book1, struct Book* book2, int weight);
void display_connections(const struct Book* book);



#endif