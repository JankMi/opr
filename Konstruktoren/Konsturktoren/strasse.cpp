#include "strasse.h"

#include <iostream>

#include "logger.h"

using namespace std;

Strasse::Strasse(const std::string name, initializer_list<int> numbers) : m_name(name)
{
    Logger::getInstance()->write(__PRETTY_FUNCTION__);
    for( int number : numbers){
        Haus newHaus {m_name,number};
        m_houses.push_back(newHaus);
    }
}


Strasse::~Strasse()
{
    Logger::getInstance()->write(__PRETTY_FUNCTION__);
}

void Strasse::write() const{
    cout << "Strasse: "<<m_name<<" hat die Haeuser: "<<std::endl;
    for (auto haus : m_houses) {
        haus.write();
    }
}
