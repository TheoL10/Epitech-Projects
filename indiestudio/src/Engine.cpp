/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-theo.louismet
** File description:
** Engine
*/

#include "../hpp/Engine.hpp"

Engine::Engine()
{
}

Engine::~Engine()
{
    for (const auto &p : _sceneList) { delete(p.second); };
}

void Engine::setLvl(int lvl)
{
    _sceneList["menu"]->setLvls(lvl);
}

void Engine::setupVersus(int nbManettes, std::vector<int> listSkins)
{
    setCamera(1);
    _sceneList["game"]->setMap(-1, listSkins);
    _sceneList["game"]->setControlers(nbManettes);
    setScene("game");
}

void Engine::resetGame(void)
{
    delete(_sceneList["game"]);
    _sceneList["game"] = new SceneGame(_models, _anims,  _sprites, _musics, this);
}

void Engine::setVolume(float volume)
{
    for (const auto &p : _musics) { raylib.setMusicVolume(p.second, volume); };
    for (const auto &p : _sounds) { raylib.setSoundVolume(p.second, volume); };
}

void Engine::setFps(int fps)
{
    raylib.setTargetFps(fps);
    _fps = fps;
}

void Engine::initSounds(void)
{
    this->_musics = { {"menu", raylib.loadMusicStream(ASSETS_PATH"Music/Title_Music.mp3")},
                      {"lvl1", raylib.loadMusicStream(ASSETS_PATH"Music/sonlevel1.mp3")}, 
                      {"lvl2", raylib.loadMusicStream(ASSETS_PATH"Music/sonlevel2.mp3")}, 
                      {"lvl3", raylib.loadMusicStream(ASSETS_PATH"Music/sonlevel3.mp3")}, 
    };

    this->_sounds = { {"select", raylib.loadSound(ASSETS_PATH"SFX/menu_select.wav")},
                      {"validation", raylib.loadSound(ASSETS_PATH"SFX/menu_validation.wav")},
                      {"bonus", raylib.loadSound(ASSETS_PATH"PowerUp/bonus.ogg")},
                      {"bomb", raylib.loadSound(ASSETS_PATH"Explosion/bomb_drop.ogg")},
                      {"explode1", raylib.loadSound(ASSETS_PATH"Explosion/boom/explosion_1.ogg")},
                      {"explode2", raylib.loadSound(ASSETS_PATH"Explosion/boom/explosion_2.ogg")},
                      {"explode3", raylib.loadSound(ASSETS_PATH"Explosion/boom/explosion_3.ogg")},
                      {"explode4", raylib.loadSound(ASSETS_PATH"Explosion/boom/explosion_4.ogg")},
                      {"explode5", raylib.loadSound(ASSETS_PATH"Explosion/boom/explosion_big.ogg")},
                      {"death", raylib.loadSound(ASSETS_PATH"SFX/bummed.wav")},
                      {"victoire", raylib.loadSound(ASSETS_PATH"SFX/victory.wav")},
                      {"pause", raylib.loadSound(ASSETS_PATH"SFX/pause.wav")}
    };
}

void Engine::initScene(void)
{
    this->_sceneList = { {"menu", new MenuManager(_sprites, _models, _musics, this)},
                         {"game", new SceneGame(_models, _anims,  _sprites, _musics, this)},
                         {"pause", new ScenePause(_sprites, this)}
    };
}

void Engine::initAnims(void)
{
    _animsCount = { {"player0", 0},
                    {"player1", 0},
                    {"player2", 0},
                    {"player3", 0}
    };

    _anims = { {"player0", raylib.loadModelAnimations(ASSETS_PATH"skins/characterAnimation.iqm", &_animsCount["player0"])},
                {"player2", raylib.loadModelAnimations(ASSETS_PATH"skins/demonAnimation.iqm", &_animsCount["player1"])},
                {"player3", raylib.loadModelAnimations(ASSETS_PATH"skins/angelAnimation.iqm", &_animsCount["player2"])},
                {"player1", raylib.loadModelAnimations(ASSETS_PATH"skins/zombieAnimation.iqm", &_animsCount["player3"])}
                };
}

