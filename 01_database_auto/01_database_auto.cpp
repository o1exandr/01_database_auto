/*
Завдання 1.
Створити  Auto  з полями:
номер авто( у форматі AB1234CD)
максимальна швидкість авто
поточна швидкість авто
Створити методи у класі Авто
методи доступу до полів(getters, setters)
метод збільшення швидкості( по замовчуванню на 5)
метод зменшення швидкості( по замовчуванню на 5)
Створити у класі авто власні класи виключень WrongSpeed, WrongMaxSpeed   та InvalidNumber, які інкапсулюють у собі невірне дане та повідомлення про помилку.

o	Клас Auto повинен викидати виключення типу WrongMaxSpeed при встановленні максимальної швидкості більше 360
o	Клас Auto повинен викидати виключення типу WrongSpeed при встановленні  чи досягненні швидкості, яка перевищує максимальну
o	Клас повинен викидати виключення типу InvalidNumber при встановленні невірного номера авто
Створити програму для перевірки роботи виключних ситуацій класу Авто.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>

using namespace std;

class Auto
{
private:
	string number;
	int maxSpeed;
	int curSpeed;

public:

	Auto(string number = "AA0000AA", int maxSpeed = 360, int curSpeed = 0):number(number), maxSpeed(maxSpeed), curSpeed(curSpeed)
	{}

	string getNumber()const
	{
		return number;
	}

	void setNumber(string num)
	{
		try
		{
			if (num.length() != 8)
				throw InvalidNumber();
			else
				if (isupper(num[0]) && isupper(num[1]) && isdigit(num[2]) && isdigit(num[3]) &&
					isdigit(num[4]) && isdigit(num[5]) && isupper(num[6]) && isupper(num[7]));
				else
					throw InvalidNumber();
			number = num;
		}

		catch (InvalidNumber & ex)
		{
			cout << ex.what() << num << " (right example:\"AB1234CD\")";
		}

		
	}

	int getMaxSpeed()const
	{
		return maxSpeed;
	}

	void setMaxSpeed(int max)
	{
		
		try
		{
			if (max > 360)
				throw WrongMaxSpeed();
			maxSpeed = max;
		}

		catch (WrongMaxSpeed & ex)
		{
			cout << ex.what() << "(your value : " << max << ")";
		}
	}

	int getCurSpeed()const
	{
		return curSpeed;
	}

	void setCurSpeed(int cur)
	{
		curSpeed = cur;
	}

	void upSpeed()
	{
		try
		{
			if (getCurSpeed() + 5 > getMaxSpeed())
				throw WrongSpeed();
			setCurSpeed(getCurSpeed() + 5);
			cout << "\nSpeed: " << getCurSpeed();
		}

		catch (WrongSpeed & ex)
		{
			cout << ex.what() << "Max value for this auto: " << getMaxSpeed() << " (your value : " << getCurSpeed() + 5 << ")";
		}
	}

	void downSpeed()
	{
		
		try
		{	
			if (getCurSpeed() - 5 < 0)
				throw WrongSpeed();
			setCurSpeed(getCurSpeed() - 5);
			cout << "\nSpeed: " << getCurSpeed();
		}

		catch (WrongSpeed & ex)
		{
			cout << ex.what() << "Min value for this auto: 0 (your value: " << getCurSpeed() - 5 << ")";
		}
		
	}

	void print()
	{
		cout << "\n\nNumber auto:\t" << getNumber() << endl;
		cout << "MaxSpeed:\t" << getMaxSpeed() << endl;
		cout << "Current speed:\t" << getCurSpeed() << endl;
	}

	class WrongSpeed : public invalid_argument
	{
	public:
		WrongSpeed(const char* mes = "\nOut of range of speed. ") : invalid_argument(mes) {}
	};

	class WrongMaxSpeed : public invalid_argument
	{
	public:
		WrongMaxSpeed(const char* mes = "\nOut of range set Max speed. Maximum value: 360 ") : invalid_argument(mes) {}
	};

	class InvalidNumber : public logic_error
	{
	public:
		InvalidNumber(const char* mes = "\nInvalid number of auto: ") : logic_error(mes) {}
	};
};

int main()
{
	Auto a;
	a.print(); // авто по замовчуваню

	cout << "\n\n\t= Wrong number =";
	a.setNumber("AB6789CD"); //ок
	a.setNumber("ABCD1234"); //невірний номер, видає помилку 
	a.setNumber("A-6789CD"); //невірний номер, видає помилку 
	a.setNumber("ABC789Def"); //невірний номер, видає помилку 

	cout << "\n\n\t= Wrong Max speed =";
	a.setMaxSpeed(360); // максимальна 360 встановлюється
	a.setMaxSpeed(361); // при цьому значенні видасть помилку

	cout << "\n\n\t= Wrong current speed =";
	a.setMaxSpeed(300); //ставновлюємо максимальну швидкість - ок
	a.setCurSpeed(296); // ставимо поточну швидкість передмаксимальну
	a.upSpeed(); // і отримуємо помилку при збільшені швидкості, тому що перевищуємо максимально допустиму для цього авто

	a.setCurSpeed(24);
	for(int i = 0; i < 5; ++i)
		a.downSpeed(); // на останній ітерації помилка - відємне значення швидкості

	a.print(); //авто з параметрами, які були встановленні, до виключних ситуацій
	
	


	cout << endl;
	system("pause");
	return 0;

}

