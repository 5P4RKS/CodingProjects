#ifndef DATABASE_H
#define DATABASE_H
#include "Phone.h"
#include<vector>
using std::vector;

class Database
{
private:
	//Phone *pList;
	vector<Phone> pList;
	int num_of_phones;
	int index;
public:
	Database();
	Database(int);
	~Database();
	void add_phone();
	bool idChecker(string,int);
	void print_database();
	int find_product();
	void update();
	void display();
	void query();
	int find_name();
	void saveFile();

};

#endif // DATABASE_H_INCLUDED
