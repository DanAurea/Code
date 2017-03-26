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

#ifndef _EJA_SPLASH_DIALOG_
#define _EJA_SPLASH_DIALOG_

#include <QColor>
#include <QFont>
#include <QPixmap>
#include <QSplashScreen>
#include <QString>

#include "resource/resource.h"

namespace eja
{
	class splash_dialog : public QSplashScreen
	{
		Q_OBJECT

	private:
		QColor m_color = Qt::white;
		Qt::Alignment m_alignment = Qt::AlignLeft | Qt::AlignBottom;

	public:
		splash_dialog(QWidget* parent = 0) : splash_dialog(QPixmap(resource::logo)) { }
		splash_dialog(const QPixmap& pixmap, QWidget* parent = 0);
		~splash_dialog() { }

		// Utility
		using QSplashScreen::show;
		void show(const QString& str) { showMessage(str, m_alignment, m_color); }
	};
}

#endif
