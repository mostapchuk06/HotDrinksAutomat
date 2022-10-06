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

	Drink(string nam, DrinkSize s, int p) : name(nam), drink_size(s), drink_price(p)
	{ }

};

struct Ingridiants
{
	string name;
	int number;

	Ingridiants(string nam, int num) : name(nam), number(num)
	{ }
};

class Machine
{
private:
	vector<Drink> drink_list;

	vector<Ingridiants> ingridiants_list;
	string i;
	int n;
	int cl, cxl, cks;
	int tl, txl, tks;
	int cuppl, cuppxl, cuppks;

	string standart_l;
	string standart_pass;
	
	int cash;
public:

	void LogAndPass()
	{
		int audit;
		cout << "Would you like to sign in admin mode(0==NO, 1==Yes) : ";
		cin >> audit;
		cout << endl;
		if (audit == 1)
		{
			standart_l = "L";
			standart_pass = "0";
			cout << "To enter the admin mode, enter your login and password : ";
			cin >> standart_l;
			cin >> standart_pass;
			if (standart_l == "L" && standart_pass == "0")
			{
				cout << "Authorization is successful" << endl;
			}
		}
		else
		{
			cout << "...Incorrect.data..." << endl;
		}
	}

	Machine()
	{
		cout << "Enter price for you drinks : ";
		cin >> cl;
		cin >> cxl;
		cin >> cks;
		cin >> tl;
		cin >> txl;
		cin >> tks;
		cin >> cuppl;
		cin >> cuppxl;
		cin >> cuppks;
		drink_list.push_back(Drink("Coffee", DrinkSize::Large, cl));
		drink_list.push_back(Drink("Coffee", DrinkSize::Xlarge, cxl));
		drink_list.push_back(Drink("Coffee", DrinkSize::KingSize, cks));

		drink_list.push_back(Drink("Tea", DrinkSize::Large, tl));
		drink_list.push_back(Drink("Tea", DrinkSize::Xlarge, txl));
		drink_list.push_back(Drink("Tea", DrinkSize::KingSize, tks));

		drink_list.push_back(Drink("Cuppucino", DrinkSize::Large, cuppl));
		drink_list.push_back(Drink("Cuppucino", DrinkSize::Xlarge, cuppxl));
		drink_list.push_back(Drink("Cuppucino", DrinkSize::KingSize, cuppks));
	}

	void AdminIngridiants()
	{
		cout << "Add your ingridiants and ingridiants number : " << endl;
		cout << "Tip :: Milk,Sugar,Water, etc.\n";
		cin >> i;
		cin >> n;
		ingridiants_list.push_back(Ingridiants(i, n));
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

	void IngShow() const
	{
		cout << "============================ INGRIDIANTS ================================\n";
		for (auto ingridiants : ingridiants_list)
		{
			cout << ingridiants.name << " " << ingridiants.number << " g ";
		}
		cout << "=========================================================================\n\n";
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
	bool a = 1;
	Machine m1;
	m1.Show();
	m1.Order("Coffee", DrinkSize::Large);
	m1.LogAndPass();
	do
	{
		m1.AdminIngridiants();
		cout << "Have you downloaded all the required ingredients?\n";
		cout << "Enter 0 if so or 1 if not so : ";
		cin >> a;
	} while (!a == 0);
	m1.IngShow();
	m1.Cash();

}
