#ifndef DEFF_TEXT_HPP
# define DEFF_TEXT_HPP

#include <SFML/Graphics.hpp>

class mytext
{
public:
  mytext(std::string champ, int size, int x, int y, sf::Color myColor, sf::Text::Style style);
  sf::Text	getText() const;
private:
  sf::Text m_text;
  sf::Font m_font;
};

#endif
