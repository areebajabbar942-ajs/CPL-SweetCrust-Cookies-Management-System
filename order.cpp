#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct order
{
	int order_ID, cookie_ID, quantity;
	string cust_cnic, status;
	float cookie_price, totalCost;
	int read_OrderID, read_cookieID, read_quantity;
	string read_custCNIC, read_status;
	float read_price, read_TotalCost;
	string gift_box_type;
	float gift_box_cost;
};

bool CheckCookieID(int cookieID)
{
	cookies C;
	ifstream inFile("Cookies.txt");

	if (!inFile)
		return false;

	string line;

	while (getline(inFile, line))
	{
		if (line.empty())
			continue;

		int pos1 = line.find('|');

		C.read_cookieID = stoi(line.substr(0, pos1));

		if (C.read_cookieID == cookieID)
		{
			inFile.close();
			return true;
		}
	}

	inFile.close();
	return false;
}

bool CheckCookieIDInput(int& cookieID)
{
	while (true)
	{
		cin >> cookieID;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input! Enter numbers only: ";
		}
		else if (cookieID <= 0)
		{
			cout << "Cookie ID must be greater than 0: ";
		}
		else
		{
			return true;
		}
	}
}

char CheckYN()
{
	char choice;

	while (true)
	{
		cin >> choice;

		if (choice == 'Y' || choice == 'y' ||
			choice == 'N' || choice == 'n')
		{
			return choice;
		}

		cout << "Invalid choice! Enter Y or N only: ";
	}
}

void write_Bookings(order arr[100], int count)
{
	ofstream outFile("Orders.txt", ios::app);
	if (outFile.is_open())
	{
		for (int i = 0; i < count; i++)
		{
			outFile << arr[i].order_ID << "|"
				<< arr[i].cust_cnic << "|"
				<< arr[i].cookie_ID << "|"
				<< arr[i].quantity << "|"
				<< arr[i].cookie_price << "|"
				<< arr[i].gift_box_type << "|"
				<< arr[i].gift_box_cost << "|"
				<< arr[i].totalCost << "|"
				<< arr[i].status << endl;
		}
		outFile.close();
		cout << "Data entered successfully." << endl;
	}
	else
	{
		cout << "Error file opening for write." << endl;
	}
}

void read_Bookings()
{
	order O;
	ifstream inFile("Orders.txt");

	if (!inFile.is_open())
	{
		cout << "Error opening file." << endl;
		return;
	}

	string line;

	while (getline(inFile, line))
	{
		if (line.empty())
			continue;

		int pos1 = line.find('|');
		int pos2 = line.find('|', pos1 + 1);
		int pos3 = line.find('|', pos2 + 1);
		int pos4 = line.find('|', pos3 + 1);
		int pos5 = line.find('|', pos4 + 1);
		int pos6 = line.find('|', pos5 + 1);
		int pos7 = line.find('|', pos6 + 1);
		int pos8 = line.find('|', pos7 + 1);

		O.read_OrderID = stoi(line.substr(0, pos1));
		O.read_custCNIC = line.substr(pos1 + 1, pos2 - pos1 - 1);
		O.read_cookieID = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
		O.read_quantity = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
		O.read_price = stof(line.substr(pos4 + 1, pos5 - pos4 - 1));

		O.gift_box_type = line.substr(pos5 + 1, pos6 - pos5 - 1);
		O.gift_box_cost = stof(line.substr(pos6 + 1, pos7 - pos6 - 1));

		O.read_TotalCost = stof(line.substr(pos7 + 1, pos8 - pos7 - 1));
		O.read_status = line.substr(pos8 + 1);

		cout << "\n=========================================\n";
		cout << "Order ID       : " << O.read_OrderID << endl;
		cout << "Customer CNIC  : " << O.read_custCNIC << endl;
		cout << "Cookie ID      : " << O.read_cookieID << endl;
		cout << "Quantity       : " << O.read_quantity << endl;
		cout << "Price/Box      : " << O.read_price << " AED" << endl;
		cout << "Gift Box       : " << O.gift_box_type << endl;
		cout << "Gift Charges   : " << O.gift_box_cost << " AED" << endl;
		cout << "Total Cost     : " << O.read_TotalCost << " AED" << endl;
		cout << "Status         : " << O.read_status << endl;
		cout << "=========================================\n";
	}

	inFile.close();
}

