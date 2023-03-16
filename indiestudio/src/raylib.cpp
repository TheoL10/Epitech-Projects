/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** raylib
*/

#include "../hpp/raylib.hpp"

void Raylib::initWindow(int width, int height, const char *title)
{
    InitWindow(width, height, title);
}

void Raylib::setCameraMode(Camera camera, int mode)
{
    SetCameraMode(camera, mode);
}

void Raylib::setTargetFps(int fps)
{
    SetTargetFPS(fps);
}

void Raylib::updateCamera(Camera *camera)
{
    UpdateCamera(camera);
}

void Raylib::beginDrawing()
{
    BeginDrawing();
}

void Raylib::clearBackground(Color color)
{
    ClearBackground(color);
}

void Raylib::beginMode3D(Camera camera)
{
    BeginMode3D(camera);
}

void Raylib::drawModel(Model model, Vector3 position, float scale, Color tint)
{
    DrawModel(model, position, scale, tint);
}

void Raylib::drawGrid(int size, float step)
{
    DrawGrid(size, step);
}

void Raylib::endMode3D()
{
    EndMode3D();
}

void Raylib::endDrawing()
{
    EndDrawing();
}

void Raylib::unloadModel(Model model)
{
    UnloadModel(model);
}

void Raylib::closeWindow()
{
    CloseWindow();
}

Model Raylib::loadModel(const char *fileName)
{
    return (LoadModel(fileName));
}

bool Raylib::windowShouldClose()
{
    return (WindowShouldClose());
}

bool Raylib::isKeyDown(int key)
{
    return (IsKeyDown(key));
}

bool Raylib::isKeyReleased(int key)
{
    return (IsKeyReleased(key));
}


ModelAnimation *Raylib::loadModelAnimations(const char *fileName, unsigned int *animCount)
{
    return (LoadModelAnimations(fileName, animCount));
}


void Raylib::initAudioDevice()
{
    InitAudioDevice();
}


void Raylib::drawText(const char *text, int posX, int posY, int fontSize, Color color)
{
    DrawText(text, posX, posY, fontSize, color);
}


void Raylib::unloadTexture(Texture2D texture)
{
    UnloadTexture(texture);
}


void Raylib::unloadMusicStream(Music music)
{
    UnloadMusicStream(music);
}


Texture2D Raylib::loadTexture(const char *fileName)
{
    return (LoadTexture(fileName));
}


void Raylib::drawRectangle(int posX, int posY, int width, int height, Color color)
{
    DrawRectangle(posX, posY, width, height, color);
}


void Raylib::drawRectangleLines(int posX, int posY, int width, int height, Color color)
{
    DrawRectangleLines(posX, posY, width, height, color);
}


Sound Raylib::loadSound(const char *fileName)
{
    return (LoadSound(fileName));
}


void Raylib::playSound(Sound sound)
{
    PlaySound(sound);
}


void Raylib::playMusicStream(Music music)
{
    PlayMusicStream(music);
}

Music Raylib::loadMusicStream(const char *fileName)
{
    return (LoadMusicStream(fileName));
}

bool Raylib::isKeyPressed(int key)
{
    return (IsKeyPressed(key));
}

void Raylib::drawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color color)
{
    DrawTextureEx(texture, position, rotation, scale, color);
}

void Raylib::updateMusicStream(Music music)
{
    UpdateMusicStream(music);
}

bool Raylib::isWindowFullscreen()
{
    return (IsWindowFullscreen());
}

void Raylib::toggleFullscreen()
{
    ToggleFullscreen();
}

void Raylib::setWindowSize(int width, int height)
{
    SetWindowSize(width, height);
}

int Raylib::getMonitorHeight(int monitor)
{
    return(GetMonitorHeight(monitor));
}

int Raylib::getMonitorWidth(int monitor)
{
    return(GetMonitorWidth(monitor));
}

double Raylib::getTime()
{
    return (GetTime());
}

void Raylib::drawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)
{
    DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
}

void Raylib::updateModelAnimation(Model model, ModelAnimation animation, int frame)
{
    UpdateModelAnimation(model, animation, frame);
}

int Raylib::getCurrentMonitor()
{
    return (GetCurrentMonitor());
}

void Raylib::setMusicVolume(Music music, float volume)
{
    SetMusicVolume(music, volume);
}

void Raylib::setSoundVolume(Sound sound, float volume)
{
    SetSoundVolume(sound, volume);
}

float Raylib::getGamepadAxisMovement(int gamepad, int axis)
{
    return GetGamepadAxisMovement(gamepad, axis);
}

bool Raylib::isGamepadButtonDown(int gamepad, int button)
{
    return IsGamepadButtonDown(gamepad, button);
}

bool Raylib::isGamepadButtonPressed(int gamepad, int button)
{
    return IsGamepadButtonPressed(gamepad, button);
}

int Raylib::getKeyPressed()
{
    return GetKeyPressed();
}

int Raylib::getFPS()
{
    return GetFPS();
}

bool Raylib::isGamepadAvailable(int gamepad)
{
    return IsGamepadAvailable(gamepad);
}
