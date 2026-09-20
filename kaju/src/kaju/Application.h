#pragma once
#include "core.h"
namespace kaju
{
    class KAJU_API Application
    {
    public:
        Application();
        virtual ~Application();

        void virtual run() = 0;
    };
}