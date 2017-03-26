//
// The MIT License(MIT)
//
// Copyright(c) 2014 Demonsaw LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _EJA_ACCEPTOR_SERVICE_COMPONENT_H_
#define _EJA_ACCEPTOR_SERVICE_COMPONENT_H_

#include <memory>
#include <set>

#include "component/service/service_component.h"
#include "system/type.h"
#include "thread/thread_safe.h"

namespace eja
{
	class http_acceptor;
	class http_socket;

	class acceptor_service_component : public service_component
	{
	protected:
		std::shared_ptr<http_acceptor> m_acceptor;
		thread_safe<std::set<std::shared_ptr<http_socket>>> m_sockets;

	protected:
		acceptor_service_component();
		acceptor_service_component(const acceptor_service_component& comp) : service_component(comp) { }
		acceptor_service_component(const size_t threads) : service_component(threads) { }
		virtual ~acceptor_service_component() override;

		// Operator
		acceptor_service_component& operator=(const acceptor_service_component& comp);

		// Command
		void on_accept(const std::shared_ptr<http_socket> socket);
		void on_timer(const std::shared_ptr<http_socket> socket, const boost::system::error_code& error);

	public:
		virtual void shutdown() override;
		virtual void clear() /*override*/;

		// Utility		
		virtual void close();

		void push(const std::shared_ptr<http_socket> socket);
		void pop(const std::shared_ptr<http_socket> socket);

		// Get
		const thread_safe<std::set<std::shared_ptr<http_socket>>>& get_sockets() const { return m_sockets; }
		thread_safe<std::set<std::shared_ptr<http_socket>>>& get_sockets() { return m_sockets; }

	public:
		// Utility
		virtual void stop() override;

		// Get
		const std::shared_ptr<http_acceptor> get_acceptor() const { return m_acceptor; }
		std::shared_ptr<http_acceptor> get_acceptor() { return m_acceptor; }
	};
}

#endif
