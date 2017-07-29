#include "personnage.hpp"

personnage::personnage(int hp, std::string name, std::string imgPlayer, int vitesse, int attack)
  : m_hp(hp), m_name(name), m_imgPlayer(imgPlayer), m_vitesse(vitesse), m_attack(attack)
{
  m_image.loadFromFile(m_imgPlayer); /*****************************************/
  m_texture.loadFromImage(m_image);  /* création de la texture du personnage  */
  m_sprite.setTexture(m_texture);    /*****************************************/

  m_coord_perso.x = 50;
  m_coord_perso.y = 50;
  m_sprite.setPosition(m_coord_perso);
  m_lvl = 1;
}

int		personnage::getHp() const
{
  return m_hp;
}

std::string	personnage::getName() const
{
  return m_name;
}

sf::Sprite	personnage::getSprite() const
{
  return m_sprite;
}

sf::Vector2f	personnage::getCoordPerso() const
{
  return m_coord_perso;
}

void		personnage::setSprite(std::vector<sf::IntRect> anim)
{
  m_sprite.setTextureRect(anim[0]);
}

void		personnage::setCoordPerso(sf::Vector2f coord_perso)
{
  m_coord_perso.x = coord_perso.x;
  m_coord_perso.y = coord_perso.y;
  m_sprite.setPosition(m_coord_perso);
}

int		personnage::GoDown(int HauteurImageSecondaire)
{
  if ((m_coord_perso.y + m_vitesse) < (getHeight() - HauteurImageSecondaire))
    {
      m_coord_perso.y += m_vitesse;
      setCoordPerso(m_coord_perso);
    }
  return (-1);
}

int		personnage::GoRight(int LargeurImageSecondaire)
{
  if ((m_coord_perso.x + m_vitesse) < (getWidth() - LargeurImageSecondaire))
    {
      m_coord_perso.x += m_vitesse;
      setCoordPerso(m_coord_perso);
    }
  return (-1);
}

int		personnage::GoLeft()
{
  if ((m_coord_perso.x - m_vitesse) > 0)
    {
      m_coord_perso.x -= m_vitesse;
      setCoordPerso(m_coord_perso);
    }
  return (-1);
}

int		personnage::GoUp()
{
  if ((m_coord_perso.y - m_vitesse) > 0)
    {
      m_coord_perso.y -= m_vitesse;
      setCoordPerso(m_coord_perso);
    }
  return (-1);
}

int		personnage::getVitesse() const
{
  return m_vitesse;
}

void		personnage::setVitesse(int vitesse)
{
  m_vitesse = vitesse;
}

void		personnage::setWidth(int w)
{
  m_width = w;
}

void		personnage::setHeight(int h)
{
  m_height = h;
}   

int		personnage::getHeight() const
{
  return m_height;
}

int		personnage::getWidth() const
{
  return m_width;
}

int		personnage::getLvl() const
{
  return m_lvl;
}

int		personnage::getAttack() const
{
  return m_attack;
}

void		personnage::setAttack(int attack)
{
  m_attack = attack;
}

void		personnage::setLvl(int lvl_next)
{
  m_lvl += lvl_next;
}

void		personnage::recevoirDegats(int nbDegat)
{
  m_hp -= nbDegat;
  if (m_hp < 0)
    m_hp = 0;
}

void		personnage::attack(personnage &cible)
{
  cible.recevoirDegats(m_attack);
}
