#include <iostream>
#include "Phone.h"

using namespace std;

/*===================================================================
Constructors:
==================================================================*/
//default
Phone :: Phone()
{
}

Phone :: Phone(string id, int q, double p, string n)
{
    productID=id;
    quantity=q;
    price=p;
    name=n;
}

/*===================================================================
Methods
====================================================================*/

void Phone::setProductID(string id)
{
  productID=id;
}

void Phone::setQuantity(int q)
{
    quantity=q;
}

void Phone::setPrice(double p)
{
    price=p;
}

void Phone::setName(string n)
{
    name=n;
}

string Phone::getProductID()
{
    return productID;
}

int Phone::getQuantity()
{
    return quantity;
}

double Phone::getPrice()
{
    return price;
}

string Phone::getName()
{
    return name;
}
