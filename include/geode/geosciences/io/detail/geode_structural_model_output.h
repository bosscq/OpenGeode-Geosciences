/*
 * Copyright (c) 2019 Geode-solutions
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

#include <fstream>

#include <geode/basic/uuid.h>

#include <geode/georepresentation/io/detail/geode_boundary_representation_output.h>

#include <geode/geosciences/core/structural_model.h>
#include <geode/geosciences/io/structural_model_output.h>

namespace geode
{
    class OpenGeodeStructuralModelOutput final : public StructuralModelOutput
    {
    public:
        OpenGeodeStructuralModelOutput(
            const StructuralModel& structural_model, std::string filename )
            : StructuralModelOutput( structural_model, std::move( filename ) )
        {
        }

        static std::string extension()
        {
            return StructuralModel::native_extension_static();
        }

        void write() const final
        {
            OpenGeodeBRepOutput brep_output{ structural_model(), filename() };
            ZipFile zip_writer{ filename(), uuid{}.string() };
            brep_output.archive_brep_files( zip_writer );
            zip_writer.archive_files(
                structural_model().save_faults( zip_writer.directory() ) );
            zip_writer.archive_files(
                structural_model().save_horizons( zip_writer.directory() ) );
        }
    };
} // namespace geode