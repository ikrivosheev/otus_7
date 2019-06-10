#include <iostream>
#include <memory>
#include "logger.h"
#include "console_handler.h"
#include "file_handler.h"

int main() {
    Logger log;
    log.add_handler(std::make_shared<ConsoleHandler>());
    log.add_handler(std::make_shared<FileHandler>("/tmp/", "bulk"));
    log.emit("test");
    return 0;
}
