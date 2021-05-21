#pragma once
#include "home_bookkeeping/lib/logger/Record.h"
#include "home_bookkeeping/lib/logger/Util.h"

namespace plog
{
    class FuncMessageFormatter
    {
    public:
        static util::nstring header()
        {
            return util::nstring();
        }

        static util::nstring format(const Record& record)
        {
            util::nostringstream ss;
            ss << record.getFunc() << PLOG_NSTR("@") << record.getLine() << PLOG_NSTR(": ") << record.getMessage() << PLOG_NSTR("\n");

            return ss.str();
        }
    };
}