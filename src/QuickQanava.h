/*
 Copyright (c) 2008-2020, Benoit AUTHEMAN All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the author or Destrat.io nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL AUTHOR BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

//-----------------------------------------------------------------------------
// This file is a part of the QuickQanava software library.
//
// \file	QuickQanava.h
// \author	benoit@destrat.io
// \date	2016 02 04
//-----------------------------------------------------------------------------

#pragma once

// GTpo headers
#include <gtpo/GTpo.h>

// QuickContainers headers
#include <QuickContainers>

// Qt header
#include <QQmlEngine>

// QuickQanava headers
#include "./qanGraphConfig.h"
#include "./qanEdge.h"
#include "./qanEdgeItem.h"
#include "./qanNode.h"
#include "./qanNodeItem.h"
#include "./qanPortItem.h"
#include "./qanConnector.h"
#include "./qanGroup.h"
#include "./qanGroupItem.h"
#include "./qanGraph.h"
#include "./qanNavigable.h"
#include "./qanGrid.h"
#include "./qanLineGrid.h"
#include "./qanGraphView.h"
#include "./qanStyle.h"
#include "./qanStyleManager.h"
#include "./qanBottomRightResizer.h"
#include "./qanNavigablePreview.h"

struct QuickQanava {
    static void initialize(QQmlEngine* engine) {
#ifdef QUICKQANAVA_STATIC   // Initialization is done in QuickQanavaPlugin when QUICKQANAVA_STATIC is not defined

        Q_INIT_RESOURCE(QuickQanava_static);
        Q_INIT_RESOURCE(QuickQanavaGraphicalEffects);
#if QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
        qWarning() << "QuickQanava::initialize(): Warning: QuickQanava depends on Qt Quick Shapes library available since Qt 5.10.";
#endif
        QuickContainers::initialize();

        qmlRegisterType<qan::Node>("QuickQanava", 2, 0, "AbstractNode");
        if (engine != nullptr) {
            engine->rootContext()->setContextProperty("defaultNodeStyle", QVariant::fromValue(qan::Node::style()));
            engine->rootContext()->setContextProperty("defaultEdgeStyle", QVariant::fromValue(qan::Edge::style()));
            engine->rootContext()->setContextProperty("defaultGroupStyle", QVariant::fromValue(qan::Group::style()));
        }
        qmlRegisterType<qan::NodeItem>("QuickQanava", 2, 0, "NodeItem");
        qmlRegisterType<qan::PortItem>("QuickQanava", 2, 0, "PortItem");
        qmlRegisterType<qan::Edge>("QuickQanava", 2, 0, "AbstractEdge");
        qmlRegisterType<qan::EdgeItem>("QuickQanava", 2, 0, "EdgeItem");
        qmlRegisterType<qan::Group>("QuickQanava", 2, 0, "AbstractGroup");
        qmlRegisterType<qan::GroupItem>("QuickQanava", 2, 0, "GroupItem");
        qmlRegisterType<qan::Connector>("QuickQanava", 2, 0, "Connector");

        qmlRegisterType<qan::Graph>("QuickQanava", 2, 0, "Graph");
        qmlRegisterType<qan::GraphView>("QuickQanava", 2, 0, "AbstractGraphView");
        qmlRegisterType<qan::Navigable>("QuickQanava", 2, 0, "Navigable");
        qmlRegisterType<qan::NavigablePreview>("QuickQanava", 2, 0, "AbstractNavigablePreview");

        qmlRegisterType<qan::Grid>("QuickQanava", 2, 0, "AbstractGrid");
        qmlRegisterType<qan::OrthoGrid>("QuickQanava", 2, 0, "OrthoGrid");
        qmlRegisterType<qan::LineGrid>("QuickQanava", 2, 0, "AbstractLineGrid");
        qmlRegisterType<qan::impl::GridLine>("QuickQanava", 2, 0, "GridLine");

        qmlRegisterType<qan::Style>("QuickQanava", 2, 0, "Style");
        qmlRegisterType<qan::NodeStyle>("QuickQanava", 2, 0, "NodeStyle");
        qmlRegisterType<qan::EdgeStyle>("QuickQanava", 2, 0, "EdgeStyle");
        qmlRegisterType<qan::StyleManager>("QuickQanava", 2, 0, "StyleManager");
        qmlRegisterType<qan::BottomRightResizer>("QuickQanava", 2, 0, "BottomRightResizer" );
#endif // QUICKQANAVA_STATIC
    } // initialize()
};

namespace qan { // ::qan

} // ::qan
