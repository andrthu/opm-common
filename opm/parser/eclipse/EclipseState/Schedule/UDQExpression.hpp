/*
  Copyright 2018 Statoil ASA.

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


#ifndef UDQ_EXPRESSION_HPP_
#define UDQ_EXPRESSION_HPP_

#include <vector>

#include <opm/parser/eclipse/Deck/DeckRecord.hpp>


namespace Opm {

    enum class UDQAction {ASSIGN, DEFINE, UNITS, UPDATE};


    class UDQExpression {
    public:
        UDQExpression(const std::string& action, const std::string& keyword, const std::vector<std::string>& data);
        explicit UDQExpression(const DeckRecord& expression);
        const std::vector<std::string>& tokens() const;
        UDQAction action() const;
        const std::string& keyword() const;
        static UDQAction actionString2Enum(const std::string& action_string);
    private:
        UDQAction m_action;
        std::string m_keyword;
        std::vector<std::string> data;
    };
}



#endif
