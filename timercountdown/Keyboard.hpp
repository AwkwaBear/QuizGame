#ifndef SFML_KEYBOARD_HPP
 #define SFML_KEYBOARD_HPP

// Headers
 #include <SFML/Window/Export.hpp>

 namespace sf
 {
 class SFML_WINDOW_API Keyboard
 {
 public:

   enum Key
   {  Num0
      Num1,
      Num2,
      Num3,
      Num4
  };
  static bool isKeyPressed(Key key);
  };
}

#endif // SFML_KEYBOARD_HPP
