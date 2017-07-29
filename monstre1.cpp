#include "monstre1.hpp"
#include "print_player.hpp"

monstre1::monstre1(sf::Vector2u size) : personnage(50, "Dragon de Feu", "monstre1.png", 1, 1)
{
  print_player                  sprit_monstre1(4, 384, 1, 384, 4, 1);
  setSprite(sprit_monstre1.getVector());

  setWidth(size.x);
  setHeight(size.y);
  
  sf::Vector2f coord;
  coord.x = 0;
  coord.y = 0;
  while (coord.x <= 120 && coord.y <= 120)
    {
      coord.x = rand() % (getWidth() - (sprit_monstre1.getLargeurImageSecondaire() + 10));
      coord.y = rand() % (getHeight() - (sprit_monstre1.getHauteurImageSecondaire() + 10));
    }
  setCoordPerso(coord);
  m_direction = rand() % 4;
}

int	monstre1::getDirection() const
{
  return m_direction;
}

void	monstre1::setDirection(int dir)
{
  m_direction = dir;
}
