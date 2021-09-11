 // Fig. 9.8: Time.h
// Time class containing a constructor with default arguments.
// Member functions defined in Time.cpp.
// prevent multiple inclusions of header
 #ifndef TIME_H
 #define TIME_H

 // Time abstract data type definition
class Time {
public:
	explicit Time(int = 0, int = 0, int = 0);

	// SETTERS
	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	// GETTERS
	int getHour();
	int getMinute();
	int getSecond();

	void tick();  // increment time by 1 second

	void printUniversal();
	void printStandard();

private:
	int hour;
	int minute;
	int second;
};

 #endif