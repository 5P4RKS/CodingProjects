#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;
int index=-1; //set to negative one because currently there are no entries

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

    //other methods
    void add_phone(Phone [],const int);
    bool idChecker(string,int);
};

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

class Database
{
private:
public:
    void add_phone(Phone [], const int);
    bool idChecker(string,int);
    void print_database(Phone []);
    int find_product(Phone []);
    void update(Phone []);
    void display(Phone []);
    void query(Phone []);
    int find_name(Phone []);

};

int Database::find_name(Phone pList[])
{
    int index_loc=-1;
    string name;
    cout<<"Provide the name of the phone..."<<endl;
    cin.ignore();
    getline(cin,name);

    for(int i=0;i<=index;i++)
    {
        if(name==pList[i].getName())
        {
            index_loc=i;
            cout<<"Product found...in the following location in the array...\n";
            cout<<index_loc<<endl;
        }
    }
    if(index_loc<0)
        cout<<"Product not found in the database...try again"<<endl;
    return index_loc;
}

void Database::query(Phone pList[])
{
    string user_input;
    int prod_loc=-1;
    double low,high;
    cout <<"You will now be seraching for an item in the database....\n";
    cout <<"How would you like to search for an item in the database? \n";
    cout <<"By product name? product ID? or by price...Enter name,id or price \n";
    cin >> user_input;

    if(user_input=="name")
    {
        prod_loc=find_name(pList);
    }

    if(user_input=="id")
    {
        prod_loc=find_product(pList);
    }

    if(prod_loc!=-1)
    {
        cout<<"Here is the product information.... \n";
        cout<<"product id\t"<<pList[prod_loc].getProductID()<<endl;
        cout<<"price is \t" <<pList[prod_loc].getPrice()<<endl;
        cout<<"quantity on hand is \t" <<pList[prod_loc].getQuantity()<<endl;
        cout<<"name of the phone is \t" <<pList[prod_loc].getName()<<endl;
    }

    if(user_input=="price")
    {
        cout<<"I have entered..."<<endl;
        cout <<"What is the price range that you want to search...provide the lower range number first"<<endl;
        cin >> low >> high;
        cout << "Here are the phones in that price range" <<endl;
        cout <<"product number \t\t" <<"price \t\t" <<"quantity on hand" <<"\t name "<<endl <<endl;
        for(int j=0; j<=index; j++)
        {
            if(pList[j].getPrice()>=low||pList[j].getPrice()<=high)
            {
                cout <<pList[j].getProductID() <<"\t\t\t" << pList[j].getPrice() << "\t\t" <<pList[j].getQuantity() << "\t" <<"\t\t"<<pList[j].getName()<<endl;
            }

        }

    }
}

void Database::display(Phone pList[])
{
    int prod_loc=-1;

    prod_loc=find_product(pList);
    if(prod_loc!=-1)
    {
        cout<<"Here is the product information.... \n";
        cout<<"product id\t"<<pList[prod_loc].getProductID()<<endl;
        cout<<"price is \t" <<pList[prod_loc].getPrice()<<endl;
        cout<<"quantity on hand is \t" <<pList[prod_loc].getQuantity()<<endl;
        cout<<"name of the phone is \t" <<pList[prod_loc].getName()<<endl;
    }
    else
        cout <<"product not found....\n";

}

void Database::update(Phone pList[])
{
    int prod_loc=-1,tempQ;
    string user_input, tempN;
    double tempP;

    prod_loc=find_product(pList);
    if(prod_loc!=-1)
    {
        do
        {
            cout<<"what would you like to update price, quantity, name, or delete an entry(enter delete) (case sensitive)?" <<endl;
            cin.ignore();
            getline(cin,user_input);
        }while(user_input != "price" && user_input != "quantity" && user_input !="name" && user_input!="delete");

        if(user_input=="price")
        {
            cout << "input price update \n";
            cin >> tempP;
            pList[prod_loc].setPrice(tempP);
        }
        if(user_input=="quantity")
        {
            cout << "input quantity update \n";
            cin >> tempQ;
            pList[prod_loc].setQuantity(tempQ);
        }
        if(user_input=="name")
        {
            cout <<"input an updated name \n";
            getline(cin,tempN);
            pList[prod_loc].setName(tempN);
        }
        if(user_input=="delete")
        {
            cout <<"This phone is now deleting..."<<endl;
            for(int i=prod_loc;i<=index;i++)
            {
              pList[i]=pList[i+1];
            }
            index--;
        }
    }
    else
    cout <<"product not found...";

}


