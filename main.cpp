#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "mario.hpp"
#include "print_player.hpp"
#include "mytext.hpp"
#include "monstre1.hpp"

namespace patch
{
  template < typename T > std::string to_string( const T& n )
  {
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
  }
}

static int			check_impact(std::vector<std::unique_ptr<monstre1>> &vecteur_monstre1, mario &player)	// function for check impact enter monster and mario
{
  sf::Vector2f			coord_mario = player.getCoordPerso();

  for (int unsigned i=0;i<vecteur_monstre1.size();i++)
    {
      sf::Vector2f			coord_monstre1 = vecteur_monstre1[i]->getCoordPerso();
      int				x = 0, y = 0;
      
      if ((coord_mario.x - coord_monstre1.x) < 0)
        x = (coord_mario.x - coord_monstre1.x) * -1;
      else
	x = (coord_mario.x - coord_monstre1.x);
      
      if ((coord_mario.y - coord_monstre1.y) < 0)
	y = (coord_mario.y - coord_monstre1.y) * -1;
      else
	y = (coord_mario.y - coord_monstre1.y) * -1;
      
      if (x < 10 && y < 10)
	return i;
    }
  return (-1);
}

static void			mouve_monstre(std::vector<std::unique_ptr<monstre1>> &vecteur_monstre1,			// function for mouve monster
					      mario &player1, int &mouv_monstre1, sf::Clock clock, int &state, int &i)
{
  if ((rand() % (100 / player1.getLvl())) < 10)
    vecteur_monstre1[i]->setDirection(rand() % 4);
  if (vecteur_monstre1[i]->getDirection() == 0)									// if (direction == 0 ) Go Down or set new direction
    {
      print_player  sprit_monstre1(4, 384, mouv_monstre1, 384, 4, 1);
      vecteur_monstre1[i]->GoDown(sprit_monstre1.getLargeurImageSecondaire());
      vecteur_monstre1[i]->setSprite(sprit_monstre1.getVector());
    }
  else if (vecteur_monstre1[i]->getDirection() == 1)								// if (direction == 1 ) Go Up or set new direction
    {
      print_player  sprit_monstre1(4, 384, mouv_monstre1, 384, 4, 4);
      vecteur_monstre1[i]->GoUp();
      vecteur_monstre1[i]->setSprite(sprit_monstre1.getVector());
    }
  else if (vecteur_monstre1[i]->getDirection() == 2)								// if (direction == 2 ) Go Right or set new direction
    {
      print_player  sprit_monstre1(4, 384, mouv_monstre1, 384, 4, 3);
      vecteur_monstre1[i]->GoRight(sprit_monstre1.getLargeurImageSecondaire());
      vecteur_monstre1[i]->setSprite(sprit_monstre1.getVector());
    }
  else if (vecteur_monstre1[i]->getDirection() == 3)								// if (direction == 3 ) Go Left or set new direction
    {
      print_player  sprit_monstre1(4, 384, mouv_monstre1, 384, 4, 2);
      vecteur_monstre1[i]->GoLeft();
      vecteur_monstre1[i]->setSprite(sprit_monstre1.getVector());
    }
  mouv_monstre1 == 4 ? mouv_monstre1 = 1 : mouv_monstre1++;
  i++;
  if (i == vecteur_monstre1.size())
    i = 0;
}

