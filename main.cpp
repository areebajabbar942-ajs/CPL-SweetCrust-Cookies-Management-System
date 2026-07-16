#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool CheckChoice(int& choice)
{
	while (true)
	{
		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input! Enter numbers only (1-8): ";
		}
		else if (choice < 1 || choice > 8)
		{
			cout << "Invalid Choice! Enter a number between 1 and 8: ";
		}
		else
		{
			return true;
		}
	}
}
int main()
{
	cookies Cookie[4];
	int choice;
	cout << "\t\t+================================================+\n";
	cout << "\t\t|       SWEETCRUST COOKIE MANAGEMENT SYSTEM      |\n";
	cout << "\t\t+================================================+\n";
	do
	{
		cout << "\n\t--- PROGRAM MENU ---\n";
		cout << "1. Cookie add" << endl;
		cout << "2. Register Customer" << endl;
		cout << "3. View Customers" << endl;
		cout << "4. Book Orders" << endl;
		cout << "5. Search Customer Orders" << endl;
		cout << "6. Cancel Order" << endl;
		cout << "7. View Cookie Catalog" << endl;
		cout << "8. Exit\nChoice: ";
		CheckChoice(choice);

		if (choice == 1)
		{
			cout << "\t--- ADDING COOKIES ---\n";
			for (int i = 0; i < 4; i++) {
				cout << "Enter Cookie ID: ";
				CheckCookieIDInput(Cookie[i].cookie_ID);

				while (CheckCookieID(Cookie[i].cookie_ID))
				{
					cout << "Cookie ID already exists. Enter another ID: ";
					CheckCookieIDInput(Cookie[i].cookie_ID);
				}
				cin.ignore();
				do
				{
					cout << "Enter cookie name: ";
					getline(cin, Cookie[i].cookie_name);

				} while (!CheckName(Cookie[i].cookie_name));
				cout << "Enter price per box: ";
				CheckPrice(Cookie[i].price);
				cout << "Enter stock quantity: ";
				CheckStock(Cookie[i].stock);
				cout << "--------------------------------\n";
			}
			write_cookies(Cookie);
		}
		else if (choice == 2)
		{
			Cus_registration();
		}
		else if (choice == 3)
		{
			read_customers();
		}

		else if (choice == 4)
		{
			BookOrder();
		}

		else if (choice == 5)
		{
			searchCustomerorder();
		}
		else if (choice == 6)
		{
			CancelOrder();
		}
		else if (choice == 7)
		{
			cout << "\t--- COOKIES CATALOG ---\n";
			read_Cookies();
		}
		else if (choice == 8)
		{
			cout << "Exiting..." << endl;
		}
		else
		{
			cout << "Invalid choice!" << endl;
		}
	} while (choice != 8);

	return 0;
}