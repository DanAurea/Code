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

#ifndef _EJA_JSON_ROUTER_
#define _EJA_JSON_ROUTER_

#include <memory>
#include <string>

#include "json_endpoint.h"
#include "entity/entity.h"
#include "json/json.h"
#include "json/json_lib.h"
#include "json/json_value.h"
#include "object/passphrase.h"
#include "object/router/router.h"

namespace eja
{
	class json_router final : public json_endpoint
	{
	public:
		using ptr = std::shared_ptr<json_router>;

	private:
		json_router() { }
		json_router(const std::string& input) { parse(input); }
		json_router(const char* input) { parse(input); }

		json_router(const json_value::ptr value) : json_endpoint(value) { }
		json_router(const json_value::ptr value, const char* key) : json_endpoint(value, key) { }

		json_router(const Json::Value& value) : json_endpoint(value) { }
		json_router(const Json::Value& value, const char* key) : json_endpoint(value, key) { }

	public:		
		virtual ~json_router() { }

		// Mutator
		void set(const entity::ptr entity);
		void set(const router::ptr router);
		void set(const passphrase::ptr passphrase) { set_passphrase(passphrase->get_passphrase()); }

		// Static
		static ptr create() { return ptr(new json_router()); }
		static ptr create(const std::string& input) { return ptr(new json_router(input)); }
		static ptr create(const char* input) { return ptr(new json_router(input)); }

		static ptr create(const json_value::ptr value) { return ptr(new json_router(value)); }
		static ptr create(const json_value::ptr value, const char* key) { return ptr(new json_router(value, key)); }

		static ptr create(const Json::Value& value) { return ptr(new json_router(value)); }
		static ptr create(const Json::Value& value, const char* key) { return ptr(new json_router(value, key)); }
	};
}

#endif
