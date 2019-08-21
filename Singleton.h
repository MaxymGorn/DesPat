#pragma once
namespace Max_Gorn
{
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
	using namespace std;
	class Singleton
	{
	public:
		static  Singleton*GetObj(int v = 4);
		int GetValue() const;
		void SetValue(int val);
		~Singleton();
	private:
		Singleton(int val=1000);
		int val;
		static Singleton * obj;
		
		
	};
}


Max_Gorn::Singleton::Singleton(int val):val(val)
{
}

Max_Gorn::Singleton::~Singleton()
{
}

inline Singleton * Max_Gorn::Singleton::GetObj(int v)
{
			{
			if (obj == nullptr)
			{
				obj = new Singleton(v);
				
			}
			else
			return obj;
			
		}
}

inline int Max_Gorn::Singleton::GetValue() const
{
	return this->val;
}

inline void Max_Gorn::Singleton::SetValue(int val)
{
	this->val = val;
}


