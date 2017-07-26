

class Person {
protected:
    string name;
    int age;
    int this_id;
    
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person {
    int publications;
public:
    static int cur_id;
    
    void getdata() {
        string name;
        int age;
        int publications;
        
        cin >> this->name;
        cin >> this->age;
        cin >> this->publications;
        
        this->this_id = cur_id++;
    }
    
    void putdata() {
        cout << this->name << " " << this->age << " " << this->publications << " " << this->this_id << endl;
    }
};

class Student : public Person {
    int *marks = new int[6];
public:    
    static int cur_id;
    
    void getdata() {
        string name;
        int age;
        
        cin >> this->name;
        cin >> this->age;
        
        for(int x = 0; x < 6; ++x) {
            cin >> this->marks[x];
        }
        
        this->this_id = cur_id++;
    }
    
    void putdata() {
        int markSum = 0;
        
        for(int x = 0; x < 6; ++x) {
            markSum += marks[x];
        }
        
        cout << this->name << " " << this->age << " " << markSum << " " << this->this_id << endl;
    }
};

int Professor::cur_id = 1;
int Student::cur_id = 1;