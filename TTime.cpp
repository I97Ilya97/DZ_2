
#include "TTime.h"
#include <stdlib.h>


TTime::TTime(unsigned int hh, unsigned int mm, unsigned int ss, unsigned int DD,
	unsigned int MM, unsigned int YY) {
	setDate(DD, MM, YY);
	setTime(hh, mm, ss);
}
TTime::TTime(std::string& time) {

}

bool TTime::setTime(unsigned int hh, unsigned int mm, unsigned int ss) {
	bool retval = true;
	if (!setHours(hh))
		retval = false;
	if (!setMinutes(mm))
		retval = false;
	if (!setSeconds(ss))
		retval = false;
	return retval;

}
bool TTime::setDate(unsigned int DD, unsigned int MM, unsigned int YY) {

	bool retval = true;
	if (!setYear(YY))
		retval = false;
	if (!setMonth(MM))
		retval = false;
	if (!setDay(DD))
		retval = false;
	return retval;

}
unsigned int TTime::getHours() {
	return h;

}
unsigned int TTime::getMinutes() {
	return m;
}
unsigned int TTime::getSeconds() {
	return s;
}
unsigned int TTime::getDay() {
	return D;
}
unsigned int TTime::getMonth() {
	return M;
}
unsigned int TTime::getYear() {
	return Y;
}

bool TTime::setHours(unsigned int hh) {
	bool retval = false;
	if (hh < 24) {
		h = hh;
		retval = true;
	}
	return retval;
}
bool TTime::setMinutes(unsigned int mm) {
	bool retval = false;
	if (mm < 60) {
		m = mm;
		retval = true;
	}
	return retval;
}
bool TTime::setSeconds(unsigned int ss) {
	bool retval = false;
	if (ss < 60) {
		s = ss;
		retval = true;
	}
	return retval;
}
bool TTime::setDay(unsigned int DD) {
	bool retval = false;
	unsigned int M_cnt;
	bool isVis = Y % 4;
	switch (M) {
	case 1:
		M_cnt = 31;
		break;
	case 2:
		M_cnt = isVis ? 29 : 28;
		break;
	case 3:
		M_cnt = 31;
		break;
	case 4:
		M_cnt = 30;
		break;
	case 5:
		M_cnt = 31;
		break;
	case 6:
		M_cnt = 30;
		break;
	case 7:
		M_cnt = 31;
		break;
	case 8:
		M_cnt = 31;
		break;
	case 9:
		M_cnt = 30;
		break;
	case 10:
		M_cnt = 31;
		break;
	case 11:
		M_cnt = 30;
		break;
	case 12:
		M_cnt = 31;
		break;
	default:
		throw new std::string("BAD MONTH\n");
		break;
	}
	if (DD <= M_cnt) {
		D = DD;
		retval = true;
	}
	return retval;
}
bool TTime::setMonth(unsigned int MM) {
	bool retval = false;
	if (MM <= 12) {
		M = MM;
		retval = true;
	}
	return retval;
}
bool TTime::setYear(unsigned int YY) {
	Y = YY;
	return true;
}

TTime& TTime::operator++() {
	s++;
	if (s > 59) {
		s = 0;
		m++;
	}
	if (m > 59) {
		m = 0;
		h++;
	}
	if (h > 23) {
		h = 0;
		D++;
	}
	unsigned int M_cnt;
	bool isVis = Y % 4;
	switch (M) {
	case 1:
		M_cnt = 31;
		break;
	case 2:
		M_cnt = isVis ? 29 : 28;
		break;
	case 3:
		M_cnt = 31;
		break;
	case 4:
		M_cnt = 30;
		break;
	case 5:
		M_cnt = 31;
		break;
	case 6:
		M_cnt = 30;
		break;
	case 7:
		M_cnt = 31;
		break;
	case 8:
		M_cnt = 31;
		break;
	case 9:
		M_cnt = 30;
		break;
	case 10:
		M_cnt = 31;
		break;
	case 11:
		M_cnt = 30;
		break;
	case 12:
		M_cnt = 31;
		break;
	default:
		throw new std::string("BAD MONTH\n");
		break;
	}
	if (M > M_cnt) {
		M = 1;
		Y++;
	}
	return *this;
}
bool TTime::operator>(TTime& a) {
	bool Yh = Y > a.getYear();
	bool Mh = M > a.getMonth();
	bool Dh = D > a.getDay();
	bool hh = h > a.getHours();
	bool mh = m > a.getMinutes();
	bool sh = s > a.getSeconds();
	bool Ye = Y == a.getYear();
	bool Me = M == a.getMonth();
	bool De = D == a.getDay();
	bool he = h == a.getHours();
	bool me = m == a.getMinutes();
	bool retval = ((Yh) || (Mh && Ye) || (Dh && Ye && Me)
		|| (hh && Ye && Me && De) || (mh && Ye && Me && De && he)
		|| (sh && Ye && Me && De && he && me));
	return retval;
}
bool TTime::operator<(TTime& a) {
	bool Yh = Y < a.getYear();
	bool Mh = M < a.getMonth();
	bool Dh = D < a.getDay();
	bool hh = h < a.getHours();
	bool mh = m < a.getMinutes();
	bool sh = s < a.getSeconds();
	bool Ye = Y == a.getYear();
	bool Me = M == a.getMonth();
	bool De = D == a.getDay();
	bool he = h == a.getHours();
	bool me = m == a.getMinutes();
	bool retval = ((Yh) || (Mh && Ye) || (Dh && Ye && Me)
		|| (hh && Ye && Me && De) || (mh && Ye && Me && De && he)
		|| (sh && Ye && Me && De && he && me));
	return retval;
}
bool TTime::operator==(TTime& a) {
	bool Ye = Y == a.getYear();
	bool Me = M == a.getMonth();
	bool De = D == a.getDay();
	bool he = h == a.getHours();
	bool me = m == a.getMinutes();
	bool se = m == a.getSeconds();
	bool retval = (Ye && Me && De && he && me && se);
	return retval;
}
bool TTime::operator!=(TTime& a) {
	bool Ye = Y == a.getYear();
	bool Me = M == a.getMonth();
	bool De = D == a.getDay();
	bool he = h == a.getHours();
	bool me = m == a.getMinutes();
	bool se = m == a.getSeconds();
	bool retval = (Ye && Me && De && he && me && se);
	return !retval;
}
bool TTime::operator>=(TTime& a) {
	bool retval = ((*this > a) || (*this == a));
	return retval;
}
bool TTime::operator<=(TTime& a) {
	bool retval = ((*this < a) || (*this == a));
	return retval;
}

std::string& TTime::toString() {
	static std::string retval;
	retval += h;
	retval += ":";
	retval += m;
	retval += ":";
	retval += s;
	retval += " ";

	retval += D;
	retval += ".";
	retval += M;
	retval += ".";
	retval += Y;
	return retval;
}
