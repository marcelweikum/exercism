#include "protein_translation.h"

#include <unordered_map>

namespace protein_translation
{

    std::vector<std::string> proteins(std::string sequence)
    {
        std::string actual_codon{};
        std::vector<std::string> result{};
        std::unordered_map<std::string, std::string> codons{
            {"AUG", "Methionine"},
            {"UUU", "Phenylalanine"},
            {"UUC", "Phenylalanine"},
            {"UUA", "Leucine"},
            {"UUG", "Leucine"},
            {"UCU", "Serine"},
            {"UCC", "Serine"},
            {"UCA", "Serine"},
            {"UCG", "Serine"},
            {"UAU", "Tyrosine"},
            {"UAC", "Tyrosine"},
            {"UGU", "Cysteine"},
            {"UGC", "Cysteine"},
            {"UGG", "Tryptophan"},
            {"UAA", "STOP"},
            {"UAG", "STOP"},
            {"UGA", "STOP"}};

        for (size_t i{}; i < sequence.size(); i += 3)
        {
            actual_codon = sequence.substr(i, 3);
            if (codons.find(actual_codon) != codons.end())
            {
                std::string protein = codons[actual_codon];
                if (protein == "STOP")
                {
                    break;
                }
                result.push_back(protein);
            }
        }
        return result;
    }

} // namespace protein_translation
