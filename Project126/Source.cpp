#include<iostream>
#include<string>
#include<Windows.h>
#include <vector>
#include"AbsFabrika.h"
using namespace Max_Gorn;
BotleFactory * BotleFactory::val = nullptr;
WaterFactory * WaterFactory::val = nullptr;
int main()
{
	Menu();
	system("pause");
}
