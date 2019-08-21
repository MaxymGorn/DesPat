#pragma once
#include <string>
#include <iostream>
#include<Windows.h>
namespace Max_Gorn
{
	using namespace std;

	enum ConsoleColor {
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};
	class Toy
	{
	protected:
		string name;
	public:
		Toy(string name)
		{
			this->name = name;
		}
	};

	__interface IToyFactory
	{
	public:
		virtual Toy * GetBear() = 0;
		virtual Toy * GetCat() = 0;
	};

	class WoodenCat : public Toy
	{
	public:

		WoodenCat() : Toy("Cat1")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Yellow);
			cout << this->name << '\n'<<endl;
		}
	};
	class TeddyCat : public Toy
	{
	public:
		TeddyCat() : Toy("Cat2")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Green);
			cout << this->name << '\n'<<endl;
		}
	};
	class WoodenBear : public Toy
	{
	public:
		WoodenBear() : Toy("Bear1")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Yellow);
			cout << this->name << '\n';
		}
	};
	class TeddyBear : public Toy
	{
	public:
		TeddyBear() : Toy("Bear2")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Green);
			cout << this->name << '\n';
		}
	};


	class TeddyToysFactory :public IToyFactory
	{
	public:
		virtual Toy * GetBear()
		{
			return new TeddyBear();
		}
		virtual Toy * GetCat()
		{
			return new TeddyCat();
		}
	};

	class WoodenToysFactory :public IToyFactory
	{
	public:
		virtual Toy * GetBear()
		{
			return new WoodenBear();
		}
		virtual Toy * GetCat()
		{
			return new WoodenCat();
		}
	};

	void Client(IToyFactory * toyFactory)
	{
		Toy * bear = toyFactory->GetBear();
		Toy * cat = toyFactory->GetCat();
	}
	void Menu()
	{
		setlocale(LC_ALL, "rus");
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 20;
		cfi.dwFontSize.X = 20;
		cfi.dwFontSize.Y = 30;
		cfi.FontFamily = FF_MODERN;
		cfi.FontWeight = FW_BOLD | FW_EXTRALIGHT;
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |Magenta);
		cout << "Перша фабрика:" << endl;
		Client(&WoodenToysFactory());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Magenta);
		cout << "Друга фабрика:" << endl;
		Client(&TeddyToysFactory());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | LightRed);
		system("pause");
	}
}
