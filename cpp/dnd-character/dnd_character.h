#pragma once

namespace dnd_character
{
    int ability();

    int modifier(int n);

    class Character
    {
    public:
        Character()
        {
            strength = ability();
            dexterity = ability();
            constitution = ability();
            intelligence = ability();
            wisdom = ability();
            charisma = ability();
            hitpoints = 10 + modifier(constitution);
        }

        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
        int hitpoints;
    };

} // namespace dnd_character
