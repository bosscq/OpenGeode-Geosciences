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

#include <geode/basic/factory.h>

#include <geode/georepresentation/io/boundary_representation_output.h>

#include <geode/geosciences/common.h>

namespace geode
{
    class StructuralModel;
} // namespace geode

namespace geode
{
    /*!
     * API function for saving a StructuralModel.
     * The adequate saver is called depending on the given filename extension.
     * @param[in] structural_model StructuralModel to save.
     * @param[in] filename Path to the file where save the StructuralModel.
     */
    void opengeode_geosciences_geosciences_api save_structural_model(
        const StructuralModel& structural_model, const std::string& filename );

    class opengeode_geosciences_geosciences_api StructuralModelOutput
        : public Output
    {
    public:
        virtual ~StructuralModelOutput() = default;

    protected:
        StructuralModelOutput(
            const StructuralModel& structural_model, std::string filename );

        const StructuralModel& structural_model() const
        {
            return structural_model_;
        }

    private:
        const StructuralModel& structural_model_;
    };

    using StructuralModelOutputFactory = Factory< std::string,
        StructuralModelOutput,
        const StructuralModel&,
        std::string >;
} // namespace geode