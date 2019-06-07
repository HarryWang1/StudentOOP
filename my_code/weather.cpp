#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

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

std:: ostream& operator<<(std::ostream& os, const Weather& w){
	os<<w.get_name() << "rating: " << w.get_rating() << ", GPS:" << w.my_loc <<endl;
	return os;
}

std:: ostream& operator<<(std::ostream& os, const GPS& gps){
	os << gps.latitude << "," << gps.longitude <<endl;
	return os;
}

