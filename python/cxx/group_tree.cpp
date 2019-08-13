#include <opm/parser/eclipse/EclipseState/Schedule/Group/GTNode.hpp>
#include <opm/parser/eclipse/EclipseState/Schedule/Schedule.hpp>

#include "sunbeam.hpp"
#include "converters.hpp"

namespace {

    GTNode parent( const GTNode & gt ) {
        return gt.parent();
    }

    py::list children( const GTNode & gt ) {
        return iterable_to_pylist(gt.groups()) ;
    }
}

void sunbeam::export_GroupTree(py::module& module) {

  py::class_<GTNode>(module, "GroupTree")

        .def( "name", &GTNode::name)
        .def( "_parent", &parent,                       "parent function returning parent of a group")
        .def( "_children", &children,                   "children function returning python"
                                                       " list containing children of a group")
        ;
}
