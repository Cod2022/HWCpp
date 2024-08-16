#include "logger.h"
#include <iostream>

Logger::Logger(): id(++counter) {
    std::cout << "Logger(): " << id << "\n";
}

Logger::Logger(const Logger& other): id(++counter) {
    std::cout << "Logger(const Logger&): " << id << " " << other.id << "\n";
}

Logger::Logger(Logger&& other): id(++counter) {
    std::cout << "Logger(Logger&&): " << id << " " << other.id << "\n";
}

Logger& Logger::operator = (const Logger& other) {
    std::cout << "Logger& operator = (const Logger&): " << id << " " << other.id << "\n";
    return *this;
}

Logger& Logger::operator = (Logger&& other) {
    std::cout << "Logger& operator = (Logger&&): " << id << " " << other.id << "\n";
    return *this;
}

Logger::~Logger() {
    std::cout << "~Logger(): " << id << "\n";
}

int Logger::counter = 0;
