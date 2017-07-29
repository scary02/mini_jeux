#ifndef DEF_PRINT_SPRITE
# define DEF_PRINT_SPRITE

#include <SFML/Graphics.hpp>

class print_player
{
public:
  print_player(int nb_imgSecondaire, int largeurImage, int indiceImage,
	       int hautImage, int nbAction, int ligne);
  std::vector<sf::IntRect>	getVector() const;
  int				getLargeurImageSecondaire() const;
  int				getHauteurImageSecondaire() const;
private:
  int				m_largeurImageSecondaire;
  int				m_largeurImagePrint;
  int				m_hauteurImageSecondaire;
  int				m_hauteurImagePrint;
  std::vector<sf::IntRect>	m_Anim;
};

#endif
