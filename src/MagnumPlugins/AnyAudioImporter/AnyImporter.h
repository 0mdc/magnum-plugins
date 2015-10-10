#ifndef Magnum_Trade_AnyImporter_h
#define Magnum_Trade_AnyImporter_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/** @file
 * @brief Class @ref Magnum::Audio::AnyImporter
 */

#include <memory>
#include <Magnum/Audio/AbstractImporter.h>

namespace Magnum { namespace Audio {

/**
@brief Any audio importer plugin

Detects file type based on file extension, loads corresponding plugin and then
tries to open the file with it.

This plugin is built if `WITH_ANYAUDIOIMPORTER` is enabled when building
Magnum Plugins. To use dynamic plugin, you need to load `AnyAudioImporter`
plugin from `MAGNUM_PLUGINS_IMPORTER_DIR`. To use static plugin, you need to
request `AnyAudioImporter` component of `MagnumPlugins` package in CMake and
link to `${MAGNUMPLUGINS_ANYAUDIOIMPORTER_LIBRARIES}`. To use this as a
dependency of another plugin, you additionally need to add
`${MAGNUMPLUGINS_ANYAUDIOIMPORTER_INCLUDE_DIRS}` to include path. See
@ref building-plugins, @ref cmake-plugins and @ref plugins for more
information.

Supported formats:

-   OGG Vorbis (`*.ogg`), loaded with any plugin that provides
    `VorbisAudioImporter`
-   WAV (`*.wav`), loaded with @ref WavImporter "WavAudioImporter" or any other
    plugin that provides it

Only loading from files is supported.
*/
class AnyImporter: public AbstractImporter {
    public:
        /** @brief Constructor with access to plugin manager */
        explicit AnyImporter(PluginManager::Manager<AbstractImporter>& manager);

        /** @brief Plugin manager constructor */
        explicit AnyImporter(PluginManager::AbstractManager& manager, std::string plugin);

        ~AnyImporter();

    private:
        Features doFeatures() const override;
        bool doIsOpened() const override;
        void doClose() override;
        void doOpenFile(const std::string& filename) override;

        Buffer::Format doFormat() const override;
        UnsignedInt doFrequency() const override;
        Containers::Array<char> doData() override;

        std::unique_ptr<AbstractImporter> _in;
};

}}

#endif
