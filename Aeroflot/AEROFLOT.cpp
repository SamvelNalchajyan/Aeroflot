#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "AEROFLOT.h"
using namespace std;

AEROFLOT::AEROFLOT()
{
	Destination = NULL;
	FlightNumber = 0;
	PlaneType = NULL;
}

AEROFLOT::AEROFLOT(char* _Destinatioan, int _FlightNumber, char* _PlaneType)
{
	FlightNumber = _FlightNumber;
	Destination = new char[strlen(_Destinatioan) + 1];
	strcpy(Destination, _Destinatioan);
	PlaneType = new char[strlen(_PlaneType) + 1];
	strcpy(PlaneType, _PlaneType);
}

AEROFLOT::AEROFLOT(const AEROFLOT& a)
{
	FlightNumber = a.FlightNumber;
	Destination = new char[strlen(a.Destination) + 1];
	strcpy(Destination, a.Destination);
	PlaneType = new char[strlen(a.PlaneType) + 1];
	strcpy(PlaneType, a.PlaneType);
}

AEROFLOT::~AEROFLOT()
{
	delete[] Destination;
	delete[] PlaneType;
}

AEROFLOT& AEROFLOT::operator=(const AEROFLOT& a)
{
	if (this != &a)
	{
		FlightNumber = a.FlightNumber;
		if (Destination != NULL)
		{
			if (strlen(Destination) != strlen(a.Destination))
			{
				delete[] Destination;
				Destination = new char[strlen(a.Destination) + 1];
			}
		}
		if (Destination == NULL)
		{
			Destination = new char[strlen(a.Destination) + 1];
		}
		strcpy(Destination, a.Destination);
		if (PlaneType != NULL)
		{
			if (strlen(PlaneType) != strlen(a.PlaneType))
			{
				delete[] PlaneType;
				PlaneType = new char[strlen(a.PlaneType) + 1];
			}
		}
		if (PlaneType == NULL)
		{
			PlaneType = new char[strlen(a.PlaneType) + 1];
		}
		strcpy(PlaneType, a.PlaneType);
	}
	return *this;
}

bool AEROFLOT::operator<(const AEROFLOT& a)
{
	int Size, flag;
	if (strlen(Destination) <= strlen(a.Destination))
	{
		Size = strlen(Destination);
		flag = 1;
	}
	else
	{
		Size = strlen(a.Destination);
		flag = 2;
	}
	for (int i = 0; i < Size; i++)
	{
		if (Destination[i] < a.Destination[i])
		{
			return true;
		}
		else
		{
			if (Destination[i] > a.Destination[i])
			{
				return false;
			}
		}
	}
	if (flag == 1)
	{
		return true;
	}
	if (flag == 2);
	{
		return false;
	}
}

bool AEROFLOT::operator==(char* str)
{
	if (PlaneType == NULL)
	{
		return false;
	}
	if (strlen(PlaneType) != strlen(str))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if (PlaneType[i] != str[i])
			{
				return false;
			}
		}
		return true;
	}
}

void AEROFLOT::Print()
{
	if (Destination != NULL && PlaneType != NULL)
	{
		cout << "Destination - ";
		for (int i = 0; i < strlen(Destination); i++)
		{
			cout << Destination[i];
		}
		cout << "   Flight Number - " << FlightNumber << "   Airplane Type - ";
		for (int i = 0; i < strlen(PlaneType); i++)
		{
			cout << PlaneType[i];
		}
	}
}