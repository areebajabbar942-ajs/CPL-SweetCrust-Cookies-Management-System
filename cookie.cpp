#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct cookies
{
	int cookie_ID;
	string cookie_name;
	float price;
	int stock;
	int read_cookieID, read_stock;
	string read_cookie_name;
	float read_price;
};

string GetCookieName(int cookieID)
{
	cookies C;
	ifstream inFile("Cookies.txt");
	string line;

	while (getline(inFile, line))
	{
		if (line.empty()) continue;

		int pos1 = line.find('|');
		int pos2 = line.find('|', pos1 + 1);

		C.read_cookieID = stoi(line.substr(0, pos1));
		C.read_cookie_name = line.substr(pos1 + 1, pos2 - pos1 - 1);

		if (C.read_cookieID == cookieID)
		{
			inFile.close();
			return C.read_cookie_name;
		}
	}

	inFile.close();
	return "Unknown";
}

void write_cookies(cookies arr[4])
{
	ofstream outFile("Cookies.txt", ios::out);
	if (outFile.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			outFile << arr[i].cookie_ID << "|" << arr[i].cookie_name << "|" << arr[i].price << "|" << arr[i].stock << endl;
		}
		outFile.close();
		cout << "Data added successfully." << endl;
	}
	else
	{
		cout << "Error opening file for write." << endl;
	}
}

void read_Cookies()
{
	cookies Co;
	ifstream inFile("Cookies.txt", ios::in);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			string line;
			getline(inFile, line);
			if (line.empty()) continue;

			int pos1 = line.find('|');
			int pos2 = line.find('|', pos1 + 1);
			int pos3 = line.find('|', pos2 + 1);

			Co.read_cookieID = stoi(line.substr(0, pos1));
			Co.read_cookie_name = line.substr(pos1 + 1, (pos2 - pos1) - 1);
			Co.read_price = stof(line.substr(pos2 + 1, (pos3 - pos2) - 1));
			Co.read_stock = stoi(line.substr(pos3 + 1));

			cout << "Cookie ID: " << Co.read_cookieID << " Cookie name: " << Co.read_cookie_name << " price: " << Co.read_price << " stock: " << Co.read_stock << endl;
			cout << "-----------------------------------------------------------\n\n";
		}
		inFile.close();
	}
	else
	{
		cout << "Error opening file for read." << endl;
	}
}

float GetCookiePrice(int cookieID)
{
	cookies C;
	ifstream inFile("Cookies.txt");

	if (!inFile.is_open())
	{
		cout << "Error opening Cookies file." << endl;
		return -1;
	}

	string line;

	while (getline(inFile, line))
	{
		if (line.empty())
			continue;

		int pos1 = line.find('|');
		int pos2 = line.find('|', pos1 + 1);
		int pos3 = line.find('|', pos2 + 1);

		C.read_cookieID = stoi(line.substr(0, pos1));
		C.read_cookie_name = line.substr(pos1 + 1, pos2 - pos1 - 1);
		C.read_price = stof(line.substr(pos2 + 1, pos3 - pos2 - 1));
		C.read_stock = stoi(line.substr(pos3 + 1));

		if (C.read_cookieID == cookieID)
		{
			inFile.close();
			return C.read_price;
		}
	}

	inFile.close();

	return -1;   // Cookie not found
}

bool CheckStock(int cookieID, int quantity)
{
	cookies Co;
	ifstream inFile("Cookies.txt");

	if (!inFile.is_open())
	{
		cout << "Error opening Cookies file." << endl;
		return false;
	}

	string line;

	while (getline(inFile, line))
	{
		if (line.empty()) continue;

		int pos1 = line.find('|');
		int pos2 = line.find('|', pos1 + 1);
		int pos3 = line.find('|', pos2 + 1);

		Co.read_cookieID = stoi(line.substr(0, pos1));
		Co.read_cookie_name = line.substr(pos1 + 1, pos2 - pos1 - 1);
		Co.read_price = stof(line.substr(pos2 + 1, pos3 - pos2 - 1));
		Co.read_stock = stoi(line.substr(pos3 + 1));

		if (Co.read_cookieID == cookieID)
		{
			if (Co.read_stock >= quantity)
			{
				inFile.close();
				return true;
			}
			else
			{
				cout << "Only " << Co.read_stock << " boxes are available." << endl;
				inFile.close();
				return false;
			}
		}
	}

	inFile.close();
	cout << "Cookie ID not found." << endl;
	return false;
}

void Stockupdate(int cookieID, int quantity, bool addStock)
{
	ifstream inFile("Cookies.txt");

	if (!inFile)
	{
		cout << "File not found.\n";
		return;
	}

	string line;
	int count = 0;

	while (getline(inFile, line))
	{
		if (!line.empty())
			count++;
	}

	inFile.close();

	cookies* arr = new cookies[count];

	inFile.open("Cookies.txt");

	int i = 0;

	while (getline(inFile, line))
	{
		if (line.empty())
			continue;

		int pos1 = line.find('|');
		int pos2 = line.find('|', pos1 + 1);
		int pos3 = line.find('|', pos2 + 1);

		arr[i].cookie_ID = stoi(line.substr(0, pos1));
		arr[i].cookie_name = line.substr(pos1 + 1, pos2 - pos1 - 1);
		arr[i].price = stof(line.substr(pos2 + 1, pos3 - pos2 - 1));
		arr[i].stock = stoi(line.substr(pos3 + 1));

		i++;
	}

	inFile.close();

	for (int i = 0; i < count; i++)
	{
		if (arr[i].cookie_ID == cookieID)
		{
			if (addStock)
				arr[i].stock += quantity;
			else
				arr[i].stock -= quantity;

			break;
		}
	}

	ofstream outFile("Cookies.txt");

	for (int i = 0; i < count; i++)
	{
		outFile << arr[i].cookie_ID << "|"
			<< arr[i].cookie_name << "|"
			<< arr[i].price << "|"
			<< arr[i].stock << endl;
	}

	outFile.close();

	delete[] arr;

	cout << "Stock updated successfully.\n";
}