int				main()
{
  sf::RenderWindow		window(sf::VideoMode(800, 800), "BeBar", sf::Style::Fullscreen);	// Open window
  mario				player1;								// call constructor for print mario
 
  sf::Vector2u			size = window.getSize();						// init max X Y
  player1.setWidth(size.x);
  player1.setHeight(size.y);

  srand (time(NULL));
  /************************************Loading background*************************************/
  sf::Sprite Sprite;
  sf::Image Image;
  sf::Texture texture;
  if (!Image.loadFromFile("fond.jpg"))
    return 1;
  texture.loadFromImage(Image);
  Sprite.setTexture(texture);
  Sprite.setScale(2, 2);
  /*******************************************************************************************/
 
  int				mouv_mario = 1, mouv_monstre1 = 1, state = 0, i = 0;				// Count for mouv sprite
  int				monstre_attack = 0;
  
  sf::Clock			clock;									// To declare variable for time

  mytext			text(mytext("Vies :", 30, 0, 0, sf::Color::Blue, sf::Text::Bold));	// puts text for life
  mytext			textlvl(mytext("Lvl :", 30, 0, 30, sf::Color::Blue, sf::Text::Bold));	// puts text for life
  mytext			textvitesse(mytext("vitesse :", 30, 0, 60, sf::Color::Blue, sf::Text::Bold));	// puts text for life
  
  print_player			sprit_player(4, 200, mouv_mario, 276, 4, 1);				// To declare constructor for sprite mario
  player1.setSprite(sprit_player.getVector());								// Set sprite Mario

  /***************************Monstre1*****************************/
  std::vector<std::unique_ptr<monstre1>> vecteur_monstre1;
  vecteur_monstre1.push_back(std::make_unique<monstre1>(size));
  /***************************************************************/
  while (window.isOpen())
    {
      sf::Time	time = clock.getElapsedTime();
      if (time.asSeconds() >= 60)									// all one minute up lvl
	{
	  player1.setLvl(1);
	  clock.restart();
	}
      if ((monstre_attack = (check_impact(vecteur_monstre1, player1))) != -1)				// if mario and monstre impact go attack
	vecteur_monstre1[monstre_attack]->attack(player1);
      if ((rand() % (1000 / player1.getLvl())) < 3)							// create new monster
	vecteur_monstre1.push_back(std::make_unique<monstre1>(size));
      mouve_monstre(vecteur_monstre1, player1, mouv_monstre1, clock, state, i);				// mouve monster
      sf::Event			event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !player1.getHp())
	    window.close();
	  else
	    {
	      sf::Time		time = clock.getElapsedTime();
	      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))					// mario down
		{
		  print_player	sprit_player(4, 200, mouv_mario, 276, 4, 1);
		  if (time.asMilliseconds() >= 100)
		    {
		      player1.GoDown(sprit_player.getHauteurImageSecondaire());
		      clock.restart();
		      mouv_mario == 4 ? mouv_mario = 1 : mouv_mario ++;
		    }
		  player1.setSprite(sprit_player.getVector());
		}
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))					// mario right
		{
		  print_player	sprit_player(4, 200, mouv_mario, 276, 4, 3);
		  if (time.asMilliseconds() >= 100)
		    {
		      player1.GoRight(sprit_player.getLargeurImageSecondaire());
		      mouv_mario == 4 ? mouv_mario = 1 : mouv_mario ++;
		      clock.restart();
		    }
		  player1.setSprite(sprit_player.getVector());
		}
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))					// mario left
		{
		  print_player	sprit_player(4, 200, mouv_mario, 276, 4, 2);
		  if (time.asMilliseconds() >= 100)
		    {
		      player1.GoLeft();
		      clock.restart();
		      mouv_mario == 4 ? mouv_mario = 1 : mouv_mario ++;
		    }
		  player1.setSprite(sprit_player.getVector());
		}
	      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))					// marion up
		{
		  print_player	sprit_player(4, 200, mouv_mario, 276, 4, 4);
		  if (time.asMilliseconds() >= 100)
		    {
		      player1.GoUp();
		      clock.restart();
		      mouv_mario == 4 ? mouv_mario = 1 : mouv_mario ++; 
		    }
		  player1.setSprite(sprit_player.getVector());
		}
	    }
	}
      mytext			text_hp(mytext(patch::to_string(player1.getHp()), 30, (player1.getWidth() / 6), 0, sf::Color::Blue, sf::Text::Bold));
      mytext			text_nb_lvl(mytext(patch::to_string(player1.getLvl()), 30, (player1.getWidth() / 6), 30, sf::Color::Blue, sf::Text::Bold));
      mytext			text_nb_vitesse(mytext(patch::to_string(player1.getVitesse()), 30, (player1.getWidth() / 6), 60, sf::Color::Blue, sf::Text::Bold));
      
      window.clear(sf::Color::Blue);

      window.draw(Sprite);										// Draw background
      window.draw(player1.getSprite());									// Draw Mario

      for(int unsigned i=0;i<vecteur_monstre1.size();i++)
	window.draw(vecteur_monstre1[i]->getSprite());							// Draw monstre1

      window.draw(text.getText());									// Draw life
      window.draw(textlvl.getText());									// Draw text lvl
      window.draw(text_nb_lvl.getText());								// Draw lvl
      window.draw(text_hp.getText());									// Draw Hp
      window.draw(textvitesse.getText());								// Draw vitesse
      window.draw(text_nb_vitesse.getText());								// Draw bn vitesse

      window.display();
    }
  return EXIT_SUCCESS;
}
