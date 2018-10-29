#pragma once

class Date {
private:
	int day;
	int month;
	int year;
	static bool updateNeeded;
public:
	Date();
	Date(int dayIn, int monthIn, int yearIn);
	int getDay();
	int getMon();
	int getYear();
	void setDay(int i);
	void setMon(int i);
	void setYear(int i);
	bool operator<(Date rhs);
	bool operator>(Date rhs);
	bool operator<=(Date rhs);
	bool operator>=(Date rhs);
	bool operator==(Date rhs);
	bool operator!=(Date rhs);
	void operator=(Date rhs);
	bool nextDay();
	void nextMon();
	void nextYear();
	void prevMon();
	void prevYear();
	static bool isUpdateNeeded();
	static void updated();
};
class Time {
private:
	int hours;
	int min;
	float sec;
public:
	Time();
	Time(int hourIn, int minIn, int secIn);
	int getHours();
	int getMin();
	float getSec();

};

