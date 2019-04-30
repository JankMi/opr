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

    class DeleteLoggerOnTermination{
        // statische Instanz existiert in Logger::getInstance()
        //      -> wird bei Beenden des Programms zerstört und löscht die Logger-Instanz
    public:
        ~DeleteLoggerOnTermination(){
            delete Logger::m_instance;
            Logger::m_instance = nullptr;
        }
    };
};



#endif // LOGGER_H
