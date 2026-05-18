#ifndef SYSTEM_H
#define SYSTEM_H

class System {
private:
    double value;

public:

    System(double v = 0.0);                 
    System(const System& obj);             
    virtual ~System();                      
    System& operator=(const System& obj);  

    double getValue() const;
    void setValue(double v);
};

#endif