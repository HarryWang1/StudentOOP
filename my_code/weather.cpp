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

void Weather:: add_reading(WReading wr){
	wreadings.push_back(wr);

}

std:: ostream& operator<<(std::ostream& os, const Weather& w){
	os<<w.get_name() << "rating: " << w.get_rating() << ", GPS:" << w.my_loc <<endl;
	return os;
}

std:: ostream& operator<<(std::ostream& os, const GPS& gps){
	os << gps.latitude << "," << gps.longitude <<endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Date& date){
	os << date.day << "/" << date.month << "/" << date.year <<endl;
	return os;
}

Date:: Date(int d, int m, int y) : day(d), month(m), year(y){}


Image:: Image(int w, int h, std::string flnm): width(w), height(h),filename(flnm){
    cout << "In Image::Image(int, int, string)\n";
    image_buf = new char[image_sz()];
}

Image:: Image(const Image& img2){
    image_buf = new char[width*height];
    for(int i = 0; i < image_sz(); ++i){
        image_buf[i] = img2.image_buf[i];
    }
}

Image:: ~Image(){
    delete[] image_buf;
}

Image& Image:: operator=(const Image& img2){
    if(&img2 != this){
        delete image_buf;
        image_buf = new char[width*height];
        for(int i = 0; i < width*height; ++i){
            image_buf[i] = img2.image_buf[i];
        }
    }
    return *this;
}

int Image:: image_sz(){
    return height*width;
}

void Image:: display(){
    cout<< "In Image" << endl;
}
