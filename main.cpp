#include "IntegerArray.h"
#include <iostream>
using namespace std;
  // функции с окончанием _N  - выбрасывают исключения с нулевыми объектами!
// если редко рабтаем большими массивами, то try cach (bad_alloc) из конструкторов  в main() конкретно на эти случаи!
//  Так как сейчас в программе - медленнее, но удобнее и продемонстриваны варианты cach для разных
// конструкторов и членов.
 
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
	
	// arr - пустой, вставка выбросит исключение
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
		cout << "Значение " << s << " находится в массиве по индексу: " << arr.search(s) << endl;
	else cout << "Значение " << s << " в массиве не найдено!\n ";
	
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

	if (arr.getsize())	// для работы без try c вставками и коррекцией данных через set(), можно сделать автом воззвр нулевого
		arr.inshead(6);
	
	else cout << "Нулевой массив ! Измените размер массива! \n";
	
	cout << arr;

	cout << "Done !";

	return 0;

}