#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <optional>

struct Kontak { std::string nama, nomer, email; };
std::vector<Kontak> daftarKontak;

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Window"); 
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        // Handle error
    }


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            }
        }

        window.clear();
        window.display();
    }
    return 0;
}