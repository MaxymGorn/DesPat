#pragma once
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
	class Coca_Cola
	{
	public:
		virtual void info() = 0;
		virtual ~Coca_Cola() {}
		

	};

	class Pepsi_Cola
	{
	public:
		virtual void info() = 0;
		virtual ~Pepsi_Cola() {}

	
	};




	class Coca_Cola1 : public Coca_Cola
	{
	public:
		void info() override
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | LightGreen);
			cout << "ѕл€шки Coca_Cola" << endl;
		}
	};

	class Pepsi_Cola1 : public Pepsi_Cola
	{
	public:
		void info() override
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | LightMagenta);
			cout << "ѕл€шки Pepsi_Cola" << endl;
		}
	};





	class Coca_Cola2 : public Coca_Cola
	{
	public:
		void info() override
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | LightGreen);
			cout << "—олодка вода Coca_Cola" << endl;
		}
	};

	class Pepsi_Cola2 : public Pepsi_Cola
	{
	public:
		void info() override
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | LightMagenta);
			cout << "—олодка вода Pepsi_Cola" << endl;
		}
	};





	class Factory_Water_and_botle
	{
	public:
		virtual Coca_Cola* createCoca_Cola() = 0;
		virtual Pepsi_Cola* createPepsi_Cola() = 0;
		virtual ~Factory_Water_and_botle() {}

		virtual void setValue(int val)=0;
		virtual int outputVal()=0;
	
	};



	class BotleFactory : public Factory_Water_and_botle
	{
	public:
		Coca_Cola* createCoca_Cola() override
		{
			return new Coca_Cola1;
		}
		Pepsi_Cola* createPepsi_Cola()	override
		{
			return new Pepsi_Cola1;
		}
		static BotleFactory *GetVal()
		{
			if (val == nullptr)
				val = new BotleFactory();
			return val;
		}
		int id;
		void setValue(int val)
		{
			id = val;
		}
		int outputVal()
		{
			return id;
		 }
	private:
		static BotleFactory* val;
		BotleFactory(const BotleFactory& obj) = delete;
		BotleFactory& operator=(const BotleFactory& obj) = delete;
		BotleFactory& operator=(const BotleFactory&& obj) = delete;
		BotleFactory()
		{

		}
		~BotleFactory()
		{

		}
	};



	class WaterFactory : public Factory_Water_and_botle
	{
	public:
		Coca_Cola* createCoca_Cola() override
		{
			return new Coca_Cola2;
		}
		Pepsi_Cola* createPepsi_Cola() override
		{
			return new Pepsi_Cola2;
		}
		static WaterFactory *GetVal()
		{
			if (val == nullptr)
				val = new WaterFactory();
			return val;
		}
		int id;
		void setValue(int val)
		{
			id = val;
		}
		int outputVal()
		{
			return id;
		 }
	
	private:
		static WaterFactory* val;
		WaterFactory(const WaterFactory& obj) = delete;
		WaterFactory& operator=(const WaterFactory& obj) = delete;
		WaterFactory& operator=(const WaterFactory&& obj) = delete;
		WaterFactory()
		{

		}
		~WaterFactory()
		{

		}

	};



	class ABSFABR
	{
	public:
	
		ABSFABR()
		{

		}
		void info() {
			int i;

			for (i = 0; i < Coca.size(); ++i)
			{
				Coca[i]->info();

			}
			for (i = 0; i < Pepsi.size(); ++i)
			{
				Pepsi[i]->info();
			}
		}
	
		vector<Coca_Cola*> Coca;
		vector<Pepsi_Cola*> Pepsi;
	private:

	
		~ABSFABR() {

			for (int i = 0; i < Coca.size(); ++i)
			{
				delete Coca[i];

			}
			for (int i = 0; i < Pepsi.size(); ++i)
			{
				delete Pepsi[i];
			}

		}
	};



	class Client
	{
	public:
		ABSFABR* createFabr(Factory_Water_and_botle& factory, int kilkist = 1) {
			ABSFABR* fabr = new ABSFABR;
			for (size_t i = 0; i < kilkist; i++)
			{
				fabr->Coca.push_back(factory.createCoca_Cola());
				fabr->Pepsi.push_back(factory.createPepsi_Cola());
			}

			return fabr;
		}
	};

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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Yellow);
		
		int num;
		cout << "¬ведiть кiлькiсть продуктiв: " << "\t";
		while (true)
		{

			while (!(cin >> num))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Red);
				cout << "Error  enter!\n";
				cin.clear();
				cin.ignore();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Blue);
				cout << "¬ведiть кiлькiсть продуктiв: " << "\t";
			}

			if (num >= 1)
			{
				break;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Blue);
				cout << "Error кiлькiсть продуктiв<=1!\n";
				cout << "¬ведiть кiлькiсть продуктiв: " << "\t";
			}
		}

		Client cl;
		BotleFactory *botle_factory = BotleFactory::GetVal();
		botle_factory->setValue(100);
		WaterFactory *water_factory = WaterFactory::GetVal();
		water_factory->setValue(999);
		ABSFABR * bo = cl.createFabr(*botle_factory, num);
		ABSFABR * wa = cl.createFabr(*water_factory, num);
		cout << "‘абрика пл€шок:" << endl << endl;
		bo->info();
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Yellow);
		cout << "\n‘абрика солодкоњ води:" << endl << endl;;
		wa->info();
		cout << "¬ведiть кiлькiсть продуктiв: " << "\t";
		while (true)
		{

			while (!(cin >> num))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Red);
				cout << "Error  enter!\n";
				cin.clear();
				cin.ignore();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Blue);
				cout << "¬ведiть кiлькiсть продуктiв: " << "\t";
			}

			if (num >= 1)
			{
				break;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Blue);
				cout << "Error кiлькiсть продуктiв<=1!\n";
				cout << "¬ведiть кiлькiсть продуктiв: " << "\t";
			}
		}
		Client cl2;
		BotleFactory *botle_factory2 = BotleFactory::GetVal();
		WaterFactory *water_factory2 = WaterFactory::GetVal();
		ABSFABR * bo2 = cl2.createFabr(*botle_factory2, num);
		ABSFABR * wa2 = cl2.createFabr(*water_factory2, num);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Yellow);
		cout << "\n‘абрика пл€шок:" << endl << endl;
		bo2->info();
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Yellow);
		cout << "\n‘абрика солодкоњ води:" << endl << endl;;
		wa2->info();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | Cyan);
		cout << "\nbotle_factory (адрес): " << botle_factory << endl;
		cout << "botle_factory2 (адрес): " << botle_factory2 << endl;
		cout << "botle_factory2 (значенн€): " << botle_factory2->outputVal() << endl;
		cout << "botle_factory (значенн€): " << botle_factory->outputVal() << endl;
		botle_factory2->setValue(7777);
		cout << "botle_factory2 (значенн€): " << botle_factory2->outputVal() << endl;
		cout << "botle_factory (значенн€): " << botle_factory->outputVal() << endl;

		cout << "\nwater_factory (адрес): " << water_factory << endl;
		cout << "water_factory2 (адрес): " << water_factory2 << endl;
		cout << "water_factory2 (значенн€): " << water_factory2->outputVal() << endl;
		cout << "water_factory (значенн€): " << water_factory->outputVal() << endl;
		water_factory->setValue(1111);
		cout << "water_factory2 (значенн€): " << water_factory2->outputVal() << endl;
		cout << "water_factory (значенн€): " << water_factory->outputVal() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | LightRed);
	}
}
