class Box {
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
    int l, b, h;
// The class should have the following functions : 
public:
// Constructors: 
// Box();
    Box() : l(0), b(0), h(0) {
        
    }
// Box(int,int,int);
    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }
// Box(Box);
    Box(Box* box) {
        l = box->getLength();
        b = box->getBreadth();
        h = box->getHeight();
    }


// int getLength(); // Return box's length
    int getLength() {
        return l;
    }
// int getBreadth (); // Return box's breadth
    int getBreadth() {
        return b;
    }
// int getHeight ();  //Return box's height
    int getHeight() {
        return h;
    }
// long long CalculateVolume(); // Return the volume of the box
    long long CalculateVolume() {
        return (long long)l * (long long)b * (long long)h;
    }

//Overload operator < as specified
//bool operator<(Box& b)
    bool operator<(Box& box) {
        if(l < box.l)
            return true;
        
        if(b < box.b && l == box.l)
            return true;
            
        if(h < box.h && b == box.b && l == box.l)
            return true;
        
        return false;
    }

    friend ostream& operator<<(ostream& out, Box& B);

};
//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
ostream& operator<<(ostream& out, Box& B) {
    out << B.l << " " << B.b << " " << B.h;

    return out;
}