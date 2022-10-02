#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum DrinkSize { Large, Xlarge, KingSize };

struct Drink
{
	string name;
	DrinkSize drink_size;
	int drink_price;

	Drink(string n, DrinkSize s, int p) : name(n), drink_size(s), drink_price(p)
	{ }

};

class Machine
{
	vector<Drink> drink_list;
	int cash;

	string l;
	string pass;
public:

	void LogAndPass()
	{
		this->l = "L";
		this->pass = "0";
		cout << "To enter the admin mode, enter your login and password : ";
		cin >> l;
		cin >> pass;
		if (l == "L" && pass == "0")
		{
			cout << "Authorization is successful" << endl;
		}
	}

	Machine()
	{
		drink_list.push_back(Drink("Coffee", DrinkSize::Large, 20));
		drink_list.push_back(Drink("Coffee", DrinkSize::Xlarge, 25));
		drink_list.push_back(Drink("Coffee", DrinkSize::KingSize, 30));

		drink_list.push_back(Drink("Tea", DrinkSize::Large, 18));
		drink_list.push_back(Drink("Tea", DrinkSize::Xlarge, 22));
		drink_list.push_back(Drink("Tea", DrinkSize::KingSize, 28));

		drink_list.push_back(Drink("Cuppucino", DrinkSize::Large, 19));
		drink_list.push_back(Drink("Cuppucino", DrinkSize::Xlarge, 23));
		drink_list.push_back(Drink("Cuppucino", DrinkSize::KingSize, 29));
	}

	void AdminIngridiants()
	{
		string ingridiants;
		int audit;
		cout << "Would you like to add ne ingridiants?(1==Yes, 0==No) : ";
		cin >> audit;
		if (audit == 1)
		{
			cout << "Enter your ingridiants : \n";
			cout << "Tip :: Milk,Sugar,Water, etc.\n";
			cin >> ingridiants;
			cout << "Your ingridiants : " << ingridiants;
		}
		cout << endl;
	}
	
	void Order(string name, DrinkSize size)
	{
		for (auto drink : drink_list)
		{
			if (drink.name == name)
			{
				if (drink.drink_size == size)
				{
					cout << "Price : " << drink.drink_price << endl;
					if (drink.name == "Coffee" && drink.drink_size == DrinkSize::Large)
					{
						cash = cash + 20;
					}
				}
			}
		}
	}

	void Cash()
	{
		int audit;
		cout << "Cash : " << cash << endl;
		cout << "Do you want to withdraw funds?(0==NO, 1==Yes) : ";
		cin >> audit;
		if (audit == 1)
		{
			cout << "Withdrawal of funds... ";
			cash = 0;
			cout << "Cash : " << cash << endl;
		}
		
	}

	void Show() const
	{
		cout << "============================= DRINKS ================================\n";
		for (auto drink : drink_list)
		{
			cout << drink.name << "\t\t";
			if (drink.drink_size == 0)
				cout << "Large" << "\t\t";
			else if (drink.drink_size == 1)
				cout << "Xlarge" << "\t\t";
			else if (drink.drink_size == 2)
				cout << "KingSize" << "\t\t";
			else
				cout << "Incorrect size" << endl;
			cout << drink.drink_price << " grn" << endl;
		}
		cout << "=====================================================================\n";
	}
};

int main()
{
	Machine m1;
	m1.Show();
	m1.Order("Coffee", DrinkSize::Large);
	//m1.LogAndPass();
	m1.AdminIngridiants();
	m1.Cash();
	
}
