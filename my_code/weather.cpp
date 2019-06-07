#include <iostream>
#include <string>
#include "weather.h"
#include <vector>
using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) : station_nm(nm), my_loc(loc) {}

Date:: Date(int d, int m, int y) : day(d), month(m), year(y){}

string Weather::get_name() const {
    return station_nm;
}

int Weather:: get_rating() const{
	return rating;
}

void Weather:: set_rating(int new_rating){
	rating = new_rating;
}

void Weather:: add_reading(WReading wr){
	wreadings.push_back(wr);
}


std:: ostream& operator<<(std::ostream& os, const GPS& gps){
	os << gps.latitude << "," << gps.longitude <<endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Date& date){
	os << date.day << "/" << date.month << "/" << date.year <<endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const WReading& wr){
	os << "date: " << wr.date << ", temp: " << wr.temperature << ", humi: " << wr.humidity  << ", wind: " << wr.windspeed <<endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Weather& w){
	os << "name: " << w.station_nm << "Rating: "<< w.rating <<"Loc: " << w.my_loc <<endl;
	for(WReading wr : w.wreadings){
		os << wr << " ";
	}
	os << endl;
	return os;
}