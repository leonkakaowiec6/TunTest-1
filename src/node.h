#ifndef NODE_H
#define NODE_H

#include "iCrypto.h"
#include "iTun.h"
#include "iUdp.h"
#include <boost/asio/io_service.hpp>
#include <memory>
#include <mutex>

class node final {
	public:
        node() = default;
        void run();
        static std::unique_ptr<node> node_factory();
        node(node &&) = default;
	private:
        std::unique_ptr<boost::asio::io_service> m_io_service;
		std::unique_ptr<iCrypto> m_crypto;
		std::unique_ptr<iTun> m_tun;
		std::unique_ptr<iUdp> m_udp;
        std::mutex m_udp_mutex;
};

#endif // NODE_H
