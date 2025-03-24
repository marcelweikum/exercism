#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count
{

    std::map<char, int> count(std::string sequence)
    {
        std::map<char, int> dna{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

        for (char c : sequence)
        {
            if (!dna.count(c))
                throw std::invalid_argument("invalid nucleotide");
            dna[c]++;
        }
        return dna;
    }

} // namespace nucleotide_count
