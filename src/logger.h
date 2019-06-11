#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <list>
#include "handler.h"
#include "record.h"


class Logger {
    public:
        Logger& add_handler(std::shared_ptr<IHandler> handler);
        void log(const Record&);
        void log(const std::string&);
        void log(const std::string&, const std::time_t&);

        ~Logger() = default;

        static Logger& get() {
            static Logger logger;
            return logger;
        }

    private:
        Logger() {};
        Logger(const Logger&);
        Logger& operator=(Logger&);

        std::list<std::shared_ptr<IHandler>> _handlers;
};

#endif // LOGGER_H
