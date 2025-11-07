#include <GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f); // cor amarela (R=1, G=1, B=0)

    glBegin(GL_QUADS);        // desenhar quadrado
    glVertex2f(-0.5f, -0.5f); // canto inferior esquerdo
    glVertex2f(0.5f, -0.5f);  // canto inferior direito
    glVertex2f(0.5f, 0.5f);   // canto superior direito
    glVertex2f(-0.5f, 0.5f);  // canto superior esquerdo
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Yellow Square - FreeGLUT + MinGW32");

    glClearColor(0.1f, 0.1f, 0.12f, 1.0f); // cor de fundo (quase preto)

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
