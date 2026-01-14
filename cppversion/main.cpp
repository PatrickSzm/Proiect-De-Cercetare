#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "Bouncing Ball");
    sf::CircleShape ball(20.f);
    ball.setFillColor(sf::Color::Red);
    float x = 200, y = 150, dx = 3, dy = 3;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        x += dx; y += dy;
        if (x < 0 || x > 400) dx = -dx;
        if (y < 0 || y > 300) dy = -dy;
        ball.setPosition(x, y);

        window.clear();
        window.draw(ball);
	static sf::Clock fpsClock;
	static int frameCount = 0;
	frameCount++;

	if (fpsClock.getElapsedTime().asSeconds() >= 1.0f) {
    	  std::cout << "FPS: " << frameCount << std::endl;
    	  frameCount = 0;
    	  fpsClock.restart();
	}

        window.display();
        sf::sleep(sf::milliseconds(16)); // aprox. 60 FPS
    }
    return 0;
}
