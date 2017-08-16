/* Define the exception here */
class BadLengthException : public std::exception {
    string message;
    
public:
    BadLengthException(int length) {
        stringstream ss;
        
        ss << length;
        
        this->message = ss.str();
    }
    
    virtual const char* what() const throw () { 
        
        
        return this->message.c_str(); 
    }
    
    virtual ~BadLengthException() throw (){}
};