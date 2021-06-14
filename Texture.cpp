#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

extern unsigned int texture[25];

std::string GetPath(std::string nameFile)
{
    std::string s = __argv[0];
    std::string::size_type pos = s.find_last_of("\\/");
    std::string path = s.substr(0, pos) + "\\" + "Image\\" + nameFile;
    return path;
}

void InitTexture()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0);
    glEnable(GL_TEXTURE_2D);
    int width, height, nrChannels;
    glGenTextures(25, texture);

    unsigned char* dataT0 = stbi_load(GetPath("Empty.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT0);
    stbi_image_free(dataT0);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT1 = stbi_load(GetPath("Missed.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT1);
    stbi_image_free(dataT1);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT2 = stbi_load(GetPath("Hit.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT2);
    stbi_image_free(dataT2);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT3 = stbi_load(GetPath("Die.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT3);
    stbi_image_free(dataT3);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT4 = stbi_load(GetPath("MapBorder.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT4);
    stbi_image_free(dataT4);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT5 = stbi_load(GetPath("TurnRight.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT5);
    stbi_image_free(dataT5);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT6 = stbi_load(GetPath("Ship1x1.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT6);
    stbi_image_free(dataT6);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT7 = stbi_load(GetPath("Ship1x2.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT7);
    stbi_image_free(dataT7);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT8 = stbi_load(GetPath("Ship1x3.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT8);
    stbi_image_free(dataT8);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT9 = stbi_load(GetPath("Ship1x4.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[9]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT9);
    stbi_image_free(dataT9);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT10 = stbi_load(GetPath("Ship2x1.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[10]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT10);
    stbi_image_free(dataT10);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT11 = stbi_load(GetPath("Ship3x1.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[11]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT11);
    stbi_image_free(dataT11);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT12 = stbi_load(GetPath("Ship4x1.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT12);
    stbi_image_free(dataT12);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT13 = stbi_load(GetPath("ButtonPlayerBot.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT13);
    stbi_image_free(dataT13);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT14 = stbi_load(GetPath("ButtonBotBot.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[14]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT14);
    stbi_image_free(dataT14);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT15 = stbi_load(GetPath("ButtonEasy.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[15]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT15);
    stbi_image_free(dataT15);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT16 = stbi_load(GetPath("ButtonHard.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[16]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT16);
    stbi_image_free(dataT16);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT17 = stbi_load(GetPath("TurnLeft.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[17]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT17);
    stbi_image_free(dataT17);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT18 = stbi_load(GetPath("ButtonNext.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[18]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT18);
    stbi_image_free(dataT18);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT19 = stbi_load(GetPath("NickPlayer1.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[19]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT19);
    stbi_image_free(dataT19);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT20 = stbi_load(GetPath("NickPlayer2.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[20]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT20);
    stbi_image_free(dataT20);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT21 = stbi_load(GetPath("GoToMenu.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[21]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT21);
    stbi_image_free(dataT21);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT22 = stbi_load(GetPath("WorldShip.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[22]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT22);
    stbi_image_free(dataT22);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT23 = stbi_load(GetPath("AboutProgramm.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[23]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT23);
    stbi_image_free(dataT23);
    glBindTexture(GL_TEXTURE_2D, 0);

    unsigned char* dataT24 = stbi_load(GetPath("text.png").c_str(), &width, &height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, texture[24]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, dataT24);
    stbi_image_free(dataT24);
    glBindTexture(GL_TEXTURE_2D, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}