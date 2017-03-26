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

#ifndef _EJA_GROUP_COMPONENT_
#define _EJA_GROUP_COMPONENT_

#include <memory>
#include <string>

#include "component/component.h"
#include "entity/entity.h"
#include "object/group/group.h"

namespace eja
{
	// Component
	derived_id_component(group_component, group);

	// Container
	derived_type(group_list_component, list_component<group>);
	derived_type(group_map_component, map_component<std::string, group>);
	derived_type(group_queue_component, queue_component<group>);
	derived_type(group_vector_component, vector_component<group>);

	derived_type(group_entity_list_component, entity_list_component);
	derived_type(group_entity_map_component, entity_map_component);
	derived_type(group_entity_queue_component, entity_queue_component);
	derived_type(group_entity_vector_component, entity_vector_component);
}

#endif
