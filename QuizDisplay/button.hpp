#ifndef BUTTON_H
#define BUTTON_H


class Button {
public:
  //Button constructor, given pointer to image, a clicked version of the image, string of text, location
    Button (sf::Image* normal,sf::Image* clicked, std::string, sf::Vector2f location);
    void checkClick (sf::Vector2f);
    void setState(bool);
    void setText(std::string);
    bool getVar();
    sf::Sprite* getSprite();
    sf::String * getText();
private:
    sf::Sprite normal;
    sf::Sprite clicked;
    sf::Sprite* currentSpr;
    sf::String String;
    bool current;
};

Button::Button(sf::Image* normal,sf::Image* clicked,std::string words,sf::Vector2f location) {
    this->normal.SetImage(*normal);
    this->clicked.SetImage(*clicked);
    this->currentSpr=&this->normal;
    current =false;
    this->normal.SetPosition(location);
    this->clicked.SetPosition(location);
    String.SetText(words);
    String.SetPosition(location.x+3,location.y+3);
    String.SetSize(14);
}

#endif
