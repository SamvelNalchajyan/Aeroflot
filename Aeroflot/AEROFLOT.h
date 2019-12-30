#pragma once

class AEROFLOT
{
private:
	char* Destination;      // ����� ����������
	int FlightNumber;       // ����� �����
	char* PlaneType;        // ��� �������
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