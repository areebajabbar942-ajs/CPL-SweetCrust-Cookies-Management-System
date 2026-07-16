#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct customers
{
	string contact;
	string cus_name, cnic;
	string readname, read_cnic;
	string read_contact;
};

bool CheckCNIC(string cnic)
{
	customers C;
	ifstream inFile("customers.txt");

	if (!inFile)
		return false;

	string line;

	while (getline(inFile, line))
	{
		if (line.empty()) continue;

		int pos1 = line.find('|');
		int pos2 = line.find('|', pos1 + 1);

		C.read_cnic = line.substr(pos1 + 1, pos2 - pos1 - 1);

		if (C.read_cnic == cnic)
		{
			inFile.close();
			return true;      // CNIC already exists
		}
	}

	inFile.close();
	return false;             // CNIC not found
}

bool CheckName(string name)
{
	if (name == "")
	{
		cout << "Name cannot be empty." << endl;
		return false;
	}

	for (int i = 0; i < name.length(); i++)
	{
		if (!((name[i] >= 'A' && name[i] <= 'Z') ||
			(name[i] >= 'a' && name[i] <= 'z') ||
			name[i] == ' '))
		{
			cout << "Invalid Name! Only alphabets and spaces are allowed." << endl;
			return false;
		}
	}

	return true;
}

bool CheckCNICFormat(string cnic)
{
	if (cnic.length() != 15)
	{
		cout << "Invalid CNIC! Format should be 12345-1234567-1" << endl;
		return false;
	}


	for (int i = 0; i < 5; i++)
	{
		if (cnic[i] < '0' || cnic[i] > '9')
		{
			cout << "Invalid CNIC!" << endl;
			return false;
		}
	}

	if (cnic[5] != '-')
	{
		cout << "Invalid CNIC!" << endl;
		return false;
	}

	for (int i = 6; i < 13; i++)
	{
		if (cnic[i] < '0' || cnic[i] > '9')
		{
			cout << "Invalid CNIC!" << endl;
			return false;
		}
	}

	if (cnic[13] != '-')
	{
		cout << "Invalid CNIC!" << endl;
		return false;
	}

	if (cnic[14] < '0' || cnic[14] > '9')
	{
		cout << "Invalid CNIC!" << endl;
		return false;
	}

	return true;
}

bool CheckContact(string contact)
{
	if (contact.length() != 11)
	{
		cout << "Invalid Contact Number! It must contain 11 digits." << endl;
		return false;
	}

	if (contact[0] != '0' || contact[1] != '3')
	{
		cout << "Contact Number must start with 03." << endl;
		return false;
	}

	for (int i = 0; i < contact.length(); i++)
	{
		if (contact[i] < '0' || contact[i] > '9')
		{
			cout << "Invalid Contact Number! Only digits are allowed." << endl;
			return false;
		}
	}

	return true;
}

void Cus_registration()
{
	customers C;
	ofstream outFile("customers.txt", ios::app);
	cout << "\t--- ADD CUSTOMER ---\n";
	if (outFile.is_open())
	{
		cin.ignore();
		do
		{
			cout << "Enter customer name: ";
			getline(cin, C.cus_name);

		} while (!CheckName(C.cus_name));

		do
		{
			cout << "Enter customer CNIC (12345-1234567-1): ";
			cin >> C.cnic;

		} while (!CheckCNICFormat(C.cnic));

		if (CheckCNIC(C.cnic))
		{
			cout << "Customer with this CNIC already exists.\n";
			outFile.close();
			return;
		}
		do
		{
			cout << "Enter customer contact: ";
			cin >> C.contact;

		} while (!CheckContact(C.contact));

		outFile << C.cus_name << "|" << C.cnic << "|" << C.contact << endl;
		outFile.close();

		cout << "Data added successfully." << endl;
	}
	else
	{
		cout << "Error opening file not found." << endl;
	}
}

void read_customers()
{
	customers C;
	ifstream inFile("customers.txt", ios::in);
	cout << "\t---- CUSTOMER DETAILS ----\n\n";
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			string line;
			getline(inFile, line);
			if (line.empty()) continue;

			int pos1 = line.find('|');
			int pos2 = line.find('|', pos1 + 1);

			C.readname = line.substr(0, pos1);
			C.read_cnic = line.substr(pos1 + 1, (pos2 - pos1) - 1);
			C.read_contact = line.substr(pos2 + 1);

			cout << "Customer name: " << C.readname << " CNIC: " << C.read_cnic << " contact: " << C.read_contact << endl;
			cout << "----------------------------------------------------------------------------\n\n";
		}
		inFile.close();
	}
	else
	{
		cout << "Error opening file for read." << endl;
	}
}

bool CheckCustomer(string cnic)
{
	customers C;
	ifstream inFile("customers.txt");

	if (!inFile.is_open())
	{
		cout << "Error opening customers file." << endl;
		return false;
	}

	string line;

	while (getline(inFile, line))
	{
		if (line.empty()) continue;

		int pos1 = line.find('|');
		int pos2 = line.find('|', pos1 + 1);

		C.cus_name = line.substr(0, pos1);
		C.read_cnic = line.substr(pos1 + 1, pos2 - pos1 - 1);
		C.read_contact = line.substr(pos2 + 1);

		if (C.read_cnic == cnic)
		{
			inFile.close();
			return true;
		}
	}

	inFile.close();
	return false;
}
