#ifndef STRASSE_H
#define STRASSE_H

#include <string>
#include <vector>

#include "haus.h"

class Strasse
{
public:
    Strasse(const std::string name,std::initializer_list<int> numbers);
    ~Strasse();
    void write() const;
private:
    std::string m_name;
    std::vector<Haus> m_houses;
};

#endif // STRASSE_H
