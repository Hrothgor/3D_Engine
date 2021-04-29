/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** DisplayManager
*/

#include "DisplayManager.hpp"

DisplayManager::DisplayManager()
    : _keysRough(Input::KeyCount, false)
    , _keysSmooth(Input::KeyCount, false)
{
    sf::ContextSettings settings(24, 8, 0, 3.3, 0, 0, 0);
    _window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT, 32), "3D", sf::Style::Default, settings);
    _window->setFramerateLimit(120);
    glViewport(0, 0, WIDTH, HEIGHT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

DisplayManager::~DisplayManager()
{
}

void DisplayManager::event()
{
    sf::Event event;

    for (int i = 0; i < Input::KeyCount; i++)
        _keysRough[i] = false;
    while (_window->pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            _keysRough[event.key.code] = true;
            _keysSmooth[event.key.code] = true;
        }
        if (event.type == sf::Event::KeyReleased)
            _keysSmooth[event.key.code] = false;

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left)
                _keysSmooth[Input::LMouse] = true;
            if (event.mouseButton.button == sf::Mouse::Right)
                _keysSmooth[Input::RMouse] = true;
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left)
                _keysSmooth[Input::LMouse] = false;
            if (event.mouseButton.button == sf::Mouse::Right)
                _keysSmooth[Input::RMouse] = false;
        }

        if (event.type == sf::Event::Closed)
            _window->close();
    }
}

void DisplayManager::run()
{
    ///// 3D INIT /////
    Loader _loader;
    MasterRenderer _renderer;

    RawModel modelDragon = OBJLoader::loadObjModel("ressources/dragon.obj", _loader);
    sf::Texture textureDragon = _loader.LoadTexture("ressources/dragon.png");
    TexturedModel texturedModelDragon(modelDragon, textureDragon, 10, 1);

    RawModel modelInferno = OBJLoader::loadObjModel("ressources/inferno.obj", _loader);
    sf::Texture textureInferno = _loader.LoadTexture("ressources/inferno.png");
    TexturedModel texturedModelInferno(modelInferno, textureInferno, 10, 1);

    for (int i = 0; i < 1; i++) {
        float x = Maths::randFloat() * 40 - 20;
        float y = Maths::randFloat() * 40 - 20;
        float z = Maths::randFloat() * -100;
        float rotx = Maths::randFloat() * 180;
        float roty = Maths::randFloat() * 180;
        float scale = Maths::randFloat() * 2;
        Entity entity(texturedModelDragon, sf::Vector3f(x,y,z), sf::Vector3f(rotx,roty,0), scale);
        _renderer.addEntity(entity);
    }
    for (int i = 0; i < 200; i++) {
        float x = Maths::randFloat() * 500 - 250;
        float y = Maths::randFloat() * 40 - 20;
        float z = Maths::randFloat() * -100;
        float rotx = Maths::randFloat() * 180;
        float roty = Maths::randFloat() * 180;
        float scale = Maths::randFloat() * 2;
        Entity entity(texturedModelInferno, sf::Vector3f(x,0,-20), sf::Vector3f(0,0,0), scale);
        _renderer.addEntity(entity);
    }

    Light light(sf::Vector3f(3000,2000,3000), sf::Vector3f(1,1,1));
    Camera camera;
    ///////////////////

    ///// 2D INIT /////
    sf::Clock clock;
    int nbFrame = 0;
    sf::Font font;
    if (!font.loadFromFile("ressources/font.ttf"))
        exit (84);
    sf::Text text("120", font, 40);
    text.setFillColor(sf::Color::Yellow);
    ///////////////////

    while (_window->isOpen())
    {
        event();
        //////
        //entity.increasePosition(sf::Vector3f(0, 0, -0.1));
        //entity.increaseRotation(sf::Vector3f(0, 1, 0));
        //////

        camera.move(_keysSmooth, _window);
        _renderer.render(light, camera);

        //// GUI ////
        _window->pushGLStates();

        nbFrame++;
        if (clock.getElapsedTime().asSeconds() > 1) {
            sf::Time frameTime = clock.restart();
            int framerate = (1 / frameTime.asSeconds() * nbFrame);
            text.setString(std::to_string(framerate));
            nbFrame = 0;
        }
        _window->draw(text);

        _window->popGLStates();
        /////////////

        _window->display();
    }
    _keysRough.clear();
    _keysSmooth.clear();
    _renderer.destroy();
    _loader.destroy();
}