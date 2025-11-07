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
    glColor3f(0.0f, 0.1f, 0.8f);
    glVertex2i(100, 100); // baixo esquerdo - coordenadas pra me ajudar
    glVertex2i(100, 200); // cima esquerdo
    glVertex2i(200, 200); // cima direito
    glVertex2i(200, 100); // baixo direito
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.1f, 0.0f);
    glVertex2i(100, 200);
    glVertex2i(200, 200);
    glVertex2i(150, 250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.3f, 0.0f);

    glVertex2i(135, 100);
    glVertex2i(135, 165);
    glVertex2i(165, 165);
    glVertex2i(165, 100);
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
