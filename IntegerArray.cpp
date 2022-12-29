#include "IntegerArray.h"
#include <iostream>
#include <climits>

using namespace std;

static int falseint = -1;

IntegerArray::IntegerArray(){}


IntegerArray::IntegerArray(int size)
{
	
	if (size < 0)
		 throw out_of_range("Размер массива меншьше нуля! \n");	///////////////////////////////////	
	
	if (size == 0)
	{
		_size = 0;
		_ptr = nullptr;
		return;
	}
	
	_size = size;

	try
	{
		_ptr = new int[getsize()] {};
	}
	catch (bad_alloc& ba)
	{
		cout << ba.what();
		_size = 0;
		_ptr = nullptr;
		cout << "Конструктор создал нулевой объект !\n ";
	}
 }

IntegerArray::IntegerArray(const IntegerArray& ar)
{
	
	if (ar.getsize() == 0)
	{
		_size = 0;
		_ptr = nullptr;
		return;
	}	 
		_size = ar._size;	
		
		_ptr = new (nothrow)int[getsize()] {};      //// вариант new без исключения
		
		if (!_ptr )
		{
			cout << "std::bod_alloc";
			_size = 0;
			cout << "При копировании создан нулевой объект!\n";
			return ;
		}
	for (int i = 0; i < getsize(); ++i)
		   _ptr[i] = ar._ptr[i];
	
}

IntegerArray& IntegerArray::operator=(const IntegerArray& ar)
{
	   if (this == &ar)
		return *this;
	                          
	   _size = ar._size;
	     delete[] _ptr;
		 try
		 {
			 _ptr = new int[getsize()] {};    
		 }
		catch (bad_alloc& ba)
		{
			cout << ba.what();
			_size = 0;				
			_ptr = nullptr;
			cout << "При присваивании создан нулевой объeкт! \n";
			return *this;
		}
	    for (int i = 0; i < _size; ++i)
	    	_ptr[i] = ar._ptr[i];

	   return *this;
}


IntegerArray::~IntegerArray()
{
	delete[] _ptr;
}

void IntegerArray::resetArray()
{
	delete[] _ptr;
	_size = 0;
	_ptr = nullptr;
}



int& IntegerArray::operator[](int i)  
{
	try   // перенести в main()
	{
		if (i < 0 || i >= _size)
			throw out_of_range{ "out_of_range\n" };  ///////////////////////////////////////////
	}
	catch (out_of_range& out)  
	{
		cout << "catch :" <<  out.what();
		return falseint;
	}
	return _ptr[i];
}

int IntegerArray::getsize() const
{
	return _size;
}


void IntegerArray::editSize(int size)
{	 
	if (_size == size)	
		return;
	 
	if (size <= 0)
	{
		resetArray();
		return;
	}	

	IntegerArray temp(*this);
	_size = size;	
	delete[] _ptr;
	try                              
	{
		_ptr = new int[getsize()] {};
	}
	catch (bad_alloc& ba)
	{
		cout << ba.what();		
		_ptr = nullptr;
		*this = temp;
		cout << " editSize( int " << size << " ) оставил объект без изменений !\n ";
		return;
	}
	for (int i = 0; (i < temp._size) && (i < _size); ++i)
		_ptr[i] = temp._ptr[i];

}

void IntegerArray::set_N(int N, int x)
{
	if (N < 0 || N >= getsize())
		throw out_of_range{ "out_of_range insert_N()" }; ///////////////////////////////////
	
	_ptr[N] = x;
	
}


void IntegerArray::insert_N(int N, int x)
{
	if (N < 0 || N >= getsize())
		throw out_of_range{ "out_of_range insert_N()" };  //////////////////////////////////
	
	IntegerArray temp(*this);
	
	_size += 1;
	delete[] _ptr;
	try
	{
		_ptr = new int[getsize()] {};
	}
	catch (bad_alloc& ba)
	{
		cout << ba.what();
		_ptr = nullptr;
		*this = temp;
		cout << " insert_N( int " << N << " ) оставил объект без изменений !\n ";
		return;
	}
	_ptr[N] = x;

	int i = N + 1;
	for (; i < temp.getsize(); ++i)
		_ptr[i] = temp._ptr[i - 1];
	for (i = 0; i < N; ++i)
		_ptr[i] = temp._ptr[i];
}

void IntegerArray::delete_N(int N)
{
	if (N < 0 || N >= getsize())
		throw out_of_range{ "out_of_range delete_N()" }; //////////////////////////////////////
	
	IntegerArray temp(*this);
	if (getsize() == 0)
		return;
	else _size -= 1;
	if (getsize() == 0)
	{
		_ptr = nullptr;
		return;
	}
	delete[] _ptr;
	try
	{
		_ptr = new int[getsize()] {};
	}
	catch (bad_alloc& ba)
	{
		cout << ba.what();		
		_ptr = nullptr;
		*this = temp;
		cout << " delete_N( int " << N << " ) оставил объект без изменений !\n ";
		return;
	}
	
	int i = N;
	for (; i < getsize(); ++i)
		_ptr[i] = temp._ptr[i + 1]; 
	for (i = 0; i < N; ++i)
		_ptr[i] = temp._ptr[i];
}


void IntegerArray::inshead(int x)
{
	insert_N(0, x);		
}

void IntegerArray::add_back(int x)
{	
	IntegerArray temp(*this);

	_size += 1;
	delete[] _ptr;
	try
	{
		_ptr = new int[getsize()]{};
	}
	catch (bad_alloc& ba)
	{
		cout << ba.what();
		_ptr = nullptr;
		*this = temp;
		cout << " add_back( int " << x << " ) оставил объект без изменений !\n ";
		return;
	}
	
	for (int i = 0; i < temp.getsize(); ++i)
		_ptr[i] = temp._ptr[i];
		_ptr[(getsize() - 1)] = x;
}

void IntegerArray::insback(int x)
{	
	insert_N((getsize() - 1), x);
}

void IntegerArray::out_head()
{		
	delete_N(0);
}

void IntegerArray::out_back()
{	
	delete_N((getsize() - 1));
}

ostream& operator<< (ostream& os, const IntegerArray& arr)
{	
	os << "Content of IntegerArray is : ";	
	for (int i = 0; i < arr.getsize(); ++i)
		   os << arr._ptr[i] << " ";
	           os << endl;
	return os;
}

int IntegerArray::search(int name)
{
	for (int i = 0; i < getsize(); ++i)
	{
		
		if (name == _ptr[i])
		     return i;
	}
	
	return -1;
}