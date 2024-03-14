#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>

class ShapeItem : public sf::CircleShape {
public:
    explicit ShapeItem(float r);
    explicit ShapeItem(const ShapeItem& other): ShapeItem(other.getRadius()){}

    void fly(const sf::Window &w);

private:
    std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<std::mt19937::result_type> rnd;
};

ShapeItem::ShapeItem(float r)
        : sf::CircleShape(r), dev(), rng(dev()), rnd(-45, 45) {
}

void ShapeItem::fly(const sf::Window &w) {
    auto size = w.getSize();
    auto pos = getPosition();
    int new_x = 0;
    int new_y = 0;
    do {
        new_x = static_cast<int>(pos.x) + rnd(rng);
        new_y = static_cast<int>(pos.x) + rnd(rng);
    } while (!(new_x >= 0 && new_x < size.x && new_y >= 0 && new_y < size.y));
    setPosition(new_x, new_y);
}


int main() {
    auto window = sf::RenderWindow{{500, 500}, "CMake SFML Project"};
    window.setFramerateLimit(144);

    std::vector<ShapeItem> items {
            ShapeItem(30),
            ShapeItem(55),
            ShapeItem(25),
    };

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rnd(0, 255);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                for(auto& item: items) {
                    item.setFillColor(sf::Color(rnd(rng), rnd(rng), rnd(rng)));
                    item.fly(window);
                    window.draw(item);
                }
                window.display();
                window.clear();
            }
        }
    }
}
