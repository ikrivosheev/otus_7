#include "logger.h"

Logger& Logger::add_handler(std::shared_ptr<IHandler> handler) {
    _handlers.push_back(handler);
    return (*this);
}

void Logger::emit(const Record& record) {
    for (auto& handler: _handlers) {
        handler.get()->emit(record);
    }
}

void Logger::emit(const std::string& str) {
    Record record(str);
    emit(record);
}
