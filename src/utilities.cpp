#include "utilities.hpp"

std::string sfge::keyToString(sf::Keyboard::Key key) {
	switch(key) {
		case sf::Keyboard::A: return "a";
		case sf::Keyboard::B: return "b";
		case sf::Keyboard::C: return "c";
		case sf::Keyboard::D: return "d";
		case sf::Keyboard::E: return "e";
		case sf::Keyboard::F: return "f";
		case sf::Keyboard::G: return "g";
		case sf::Keyboard::H: return "h";
		case sf::Keyboard::I: return "i";
		case sf::Keyboard::J: return "j";
		case sf::Keyboard::K: return "k";
		case sf::Keyboard::L: return "l";
		case sf::Keyboard::M: return "m";
		case sf::Keyboard::N: return "n";
		case sf::Keyboard::O: return "o";
		case sf::Keyboard::P: return "p";
		case sf::Keyboard::Q: return "q";
		case sf::Keyboard::R: return "r";
		case sf::Keyboard::S: return "s";
		case sf::Keyboard::T: return "t";
		case sf::Keyboard::U: return "u";
		case sf::Keyboard::V: return "v";
		case sf::Keyboard::W: return "w";
		case sf::Keyboard::X: return "x";
		case sf::Keyboard::Y: return "y";
		case sf::Keyboard::Z: return "z";
		case sf::Keyboard::Num0: return "0";
		case sf::Keyboard::Num1: return "1";
		case sf::Keyboard::Num2: return "2";
		case sf::Keyboard::Num3: return "3";
		case sf::Keyboard::Num4: return "4";
		case sf::Keyboard::Num5: return "5";
		case sf::Keyboard::Num6: return "6";
		case sf::Keyboard::Num7: return "7";
		case sf::Keyboard::Num8: return "8";
		case sf::Keyboard::Num9: return "9";
		case sf::Keyboard::SemiColon: return ";";
		case sf::Keyboard::Comma: return ",";
		case sf::Keyboard::Period: return ".";
		case sf::Keyboard::Quote: return "'";
		case sf::Keyboard::Slash: return "/";
		case sf::Keyboard::Dash: return "-";
		case sf::Keyboard::Space: return " ";
		case sf::Keyboard::Tab: return "\t";
		case sf::Keyboard::Add: return "+";
		case sf::Keyboard::Subtract: return "-";
		case sf::Keyboard::Multiply: return "*";
		case sf::Keyboard::Divide: return "/";
		default: return "";
	}
}
