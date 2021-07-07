#pragma once
#include "Home_Bookkeeping/lib/logger/Appenders/IAppender.h"
#include "Home_Bookkeeping/lib/logger/WinApi.h"

namespace plog
{
    template<class Formatter>
    class DebugOutputAppender : public IAppender
    {
    public:
        virtual void write(const Record& record)
        {
            OutputDebugStringW(Formatter::format(record).c_str());
        }
    };
}
