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

	Auto(string number = "AA0000AA", int maxSpeed = 360, int curSpeed = 120):number(number), maxSpeed(maxSpeed), curSpeed(curSpeed)
	{}

	string getNumber()const
	{
		return number;
	}

	void setNumber(string num)
	{
		number = num;
	}

	int getMaxSpeed()const
	{
		return maxSpeed;
	}

	void setMaxSpeed(int max)
	{
		maxSpeed = max;
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
		setCurSpeed(getCurSpeed() + 5);
	}

	void downSpeed()
	{
		
		try
		{	
			setCurSpeed(getCurSpeed() - 5);
			cout << "Speed: " << getCurSpeed() << endl;
			if (getCurSpeed() <= 0 || getCurSpeed() > getMaxSpeed())
			{
				throw WrongSpeed();
			}
		}

		catch (WrongSpeed & ex)
		{
			cout << ex.what() << endl;
		}

		
		
	}

	class WrongSpeed : public invalid_argument
	{
	public:
		WrongSpeed(const char* mes = "\nOut of range of speed") : invalid_argument(mes) {}
	};

	class WrongMaxSpeed : public invalid_argument
	{
	public:
		WrongMaxSpeed(const char* mes = "\nOut of range of Max speed") : invalid_argument(mes) {}
	};

	class InvalidNumber : public logic_error
	{
	public:
		InvalidNumber(const char* mes = "\nInvalid number of auto (example:\"AB1234CD\")") : logic_error(mes) {}
	};
};

int main()
{
	Auto a;
	//a.setCurSpeed(20);
	//a.setMaxSpeed(100);
	cout << a.getNumber();
	for(int i = 0; i < 25; ++i)
		a.downSpeed();
	


	cout << endl;
	system("pause");
	return 0;

}

