#include <iostream>
#include <SFML/Graphics.hpp>

#include "Textbox.h"
#include "Button.h"

void FirstWindow(sf::RenderWindow *window, sf::Font arial,sf::Sprite FirstFonSprite,std::string *name, std::string *gender,std::string *height,std::string *weight, std::string *age){
    window->create(sf::VideoMode(640, 480), "SFML Project", sf::Style::Fullscreen);
    window->setKeyRepeatEnabled(true);

    Textbox textbox_name(15, sf::Color::White, false);
    textbox_name.setFont(arial);
    textbox_name.setPosition({290, 220});
    textbox_name.setLimit(true, 10);//лимит на ввод символов

    Textbox textbox_gender(15, sf::Color::White, false);
    textbox_gender.setFont(arial);
    textbox_gender.setPosition({345, 270});
    textbox_gender.setLimit(true, 1);


    Textbox textbox_height(15, sf::Color::White, false);
    textbox_height.setFont(arial);
    textbox_height.setPosition({295, 320});
    textbox_height.setLimit(true, 3);

    Textbox textbox_weight(15, sf::Color::White, false);
    textbox_weight.setFont(arial);
    textbox_weight.setPosition({295, 370});
    textbox_weight.setLimit(true, 3);

    Textbox textbox_age(15, sf::Color::White, false);
    textbox_age.setFont(arial);
    textbox_age.setPosition({275, 420});
    textbox_age.setLimit(true, 3);


    //button
    Button btn_name("Enter", {50, 20}, 10, sf::Color::Green, sf::Color::Black);
    btn_name.setPosition({400, 220}, -13, -8);
    btn_name.setFont(arial);

    Button btn_gender("Enter", {50, 20}, 10, sf::Color::Green, sf::Color::Black);
    btn_gender.setPosition({400, 270}, -13, -8);
    btn_gender.setFont(arial);

    Button btn_height("Enter", {50, 20}, 10, sf::Color::Green, sf::Color::Black);
    btn_height.setPosition({400, 320}, -13, -8);
    btn_height.setFont(arial);

    Button btn_weight("Enter", {50, 20}, 10, sf::Color::Green, sf::Color::Black);
    btn_weight.setPosition({400, 370}, -13, -8);
    btn_weight.setFont(arial);

    Button btn_age("Enter", {50, 20}, 10, sf::Color::Green, sf::Color::Black);
    btn_age.setPosition({400, 420}, -13, -8);
    btn_age.setFont(arial);

    //выведем текст на экран
    sf::Text text("Welcome to our Diet.app", arial);
    text.setCharacterSize(30);
    text.setColor(sf::Color::White);
    text.setPosition({150, 150});
    text.setStyle(sf::Text::Bold);

    sf::Text text_name("Enter your name:", arial);
    text_name.setCharacterSize(15);
    text_name.setColor(sf::Color::White);
    text_name.setPosition({170, 220});

    sf::Text text_gender("Enter your gender (m/f/o):", arial);
    text_gender.setCharacterSize(15);
    text_gender.setColor(sf::Color::White);
    text_gender.setPosition({170, 270});

    sf::Text text_height("Enter your height:", arial);
    text_height.setCharacterSize(15);
    text_height.setColor(sf::Color::White);
    text_height.setPosition({170, 320});

    sf::Text text_weight("Enter your weight:", arial);
    text_weight.setCharacterSize(15);
    text_weight.setColor(sf::Color::White);
    text_weight.setPosition({170, 370});

    sf::Text text_age("Enter your age:", arial);
    text_age.setCharacterSize(15);
    text_age.setColor(sf::Color::White);
    text_age.setPosition({170, 420});

    //Main Loop:
    while (window->isOpen()) {
        sf::Event Event;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            textbox_name.setSelected(true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window->close();
        }
        //Event Loop:
        while (window->pollEvent(Event)) {
            switch (Event.type) {
                case sf::Event::Closed:
                    window->close();
                case sf::Event::TextEntered:
                    textbox_name.typedOn(Event);
                    textbox_gender.typedOn(Event);
                    textbox_height.typedOn(Event);
                    textbox_weight.typedOn(Event);
                    textbox_age.typedOn(Event);
                    break;
                case sf::Event::MouseMoved:
                    if (btn_name.isMouseOver(*window)) {
                        btn_name.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_name.setBackColor(sf::Color::Green);
                    }
                    if (btn_gender.isMouseOver(*window)) {
                        btn_gender.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_gender.setBackColor(sf::Color::Green);
                    }
                    if (btn_height.isMouseOver(*window)) {
                        btn_height.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_height.setBackColor(sf::Color::Green);
                    }
                    if (btn_weight.isMouseOver(*window)) {
                        btn_weight.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_weight.setBackColor(sf::Color::Green);
                    }
                    if (btn_age.isMouseOver(*window)) {
                        btn_age.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_age.setBackColor(sf::Color::Green);
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (btn_name.isMouseOver(*window)) {
                        *name=textbox_name.getText();
                        textbox_name.setSelected(false);
                        textbox_gender.setSelected(true);
                    }
                    if (btn_gender.isMouseOver(*window)) {
                        *gender=textbox_gender.getText();
                        textbox_gender.setSelected(false);
                        textbox_height.setSelected(true);
                    }
                    if (btn_height.isMouseOver(*window)) {
                        *height=textbox_height.getText();
                        textbox_height.setSelected(false);
                        textbox_weight.setSelected(true);
                    }
                    if (btn_weight.isMouseOver(*window)) {
                        *weight=textbox_weight.getText();
                        textbox_weight.setSelected(false);
                        textbox_age.setSelected(true);
                    }
                    if (btn_age.isMouseOver(*window)) {
                        *age=textbox_age.getText();
                        window->close();
                    }
                    break;
            }
        }
        window->clear();
        window->draw(FirstFonSprite);
        window->draw(text);
        window->draw(text_name);
        window->draw(text_gender);
        window->draw(text_height);
        window->draw(text_weight);
        window->draw(text_age);
        textbox_name.drawTo(*window);
        textbox_gender.drawTo(*window);
        textbox_height.drawTo(*window);
        textbox_weight.drawTo(*window);
        textbox_age.drawTo(*window);
        btn_name.drawTo(*window);
        btn_gender.drawTo(*window);
        btn_height.drawTo(*window);
        btn_weight.drawTo(*window);
        btn_age.drawTo(*window);
        window->display();
    }
}

void SecondWindow(sf::RenderWindow *window, sf::Font arial,sf::Sprite FirstFonSprite){

    window->create(sf::VideoMode(640, 480), "SFML Project", sf::Style::Fullscreen);
    window->setKeyRepeatEnabled(true);

    sf::Text text_congratulate("CONGRATULATIONS!!!", arial);
    text_congratulate.setCharacterSize(30);
    text_congratulate.setColor(sf::Color::Green);
    text_congratulate.setPosition({150, 150});
    text_congratulate.setStyle(sf::Text::Bold);

    sf::Text text_registration("You have successfully registered", arial);
    text_registration.setCharacterSize(30);
    text_registration.setColor(sf::Color::Green);
    text_registration.setPosition({80, 230});
    text_registration.setStyle(sf::Text::Bold);

    sf::Text text_continue("Press the button to continue",arial);
    text_continue.setCharacterSize(15);
    text_continue.setColor(sf::Color::White);
    text_continue.setPosition({220, 340});

    Button btn_continue("Continue", {100, 30}, 20, sf::Color::Green, sf::Color::Black);
    btn_continue.setPosition({260, 370}, -40, -12);
    btn_continue.setFont(arial);

    while (window->isOpen()) {
        sf::Event Event;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window->close();
        }
        while (window->pollEvent(Event)) {
            switch (Event.type) {
                case sf::Event::Closed:
                    window->close();
                case sf::Event::MouseMoved:
                    if (btn_continue.isMouseOver(*window)) {
                        btn_continue.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_continue.setBackColor(sf::Color::Green);
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (btn_continue.isMouseOver(*window)) {
                        window->close();
                    }
                    break;
            }
        }
        window->clear();
        window->draw(FirstFonSprite);
        window->draw(text_congratulate);
        window->draw(text_registration);
        window->draw(text_continue);
        btn_continue.drawTo(*window);
        window->display();

    }
}

void DietWindow(sf::RenderWindow *window, sf::Font arial,sf::Vector2f targetSize,std::string & diet, std::string *res){
    window->create(sf::VideoMode(640, 480), "SFML Project", sf::Style::Fullscreen);
    window->setKeyRepeatEnabled(true);
    arial.loadFromFile("../arial.ttf");
    //Фон
    sf::Texture SecondFonTexture;
    SecondFonTexture.loadFromFile("C:/Users/User/CLionProjects/Front1/Images/SecondFon.jpg");

    sf::Sprite SecondFonSprite;
    SecondFonSprite.setTexture(SecondFonTexture);
    SecondFonSprite.setPosition(-140, -100);
    SecondFonSprite.setScale(targetSize.x / SecondFonSprite.getLocalBounds().width,
                             targetSize.y / SecondFonSprite.getLocalBounds().height);
    //Text

    sf::Text text_resul_analysis(*res,arial);
    text_resul_analysis.setCharacterSize(20);
    text_resul_analysis.setColor(sf::Color::Black);
    text_resul_analysis.setPosition({230, 130});

    sf::Text text_HealthyWeightDiet("- HealthyWeightDiet",arial);
    text_HealthyWeightDiet.setCharacterSize(20);
    text_HealthyWeightDiet.setColor(sf::Color::Black);
    text_HealthyWeightDiet.setPosition({230, 250});

    sf::Text text_WeightGainDiet("- WeightGainDiet",arial);
    text_WeightGainDiet.setCharacterSize(20);
    text_WeightGainDiet.setColor(sf::Color::Black);
    text_WeightGainDiet.setPosition({230, 300});

    sf::Text text_PersonalDiet("- PersonalDiet",arial);
    text_PersonalDiet.setCharacterSize(20);
    text_PersonalDiet.setColor(sf::Color::Black);
    text_PersonalDiet.setPosition({230, 350});

    //Buttons
    Button btn_WeightLossDiet("- WeightLossDiet", {200, 30}, 20, sf::Color::Green, sf::Color::Black);
    btn_WeightLossDiet.setPosition({230, 200}, -100, -10);
    btn_WeightLossDiet.setFont(arial);

    Button btn_HealthyWeightDiet("- HealthyWeightDiet", {200, 30}, 20, sf::Color::Green, sf::Color::Black);
    btn_HealthyWeightDiet.setPosition({230, 250}, -100, -10);
    btn_HealthyWeightDiet.setFont(arial);

    Button btn_WeightGainDiet("- WeightGainDiet", {200, 30}, 20, sf::Color::Green, sf::Color::Black);
    btn_WeightGainDiet.setPosition({230, 300}, -100, -10);
    btn_WeightGainDiet.setFont(arial);

    Button btn_PersonalDiet("- PersonalDiet", {200, 30}, 20, sf::Color::Green, sf::Color::Black);
    btn_PersonalDiet.setPosition({230, 350}, -100, -10);
    btn_PersonalDiet.setFont(arial);

    while (window->isOpen()) {
        sf::Event Event;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window->close();
        }
        while (window->pollEvent(Event)) {
            switch (Event.type) {
                case sf::Event::Closed:
                    window->close();
                case sf::Event::MouseMoved:
                    if (btn_WeightLossDiet.isMouseOver(*window)) {
                        btn_WeightLossDiet.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_WeightLossDiet.setBackColor(sf::Color::Green);
                    }
                    if (btn_HealthyWeightDiet.isMouseOver(*window)) {
                        btn_HealthyWeightDiet.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_HealthyWeightDiet.setBackColor(sf::Color::Green);
                    }
                    if (btn_WeightGainDiet.isMouseOver(*window)) {
                        btn_WeightGainDiet.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_WeightGainDiet.setBackColor(sf::Color::Green);
                    }
                    if (btn_PersonalDiet.isMouseOver(*window)) {
                        btn_PersonalDiet.setBackColor(sf::Color::White);
                    }
                    else {
                        btn_PersonalDiet.setBackColor(sf::Color::Green);
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (btn_WeightLossDiet.isMouseOver(*window)) {
                        diet="WeightLossDiet";
                        window->close();
                    }
                    if (btn_HealthyWeightDiet.isMouseOver(*window)) {
                        diet="HealthyWeightDiet";
                        window->close();
                    }
                    if (btn_WeightGainDiet.isMouseOver(*window)) {
                        diet="WeightGainDiet";
                        window->close();
                    }
                    if (btn_PersonalDiet.isMouseOver(*window)) {
                        diet="PersonalDiet";
                        window->close();
                    }
                    break;
            }
        }
        window->clear();
        window->draw(SecondFonSprite);
        window->draw(text_resul_analysis);
        window->draw(text_PersonalDiet);
        btn_WeightLossDiet.drawTo(*window);
        btn_HealthyWeightDiet.drawTo(*window);
        btn_WeightGainDiet.drawTo(*window);
        btn_PersonalDiet.drawTo(*window);
        window->display();
    }
}

void MenuWindow(sf::RenderWindow *window, sf::Font arial,sf::Vector2f targetSize,std::string *name, std::string *gender,std::string *height,std::string *weight, std::string *diet,std::string *calories,std::string *age, bool  *change_Diet, bool *close){
    window->create(sf::VideoMode(640, 480), "SFML Project", sf::Style::Fullscreen);
    window->setKeyRepeatEnabled(true);

    sf::Texture MenuFonTexture;
    MenuFonTexture.loadFromFile("C:/Users/User/CLionProjects/Front1/Images/MenuFon.jpg");

    sf::Sprite MenuFonSprite;
    MenuFonSprite.setTexture(MenuFonTexture);
    MenuFonSprite.setPosition(-140, -500);
    MenuFonSprite.setScale(targetSize.x / MenuFonSprite.getLocalBounds().width,
                           targetSize.y / MenuFonSprite.getLocalBounds().height);

    sf::Text text_info(" Your profile information:", arial);
    text_info.setCharacterSize(20);
    text_info.setColor(sf::Color::White);
    text_info.setPosition({280, 80});

    sf::Text text_calculate("Calculate calories", arial);
    text_calculate.setCharacterSize(20);
    text_calculate.setColor(sf::Color::White);
    text_calculate.setPosition({320, 320});

    //info text
    sf::Text text_Hello("Hello,", arial);
    text_Hello.setCharacterSize(25);
    text_Hello.setColor(sf::Color::White);
    text_Hello.setPosition({270, 30});
    text_Hello.setStyle(sf::Text::Bold);

    sf::Text text_Name(*name, arial);
    text_Name.setCharacterSize(25);
    text_Name.setColor(sf::Color::White);
    text_Name.setPosition({350, 30});
    text_Name.setStyle(sf::Text::Bold);

    sf::Text text_Gender("Gender:", arial);
    text_Gender.setCharacterSize(20);
    text_Gender.setColor(sf::Color::White);
    text_Gender.setPosition({320, 120});

    sf::Text text_Gender_info(*gender, arial);
    text_Gender_info.setCharacterSize(20);
    text_Gender_info.setColor(sf::Color::White);
    text_Gender_info.setPosition({400, 120});

    sf::Text text_Height("Height:", arial);
    text_Height.setCharacterSize(20);
    text_Height.setColor(sf::Color::White);
    text_Height.setPosition({320, 150});

    sf::Text text_Height_info(*height, arial);
    text_Height_info.setCharacterSize(20);
    text_Height_info.setColor(sf::Color::White);
    text_Height_info.setPosition({400, 150});

    sf::Text text_Weight("Weight:", arial);
    text_Weight.setCharacterSize(20);
    text_Weight.setColor(sf::Color::White);
    text_Weight.setPosition({320, 180});

    sf::Text text_Weight_info(*weight, arial);
    text_Weight_info.setCharacterSize(20);
    text_Weight_info.setColor(sf::Color::White);
    text_Weight_info.setPosition({400, 180});

    sf::Text text_age("Age:", arial);
    text_age.setCharacterSize(20);
    text_age.setColor(sf::Color::White);
    text_age.setPosition({320, 210});

    sf::Text text_age_info(*age, arial);
    text_age_info.setCharacterSize(20);
    text_age_info.setColor(sf::Color::White);
    text_age_info.setPosition({370, 210});

    sf::Text text_Diet("Diet:", arial);
    text_Diet.setCharacterSize(20);
    text_Diet.setColor(sf::Color::White);
    text_Diet.setPosition({320, 240});

    sf::Text text_Diet_info(*diet, arial);
    text_Diet_info.setCharacterSize(20);
    text_Diet_info.setColor(sf::Color::White);
    text_Diet_info.setPosition({370, 240});

    sf::Text text_function("Calories:", arial);
    text_function.setCharacterSize(25);
    text_function.setColor(sf::Color::White);
    text_function.setPosition({370, 285});

    sf::Text text_function_info(*calories, arial);
    text_function_info.setCharacterSize(20);
    text_function_info.setColor(sf::Color::White);
    text_function_info.setPosition({480, 290});

    //Button
    Button btn_change_Name("CHANGE", {70, 20}, 10, sf::Color::White, sf::Color::Black);
    btn_change_Name.setPosition({450, 35}, -20, -5);
    btn_change_Name.setFont(arial);

    Button btn_change_Gender("CHANGE", {70, 20}, 10, sf::Color::White, sf::Color::Black);
    btn_change_Gender.setPosition({450, 120}, -20, -5);
    btn_change_Gender.setFont(arial);

    Button btn_change_Height("CHANGE", {70, 20}, 10, sf::Color::White, sf::Color::Black);
    btn_change_Height.setPosition({450, 150}, -20, -5);
    btn_change_Height.setFont(arial);

    Button btn_change_Weight("CHANGE", {70, 20}, 10, sf::Color::White, sf::Color::Black);
    btn_change_Weight.setPosition({450, 180}, -20, -5);
    btn_change_Weight.setFont(arial);

    Button btn_change_age("CHANGE", {70, 20}, 10, sf::Color::White, sf::Color::Black);
    btn_change_age.setPosition({450, 210}, -20, -5);
    btn_change_age.setFont(arial);

    Button btn_change_Diet("CHANGE", {70, 20}, 10, sf::Color::White, sf::Color::Black);
    btn_change_Diet.setPosition({550, 240}, -20, -5);
    btn_change_Diet.setFont(arial);

    Button btn_confirm_Name("CONFIRM", {50, 13}, 10, sf::Color::White, sf::Color::Black);
    btn_confirm_Name.setPosition({580, 10}, -22, -6);
    btn_confirm_Name.setFont(arial);

    Button btn_confirm_Gender("CONFIRM", {50, 13}, 10, sf::Color::White, sf::Color::Black);
    btn_confirm_Gender.setPosition({580, 120}, -22, -6);
    btn_confirm_Gender.setFont(arial);

    Button btn_confirm_Height("CONFIRM", {50, 13}, 10, sf::Color::White, sf::Color::Black);
    btn_confirm_Height.setPosition({580, 150}, -22, -6);
    btn_confirm_Height.setFont(arial);

    Button btn_confirm_Weight("CONFIRM", {50, 13}, 10, sf::Color::White, sf::Color::Black);
    btn_confirm_Weight.setPosition({580, 180}, -22, -6);
    btn_confirm_Weight.setFont(arial);

    Button btn_confirm_age("CONFIRM", {50, 13}, 10, sf::Color::White, sf::Color::Black);
    btn_confirm_age.setPosition({580, 210}, -22, -6);
    btn_confirm_age.setFont(arial);

    Button btn_calculate_calories("Calculate calories", {200, 50}, 25, sf::Color::White, sf::Color::Black);
    btn_calculate_calories.setPosition({350, 320}, -100, -20);
    btn_calculate_calories.setFont(arial);

    Button btn_calculate("Calculate ", {100, 30}, 20, sf::Color::White, sf::Color::Black);
    btn_calculate.setPosition({400, 430}, -40, -15);
    btn_calculate.setFont(arial);

    //TextBox
    Textbox textbox_name(15, sf::Color::White, false);
    textbox_name.setFont(arial);
    textbox_name.setPosition({530,35});
    textbox_name.setLimit(true, 10);//лимит на ввод символов

    Textbox textbox_gender(15, sf::Color::White, false);
    textbox_gender.setFont(arial);
    textbox_gender.setPosition({530,120});
    textbox_gender.setLimit(true, 1);

    Textbox textbox_height(15, sf::Color::White, false);
    textbox_height.setFont(arial);
    textbox_height.setPosition({530,150});
    textbox_height.setLimit(true, 3);

    Textbox textbox_weight(15, sf::Color::White, false);
    textbox_weight.setFont(arial);
    textbox_weight.setPosition({530,180});
    textbox_weight.setLimit(true, 3);

    Textbox textbox_age(15, sf::Color::White, false);
    textbox_age.setFont(arial);
    textbox_age.setPosition({530,210});
    textbox_age.setLimit(true, 3);

    Textbox textbox_calculate(20, sf::Color::White, false);
    textbox_calculate.setFont(arial);
    textbox_calculate.setPosition({420,380});
    textbox_calculate.setLimit(true, 4);

    bool change_name= false;
    bool change_gender= false;
    bool change_height= false;
    bool change_weight= false;
    bool change_calories= false;
    bool change_age= false;

    while (window->isOpen()) {
        sf::Event Event;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window->close();
            *close= true;

        }
        while (window->pollEvent(Event)) {
            switch (Event.type) {
                case sf::Event::Closed:
                    window->close();
                case sf::Event::TextEntered:
                    textbox_name.typedOn(Event);
                    textbox_gender.typedOn(Event);
                    textbox_height.typedOn(Event);
                    textbox_weight.typedOn(Event);
                    textbox_age.typedOn(Event);
                    textbox_calculate.typedOn(Event);
                    break;
                case sf::Event::MouseMoved:
                    if (btn_change_Name.isMouseOver(*window)) {
                        btn_change_Name.setBackColor(sf::Color::Cyan);
                    } else {
                        btn_change_Name.setBackColor(sf::Color::White);
                    }
                    if (btn_change_Gender.isMouseOver(*window)) {
                        btn_change_Gender.setBackColor(sf::Color::Cyan);
                    } else {
                        btn_change_Gender.setBackColor(sf::Color::White);
                    }
                    if (btn_change_Height.isMouseOver(*window)) {
                        btn_change_Height.setBackColor(sf::Color::Cyan);
                    } else {
                        btn_change_Height.setBackColor(sf::Color::White);
                    }
                    if (btn_change_Weight.isMouseOver(*window)) {
                        btn_change_Weight.setBackColor(sf::Color::Cyan);
                    } else {
                        btn_change_Weight.setBackColor(sf::Color::White);
                    }
                    if (btn_change_age.isMouseOver(*window)) {
                        btn_change_age.setBackColor(sf::Color::Cyan);
                    } else {
                        btn_change_age.setBackColor(sf::Color::White);
                    }
                    if (btn_change_Diet.isMouseOver(*window)) {
                        btn_change_Diet.setBackColor(sf::Color::Cyan);
                    } else {
                        btn_change_Diet.setBackColor(sf::Color::White);
                    }
                    if (btn_confirm_Name.isMouseOver(*window)) {
                        btn_confirm_Name.setBackColor(sf::Color::Red);
                    } else {
                        btn_confirm_Name.setBackColor(sf::Color::White);
                    }
                    if (btn_confirm_Gender.isMouseOver(*window)) {
                        btn_confirm_Gender.setBackColor(sf::Color::Red);
                    } else {
                        btn_confirm_Gender.setBackColor(sf::Color::White);
                    }
                    if (btn_confirm_Height.isMouseOver(*window)) {
                        btn_confirm_Height.setBackColor(sf::Color::Red);
                    } else {
                        btn_confirm_Height.setBackColor(sf::Color::White);
                    }
                    if (btn_confirm_Weight.isMouseOver(*window)) {
                        btn_confirm_Weight.setBackColor(sf::Color::Red);
                    } else {
                        btn_confirm_Weight.setBackColor(sf::Color::White);
                    }
                    if (btn_confirm_age.isMouseOver(*window)) {
                        btn_confirm_age.setBackColor(sf::Color::Red);
                    } else {
                        btn_confirm_age.setBackColor(sf::Color::White);
                    }
                    if (btn_calculate_calories.isMouseOver(*window)) {
                        btn_calculate_calories.setBackColor(sf::Color::Cyan);
                    } else {
                        btn_calculate_calories.setBackColor(sf::Color::White);
                    }
                    if (btn_calculate.isMouseOver(*window)) {
                        btn_calculate.setBackColor(sf::Color::Red);
                    } else {
                        btn_calculate.setBackColor(sf::Color::White);
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (btn_change_Name.isMouseOver(*window)) {
                        textbox_name.setSelected(true);
                        change_name = true;
                    }
                    if (btn_confirm_Name.isMouseOver(*window) && change_name) {
                        *name = textbox_name.getText();
                        window->close();
                    }
                    if (btn_change_Gender.isMouseOver(*window)) {
                        textbox_gender.setSelected(true);
                        change_gender = true;
                    }
                    if (btn_confirm_Gender.isMouseOver(*window) && change_gender) {
                        *gender = textbox_gender.getText();
                        window->close();
                    }
                    if (btn_change_Height.isMouseOver(*window)) {
                        textbox_height.setSelected(true);
                        change_height = true;
                    }
                    if (btn_confirm_Height.isMouseOver(*window) && change_height) {
                        *height = textbox_height.getText();
                        window->close();
                    }
                    if (btn_change_Weight.isMouseOver(*window)) {
                        textbox_weight.setSelected(true);
                        change_weight = true;
                    }
                    if (btn_confirm_Weight.isMouseOver(*window) && change_weight) {
                        *weight = textbox_weight.getText();
                        window->close();
                    }
                    if (btn_change_age.isMouseOver(*window)) {
                        textbox_age.setSelected(true);
                        change_age = true;
                    }
                    if (btn_confirm_age.isMouseOver(*window) && change_age) {
                        *age = textbox_age.getText();
                        window->close();
                    }
                    if(btn_change_Diet.isMouseOver(*window)){
                        *change_Diet= true;
                        window->close();
                    }
                    if(btn_calculate_calories.isMouseOver(*window)){
                        textbox_calculate.setSelected(true);
                        change_calories= true;
                    }
                    if (btn_calculate.isMouseOver(*window) && change_calories) {
                        *calories = std::to_string(((stoi(*calories)-stoi(textbox_calculate.getText()))));
                        window->close();
                        break;
                    }
            }
            window->clear();
            window->draw(MenuFonSprite);
            btn_change_Name.drawTo(*window);
            btn_change_Gender.drawTo(*window);
            btn_change_Height.drawTo(*window);
            btn_change_Weight.drawTo(*window);
            btn_change_age.drawTo(*window);
            btn_change_Diet.drawTo(*window);
            btn_confirm_Name.drawTo(*window);
            btn_confirm_Gender.drawTo(*window);
            btn_confirm_Height.drawTo(*window);
            btn_confirm_Weight.drawTo(*window);
            btn_confirm_age.drawTo(*window);
            btn_calculate_calories.drawTo(*window);
            btn_calculate.drawTo(*window);
            window->draw(text_Hello);
            window->draw(text_Name);
            window->draw(text_info);
            window->draw(text_Gender);
            window->draw(text_Gender_info);
            window->draw(text_Height);
            window->draw(text_Height_info);
            window->draw(text_Weight);
            window->draw(text_Weight_info);
            window->draw(text_age);
            window->draw(text_age_info);
            window->draw(text_Diet);
            window->draw(text_Diet_info);
            window->draw(text_function);
            window->draw(text_function_info);
            textbox_name.drawTo(*window);
            textbox_gender.drawTo(*window);
            textbox_height.drawTo(*window);
            textbox_weight.drawTo(*window);
            textbox_age.drawTo(*window);
            textbox_calculate.drawTo(*window);
            window->display();
        }
    }
}

std::string  result(std::string *weight, std::string *height){
    float weightPercentage = static_cast<float>(stoi(*weight)) / stoi(*height) * 100;
    if (weightPercentage >= 55) {
        return "Sadly, you are fat :( ";
    }
    else if (weightPercentage <= 45) {
        return "Sadly, you are skinny :( ";
    }
    else if ((weightPercentage > 45) && (weightPercentage < 55)) {
        return  "Wow! You have healthy weight! :) ";
    }
}

std::string calculateCalories (std::string *height,std::string *weight,std::string *age,std::string *diet) {
        double calories = 100*((stoi(*weight) * 10 + stoi(*height) * 6, 25 - stoi(*age)) * 5) * 1.4;
        if (*diet == "WeightGainDiet") {
            calories *= 1.3;
            return std::to_string(int(calories));
        }
        if (*diet == "WeightLossDiet") {
            calories*=0.7;
            return std::to_string(int(calories));
        }
        if (*diet == "HealthyWeightDiet") {
            return std::to_string(int(calories*-1));
        }
}

int main() {
    std::string age;
    std::string name;
    std::string gender;
    std::string height;
    std::string weight;
    std::string diet;
    bool change_Diet= false;
    bool close= false;

    sf::RenderWindow window;
    sf::Vector2f targetSize(900.0f, 1200.0f);
    sf::Font arial;
    arial.loadFromFile("../arial.ttf");
    sf::Texture FirstFonTexture;
    FirstFonTexture.loadFromFile("C:/Users/User/CLionProjects/Front1/Images/FirstFon.jpg");

    sf::Sprite FirstFonSprite;
    FirstFonSprite.setTexture(FirstFonTexture);
    FirstFonSprite.setPosition(-100, -200);
    FirstFonSprite.setScale(targetSize.x / FirstFonSprite.getLocalBounds().width,
                            targetSize.y / FirstFonSprite.getLocalBounds().height);

    //|||||||||||||||||MAIN LOOP|||||||||||||||
    FirstWindow(&window,arial,FirstFonSprite,&name,&gender,&height,&weight,&age);
    SecondWindow(&window,arial,FirstFonSprite);
    std::string res= result(&weight,&height);
    DietWindow(&window,arial,targetSize,diet,&res);
    std::string calories= calculateCalories(&height,&weight,&age,&diet);
    MenuWindow(&window,arial,targetSize,&name,&gender,&height,&weight,&diet,&calories,&age,&change_Diet,&close);
    while (true){
        if(close){
            break;
        }
        else{
            if(change_Diet){
                DietWindow(&window,arial,targetSize,diet,&res);
                change_Diet= false;
            }
            MenuWindow(&window,arial,targetSize,&name,&gender,&height,&weight,&diet,&calories,&age,&change_Diet,&close);
        }
    }
    return 0;
}
