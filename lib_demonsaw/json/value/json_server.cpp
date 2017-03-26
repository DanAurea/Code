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

#include "json_server.h"
#include "component/server/server_component.h"
#include "component/server/server_security_component.h"

namespace eja
{
	// Mutator
	void json_server::set(const entity::ptr entity)
	{
		const auto server = entity->get<server_component>();
		set_address(server->get_address());
		set_port(server->get_port());

		if (entity->has<server_security_component>())
		{
			const auto security = entity->get<server_security_component>();
			if (security && security->has_passphrase())
				set_passphrase(security->get_passphrase());
		}
	}

	void json_server::set(const server::ptr server)
	{
		set_address(server->get_address());
		set_port(server->get_port());
	}
}