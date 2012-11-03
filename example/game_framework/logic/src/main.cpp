#include <iostream>
using namespace std;

#include "common_msg_def.h"
#include "msg_bus.h"
#include "log/log.h"

#include "logic_service.h"

using namespace ff;

int main(int argc, char* argv[])
{
    char buff[128];
    snprintf(buff, sizeof(buff), "tcp://%s:%s", "127.0.0.1", "10241");

    assert(0 == singleton_t<msg_bus_t>::instance().open(buff));

    logic_service_t logic_service;
    singleton_t<msg_bus_t>::instance().create_service_group("logic");
    singleton_t<msg_bus_t>::instance().create_service("logic", 0)
                                        .bind_service(&logic_service)
                                        .reg(&logic_service_t::login)
                                        .reg(&logic_service_t::logout);


    signal_helper_t::wait();
    singleton_t<msg_bus_t>::instance().close();
    cout <<"\noh end\n";
    
    return 0;
}