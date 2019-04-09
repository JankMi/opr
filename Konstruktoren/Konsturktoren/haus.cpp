#include "haus.h"

#include <iostream>

#include "logger.h"

using namespace std;

Haus::Haus(const std::string streetName, const int number) : m_streetName(streetName), m_number(number)
{
    Logger::getInstance()->write(__PRETTY_FUNCTION__);
}

Haus::~Haus()
{
    Logger::getInstance()->write(__PRETTY_FUNCTION__);
}

void Haus::write(){
    cout << "\tHaus: " << m_streetName << " "<<m_number<<endl;
}
