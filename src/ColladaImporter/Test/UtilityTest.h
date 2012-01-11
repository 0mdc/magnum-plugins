#ifndef Magnum_Plugins_ColladaImporter_Test_UtilityTest_h
#define Magnum_Plugins_ColladaImporter_Test_UtilityTest_h
/*
    Copyright © 2010, 2011 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include <QtCore/QObject>

namespace Magnum { namespace Plugins { namespace ColladaImporter { namespace Test {

class UtilityTest: public QObject {
    Q_OBJECT

    private slots:
        void parseVector();
        void parseArray();
};

}}}}

#endif