bool CheckOrderID(int orderID)
{
	order O;
	ifstream inFile("Orders.txt");

	if (!inFile.is_open())
	{
		return false;
	}

	string line;

	while (getline(inFile, line))
	{
		if (line.empty())
			continue;

		int pos1 = line.find('|');

		O.read_OrderID = stoi(line.substr(0, pos1));

		if (O.read_OrderID == orderID)
		{
			inFile.close();
			return true;
		}
	}

	inFile.close();
	return false;
}

void searchCustomerorder()
{
	string cnic;
	cout << "Enter Customer CNIC to search: ";
	cin >> cnic;

	bool found = false;
	order O;

	ifstream inFile("Orders.txt");

	if (!inFile.is_open())
	{
		cout << "Error opening file." << endl;
		return;
	}

	string line;

	while (getline(inFile, line))
	{
		if (line.empty())
			continue;

		int pos1 = line.find('|');
		int pos2 = line.find('|', pos1 + 1);
		int pos3 = line.find('|', pos2 + 1);
		int pos4 = line.find('|', pos3 + 1);
		int pos5 = line.find('|', pos4 + 1);
		int pos6 = line.find('|', pos5 + 1);
		int pos7 = line.find('|', pos6 + 1);
		int pos8 = line.find('|', pos7 + 1);

		O.read_OrderID = stoi(line.substr(0, pos1));
		O.read_custCNIC = line.substr(pos1 + 1, pos2 - pos1 - 1);
		O.read_cookieID = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
		O.read_quantity = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
		O.read_price = stof(line.substr(pos4 + 1, pos5 - pos4 - 1));

		O.gift_box_type = line.substr(pos5 + 1, pos6 - pos5 - 1);
		O.gift_box_cost = stof(line.substr(pos6 + 1, pos7 - pos6 - 1));

		O.read_TotalCost = stof(line.substr(pos7 + 1, pos8 - pos7 - 1));
		O.read_status = line.substr(pos8 + 1);

		if (O.read_custCNIC == cnic)
		{
			cout << "\t--- ORDER DETAILS ---\n";
			found = true;

			cout << "\n=========================================\n";
			cout << "Order ID       : " << O.read_OrderID << endl;
			cout << "Customer CNIC  : " << O.read_custCNIC << endl;
			cout << "Cookie Name    : " << GetCookieName(O.read_cookieID) << endl;
			cout << "Cookie ID      : " << O.read_cookieID << endl;
			cout << "Quantity       : " << O.read_quantity << endl;
			cout << "Price Per Box  : " << O.read_price << " AED" << endl;
			cout << "Gift Box       : " << O.gift_box_type << endl;
			cout << "Gift Charges   : " << O.gift_box_cost << " AED" << endl;
			cout << "Total Cost     : " << O.read_TotalCost << " AED" << endl;
			cout << "Status         : " << O.read_status << endl;
			cout << "=========================================\n";
		}
	}

	inFile.close();

	if (!found)
	{
		cout << "No order found for this customer." << endl;
	}
}

bool CheckQuantity(int quantity)
{
	if (quantity >= 1 && quantity <= 5)
	{
		return true;
	}

	cout << "Invalid quantity! You can order only 1 to 5 cookie boxes." << endl;
	return false;
}

void customize_gift_box(order& O)
{
	char choice;

	cout << "Do you want to customize a gift box? (Y/N): ";
	choice = CheckYN();

	if (choice == 'Y' || choice == 'y')
	{
		int theme, size;

		cout << "\n========== Gift Box Themes ==========" << endl;
		cout << "1. Birthday Theme" << endl;
		cout << "2. Anniversary Theme" << endl;
		cout << "3. Baby Shower Theme" << endl;
		cout << "4. Eid Special Theme" << endl;
		cout << "5. Christmas Theme" << endl;

		cout << "\nSelect Theme: ";
		cin >> theme;

		switch (theme)
		{
		case 1:
			O.gift_box_type = "Birthday Theme";
			break;

		case 2:
			O.gift_box_type = "Anniversary Theme";
			break;

		case 3:
			O.gift_box_type = "Baby Shower Theme";
			break;

		case 4:
			O.gift_box_type = "Eid Special Theme";
			break;

		case 5:
			O.gift_box_type = "Christmas Theme";
			break;

		default:
			cout << "Invalid Theme! Standard Theme Selected." << endl;
			O.gift_box_type = "Standard Theme";
		}

		cout << "\n========== Box Size ==========" << endl;
		cout << "1. Small (2 AED per box)" << endl;
		cout << "2. Medium (5 AED per box)" << endl;
		cout << "3. Large (8 AED per box)" << endl;

		cout << "Select Box Size: ";
		cin >> size;

		switch (size)
		{
		case 1:
			O.gift_box_cost = 2 * O.quantity;
			break;

		case 2:
			O.gift_box_cost = 5 * O.quantity;
			break;

		case 3:
			O.gift_box_cost = 8 * O.quantity;
			break;

		default:
			cout << "Invalid Size!" << endl;
			O.gift_box_cost = 0;
		}

		O.totalCost += O.gift_box_cost;

		cout << "\nGift Box Theme : " << O.gift_box_type << endl;
		cout << "Gift Box Charges : " << O.gift_box_cost << " AED" << endl;
		cout << "Grand Total Bill : " << O.totalCost << " AED" << endl;
	}
	else
	{
		O.gift_box_type = "No Gift Box";
		O.gift_box_cost = 0;

		cout << "\nNo Gift Box Selected." << endl;
		cout << "Grand Total Bill : " << O.totalCost << " AED" << endl;
	}
}

