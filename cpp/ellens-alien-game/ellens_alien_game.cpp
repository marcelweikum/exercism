namespace targets
{
    class Alien
    {
    public:
        Alien(int x, int y)
        {
            x_coordinate = x;
            y_coordinate = y;
        }

        int get_health()
        {
            return health;
        }

        bool hit()
        {
            if (health > 0)
            {
                health -= 1;
                return true;
            }
            return false;
        }

        bool is_alive()
        {
            if (health > 0)
            {
                return true;
            }
            return false;
        }

        bool teleport(int x_new, int y_new)
        {
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }

        bool collision_detection(Alien alien)
        {
            if (alien.x_coordinate == x_coordinate || alien.y_coordinate == y_coordinate)
            {
                return true;
            }
            return false;
        }

        int x_coordinate{};
        int y_coordinate{};

    private:
        int health{3};
    };
} // namespace targets