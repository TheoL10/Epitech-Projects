/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** raylib
*/

#ifndef RAYLIB_HPP_
#define RAYLIB_HPP_
#include "raylib.h"

class Raylib{
    public:
        Raylib() {};
        ~Raylib() {};
        void initWindow(int width, int height, const char *title);
        void setCameraMode(Camera camera, int mode);
        void setTargetFps(int fps);
        void updateCamera(Camera *camera);
        void beginDrawing();
        void clearBackground(Color color);
        void beginMode3D(Camera camera);
        void drawModel(Model model, Vector3 position, float scale, Color tint);
        void drawGrid(int size, float step);
        void endMode3D();
        void endDrawing();
        void unloadModel(Model model);
        void closeWindow();
        Model loadModel(const char *fileName);
        bool windowShouldClose();
        Music loadMusicStream(const char *fileName);
        bool isKeyDown(int key);
        bool isKeyReleased(int key);
        ModelAnimation *loadModelAnimations(const char *fileName, unsigned int *animCount);
        void initAudioDevice();
        void drawText(const char *text, int posX, int posY, int fontSize, Color color);
        void unloadTexture(Texture2D texture);
        void unloadMusicStream(Music music);
        Texture2D loadTexture(const char *fileName);
        void drawRectangle(int posX, int posY, int width, int height, Color color);
        void drawRectangleLines(int posX, int posY, int width, int height, Color color);
        Sound loadSound(const char *fileName);
        double getTime(void);
        void drawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
        void updateModelAnimation(Model model, ModelAnimation anim, int frame);
        void drawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
        void playSound(Sound sound);
        bool isKeyPressed(int key);
        void updateMusicStream(Music music);
        int getCurrentMonitor(void);
        bool isWindowFullscreen(void);
        void toggleFullscreen(void);
        int getMonitorWidth(int monitor);
        int getMonitorHeight(int monitor);
        void setWindowSize(int width, int height);
        void playMusicStream(Music music);
        void setMusicVolume(Music music, float volume);
        void setSoundVolume(Sound sound, float volume);
        float getGamepadAxisMovement(int gamepad, int axis);
        bool isGamepadButtonDown(int gamepad, int button);
        bool isGamepadButtonPressed(int gamepad, int button);
        int getKeyPressed(void);
        int getFPS(void);
        bool isGamepadAvailable(int gamepad);
    private:

};

#endif /* !RAYLIB_HPP_ */