bool CheckOrderIDInput(int& orderID)
{
	while (true)
	{
		cin >> orderID;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input! Enter numbers only: ";
		}
		else if (orderID <= 0)
		{
			cout << "Order ID must be greater than 0: ";
		}
		else
		{
			return true;
		}
	}
}

void BookOrder()
{
	order Order[100];
	int totalOrders = 0;

	char add = 'Y';


	cout << "\n=========== BOOK ORDER ===========\n";

	cout << "Enter Customer CNIC: ";
	cin >> Order[0].cust_cnic;

	if (!CheckCustomer(Order[0].cust_cnic))
	{
		cout << "Customer not registered.\n";
		return;
	}

	cout << "Enter Order ID: ";
	CheckOrderIDInput(Order[0].order_ID);

	while (CheckOrderID(Order[0].order_ID))
	{
		cout << "Order ID already exists. Enter another ID: ";
		CheckOrderIDInput(Order[0].order_ID);
	}

	if (CheckOrderID(Order[0].order_ID))
	{
		cout << "Order ID already exists.\n";
		return;
	}

	while (add == 'Y' || add == 'y')
	{

		Order[totalOrders].cust_cnic = Order[0].cust_cnic;
		Order[totalOrders].order_ID = Order[0].order_ID;

		cout << "\n========== COOKIE MENU ==========\n";
		read_Cookies();

		do
		{
			cout << "\nEnter Cookie ID: ";
			CheckCookieIDInput(Order[totalOrders].cookie_ID);

			if (!CheckCookieID(Order[totalOrders].cookie_ID))
			{
				cout << "Cookie ID does not exist. Please enter a valid Cookie ID.\n";
			}

		} while (!CheckCookieID(Order[totalOrders].cookie_ID));

		Order[totalOrders].cookie_price =
			GetCookiePrice(Order[totalOrders].cookie_ID);

		cout << "Each box contains 6 cookies.\n";

		cout << "Enter Quantity (Max 5): ";
		cin >> Order[totalOrders].quantity;

		if (!CheckQuantity(Order[totalOrders].quantity))
			continue;

		if (!CheckStock(Order[totalOrders].cookie_ID,
			Order[totalOrders].quantity))
		{
			cout << "Insufficient Stock.\n";
			continue;
		}

		Order[totalOrders].totalCost =
			Order[totalOrders].cookie_price *
			Order[totalOrders].quantity;

		customize_gift_box(Order[totalOrders]);

		Order[totalOrders].status = "Booked";

		Stockupdate(Order[totalOrders].cookie_ID,
			Order[totalOrders].quantity,
			false);

		totalOrders++;

		cout << "Do you want to add another cookie? (Y/N): ";
		add = CheckYN();
	}

	// Receipt
	cout << "\n";
	cout << "=========================================================\n";
	cout << "            SWEETCRUST COOKIES ORDER RECEIPT\n";
	cout << "=========================================================\n";

	cout << "Customer CNIC : " << Order[0].cust_cnic << endl;
	cout << "Order ID      : " << Order[0].order_ID << endl;

	float grandTotal = 0;

	for (int i = 0; i < totalOrders; i++)
	{
		cout << "\n---------------------------------------------\n";
		cout << "Cookie Name   : "
			<< GetCookieName(Order[i].cookie_ID) << endl;
		cout << "Boxes         : "
			<< Order[i].quantity << endl;
		cout << "Price/Box     : "
			<< Order[i].cookie_price << " AED" << endl;
		cout << "Gift Box      : "
			<< Order[i].gift_box_type << endl;
		cout << "Gift Charges  : "
			<< Order[i].gift_box_cost << " AED" << endl;
		cout << "Item Total    : "
			<< Order[i].totalCost << " AED" << endl;

		grandTotal += Order[i].totalCost;
	}

	cout << "\n=========================================================\n";
	cout << "Grand Total : " << grandTotal << " AED" << endl;
	cout << "Status      : Booked" << endl;
	cout << "=========================================================\n";
	cout << "Thank You For Shopping With SweetCrust!\n";

	write_Bookings(Order, totalOrders);
}

