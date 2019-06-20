using namespace std;
class Image {
public:
    Image(int w, int h, std::string flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();
    
    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
    virtual void display();
    /*
     * If we don't want virtual method lookup, we
     * could just declare:
     * void display();
     * */
    
    int get_height() { return height; }
    int get_width() { return width; }
    
private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image& img2);
};


class Gif: public Image{
public:

    Gif(int w, int h, std:: string flnm, int cl = 0): Image(w,h,flnm), compression_level(cl){}
    void display(){ cout << "In GIF" <<endl;}
private:
    int compression_level;
};

class Jpeg: public Image{
public:
    Jpeg(int w, int h, std:: string flnm):Image(w,h,flnm){}
    void display(){ cout << "In Jpeg" <<endl;}
};

class Png:public Image{
public:
    Png(int w, int h, std:: string flnm): Image(w,h,flnm){}
    void display(){ cout << "In Png" <<endl;}
};







