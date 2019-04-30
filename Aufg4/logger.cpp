#include "logger.h"

#include <iostream>

using namespace std;

Logger::Logger()
{
    cout << __PRETTY_FUNCTION__<<endl;
}

Logger::~Logger(){
    cout << __PRETTY_FUNCTION__<<endl;
}



Logger* Logger::getInstance(){
    static DeleteLoggerOnTermination deleter;
    return m_instance ? m_instance : m_instance = new Logger();
}

void Logger::write(std::string msg) const{
    cout << "Logger: "<< msg<<endl;
}



Logger* Logger::m_instance = nullptr;
