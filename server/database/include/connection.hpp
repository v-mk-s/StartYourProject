
#pragma once


namespace cpool {


class Connection {
public:
    virtual ~Connection() = default;

    virtual bool heart_beat() = 0;
    virtual bool is_healthy() = 0;
    virtual bool connect()    = 0;
    virtual void disconnect() = 0;
};


}  