int Database::find_product(Phone pList[])
{
    string id_input="-1";
    int index_loc=-1;

    cout<<"Please enter the product ID that you need information for...." <<endl;
    cin>>id_input;

    for(int i=0;i<=index;i++)
    {
        if(id_input==pList[i].getProductID())
        {
            index_loc=i;
            cout<<"Product found in the following location in the database...."<<endl;
            cout<<index_loc<<endl;
        }
    }

    if(index_loc<0)
        cout<<"Product not found in the database....try again"<<endl;
    return index_loc;
}

void Database::print_database(Phone pList[])
{
    cout<<"The following items are currently in the database"<<endl;
    cout <<"product ID \t\t" <<"price \t\t" <<"quantity on hand" <<"\t name "<<endl <<endl;
    for(int i=0; i <= index; i++)
    {
        cout <<pList[i].getProductID() <<"\t\t\t" << pList[i].getPrice() << "\t\t" <<pList[i].getQuantity() << "\t" <<"\t\t"<<pList[i].getName()<<endl;
    }
}

void Database::add_phone(Phone pList[], const int MAX)
{
    string id_input;
    int lenSIZE,tempint;
    string tempstr;
    double temp; //used to store user input
    int duplicate_check=1;
    do
    {
        cout << "Please provide the following information....The product ID number which should be two letters followed by 2 integers... \n";
        getline(cin,id_input);
        cout<<"checking to see if this is storing correctly...." <<id_input <<endl;
        lenSIZE=id_input.length();
        cout<<"length of string is " << lenSIZE <<endl;

    }while(idChecker(id_input,lenSIZE));

    for(int i=0; i < MAX; i++)
    {
        if(id_input==pList[i].getProductID())
        {
            cout << "Product already exists in database\n";
            duplicate_check =0;
            break;
        }
    }

    //will create a new entry if duplicate_check is set to one
    if(duplicate_check ==1)
    {
        cout << "Product does not exist...will now create entry...\n";
        index++; //glovbal variable to keep index of number of elements/objects
        pList[index].setProductID(id_input);

        cout << "What is the price of the phone....provide an int or double\n";
        cin>>temp;
        pList[index].setPrice(temp);
        cout << "What is the quantity on hand (must be integer)\n";
        cin>>tempint;
        pList[index].setQuantity(tempint);
        cout << "What is the name of the phone?.\n";
        cin.ignore();
        getline(cin,tempstr);
        pList[index].setName(tempstr);
        cout << "Entry has been added to database...\n";
    }

}

bool Database::idChecker(string id, int lenSIZE)
{
    int counter;
    if(lenSIZE>4 || lenSIZE<4) return true; //if the ID is not 4 characters long return true so that user can input again

    //Test for the alpha letters at the beginning of the product number
    for(counter=0;counter<2;counter++)
    {
        cout<<"checking.." <<id[counter] <<" in position.." <<counter<<endl;
        if(!isalpha(id[counter]))
            return true;
    }
    //Test if the second two characters are digits
    for(counter=2;counter<lenSIZE;counter++)
    {
        cout<<"checking.." <<id[counter] <<" in position.." <<counter<<endl;
        if(!isdigit(id[counter]))
            return true;
    }
        return false;

}

int main()
{
    const int MAX=500;
    Phone phones[MAX];
    Database smartphones;
    int user_input;

    while(user_input!=7)
    {
        cout << "Welcome to the smart phone database. Please select one of the options below to proceed." <<endl;
        cout << "Enter 1 to add a new item...\n";
        cout << "Enter 2 to update an item...\n";
        cout << "Enter 3 to display an item's location...\n";
        cout << "Enter 4 to print the database...\n";
        cout << "Enter 5 to display a smart phone's information in the database\n";
        cout << "Enter 6 to query the data \n";
        cout << "Enter 7 to quit this program...\n";
        cout << "this is the value of index "<<index<<endl;

        cin >> user_input;
        cin.ignore();

        switch(user_input)
        {
            case 1: cout << "you have chosen 1" <<endl;
            smartphones.add_phone(phones,MAX);
            break;
            case 2: cout << "You have chosen 2" <<endl;
            smartphones.update(phones);
            break;
            case 3: cout << "You have chosen 3" <<endl;
            smartphones.find_product(phones);
            break;
            case 4: cout << "You have chosen 4" <<endl;
            smartphones.print_database(phones);
            break;
            case 5: cout << "You have chosen 5" <<endl;
            smartphones.display(phones);
            break;
            case 6: cout << "You have chosen 6" <<endl;
            //query(productNum,price,phone_names,ipntr,quantity_on_hand,index);
            smartphones.query(phones);
            break;
            case 7: cout << "You have chosen 7" <<endl;
            break;
            default: cout <<"You must choose a number from 1 through 6. Please try again..." <<endl;
            break;

        }
        cout << endl <<endl;

    }

    return 0;
    }
