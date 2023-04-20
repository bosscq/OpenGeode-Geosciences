/*
 * Copyright (c) 2019 - 2023 Geode-solutions
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#pragma once

#include <geode/basic/factory.h>
#include <geode/basic/output.h>

#include <geode/geosciences/implicit/common.h>

namespace geode
{
    class StratigraphicSection;
} // namespace geode

namespace geode
{
    /*!
     * API function for saving a StratigraphicSection.
     * The adequate saver is called depending on the given filename extension.
     * @param[in] stratigraphic_section StratigraphicSection to save.
     * @param[in] filename Path to the file where save the
     * StratigraphicSection.
     */
    void opengeode_geosciences_implicit_api save_stratigraphic_section(
        const StratigraphicSection& stratigraphic_section,
        absl::string_view filename );

    class StratigraphicSectionOutput : public Output< StratigraphicSection >
    {
    public:
        virtual ~StratigraphicSectionOutput() = default;

    protected:
        StratigraphicSectionOutput( absl::string_view filename )
            : Output< StratigraphicSection >{ filename }
        {
        }
    };

    using StratigraphicSectionOutputFactory =
        Factory< std::string, StratigraphicSectionOutput, absl::string_view >;
} // namespace geode
