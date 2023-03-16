#include "../hpp/Particle_System.hpp"

Particle_System::Particle_System(sf::RenderWindow *windows11, std::string color, std::string direction, int count, int size, int lifetime, float speed) {
    _count = count;
    _size = size;
    _windows11 = windows11;
    _color = color;
    _direction = direction;
    _lifetime = lifetime;
    _speed = speed;
    reset_particles();
}

void Particle_System::reset_particles() {
    _particles = std::vector<Particle>(_count);
    _vertices = sf::VertexArray(sf::Quads, _count * 4);
    for (std::size_t i = 0; i < _particles.size(); i++) {
        reset_particle(i, 0, 0);
    }
}

void Particle_System::reset_particle(int index, float x, float y) {
    _vertices[4 * index + 0].position = sf::Vector2f(x, y);
    _vertices[4 * index + 1].position = sf::Vector2f(x + _size, y);
    _vertices[4 * index + 2].position = sf::Vector2f(x + _size, y + _size);
    _vertices[4 * index + 3].position = sf::Vector2f(x, y + _size);

    sf::Color color;
    if (_color == "rainbow")
        color = sf::Color(rand() % 255, rand() % 255, rand() % 255, (rand() % 255) + 150);
    else if (_color == "fire")
        color = sf::Color(255, (rand() % 255) + 50, rand() % 30, rand() % 255 + 100);
    else if (_color == "blue")
        color = sf::Color(0, 0, 255, 255);
    else if (_color == "blue-gradient")
        color = sf::Color(rand() % 20, rand() % 20, rand() % 255, rand() % 255 + 100);
    else if (_color == "red")
        color = sf::Color(255, 0, 0, 255);
    else if (_color == "red-gradient")
        color = sf::Color(rand() % 255, rand() % 20, rand() % 20, rand() % 255 + 100);
    else if (_color == "green")
        color = sf::Color(0, 255, 0, 255);
    else if (_color == "red-gradient")
        color = sf::Color(rand() % 20, rand() % 255, rand() % 20, rand() % 255 + 100);
    for (int i = 0; i < 4; i++) {
        _vertices[4 * index + i].color = color;
    }

    sf::Vector2f position;

    if (_direction == "left")
        position = {
            static_cast<float>(rand()) / (float)RAND_MAX * _speed - (_speed + 1),
            static_cast<float>(rand()) / (float)RAND_MAX * _speed - (_speed / 2),
        };
    if (_direction == "right")
        position = {
            static_cast<float>(rand()) / (float)RAND_MAX * _speed + (_speed + 1),
            static_cast<float>(rand()) / (float)RAND_MAX * _speed + (_speed / 2),
        };
    else
        position = {
            static_cast<float>(rand()) / (float)RAND_MAX * _speed - (_speed / 2),
            static_cast<float>(rand()) / (float)RAND_MAX * _speed - (_speed / 2),
        };
    _particles[index].velocity = position;
    _particles[index].lifetime = 1 + rand() % _lifetime;

}

void Particle_System::update(float x, float y) {
    for (std::size_t i = 0; i < _particles.size(); i++) {
        if (_particles[i].lifetime > 0)
            _particles[i].lifetime--;
        else
            reset_particle(i, x, y);
        _vertices[4 * i + 0].position += _particles[i].velocity;
        _vertices[4 * i + 1].position += _particles[i].velocity;
        _vertices[4 * i + 2].position += _particles[i].velocity;
        _vertices[4 * i + 3].position += _particles[i].velocity;
    }
}

void Particle_System::run() {
    _windows11->draw(_vertices);
}