void Engine::initModels(void)
{
    _models = { {"box", raylib.loadModel(ASSETS_PATH"box.obj")},
                {"wall", raylib.loadModel(ASSETS_PATH"wall.obj")},
                {"bomb", raylib.loadModel(ASSETS_PATH"bomb_vox.obj")},
                {"grass", raylib.loadModel(ASSETS_PATH"grass.obj")},
                {"bomb", raylib.loadModel(ASSETS_PATH"bomb_vox.obj")},
                {"player0", raylib.loadModel(ASSETS_PATH"skins/character.iqm")},
                {"player2", raylib.loadModel(ASSETS_PATH"skins/demon.iqm")},
                {"player3", raylib.loadModel(ASSETS_PATH"skins/angel.iqm")},
                {"player1", raylib.loadModel(ASSETS_PATH"skins/zombie.iqm")},
                {"horizontalKaboom", raylib.loadModel(ASSETS_PATH"explosion_right2.obj")},
                {"verticalKaboom", raylib.loadModel(ASSETS_PATH"explosion_down2.obj")},
                {"centerKaboom", raylib.loadModel(ASSETS_PATH"explosion_center2.obj")},
                {"skate", raylib.loadModel(ASSETS_PATH"skate.obj")},
                {"fireUp", raylib.loadModel(ASSETS_PATH"fire_up.obj")},
                {"bombUp", raylib.loadModel(ASSETS_PATH"item_bomb.obj")},
                {"level1", raylib.loadModel(ASSETS_PATH"menu/level/maplvl1.obj")},
                {"level1.5", raylib.loadModel(ASSETS_PATH"menu/level/maplvl1.5.obj")},
                {"level2", raylib.loadModel(ASSETS_PATH"menu/level/maplvl2.obj")},
                {"level2.5", raylib.loadModel(ASSETS_PATH"menu/level/maplvl2.5.obj")},
                {"level3", raylib.loadModel(ASSETS_PATH"menu/level/maplvl3.obj")},
                {"level3.5", raylib.loadModel(ASSETS_PATH"menu/level/maplvl3.5.obj")},
                {"lock", raylib.loadModel(ASSETS_PATH"menu/level/locker.obj")}
    };

    _models["box"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"box.png");
    _models["wall"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"wall.png");
    _models["bomb"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"bomb_vox.png");
    _models["grass"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"grass.png");
    _models["bomb"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"bomb_vox.png");
    _models["player0"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"skins/bomberman_nowalk_test.png");
    _models["player1"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"skins/bomberman_nowalk_demon.png");
    _models["player2"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"skins/bomberman_nowalk_angel.png");
    _models["player3"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"skins/bomberman_nowalk_zombi.png");
    _models["horizontalKaboom"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(ASSETS_PATH"explosion_right2.png");
    _models["verticalKaboom"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"explosion_down2.png");
    _models["centerKaboom"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"explosion_center2.png");
    _models["skate"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"skate.png");
    _models["fireUp"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"fire_up.png");
    _models["bombUp"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"item_bomb.png");
    _models["level1"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"menu/level/grass.png");
    _models["level1.5"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"menu/level/box.png");
    _models["level2"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"menu/level/grass.png");
    _models["level2.5"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"menu/level/box.png");
    _models["level3"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"menu/level/grass.png");
    _models["level3.5"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"menu/level/box.png");
    _models["lock"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = raylib.loadTexture(ASSETS_PATH"menu/level/locker.png");
}

void Engine::initSprites(void)
{
    _sprites = { {"buttonJouer", raylib.loadTexture(ASSETS_PATH"menu/button_jouer_png.png")}, 
                 {"buttonJouerHover", raylib.loadTexture(ASSETS_PATH"menu/button_jouer_hover_png.png")},
                 {"buttonVersus", raylib.loadTexture(ASSETS_PATH"menu/button_versus_png.png")},
                 {"buttonVersusHover", raylib.loadTexture(ASSETS_PATH"menu/button_versus_hover_png.png")},
                 {"buttonParametre", raylib.loadTexture(ASSETS_PATH"menu/button_parametre_png.png")},
                 {"buttonParametreHover", raylib.loadTexture(ASSETS_PATH"menu/button_parametre_hover_png.png")},
                 {"buttonQuitter", raylib.loadTexture(ASSETS_PATH"menu/button_quitter_png.png")},
                 {"buttonQuitterHover", raylib.loadTexture(ASSETS_PATH"menu/button_quitter_hover_png.png")},
                 {"background", raylib.loadTexture(ASSETS_PATH"menu/background.png")},
                 {"settings", raylib.loadTexture(ASSETS_PATH"menu/settings.png")},
                 {"button30", raylib.loadTexture(ASSETS_PATH"menu/button_30.png")},
                 {"button30Hover", raylib.loadTexture(ASSETS_PATH"menu/button_30_hover.png")},
                 {"button60", raylib.loadTexture(ASSETS_PATH"menu/button_60.png")},
                 {"button60Hover", raylib.loadTexture(ASSETS_PATH"menu/button_60_hover.png")},
                 {"button90", raylib.loadTexture(ASSETS_PATH"menu/button_90.png")},
                 {"button90Hover", raylib.loadTexture(ASSETS_PATH"menu/button_90_hover.png")},
                 {"button120", raylib.loadTexture(ASSETS_PATH"menu/button_120.png")},
                 {"button120Hover", raylib.loadTexture(ASSETS_PATH"menu/button_120_hover.png")},
                 {"buttonFps", raylib.loadTexture(ASSETS_PATH"menu/button_fps.png")},
                 {"buttonFpsHover", raylib.loadTexture(ASSETS_PATH"menu/button_fps_hover.png")},
                 {"buttonFullscreen", raylib.loadTexture(ASSETS_PATH"menu/button_fullscreen.png")},
                 {"buttonFullscreenHover", raylib.loadTexture(ASSETS_PATH"menu/button_fullscreen_hover.png")},
                 {"buttonMinus", raylib.loadTexture(ASSETS_PATH"menu/button_minus.png")},
                 {"buttonMinusHover", raylib.loadTexture(ASSETS_PATH"menu/button_minus_hover.png")},
                 {"buttonPlus", raylib.loadTexture(ASSETS_PATH"menu/button_plus.png")},
                 {"buttonPlusHover", raylib.loadTexture(ASSETS_PATH"menu/button_plus_hover.png")},
                 {"soundOn", raylib.loadTexture(ASSETS_PATH"menu/sound_on.png")},
                 {"soundOff", raylib.loadTexture(ASSETS_PATH"menu/sound_off.png")},
                 {"hills", raylib.loadTexture(ASSETS_PATH"menu/menu_hills.png")},
                 {"buttonSound", raylib.loadTexture(ASSETS_PATH"menu/button_sound.png")},
                 {"buttonSoundHover", raylib.loadTexture(ASSETS_PATH"menu/button_sound_hover.png")},
                 {"volume3", raylib.loadTexture(ASSETS_PATH"menu/volume_3.png")},
                 {"volume2", raylib.loadTexture(ASSETS_PATH"menu/volume_2.png")},
                 {"volume1", raylib.loadTexture(ASSETS_PATH"menu/volume_1.png")},
                 {"volume0", raylib.loadTexture(ASSETS_PATH"menu/volume_0.png")},
                 {"debut", raylib.loadTexture(ASSETS_PATH"menu/debut.png")},
                 {"debutText", raylib.loadTexture(ASSETS_PATH"menu/debut_text.png")},
                 {"logo", raylib.loadTexture(ASSETS_PATH"menu/logo.png")},
                 {"save", raylib.loadTexture(ASSETS_PATH"menu/save.png")},
                 {"saveHover", raylib.loadTexture(ASSETS_PATH"menu/save_hover.png")},
                 {"backgroundLevel", raylib.loadTexture(ASSETS_PATH"menu/level/background_level.png")},
                 {"backgroundVersus", raylib.loadTexture(ASSETS_PATH"menu/background_versus.png")},
                 {"skateIcon", raylib.loadTexture(ASSETS_PATH"HUD/skate_icon.png")},
                 {"fireUpIcon", raylib.loadTexture(ASSETS_PATH"HUD/fireup.png")},
                 {"bombUpIcon", raylib.loadTexture(ASSETS_PATH"HUD/bombup.png")},
                 {"hudCard1", raylib.loadTexture(ASSETS_PATH"HUD/HUDplayer01.png")},
                 {"hudCard2", raylib.loadTexture(ASSETS_PATH"HUD/HUDplayer02.png")},
                 {"hudCard3", raylib.loadTexture(ASSETS_PATH"HUD/HUDplayer03.png")},
                 {"hudCard4", raylib.loadTexture(ASSETS_PATH"HUD/HUDplayer04.png")},
                 {"perso1", raylib.loadTexture(ASSETS_PATH"skins/personnage1.png")},
                 {"perso2", raylib.loadTexture(ASSETS_PATH"skins/personnage2.png")},
                 {"perso3", raylib.loadTexture(ASSETS_PATH"skins/personnage3.png")},
                 {"perso4", raylib.loadTexture(ASSETS_PATH"skins/personnage4.png")},
                 {"endbg", raylib.loadTexture(ASSETS_PATH"end_screen.png")},
                 {"help", raylib.loadTexture(ASSETS_PATH"menu/Help_menu.png")},
                 {"pauseMenu", raylib.loadTexture(ASSETS_PATH"pause/pause_menu.png")},
                 {"pauseMenuHover", raylib.loadTexture(ASSETS_PATH"pause/pause_menu_hover.png")},
                 {"pauseReprendre", raylib.loadTexture(ASSETS_PATH"pause/pause_reprendre.png")},
                 {"pauseReprendreHover", raylib.loadTexture(ASSETS_PATH"pause/pause_reprendre_hover.png")}
    };
}

void Engine::setCamera(int idCam)
{
    if (idCam == 1) {
        _camera.position = { 15.0f, 23.0f, 9.0f };
        _camera.target = { 9.0f, 0.0f, 9.0f };
        _camera.up = { 0.0f, 1.0f, 0.0f };
        _camera.fovy = 45.0f;
        _camera.projection = CAMERA_PERSPECTIVE;
        raylib.setCameraMode(_camera, CAMERA_FREE);
    }
    if (idCam == 2) {
        _camera.position = { 30.0f, 30.0f, 30.0f };
        _camera.target = { 0.0f, 0.0f, 0.0f };
        _camera.up = { 0.0f, 1.0f, 0.0f };
        _camera.fovy = 45.0f;
        _camera.projection = CAMERA_PERSPECTIVE;
        raylib.setCameraMode(_camera, CAMERA_ORBITAL);
    }
    if (idCam == 3) {
        _camera.position = { 15.0f, 15.0f, 15.0f };
        _camera.target = { 0.0f, 0.0f, 0.0f };
        _camera.up = { 0.0f, 1.0f, 0.0f };
        _camera.fovy = 45.0f;
        _camera.projection = CAMERA_PERSPECTIVE;
        raylib.setCameraMode(_camera, CAMERA_FREE);
    }
}

void Engine::initAll(void)
{
    raylib.initWindow(1920, 1080, "Bomberman");
    raylib.initAudioDevice();

    setCamera(2);

    setFps(60);


    int loadingState = 0;
    int recSize = 0;
    std::vector<std::string> nameStates = {"", "Loading Sounds ...", "Loading Models ...", "Loading Animation ...", "Loading Sprites ...", "Loading Scenes ..."};
    while (loadingState != 6)
    {
        raylib.beginDrawing();
        raylib.clearBackground(RAYWHITE);
        raylib.drawText("Loading ...", 620, 270, 150, LIGHTGRAY);
        raylib.drawRectangle(215, 650, 1490, 100, LIGHTGRAY);
        raylib.drawRectangleLines(215, 650, 1490, 100, GRAY);
        raylib.drawRectangle(215, 650, recSize, 100, MAROON);
        raylib.drawText(nameStates[loadingState].c_str(), 215, 775, 20, LIGHTGRAY);
        if (loadingState == 5)
            initScene();
        if (loadingState == 4)
            initSprites();
        if (loadingState == 3)
            initAnims();
        if (loadingState == 2)
            initModels();
        if (loadingState == 1)
            initSounds();
        if (loadingState != 0)
            recSize += 298;
        loadingState++;
        raylib.endDrawing();
    }
}

void Engine::destroyAll(void)
{
    for (const auto &p : _sprites) { raylib.unloadTexture(p.second); };
    for (const auto &p : _models) { raylib.unloadModel(p.second); };
    for (const auto &p : _musics) { raylib.unloadMusicStream(p.second); };
    StopSoundMulti();
    for (const auto &p : _sounds) { UnloadSound(p.second); };
}

void Engine::gameLoop(void)
{
    initAll();
    while (!raylib.windowShouldClose() && _leaveGame == false)
    {
        raylib.updateCamera(&_camera);
        raylib.beginDrawing();
            raylib.clearBackground(SKYBLUE);
            this->_sceneList[_currSceneId]->update();
            this->_sceneList[_currSceneId]->draw();
        raylib.endDrawing();
    }
    destroyAll();
    raylib.closeWindow();
}