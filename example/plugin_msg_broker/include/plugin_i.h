#ifndef _PLUGIN_H_
#define _PLUGIN_H_

#include "channel.h"
#include "message.h"

class plugin_i
{
public:
    virtual ~plugin_i(){}
    virtual int start() = 0;
    virtual int stop() = 0;

    virtual int handle_broken(channel_ptr_t channel_) = 0;
    virtual int handle_msg(const message_t& msg_, channel_ptr_t channel_) = 0;
};

typedef plugin_i* plugin_ptr_t;
typedef int (*handle_channel_func_t)(channel_ptr_t);

#endif
