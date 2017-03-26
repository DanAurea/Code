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

#ifndef _EJA_CLIENT_UPLOAD_REQUEST_COMMAND_
#define _EJA_CLIENT_UPLOAD_REQUEST_COMMAND_

#include <memory>
#include <string>

#include "command/client/client_command.h"
#include "entity/entity.h"
#include "http/http_socket.h"
#include "http/http_status.h"

namespace eja
{
	class client_upload_request_command final : public client_command
	{
	private:
		size_t m_delay = 0;

	public:
		using ptr = std::shared_ptr<client_upload_request_command>;

	private:
		client_upload_request_command(const entity::ptr entity, const http_socket::ptr socket) : client_command(entity, socket) { }

	public:
		virtual ~client_upload_request_command() override { }

		// Interface
		virtual void clear() override;

		// Utility
		virtual http_status execute() override;
		bool has_delay() const { return m_delay > 0; }

		// Accessor
		size_t get_delay() const { return m_delay; }

		// Static
		static ptr create(const entity::ptr entity, const http_socket::ptr socket) { return ptr(new client_upload_request_command(entity, socket)); }
	};
}

#endif
