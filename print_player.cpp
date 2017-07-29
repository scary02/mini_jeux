#include "print_player.hpp"
#include <iostream>

print_player::print_player(int nb_imgSecond, int largeurImage, int indiceImage,
			   int hauteurImage, int nbAction, int ligne)
{
  m_largeurImageSecondaire = largeurImage / nb_imgSecond;
  m_largeurImagePrint = (indiceImage * m_largeurImageSecondaire) - m_largeurImageSecondaire;

  m_hauteurImageSecondaire = hauteurImage / nbAction;
  m_hauteurImagePrint = (ligne * m_hauteurImageSecondaire) - m_hauteurImageSecondaire;
  
  m_Anim.push_back(sf::IntRect(m_largeurImagePrint, m_hauteurImagePrint,
			       m_largeurImageSecondaire, m_hauteurImageSecondaire));
  /*std::cout << "mlargeurImageprint = " << m_largeurImagePrint << std::endl << "m_hauteurImagePrint = " << m_hauteurImagePrint << std::endl;
    std::cout << "m_largeurImageSecond&ire = " << m_largeurImageSecondaire << std::endl << "m_hauteurImageSecondaire = " << m_hauteurImageSecondaire << std::endl;*/
}

std::vector<sf::IntRect>	print_player::getVector() const
{
  return m_Anim;
}

int				print_player::getLargeurImageSecondaire() const
{
  return m_largeurImageSecondaire;
}

int				print_player::getHauteurImageSecondaire() const
{
  return m_hauteurImageSecondaire;
}
