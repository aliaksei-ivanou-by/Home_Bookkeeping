#pragma once
#include "home_bookkeeping/lib/logger/Record.h"
#include "home_bookkeeping/lib/logger/Util.h"

namespace plog
{
    class PLOG_LINKAGE IAppender
    {
    public:
        virtual ~IAppender()
        {
        }

        virtual void write(const Record& record) = 0;
    };
}
