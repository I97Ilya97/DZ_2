#ifndef TTIME_H_
#define TTIME_H_

#include <string>
#include <exception>
#include <cstdlib>

class TTime {
private:
	unsigned int h = 0, m = 0, s = 0;
	unsigned int D = 0, M = 0, Y = 0;
public:
	TTime() = default;
	//virtual ~TTime();
	TTime(unsigned int hh, unsigned int mm, unsigned int ss, unsigned int DD,
		unsigned int MM, unsigned int YY);
	TTime(std::string& time);

	bool setTime(unsigned int hh, unsigned int mm, unsigned int ss);
	bool setDate(unsigned int DD, unsigned int MM, unsigned int YY);
	unsigned int getHours();
	unsigned int getMinutes();
	unsigned int getSeconds();
	unsigned int getDay();
	unsigned int getMonth();
	unsigned int getYear();

	bool setHours(unsigned int hh);
	bool setMinutes(unsigned int mm);
	bool setSeconds(unsigned int ss);
	bool setDay(unsigned int DD);
	bool setMonth(unsigned int MM);
	bool setYear(unsigned int YY);

	TTime& operator++();
	bool operator>(TTime& a);
	bool operator<(TTime& a);
	bool operator==(TTime& a);
	bool operator!=(TTime& a);
	bool operator>=(TTime& a);
	bool operator<=(TTime& a);

	std::string& toString();

};

#endif /* TTIME_H_ */
