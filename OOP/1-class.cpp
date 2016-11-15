#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Student
{
private:
	string name;
	int age;
	string class_name;
public:
	Student()
	{
		name = "";
		age = 0;
		class_name = "";
	}
	Student(string name, int age, string class_name)
	{
		this->name = name;
		this->age = age;
		this->class_name = class_name;
	}

	string getName()
	{
		return name;
	}
	void setName(string name)
	{
		this->name = name;
	}

	int getAge()
	{
		return age;
	}
	void setAge(int age)
	{
		this->age = age;
	}

	string getClass_name()
	{
		return class_name;
	}
	void setClass_name(string class_name)
	{
		this->class_name = class_name;
	}

	void showInf()
	{
		cout << "Name: " << name << ", age: " << age << ", class: " << class_name << endl;
	}
};

main(int argc, char *argv[])
{
	Student s1 = Student();
	Student s2("Thu Huong", 23, "12Math");

	s1.setName("Clark");
	s1.setAge(24);
	s1.setClass_name("12 Math");

	s1.showInf();
	s2.showInf();
	return 0;
}