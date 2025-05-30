/*
 * Copyright (c) 2019 - 2025 Geode-solutions
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

#include <geode/geosciences/implicit/representation/builder/implicit_structural_model_builder.hpp>

#include <geode/geometry/point.hpp>

namespace geode
{
    void define_implicit_structural_model_builder( pybind11::module& module )
    {
        pybind11::class_< ImplicitStructuralModelBuilder,
            StructuralModelBuilder >( module, "ImplicitStructuralModelBuilder" )
            .def( pybind11::init< ImplicitStructuralModel& >() )
            .def( "copy",
                []( ImplicitStructuralModelBuilder& builder,
                    const ImplicitStructuralModel& other_model ) {
                    builder.copy( other_model );
                } )
            .def( "instantiate_implicit_attribute_on_blocks",
                &ImplicitStructuralModelBuilder::
                    instantiate_implicit_attribute_on_blocks )
            .def( "set_implicit_value",
                &ImplicitStructuralModelBuilder::set_implicit_value )
            .def( "set_horizons_stack",
                []( ImplicitStructuralModelBuilder& builder,
                    HorizonsStack3D& horizons_stack ) {
                    builder.set_horizons_stack( horizons_stack.clone() );
                } )
            .def( "set_horizon_implicit_value",
                &ImplicitStructuralModelBuilder::set_horizon_implicit_value )
            .def( "horizons_stack_builder",
                &ImplicitStructuralModelBuilder::horizons_stack_builder );
    }
} // namespace geode