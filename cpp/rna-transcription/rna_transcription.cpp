#include "rna_transcription.h"

namespace rna_transcription
{
    char to_rna(char nucleotide)
    {
        switch (nucleotide)
        {
        case 'G':
            return 'C';
            break;
        case 'C':
            return 'G';
            break;
        case 'T':
            return 'A';
            break;
        case 'A':
            return 'U';
            break;
        default:
            return '-';
        }
    }

    std::string to_rna(std::string nucleotides)
    {
        std::string rna{};

        for (char c : nucleotides)
        {
            switch (c)
            {
            case 'G':
                rna += 'C';
                break;
            case 'C':
                rna += 'G';
                break;
            case 'T':
                rna += 'A';
                break;
            case 'A':
                rna += 'U';
                break;
            }
        }
        return rna;
    }

} // namespace rna_transcription
