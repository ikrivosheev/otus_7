#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <list>
#include "handler.h"
#include "record.h"


class Logger {
    public:
        Logger(const std::string& name = "root"): _name(name) {};
        Logger(const Logger&) = default;

        Logger& add_handler(std::shared_ptr<IHandler> handler);
        void emit(const Record&);
        void emit(const std::string&);
        ~Logger() = default;

    private:
        std::string _name;
        std::list<std::shared_ptr<IHandler>> _handlers;
};

#endif // LOGGER_H
