#ifndef DEFF_MONSTRE1_HPP
# define DEFF_MONSTRE1_HPP

#include "personnage.hpp"

class monstre1 : public personnage
{
public:
  monstre1(sf::Vector2u size);
  void	mouve();
  int	getDirection() const;
  void	setDirection(int dir);
  void	attack_feu(int hp);
private:
  int	m_rand;
  int	m_direction;
};

#endif
