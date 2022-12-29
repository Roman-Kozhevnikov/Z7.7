#include "IntegerArray.h"
#include <iostream>
using namespace std;
  // ������� � ���������� _N  - ����������� ���������� � �������� ���������!
// ���� ����� ������� �������� ���������, �� try cach (bad_alloc) �� �������������  � main() ��������� �� ��� ������!
//  ��� ��� ������ � ��������� - ���������, �� ������� � ���������������� �������� cach ��� ������
// ������������� � ������.
 
int main()
{
	setlocale(LC_ALL, "");	
	
	IntegerArray arr(2);	
	cout << arr;
	
	arr.editSize(5);
	cout << arr;
	
	arr.insert_N(2, 6);
	cout << arr;
	
	try
	{
		for (int i = 0; i < arr.getsize(); ++i)
		{
			arr.set_N(i, arr.getsize() - 1 - i);
		}
	}
	catch (out_of_range& e)
	{
		cout << " catch : " << e.what() << endl;
	}

	cout << arr;
	
	int tempsize{ arr.getsize() };
	
	try
	{
		for (int i = 0; i < tempsize; ++i)
		{
			arr.insert_N(i, (i + 1));
		}
	}
	catch (out_of_range& e)
	{
		cout << " catch : " << e.what() << endl;
	}

	cout << arr;
	
	try
	{
		arr.delete_N(0);
	}
	catch (out_of_range& e)
	{
		cout << " catch : " << e.what() << endl;
	}
	
	cout << arr;
	

	tempsize = arr.getsize();
	try
	{
		for (int i = 0; i < tempsize; ++i)
		{
			arr.delete_N(0);
			cout << arr;
		}
	}
	catch (out_of_range& e)
	{
		cout << " catch : " << e.what() << endl;
	}
	
	// arr - ������, ������� �������� ����������
	cout << endl;
	try
	{
		arr.inshead(6);
	}
	catch (out_of_range& e)
	{
		cout << " catch : " << e.what() << endl;
	}
	cout << arr.getsize() << endl;
	cout << arr;

	arr.editSize(4);
	cout << arr;	
	
	arr.inshead(6);
	
	cout << arr;
	cout << arr.getsize() << endl;
	
	arr.insback(6);
	
	cout << arr;
	cout << arr.getsize() << endl;
		
	arr.out_back();
	
	cout << arr;
	cout << arr.getsize() << endl;
	
	arr.out_head();
	
	cout << arr;
	cout << arr.getsize() << endl;

	int s = 6;
	if (arr.search(s) >= 0)
		cout << "�������� " << s << " ��������� � ������� �� �������: " << arr.search(s) << endl;
	else cout << "�������� " << s << " � ������� �� �������!\n ";
	
	arr.add_back(4);	
	
	cout << arr;
	cout << arr.getsize() << endl;

	int temp;
	temp = arr[5];
	cout << "temp = " << temp << endl;
	
	tempsize = arr.getsize();
	try
	{
		for (int i = 0; i < tempsize; ++i)
		{
			arr.delete_N(0);			
		}
	}
	catch (out_of_range& e)
	{
		cout << " catch : " << e.what() << endl;
	}	

	cout << endl;

	//arr.editSize(2);

	if (arr.getsize())	// ��� ������ ��� try c ��������� � ���������� ������ ����� set(), ����� ������� ����� ������ ��������
		arr.inshead(6);
	
	else cout << "������� ������ ! �������� ������ �������! \n";
	
	cout << arr;

	cout << "Done !";

	return 0;

}