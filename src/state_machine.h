#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <stack>
#include <vector>
#include <memory>
#include <ctime>
#include "logger.h"


class StateMachine {
    public:
        StateMachine(int);
        StateMachine(const StateMachine&) = default;
        ~StateMachine() = default;
        
        void push_command(const std::string& command);
        void execute();
    
    private:
        enum class STATE {
            COMMAND,
            BLOCK,
        };

        int _bulk_size;
        STATE _cstate = STATE::COMMAND;
        std::time_t _time = 0;
        std::stack<char> _stack;
        std::vector<std::string> _commands;
};

#endif // STATE_MACHINE_H
