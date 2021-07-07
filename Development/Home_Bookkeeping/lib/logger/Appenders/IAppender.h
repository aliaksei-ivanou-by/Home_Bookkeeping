#pragma once
#include "Home_Bookkeeping/lib/logger/Record.h"
#include "Home_Bookkeeping/lib/logger/Util.h"

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
