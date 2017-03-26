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

#ifndef _EJA_ROUTER_TRANSFER_MODEL_
#define _EJA_ROUTER_TRANSFER_MODEL_

#include "entity/entity.h"
#include "entity/entity_table_model.h"

namespace eja
{
	class router_transfer_model final : public entity_table_model
	{
		Q_OBJECT

	public:
		enum column : size_t { name, chunks, idle };

	private slots:
		virtual void on_add(const entity::ptr entity) override;
		virtual void on_remove(const entity::ptr entity) override;
		virtual void on_clear(const entity::ptr entity) override { clear(); }
		virtual void on_clear() override;

	public:
		router_transfer_model(QObject* parent = 0) : entity_table_model(parent) { }
		router_transfer_model(const entity::ptr entity, QObject* parent = 0) : entity_table_model(entity, parent) { }

		router_transfer_model(const entity::ptr entity, const column_names& names, QObject* parent = 0) : entity_table_model(entity, names, parent) { }
		router_transfer_model(const entity::ptr entity, const column_names& names, const column_sizes& sizes, QObject* parent = 0) : entity_table_model(entity, names, sizes, parent) { }

		router_transfer_model(const entity::ptr entity, column_names&& names, QObject* parent = 0) : entity_table_model(entity, names, parent) { }
		router_transfer_model(const entity::ptr entity, column_names&& names, column_sizes&& sizes, QObject* parent = 0) : entity_table_model(entity, names, sizes, parent) { }
		virtual ~router_transfer_model() override { }

		// Interface
		virtual void init() override;

		// Utility
		virtual bool empty() const override;

		// Model
		virtual QVariant data(const QModelIndex& index, int role) const override;
		virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

		// Accessor
		virtual size_t get_row(const entity::ptr entity) const override;
	};
}

#endif
