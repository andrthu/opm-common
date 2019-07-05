/*
   Copyright 2019 Equinor ASA.

   This file is part of the Open Porous Media project (OPM).

   OPM is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   OPM is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with OPM.  If not, see <http://www.gnu.org/licenses/>.
   */

#ifndef OPM_IO_ERST_HPP
#define OPM_IO_ERST_HPP

#include <opm/io/eclipse/EclFile.hpp>

#include <ios>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace Opm { namespace EclIO { namespace OutputStream {
    class Restart;
}}}

namespace Opm { namespace EclIO {

class ERst : public EclFile
{
public:
    explicit ERst(const std::string& filename);
    bool hasReportStepNumber(int number) const;

    void loadReportStepNumber(int number);

    template <typename T>
    const std::vector<T>& getRst(const std::string& name, int reportStepNumber);

    const std::vector<int>& listOfReportStepNumbers() const { return seqnum; }

    std::vector<EclEntry> listOfRstArrays(int reportStepNumber);

    friend class OutputStream::Restart;

private:
    int nReports;
    std::vector<int> seqnum;                           // report step numbers, from SEQNUM array in restart file
    std::unordered_map<int,bool> reportLoaded;
    std::map<int, std::pair<int,int>> arrIndexRange;   // mapping report step number to array indeces (start and end)

    void initUnified();
    void initSeparate(const int number);

    int getArrayIndex(const std::string& name, int seqnum) const;

    std::streampos
    restartStepWritePosition(const int seqnumValue) const;
};

}} // namespace Opm::EclIO

#endif // OPM_IO_ERST_HPP