void CancelOrder()
{
	cout << "\t--- CANCEL ORDER ---\n";
	string cnic;
	int order_id;

	cout << "Enter CNIC to cancel customer's order: ";
	cin >> cnic;

	cout << "Enter Order ID: ";
	cin >> order_id;

	ifstream inFile("Orders.txt");

	if (!inFile)
	{
		cout << "Error opening file.\n";
		return;
	}

	// Count total orders
	string line;
	int count = 0;

	while (getline(inFile, line))
	{
		if (!line.empty())
			count++;
	}

	inFile.close();

	// Dynamic Array
	order* arr = new order[count];

	inFile.open("Orders.txt");

	int i = 0;

	while (getline(inFile, line))
	{
		int pos1 = line.find('|');
		int pos2 = line.find('|', pos1 + 1);
		int pos3 = line.find('|', pos2 + 1);
		int pos4 = line.find('|', pos3 + 1);
		int pos5 = line.find('|', pos4 + 1);
		int pos6 = line.find('|', pos5 + 1);
		int pos7 = line.find('|', pos6 + 1);
		int pos8 = line.find('|', pos7 + 1);

		arr[i].read_OrderID = stoi(line.substr(0, pos1));
		arr[i].read_custCNIC = line.substr(pos1 + 1, pos2 - pos1 - 1);
		arr[i].read_cookieID = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
		arr[i].read_quantity = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
		arr[i].read_price = stof(line.substr(pos4 + 1, pos5 - pos4 - 1));

		arr[i].gift_box_type = line.substr(pos5 + 1, pos6 - pos5 - 1);
		arr[i].gift_box_cost = stof(line.substr(pos6 + 1, pos7 - pos6 - 1));

		arr[i].read_TotalCost = stof(line.substr(pos7 + 1, pos8 - pos7 - 1));
		arr[i].read_status = line.substr(pos8 + 1);


		i++;
	}

	inFile.close();

	// Search & Update
	bool found = false;
	float totalFine = 0;

	// Search & Update
	for (int i = 0; i < count; i++)
	{
		if (arr[i].read_custCNIC == cnic &&
			arr[i].read_OrderID == order_id &&
			arr[i].read_status != "Cancelled")
		{
			found = true;

			arr[i].read_status = "Cancelled";

			totalFine += arr[i].read_quantity * 5;

			Stockupdate(arr[i].read_cookieID,
				arr[i].read_quantity,
				true);
		}
	}

	if (!found)
	{
		cout << "Order not found.\n";
		delete[] arr;
		return;
	}

	cout << "Total Cancellation Fine = "
		<< totalFine << " AED" << endl;

	if (!found)
	{
		cout << "Order not found.\n";
		delete[] arr;
		return;
	}

	// Rewrite file
	ofstream outFile("Orders.txt");

	for (int i = 0; i < count; i++)
	{
		outFile << arr[i].read_OrderID << "|"
			<< arr[i].read_custCNIC << "|"
			<< arr[i].read_cookieID << "|"
			<< arr[i].read_quantity << "|"
			<< arr[i].read_price << "|"
			<< arr[i].gift_box_type << "|"
			<< arr[i].gift_box_cost << "|"
			<< arr[i].read_TotalCost << "|"
			<< arr[i].read_status << endl;
	}

	outFile.close();

	delete[] arr;

	cout << "Order cancelled successfully.\n";
}

bool CheckPrice(float& price)
{
	while (true)
	{
		cin >> price;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input! Enter numbers only: ";
		}
		else if (price <= 0)
		{
			cout << "Price must be greater than 0: ";
		}
		else
		{
			return true;
		}
	}
}