#pragma once
#include <iostream>
using namespace std;

class IntegerArray
{
private:
	int _size{};
	int* _ptr{};
public:
	IntegerArray();
	IntegerArray(int);
	IntegerArray(const IntegerArray&);	
	IntegerArray& operator=(const IntegerArray&);
	~IntegerArray();	
	void resetArray();	
	int& operator[](int);	
	int getsize() const;	
    void editSize(int);
	void set_N(int = 0, int = 0);
	void insert_N(int = 0, int = 0);
	void delete_N(int = 0);	
	void inshead(int);
	void add_back(int);
	void insback(int);
	void out_head();
	void out_back();
	int search(int = 0);

	friend ostream& operator<<(ostream&, const IntegerArray&);
};

