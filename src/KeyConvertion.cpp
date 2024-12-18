std::string fromKtoS(const sf::Keyboard::Key& k){

    std::string ret;
    switch(k){
        case sf::Keyboard::A :
            ret="A";
            break;
        case sf::Keyboard::B :
            ret="B";
            break;
        case sf::Keyboard::C :
            ret="C";
            break;
        case sf::Keyboard::D :
            ret="D";
            break;
        case sf::Keyboard::E :
            ret="E";
            break;
        case sf::Keyboard::F :
            ret="F";
            break;
        case sf::Keyboard::G :
            ret="G";
            break;
        case sf::Keyboard::H :
            ret="H";
            break;
        case sf::Keyboard::I :
            ret="I";
            break;
        case sf::Keyboard::J :
            ret="J";
            break;
        case sf::Keyboard::K :
            ret="K";
            break;
        case sf::Keyboard::L :
            ret="L";
            break;
        case sf::Keyboard::M :
            ret="M";
            break;
        case sf::Keyboard::N :
            ret="N";
            break;
        case sf::Keyboard::O :
            ret="O";
            break;
        case sf::Keyboard::P :
            ret="P";
            break;
        case sf::Keyboard::Q :
            ret="Q";
            break;
        case sf::Keyboard::R :
            ret="R";
            break;
        case sf::Keyboard::S :
            ret="S";
            break;
        case sf::Keyboard::T :
            ret="T";
            break;
        case sf::Keyboard::U :
            ret="U";
            break;
        case sf::Keyboard::V :
            ret="V";
            break;
        case sf::Keyboard::W :
            ret="W";
            break;
        case sf::Keyboard::X :
            ret="X";
            break;
        case sf::Keyboard::Y :
            ret="Y";
            break;
        case sf::Keyboard::Z :
            ret="Z";
            break;
        case sf::Keyboard::Num0 :
            ret="Num0";
            break;
        case sf::Keyboard::Num1 :
            ret="Num1";
            break;
        case sf::Keyboard::Num2 :
            ret="Num2";
            break;
        case sf::Keyboard::Num3 :
            ret="Num3";
            break;
        case sf::Keyboard::Num4 :
            ret="Num4";
            break;
        case sf::Keyboard::Num5 :
            ret="Num5";
            break;
        case sf::Keyboard::Num6 :
            ret="Num6";
            break;
        case sf::Keyboard::Num7 :
            ret="Num7";
            break;
        case sf::Keyboard::Num8 :
            ret="Num8";
            break;
        case sf::Keyboard::Num9 :
            ret="Num9";
            break;
        case sf::Keyboard::LBracket :
            ret="LBracket";
            break;
        case sf::Keyboard::RBracket :

            ret="RBracket";
            break;
        case sf::Keyboard::SemiColon :

            ret="SemiColon";
            break;
        case sf::Keyboard::Comma :

            ret="Comma";
            break;
        case sf::Keyboard::Period :

            ret="Period";
            break;
        case sf::Keyboard::Quote :

            ret="Quote";
            break;
        case sf::Keyboard::Slash :

            ret="Slash";
            break;
        case sf::Keyboard::BackSlash :

            ret="BackSlash";
            break;
        case sf::Keyboard::Tilde :

            ret="Tilde";
            break;
        case sf::Keyboard::Equal :

            ret="Equal";
            break;
        case sf::Keyboard::Dash :

            ret="-";
            break;
        case sf::Keyboard::Space :

            ret="Space";
            break;
        case sf::Keyboard::BackSpace :

            ret="BackSpace";
            break;
        // case sf::Keyboard::Tab :

        //     ret="Tab";
        //     break;
        default:
            ret="";
            break;
        }
    return ret;
}
