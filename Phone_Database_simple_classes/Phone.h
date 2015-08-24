#ifndef PHONE_H
#define PHONE_H
#include<string>
#include<iostream>

using namespace std;
/*=========================================================================
Class Phone:
attributes: productID-stores phone id where first 2 chars are letters and the last two are numbers
quantity-an int that store the number of items in the warehouse
price- a double to store the price of the smartphone
name- a string to store the name of the smartphone

Methods: are accessors and mutators
===========================================================================*/

class Phone
{
private:
    string productID;
    int quantity;
    double price;
    string name;
public:
    Phone();
    Phone(string,int,double,string);

    //mutators
    void setProductID(string);
    void setQuantity(int);
    void setPrice(double);
    void setName(string);

    //accessors
    string  getProductID();
    int     getQuantity();
    double  getPrice();
    string  getName();
};

#endif

