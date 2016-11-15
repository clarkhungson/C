// Write and Read to/from a file

#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	char data[100];

	// Open a file in write mode
	ofstream file_write;
	file_write.open("2-File2.dat");

	cout << "Writting to the file" << endl;
	cout << "enter your name: ";
	cin.getline(data, 100);

	// write inputted data into the file
	file_write << data << endl;

	cout << "enter your age: ";
	cin >> data;
	//cin.ignore();

	// again write inputted data into the file
	file_write << data << endl;

	// close the opened file
	file_write.close();



	// Open a file in read mode
	ifstream file_read;
	file_read.open("2-File2.dat");

	cout << "Reading from the file" << endl;
	file_read >> data;

	// write the data at the screen
	cout << data << endl;

	// again read the data from the file and display it
	file_read >> data;
	cout << data << endl;

	// close the opened file
	file_read.close();

	return 0;
}