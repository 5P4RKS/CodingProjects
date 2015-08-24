#include <iostream>
#include "Phone.h"
#include "Database.h"
#include <fstream>
#include <vector>
using namespace std;


Database::Database()
{
	//default constructor
	num_of_phones=500;
    //pList(num_of_phones);
	index=-1;
}

Database::Database(int number_phones)
{
    //number_phones no longer is necessary because of the vector class.
	num_of_phones=number_phones;
    //pList(num_of_phones);
	index=-1;
}

Database::~Database()
{
	//destructor
	//save phones to an output file before clearing memory
	saveFile();
	//delete [] pList;
}

void Database::saveFile()
{
	fstream dataFile;
	dataFile.open("database.txt", ios::out);

	for(int i=0; i<=index; i++)
	{
	dataFile<<pList[i].getProductID()<<"\t\t\t" << pList[i].getPrice() << "\t\t" <<pList[i].getQuantity() << "\t" <<"\t\t"<<pList[i].getName()<<endl;
    }
	dataFile.close();
}


int Database::find_name()
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

void Database::query()
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
        prod_loc=find_name();
    }

    if(user_input=="id")
    {
        prod_loc=find_product();
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
        //use index as the upper limit because the rest of the array is empty
		for(int j=0; j<=index; j++)
        {
            if(pList[j].getPrice()>=low&&pList[j].getPrice()<=high)
            {
                cout <<pList[j].getProductID() <<"\t\t\t" << pList[j].getPrice() << "\t\t" <<pList[j].getQuantity() << "\t" <<"\t\t"<<pList[j].getName()<<endl;
            }

        }

    }
}

void Database::display()
{
    int prod_loc=-1;

    prod_loc=find_product();
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

void Database::update()
{
    int prod_loc=-1,tempQ;
    string user_input, tempN;
    double tempP;

    prod_loc=find_product();
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


int Database::find_product()
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

void Database::print_database()
{
    cout<<"The following items are currently in the database"<<endl;
    cout <<"product ID \t\t" <<"price \t\t" <<"quantity on hand" <<"\t name "<<endl <<endl;
    for(int i=0; i <= index; i++)
    {
        cout <<pList[i].getProductID() <<"\t\t\t" << pList[i].getPrice() << "\t\t" <<pList[i].getQuantity() << "\t" <<"\t\t"<<pList[i].getName()<<endl;
    }
}

void Database::add_phone()
{
    Phone tempObj;
    string id_input;
    int lenSIZE,tempint;
    string tempstr;
    double temp; //used to store user input
    int duplicate_check=1;
    bool check_loop=true;

    while(check_loop)
    {


    try{
        cout << "Please provide the following information....The product ID number which should be two letters followed by 2 integers... \n";
        getline(cin,id_input);
        cout<<"checking to see if this is storing correctly...." <<id_input <<endl;
        lenSIZE=id_input.length();
        cout<<"length of string is " << lenSIZE <<endl;
        idChecker(id_input,lenSIZE);
        check_loop=false;
    }
    catch(bool e)
    {
        cout<<e<<" Invalid ID"<<endl;
    }
    }
    /*
    do
    {
        cout << "Please provide the following information....The product ID number which should be two letters followed by 2 integers... \n";
        getline(cin,id_input);
        cout<<"checking to see if this is storing correctly...." <<id_input <<endl;
        lenSIZE=id_input.length();
        cout<<"length of string is " << lenSIZE <<endl;

    }while(idChecker(id_input,lenSIZE));
*/
    for(int i=0; i < pList.size(); i++)
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
        tempObj.setProductID(id_input);

        cout << "What is the price of the phone....provide an int or double\n";
        cin>>temp;
        tempObj.setPrice(temp);
        cout << "What is the quantity on hand (must be integer)\n";
        cin>>tempint;
        //pList[index].setQuantity(tempint);
        tempObj.setQuantity(tempint);

        cout << "What is the name of the phone?.\n";
        cin.ignore();
        getline(cin,tempstr);

        tempObj.setName(tempstr);
        //pList[index].setName(tempstr);
        cout << "Entry has been added to database...\n";
        pList.push_back(tempObj);
    }

}

bool Database::idChecker(string id, int lenSIZE)
{
    int counter;
    bool fstep=false, sstep=false, astep=true;
    if(lenSIZE>4 || lenSIZE<4) astep=false; //if the ID is not 4 characters long return true so that user can input again

    //Test for the alpha letters at the beginning of the product number
    for(counter=0;counter<2;counter++)
    {
        cout<<"checking.." <<id[counter] <<" in position.." <<counter<<endl;
        if(isalpha(id[counter])&&isalpha(id[counter+1]))
            fstep=true;
    }
    //Test if the second two characters are digits
    for(counter=2;counter<lenSIZE;counter++)
    {
        cout<<"checking.." <<id[counter] <<" in position.." <<counter<<endl;
        if(isdigit(id[counter])&&isdigit(id[counter+1]))
            sstep=true;
    }
    if(sstep==true && fstep==true && astep==true)
        {
            return true;
        }
    else
        {
            throw false;
        }
}
