#pragma once
#include "book.h" 


unsigned int book::id_generator = 0;

//Description: Function that makes ID for the book.
//Parameter: string tittle, string genre, and int year.
//Return: The unique ID
book::book(string t, string g, unsigned int y) :
title(t), genre(g), year(y)
{
    id = ++id_generator;
}

//This use to get the title.
string book::getTitle()
{
  return title;
}

//This use to get the ID.
unsigned int book::getId() const
{
  return id;
}

//This use to get the genre.
string book::getGenre()
{
  return genre;
}

//This use to get the year.
unsigned int book::getYear()
{
  return year; 
}
