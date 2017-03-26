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
#ifndef _EJA_CLIENT_GROUP_MODEL_
#define _EJA_CLIENT_GROUP_MODEL_

#include "entity/entity.h"
#include "component/group/group_component.h"
#include "entity/entity_table_model.h"
#include "system/function/function.h"

namespace eja
{
	class client_group_model final : public entity_table_model
	{
		Q_OBJECT

		// Using
		using entity_table_model::on_refresh;

	public:
		enum column : size_t { row, file, size, entropy, cipher, bits, hash, iterations, salt };
		enum offset : size_t { icon = 64 };
	
	private:
		function::ptr m_function;

	private slots:		
		virtual void on_refresh() override { set_modified(false); }

		virtual void on_add(const entity::ptr entity) override;
		virtual void on_remove(const entity::ptr entity) override;

	public:
		client_group_model(QObject* parent = 0) : entity_table_model(parent) { }
		client_group_model(const entity::ptr entity, QObject* parent = 0) : entity_table_model(entity, parent) { }

		client_group_model(const entity::ptr entity, const column_names& names, QObject* parent = 0) : entity_table_model(entity, names, parent) { }
		client_group_model(const entity::ptr entity, const column_names& names, const column_sizes& sizes, QObject* parent = 0) : entity_table_model(entity, names, sizes, parent) { }

		client_group_model(const entity::ptr entity, column_names&& names, QObject* parent = 0) : entity_table_model(entity, names, parent) { }
		client_group_model(const entity::ptr entity, column_names&& names, column_sizes&& sizes, QObject* parent = 0) : entity_table_model(entity, names, sizes, parent) { }
		virtual ~client_group_model() override { shutdown(); }

		// Interface
		virtual void init() override;
		virtual void shutdown() override;

		virtual void refresh() override;

		// Utility
		virtual bool empty() const override;

		// Model
		virtual bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
		virtual bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

		virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
		virtual QVariant data(const QModelIndex& index, int role) const override;
		virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
		virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

		// Accessor
		virtual size_t get_row(const entity::ptr entity) const;

	public slots:
		void post_create();
	};
}

#endif
