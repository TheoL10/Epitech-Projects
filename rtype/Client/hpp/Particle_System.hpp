#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Particle_System {
    public:
        struct Particle {
            sf::Vector2f velocity;
            int lifetime;
        };
        std::vector<Particle> _particles;
        sf::VertexArray _vertices;
        float _size;
        std::size_t _count;
        float _x;
        float _y;
        std::string _color;
        std::string _direction;
        int _lifetime;
        float _speed;
        void reset_particles();
        void reset_particle(int index, float x, float y);
        void update(float x, float y);
        Particle_System(sf::RenderWindow *windows11, std::string color, std::string direction = "center", int _count = 1024, int _size = 4, int lifetime = 60, float speed = 6);
        void run();
        sf::RenderWindow *_windows11;
};