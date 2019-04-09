#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:
    static Logger* getInstance();
    void write(std::string) const;
    ~Logger();
private:
    Logger();
    static Logger* m_instance;
};

#endif // LOGGER_H
