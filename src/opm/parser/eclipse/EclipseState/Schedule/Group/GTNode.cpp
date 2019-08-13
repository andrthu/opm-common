/*
  Copyright 2019 Equinor ASA.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <opm/parser/eclipse/EclipseState/Schedule/Group/GTNode.hpp>

namespace Opm {

GTNode::GTNode(const Group2& group_arg, const GTNode * parent_arg) :
    m_group(group_arg),
    m_parent(parent_arg)
{}

const std::string& GTNode::name() const {
    return this->m_group.name();
}

const Group2& GTNode::group() const {
    return this->m_group;
}

const GTNode& GTNode::parent() const {
    if (this->m_parent)
        return *this->m_parent;

    throw std::invalid_argument("Tried to access parent of root in GroupTree. Root: " + this->name());
}


void GTNode::add_well(const Well2& well) {
    this->m_wells.push_back(well);
}

void GTNode::add_group(const GTNode& child_group) {
    this->m_child_groups.push_back(child_group);
}

const std::vector<Well2>& GTNode::wells() const {
    return this->m_wells;
}

const std::vector<GTNode>& GTNode::groups() const {
    return this->m_child_groups;
}


}
