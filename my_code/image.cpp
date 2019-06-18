#include <iostream>
#include <string>
#include "image.h"
#include <vector>
using namespace std;

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
    delete image_buf;
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

void display(const std::string& s){
    cout<< s << endl;
}

void make_images1(Image& img1) {
    for (int i = 0; i < 10; i++) {
        Image img2 = Image(10, 10, "foo.txt");
        img2 = img1;
    }
}

void make_images2(Image& img1) {
    for (int i = 0; i < 10; i++) {
        Image img2 = img1;
    }
}
