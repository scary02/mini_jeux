
#ifndef DEF_PERSONNAGE
# define DEF_PERSONNAGE

#include <SFML/Graphics.hpp>
#include <iostream>

class personnage
{
public:
  /************************CONSTRUCTOR*************************************/
  personnage(); // constructor by défault
  // constructeur two parameters the first parameters is hp and second parameters is name of perso
  personnage(int hp, std::string name, std::string imgPlayer, int vitesse, int attack);

  /************************FONCTION MEMBRE*********************************/
  int						getHp() const; // return hp
  int						getVitesse() const; // return vitesse
  void						setVitesse(int vitesse); // set vitesse
  sf::Sprite					getSprite() const; // return sprite
  std::string					getName() const; // return name
  sf::Vector2f					getCoordPerso() const; // return coord perso
  int						getWidth() const;
  int						getHeight() const;
  int						getLvl() const;
  int						getAttack() const;
  void						setAttack(int attack);
  void						setLvl(int lvl_next);
  void						setWidth(int w);
  void						setHeight(int h);
  void						setCoordPerso(sf::Vector2f coord_perso);
  void						setSprite(std::vector<sf::IntRect> anim);
  int						GoDown(int HauteurImageSecondaire);
  int						GoRight(int LargeurImageSecondaire);
  int						GoLeft();
  int						GoUp();
  void						attack(personnage & attack);
  void						recevoirDegats(int nbDegat);
private:
  int						m_hp;
  std::string					m_name;
  std::string					m_imgPlayer;
  sf::Image					m_image;
  sf::Texture					m_texture;
  sf::Sprite					m_sprite;
  sf::Vector2f					m_coord_perso;
  int						m_vitesse;
  int						m_width;
  int						m_height;
  int						m_lvl;
  int						m_attack;
};

#endif
