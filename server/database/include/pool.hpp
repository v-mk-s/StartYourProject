#pragma once

#include "connection.hpp"

#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>


namespace cpool {


class ConnectionPool {
public:
    class ConnectionProxy final {
        friend ConnectionPool;

    public:
        ConnectionProxy( ConnectionProxy&& other ) noexcept;
        ConnectionProxy& operator=( ConnectionProxy&& other ) noexcept;

        ~ConnectionProxy();

        Connection* operator->();
        Connection& operator*();

        bool valid() const;

    private:
        ConnectionProxy( ConnectionPool* pool, Connection* connection ) noexcept;

        ConnectionPool* m_pool;
        Connection*     m_connection;
    };

protected:
    explicit ConnectionPool( std::vector< std::unique_ptr< Connection > >&& connections );

    template < class T >
    friend class ConnectionPoolFactory;

public:
    virtual ~ConnectionPool();

    ConnectionProxy get_connection();
    void            release_connection( ConnectionProxy&& proxy );

    std::size_t size() const;
    std::size_t size_idle() const;
    std::size_t size_busy() const;

    void heart_beat();

private:
    void release_connection( Connection* connection );

    mutable std::mutex                                               m_connections_mtx;
    std::unordered_map< Connection*, std::unique_ptr< Connection > > m_connections_idle;
    std::unordered_map< Connection*, std::unique_ptr< Connection > > m_connections_busy;
};


template < class T >
class ConnectionPoolFactory final {
private:
    ConnectionPoolFactory();
};


}    // namespace cpool