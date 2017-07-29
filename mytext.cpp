#include "mytext.hpp"

mytext::mytext(std::string champ, int size, int x, int y, sf::Color mycolor, sf::Text::Style style)
{
  if (!m_font.loadFromFile("police.ttf"))
    exit(1);
  m_text.setFont(m_font);
  m_text.setString(champ);
  m_text.setCharacterSize(size);
  m_text.setColor(mycolor);
  m_text.setStyle(style);
  m_text.setPosition(x, y);
}

sf::Text	mytext::getText() const
{
  return m_text;
}
