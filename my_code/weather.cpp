#include <iostream>
#include <string>
#include "weather.h"
#include "date.h"
#include <vector>
using namespace std;

const double F_TO_C = 5/9;
const double C_TO_F = 9/5;

double WReading:: get_tempF(){
	return ((temperature*C_TO_F)+32);
}
double WReading:: get_tempC(){
	return ((temperature-32)*F_TO_C);
}

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) : station_nm(nm), my_loc(loc) {}

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