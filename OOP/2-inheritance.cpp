#include <stdio.h>
#include <iostream>

class Shape
{
public:
	float P() {};
	float S() {}
}

class Rectangle: public Shape
{
protected:
	int width;
	int height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
}
int main(int argc, char *argv[])
{

}