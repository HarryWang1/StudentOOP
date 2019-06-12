#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"
#include "../my_code/date.h"

using namespace std;

void make_images1(Image& img1) {
    for (int i = 0; i < 100; i++) {
        Image img2 = Image(10, 10, "foo.txt");
        img2 = img1;
    }
}

void make_images2(Image& img1) {
    for (int i = 0; i < 100; i++) {
        Image img2 = img1;
    }
}


int main() {
    string fnm = "happy.gif!";
    Image img = Image(100, 100, fnm);
    for (int i = 1; i < 100; i++) {
         make_images1(img);
         make_images2(img);
    }
    exit(0);

//    cout << irkutsk << endl;
}