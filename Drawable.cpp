#include "Drawable.h"

extern unsigned int texture[25];

Drawable::Drawable(Point GlobalPos, Point GlobalSize, int indexTexture)
{
    this->GlobalPos = GlobalPos;
    this->GlobalSize = GlobalSize;

    Index = indexTexture;
}

bool Drawable::operator==(Drawable& obj)
{
    return (IsVisible == obj.IsVisible) &&
        (GlobalPos == obj.GlobalPos) &&
        (GlobalSize == obj.GlobalSize) &&
        (Index == obj.Index);
}

void Drawable::DrawSelf()
{
    if (IsVisible == false) return;

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture[Index]);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex2d(GlobalPos.x, GlobalPos.y);

    glTexCoord2f(1.0f, 0.0f);
    glVertex2d(GlobalPos.x + GlobalSize.x, GlobalPos.y);

    glTexCoord2f(1.0f, 1.0f);
    glVertex2d(GlobalPos.x + GlobalSize.x, GlobalPos.y - GlobalSize.y);

    glTexCoord2f(0.0f, 1.0f);
    glVertex2d(GlobalPos.x, GlobalPos.y - GlobalSize.y);

    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}