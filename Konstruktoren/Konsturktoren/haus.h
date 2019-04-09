#ifndef HAUS_H
#define HAUS_H

#include <string>

class Haus
{
public:
    Haus(const std::string streetName, const int number);
    ~Haus();
    void write();
private:
    std::string m_streetName;
    int m_number;
};

#endif // HAUS_H
