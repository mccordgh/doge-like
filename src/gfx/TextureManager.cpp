//
//  TextureManager.cpp
//  2d_game_engine
//
//  Created by Matthew mccord on 8/9/20.
//  Copyright © 2020 MCCORDINATOR. All rights reserved.
//

//#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <iostream>
//#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "Game.h"
#include <direct.h>

//const char* assetsDir = "assets/";
//const char* spriteExtension = ".png";

SDL_Texture* TextureManager::LoadTexture(const char* fullpath)
{
//    size_t bufferSize = strlen(assetsDir) + strlen(fileName) + strlen(spriteExtension) + 1;
//    char* fullpath = new char[bufferSize];
//
//    strcpy(fullpath, assetsDir);
//    strcat(fullpath, fileName);
//    strcat(fullpath, spriteExtension);

    char buff[FILENAME_MAX];
    getcwd(buff, FILENAME_MAX);
    std::string currentDir(buff);
    std::cout << currentDir << std::endl;

    SDL_Surface* tempSurface = IMG_Load(fullpath);

    std::string imgError = IMG_GetError();

    if (!imgError.empty()) {
        std::cout << "!!!!! IMG_Load Error: " << imgError << std::endl << std::endl;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);

    SDL_FreeSurface(tempSurface);
//    delete[] fullpath;

    return texture;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, 0, NULL, flip);
}

