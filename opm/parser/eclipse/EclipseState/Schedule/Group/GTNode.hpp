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

#include <vector>

#include <opm/parser/eclipse/EclipseState/Schedule/Group/Group2.hpp>
#include <opm/parser/eclipse/EclipseState/Schedule/Well/Well2.hpp>

#ifndef GROUPTREE2
#define GROUPTREE2

namespace Opm {

class GTNode {
public:
    GTNode(const Group2& group, const GTNode* parent);

    void add_group(const GTNode& child_group);
    void add_well(const Well2& well);

    const std::vector<Well2>& wells() const;
    const std::vector<GTNode>& groups() const;
    const std::string& name() const;
    const GTNode& parent() const;
    const Group2& group() const;
private:
    const Group2 m_group;
    const GTNode * m_parent;
    /*
      Class T with a stl container <T> - supposedly undefined behavior before
      C++17 - but it compiles without warnings.
    */
    std::vector<GTNode> m_child_groups;
    std::vector<Well2> m_wells;
};

}
#endif


