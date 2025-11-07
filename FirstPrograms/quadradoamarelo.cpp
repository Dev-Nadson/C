#include <GL/glut.h>

void init()
{
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glVertex2i(100, 100);
    glVertex2i(100, 200);
    glVertex2i(200, 200);
    glVertex2i(200, 100);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Quadrado amarelo teste");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
