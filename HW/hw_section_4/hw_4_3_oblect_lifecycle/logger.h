#ifndef LOGGER_H
#define LOGGER_H

class Logger {
private:
    static int counter;
    const int id;

public:
    Logger();

    Logger(const Logger& other);

    Logger(Logger&& other);

    Logger& operator = (const Logger& other);

    Logger& operator = (Logger&& other);

    ~Logger();
};

#endif