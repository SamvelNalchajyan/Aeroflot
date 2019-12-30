#pragma once

class AEROFLOT
{
private:
	char* Destination;      // пункт назначения
	int FlightNumber;       // номер рейса
	char* PlaneType;        // тип самолёта
public:
	AEROFLOT();
	AEROFLOT(char* _Destinatioan, int _FlightNumber, char* _PlaneType);
	AEROFLOT(const AEROFLOT& a);
	~AEROFLOT();

	AEROFLOT& operator=(const AEROFLOT& a);
	bool operator<(const AEROFLOT& a);
	bool operator==(char* str);
	void Print();
};