#include "GlobalResource.h"
#include "InputSystem.h"
#include "Texture.h"

unsigned int texture[25];
float coord_x, coord_y;
float HALF_SCREEN_WIDTH, HALF_SCEEN_HEIGHT, SCREN_HEIGHT, SCREN_WIDTH;
vector<Drawable*> drawObjects_layer0;
vector<Drawable*> drawObjects_layer1;
vector<Drawable*> drawObjects_layer2;
InputSystem inputSystem = InputSystem();
Window* windows[5];

void DisplayAll()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    /*Drawable obj = Drawable(Point(360, 650), Point(200, 80), 16);
    obj.DrawSelf();*/
    
    for (auto object : drawObjects_layer0)
    {
        object->DrawSelf();
    }
    for (auto object : drawObjects_layer1)
    {
        object->DrawSelf();
    }
    /*for (auto object : drawObjects_layer2)
    {
        object->DrawSelf();
    }*/
    glFlush();
}

void Timer(int = 0)
{
    DisplayAll();
    glutTimerFunc(50, Timer, 0);
}

void processNormalKeys(unsigned char key, int x, int y)
{
    
}

void processSpecialKeys(int key, int x, int y)
{
    inputSystem.SpecialKeys(key, x, y);
}

void mouse(int button, int state, int x, int y)
{
    inputSystem.Mouse(button, state, x, y);
}

void mouseMove(int x, int y)
{
    inputSystem.MouseMove(x, y);
}

static void Reshape(GLint width, GLint height)
{
    glOrtho(0, SCREN_WIDTH, 0, SCREN_HEIGHT, 0, 100.0f);
}

int main(int argc, char* argv[])
{
    /*for (auto& wind : windows)
        wind = Window();*/
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    SCREN_HEIGHT = glutGet(GLUT_SCREEN_HEIGHT);
    SCREN_WIDTH = glutGet(GLUT_SCREEN_WIDTH);
    glutInitWindowSize(SCREN_WIDTH, SCREN_HEIGHT);
    HALF_SCEEN_HEIGHT = SCREN_HEIGHT / 2;
    HALF_SCREEN_WIDTH = SCREN_WIDTH / 2;

    glutCreateWindow("World of Warships");
    //glutFullScreen();
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(Reshape);
    glutTimerFunc(50, Timer, 0);
    InitTexture();
    glutDisplayFunc(DisplayAll);
    glutMainLoop();
    return 0;
}

