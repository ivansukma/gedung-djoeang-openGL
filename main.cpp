#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void resize(int, int);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
float angkatranslasi = 0;
float angkatranslasi2 = 0;
bool mousedown = false;
int is_depth;

void timer(int value)
{

    if (angkatranslasi == 0) {
        angkatranslasi = 17;
    }
    else if (angkatranslasi == 17) {
        angkatranslasi = 0;
    }

    if (angkatranslasi2 == 0) {
        angkatranslasi2 = -17;
    }
    else if (angkatranslasi2 == -17) {
        angkatranslasi2 = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(1000, timer, 10);
}

int main(int argc, char** argv) {


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Tugas Rancang Grafkom");
    glutTimerFunc(1, timer, 0);
    init();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}


void init(void) {
    glClearColor(1.0, 0.412, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glLineWidth(6.0f);
}

void interior(int xkiri, int xkanan, int xatas) {
    glBegin(GL_QUADS);//tembok depan kampus bagian kiri
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-80.0 - xkiri, 0.0, 150.1);
    glVertex3f(-80.0 - xkiri, 100.0 + xatas, 150.1);
    glVertex3f(-100.0 + xkanan, 100.0 + xatas, 150.1);
    glVertex3f(-100.0 + xkanan, 0.0, 150.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-80.0 - xkiri, 0.0, 150.1);
    glVertex3f(-80.0 - xkiri, 100.0 + xatas, 150.1);
    glVertex3f(-100.0 + xkanan, 100.0 + xatas, 150.1);
    glVertex3f(-100.0 + xkanan, 0.0, 150.1);
    glEnd();


    glBegin(GL_QUADS);//tembok depan kampus bagian kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(100.0 - xkiri, 0.0, 150.1);
    glVertex3f(100.0 - xkiri, 100.0 + xatas, 150.1);
    glVertex3f(80.0 + xkanan, 100.0 + xatas, 150.1);
    glVertex3f(80.0 + xkanan, 0.0, 150.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(100.0 - xkiri, 0.0, 150.1);
    glVertex3f(100.0 - xkiri, 100.0 + xatas, 150.1);
    glVertex3f(80.0 + xkanan, 100.0 + xatas, 150.1);
    glVertex3f(80.0 + xkanan, 0.0, 150.1);
    glEnd();

    glBegin(GL_QUADS);//garis siku siku kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-40.0, 0.0, 150.1);
    glVertex3f(-40.0, 180.0, 150.1);
    glVertex3f(-40.0, 180.0, 140.1);
    glVertex3f(-40.0, 0.0, 140.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-40.0, 0.0, 150.1);
    glVertex3f(-40.0, 180.0, 150.1);
    glVertex3f(-40.0, 180.0, 140.1);
    glVertex3f(-40.0, 0.0, 140.1);
    glEnd();

    glBegin(GL_QUADS);//garis siku siku kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(40.0, 0.0, 150.1);
    glVertex3f(40.0, 180.0, 150.1);
    glVertex3f(40.0, 180.0, 140.1);
    glVertex3f(40.0, 0.0, 140.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(40.0, 0.0, 150.1);
    glVertex3f(40.0, 180.0, 150.1);
    glVertex3f(40.0, 180.0, 140.1);
    glVertex3f(40.0, 0.0, 140.1);
    glEnd();

    glBegin(GL_QUADS);//garis belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-80.0 - xkiri, 0.0, -100.1);
    glVertex3f(-80.0 - xkiri, 100.0 + xatas, -100.1);
    glVertex3f(80.0 + xkanan, 100.0 + xatas, -100.1);
    glVertex3f(80.0 + xkanan, 0.0, -100.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-80.0 - xkiri, 0.0, -100.1);
    glVertex3f(-80.0 - xkiri, 100.0 + xatas, -100.1);
    glVertex3f(80.0 + xkanan, 100.0 + xatas, -100.1);
    glVertex3f(80.0 + xkanan, 0.0, -100.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-80.0 - xkiri, 0.0, -100.1);
    glVertex3f(-80.0 - xkiri, 100.0 + xatas, -100.1);
    glVertex3f(80.0 + xkanan, 100.0 + xatas, -100.1);
    glVertex3f(80.0 + xkanan, 0.0, -100.1);
    glEnd();

    glBegin(GL_QUADS);//garis depan rumah`transisi 4 kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-20.0 - xkiri + 40, 100.0 + xatas, 140.1);
    glVertex3f(40.0, 100.0 + xatas, 140.1);
    glVertex3f(40.0, 0.0, 140.1);
    glVertex3f(-20.0 - xkiri + 40, 0.0, 140.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-20.0 - xkiri + 40, 100.0 + xatas, 140.1);
    glVertex3f(40.0, 100.0 + xatas, 140.1);
    glVertex3f(40.0, 0.0, 140.1);
    glVertex3f(-20.0 - xkiri + 40, 0.0, 140.1);
    glEnd();


    glBegin(GL_QUADS);//penutup tembok depan bagian depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-20.0 - xkiri + 40, 100.0 + xatas, 140.0);
    glVertex3f(40.0, 100.0 + xatas, 140.0);
    glVertex3f(40.0, 0.0, 140.0);
    glVertex3f(-20.0 - xkiri + 40, 0.0, 140.0);
    glEnd();

    glBegin(GL_QUADS);//penutup tembok atas bagian depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-20.0 - xkiri + 40, 100.0 + xatas, 120.1);
    glVertex3f(40.0, 100.0 + xatas, 120.1);
    glVertex3f(40.0, 100.0 + xatas, 140.1);
    glVertex3f(-20.0 - xkiri + 40, 100.0 + xatas, 140.1);
    glEnd();

    glBegin(GL_QUADS);//tembok kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(140.0, 0.0, 150.0);
    glVertex3f(140.0, 180.0, 150.0);
    glVertex3f(140.0, 180.0, -100.0);
    glVertex3f(140.0, 0.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis tembok kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(140.0, 0.0, 150.0);
    glVertex3f(140.0, 180.0, 150.0);
    glVertex3f(140.0, 180.0, -100.0);
    glVertex3f(140.0, 0.0, -100.0);
    glEnd();

    glBegin(GL_QUADS);//tembok kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-140.0, 0.0, 150.0);
    glVertex3f(-140.0, 180.0, 150.0);
    glVertex3f(-140.0, 180.0, -100.0);
    glVertex3f(-140.0, 0.0, -100.0);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis tembok kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-140.0, 0.0, 150.0);
    glVertex3f(-140.0, 180.0, 150.0);
    glVertex3f(-140.0, 180.0, -100.0);
    glVertex3f(-140.0, 0.0, -100.0);
    glEnd();
}

void jendelakiri(void) {

    // jendela pojok kiri atas
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(0.5f, 0.5f, 0.45f); // warna jendela dalam
    glVertex3f(-140.5, 110, 130.0);
    glVertex3f(-140.5, 160, 130.0);
    glVertex3f(-140.5, 160, 80.0);
    glVertex3f(-140.5, 110, 80.0);
    glEnd();

    // jendela pojok kiri atas (garis jendela dalam)
    glBegin(GL_LINE_LOOP);//jendela pojok kanan atas kiri
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-140.5, 110, 130.0);
    glVertex3f(-140.5, 160, 130.0);
    glVertex3f(-140.5, 160, 80.0);
    glVertex3f(-140.5, 110, 80.0);
    glEnd();

    // garis jendela dalam
    glBegin(GL_LINE_LOOP);//jendela pojok kanan atas kiri
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-140.6, 109.5, 130.0);
    glVertex3f(-140.6, 159.5, 130.0);
    glVertex3f(-140.6, 159.5, 80.0);
    glVertex3f(-140.6, 109.5, 80.0);
    glEnd();


    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 122.5, 130.0);
    glVertex3f(-140.6, 122.5, 80.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 135, 130.0);
    glVertex3f(-140.6, 135, 80.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 147.5, 130.0);
    glVertex3f(-140.6, 147.5, 80.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 160, 96.6);
    glVertex3f(-140.6, 110, 96.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 160, 113.2);
    glVertex3f(-140.6, 110, 113.2);
    glEnd();

    // pintu jendela kanan
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-155.5, 110, 140.0);
    glVertex3f(-155.5, 160, 140.0);
    glVertex3f(-140.5, 160, 130.0);
    glVertex3f(-140.5, 110, 130.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-140.5, 110, 80.0);
    glVertex3f(-140.5, 160, 80.0);
    glVertex3f(-155.5, 160, 70.0);
    glVertex3f(-155.5, 110, 70.0);
    glEnd();

    //..//
    // jendela tengah
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.45f);  // warna jendela dalam
    glVertex3f(-140.5, 110, 50.0);
    glVertex3f(-140.5, 160, 50.0);
    glVertex3f(-140.5, 160, 0.0);
    glVertex3f(-140.5, 110, 0.0);
    glEnd();

    // jendela tengah (garis dalam hitam)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-140.5, 110, 50.0);
    glVertex3f(-140.5, 160, 50.0);
    glVertex3f(-140.5, 160, 0.0);
    glVertex3f(-140.5, 110, 0.0);
    glEnd();

    // garis jendela dalam (tengah)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-140.6, 109.5, 50.0);
    glVertex3f(-140.6, 159.5, 50.0);
    glVertex3f(-140.6, 159.5, 0.0);
    glVertex3f(-140.6, 109.5, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 122.5, 50.0);
    glVertex3f(-140.6, 122.5, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 135, 50.0);
    glVertex3f(-140.6, 135, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 147.5, 50.0);
    glVertex3f(-140.6, 147.5, 0.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 160, 16.6);
    glVertex3f(-140.6, 110, 16.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 160, 33.2);
    glVertex3f(-140.6, 110, 33.2);
    glEnd();


    // pintu jendela kanan
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-155.5, 110, 60.0);
    glVertex3f(-155.5, 160, 60.0);
    glVertex3f(-140.5, 160, 50.0);
    glVertex3f(-140.5, 110, 50.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-140.5, 110, 0.0);
    glVertex3f(-140.5, 160, 0.0);
    glVertex3f(-155.5, 160, -10.0);
    glVertex3f(-155.5, 110, -10.0);
    glEnd();
    //..//

    // jendela pojok kiri atas
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.45f); // warna jendela dalam
    glVertex3f(-140.5, 110, -80.0);
    glVertex3f(-140.5, 160, -80.0);
    glVertex3f(-140.5, 160, -30.0);
    glVertex3f(-140.5, 110, -30.0);
    glEnd();

    // jendela pojok kiri atas (garis dalam hitam)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-140.5, 110, -80.0);
    glVertex3f(-140.5, 160, -80.0);
    glVertex3f(-140.5, 160, -30.0);
    glVertex3f(-140.5, 110, -30.0);
    glEnd();

    // garis jendela dalam (pojok kiri atas)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-140.6, 109.5, -80.0);
    glVertex3f(-140.6, 159.5, -80.0);
    glVertex3f(-140.6, 159.5, -30.0);
    glVertex3f(-140.6, 109.5, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 122.5, -80.0);
    glVertex3f(-140.6, 122.5, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 135, -80.0);
    glVertex3f(-140.6, 135, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 147.5, -80.0);
    glVertex3f(-140.6, 147.5, -30.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 160, -46.6);
    glVertex3f(-140.6, 110, -46.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 160, -63.2);
    glVertex3f(-140.6, 110, -63.2);
    glEnd();


    // pintu jendela kiri
    glBegin(GL_QUADS);//jendela  kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-155.5, 110, -90.0);
    glVertex3f(-155.5, 160, -90.0);
    glVertex3f(-140.5, 160, -80.0);
    glVertex3f(-140.5, 110, -80.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-140.5, 110, -30.0);
    glVertex3f(-140.5, 160, -30.0);
    glVertex3f(-155.5, 160, -20.0);
    glVertex3f(-155.5, 110, -20.0);
    glEnd();

    //..//
    //JENDELA LANTAI 1//

    // jendela pojok kiri atas
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(0.5f, 0.5f, 0.45f); // warna jendela dalam
    glVertex3f(-140.5, 20, 130.0);
    glVertex3f(-140.5, 70, 130.0);
    glVertex3f(-140.5, 70, 80.0);
    glVertex3f(-140.5, 20, 80.0);
    glEnd();

    // jendela pojok kiri atas (garis jendela dalam)
    glBegin(GL_LINE_LOOP);//jendela pojok kanan atas kiri
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-140.5, 20, 130.0);
    glVertex3f(-140.5, 70, 130.0);
    glVertex3f(-140.5, 70, 80.0);
    glVertex3f(-140.5, 20, 80.0);
    glEnd();

    // garis jendela dalam
    glBegin(GL_LINE_LOOP);//jendela pojok kanan atas kiri
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-140.6, 19.5, 130.0);
    glVertex3f(-140.6, 69.5, 130.0);
    glVertex3f(-140.6, 69.5, 80.0);
    glVertex3f(-140.6, 19.5, 80.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 32.5, 130.0);
    glVertex3f(-140.6, 32.5, 80.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 45, 130.0);
    glVertex3f(-140.6, 45, 80.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 57.5, 130.0);
    glVertex3f(-140.6, 57.5, 80.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 70, 96.6);
    glVertex3f(-140.6, 20, 96.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 70, 113.2);
    glVertex3f(-140.6, 20, 113.2);
    glEnd();

    // pintu jendela kanan
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-155.5, 20, 140.0);
    glVertex3f(-155.5, 70, 140.0);
    glVertex3f(-140.5, 70, 130.0);
    glVertex3f(-140.5, 20, 130.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-140.5, 20, 80.0);
    glVertex3f(-140.5, 70, 80.0);
    glVertex3f(-155.5, 70, 70.0);
    glVertex3f(-155.5, 20, 70.0);
    glEnd();

    //..//
    // jendela tengah
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.45f); //warna jendela dalam
    glVertex3f(-140.5, 20, 50.0);
    glVertex3f(-140.5, 70, 50.0);
    glVertex3f(-140.5, 70, 0.0);
    glVertex3f(-140.5, 20, 0.0);
    glEnd();

    // jendela tengah (garis dalam hitam)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-140.5, 20, 50.0);
    glVertex3f(-140.5, 70, 50.0);
    glVertex3f(-140.5, 70, 0.0);
    glVertex3f(-140.5, 20, 0.0);
    glEnd();

    // garis jendela dalam (tengah)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-140.6, 19.5, 50.0);
    glVertex3f(-140.6, 69.5, 50.0);
    glVertex3f(-140.6, 69.5, 0.0);
    glVertex3f(-140.6, 19.5, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 32.5, 50.0);
    glVertex3f(-140.6, 32.5, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 45, 50.0);
    glVertex3f(-140.6, 45, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 57.5, 50.0);
    glVertex3f(-140.6, 57.5, 0.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 70, 16.6);
    glVertex3f(-140.6, 20, 16.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 70, 33.2);
    glVertex3f(-140.6, 20, 33.2);
    glEnd();


    // pintu jendela kanan
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-155.5, 20, 60.0);
    glVertex3f(-155.5, 70, 60.0);
    glVertex3f(-140.5, 70, 50.0);
    glVertex3f(-140.5, 20, 50.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-140.5, 20, 0.0);
    glVertex3f(-140.5, 70, 0.0);
    glVertex3f(-155.5, 70, -10.0);
    glVertex3f(-155.5, 20, -10.0);
    glEnd();
    //..//

    // jendela pojok kiri atas
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.45f); // warna jendela dalam
    glVertex3f(-140.5, 20, -80.0);
    glVertex3f(-140.5, 70, -80.0);
    glVertex3f(-140.5, 70, -30.0);
    glVertex3f(-140.5, 20, -30.0);
    glEnd();

    // jendela pojok kiri atas (garis dalam hitam)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-140.5, 20, -80.0);
    glVertex3f(-140.5, 70, -80.0);
    glVertex3f(-140.5, 70, -30.0);
    glVertex3f(-140.5, 20, -30.0);
    glEnd();

    // garis jendela dalam (pojok kiri atas)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-140.6, 19.5, -80.0);
    glVertex3f(-140.6, 69.5, -80.0);
    glVertex3f(-140.6, 69.5, -30.0);
    glVertex3f(-140.6, 19.5, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 32.5, -80.0);
    glVertex3f(-140.6, 32.5, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 45, -80.0);
    glVertex3f(-140.6, 45, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 57.5, -80.0);
    glVertex3f(-140.6, 57.5, -30.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 70, -46.6);
    glVertex3f(-140.6, 20, -46.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-140.6, 70, -63.2);
    glVertex3f(-140.6, 20, -63.2);
    glEnd();


    // pintu jendela kiri
    glBegin(GL_QUADS);//jendela  kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-155.5, 20, -90.0);
    glVertex3f(-155.5, 70, -90.0);
    glVertex3f(-140.5, 70, -80.0);
    glVertex3f(-140.5, 20, -80.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela kanan
   glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-140.5, 20, -30.0);
    glVertex3f(-140.5, 70, -30.0);
    glVertex3f(-155.5, 70, -20.0);
    glVertex3f(-155.5, 20, -20.0);
    glEnd();


    //..// ////

}
// JENDELA TEMBOK KANAN
void jendelakanan(void) {

    // jendela pojok kiri atas
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(0.5f, 0.5f, 0.45f); // warna jendela dalam
    glVertex3f(140.5, 110, 130.0);
    glVertex3f(140.5, 160, 130.0);
    glVertex3f(140.5, 160, 80.0);
    glVertex3f(140.5, 110, 80.0);
    glEnd();

    // jendela pojok kiri atas (garis jendela dalam)
    glBegin(GL_LINE_LOOP);//jendela pojok kanan atas kiri
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(140.5, 110, 130.0);
    glVertex3f(140.5, 160, 130.0);
    glVertex3f(140.5, 160, 80.0);
    glVertex3f(140.5, 110, 80.0);
    glEnd();

    // garis jendela dalam
    glBegin(GL_LINE_LOOP);//jendela pojok kanan atas kiri
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(140.6, 109.5, 130.0);
    glVertex3f(140.6, 159.5, 130.0);
    glVertex3f(140.6, 159.5, 80.0);
    glVertex3f(140.6, 109.5, 80.0);
    glEnd();


    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 122.5, 130.0);
    glVertex3f(140.6, 122.5, 80.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 135, 130.0);
    glVertex3f(140.6, 135, 80.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 147.5, 130.0);
    glVertex3f(140.6, 147.5, 80.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 160, 96.6);
    glVertex3f(140.6, 110, 96.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 160, 113.2);
    glVertex3f(140.6, 110, 113.2);
    glEnd();

    // pintu jendela kanan
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(155.5, 110, 140.0);
    glVertex3f(155.5, 160, 140.0);
    glVertex3f(140.5, 160, 130.0);
    glVertex3f(140.5, 110, 130.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(140.5, 110, 80.0);
    glVertex3f(140.5, 160, 80.0);
    glVertex3f(155.5, 160, 70.0);
    glVertex3f(155.5, 110, 70.0);
    glEnd();

    //..//
    // jendela tengah
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.45f);  // warna jendela dalam
    glVertex3f(140.5, 110, 50.0);
    glVertex3f(140.5, 160, 50.0);
    glVertex3f(140.5, 160, 0.0);
    glVertex3f(140.5, 110, 0.0);
    glEnd();

    // jendela tengah (garis dalam hitam)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(140.5, 110, 50.0);
    glVertex3f(140.5, 160, 50.0);
    glVertex3f(140.5, 160, 0.0);
    glVertex3f(140.5, 110, 0.0);
    glEnd();

    // garis jendela dalam (tengah)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(140.6, 109.5, 50.0);
    glVertex3f(140.6, 159.5, 50.0);
    glVertex3f(140.6, 159.5, 0.0);
    glVertex3f(140.6, 109.5, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 122.5, 50.0);
    glVertex3f(140.6, 122.5, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 135, 50.0);
    glVertex3f(140.6, 135, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 147.5, 50.0);
    glVertex3f(140.6, 147.5, 0.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 160, 16.6);
    glVertex3f(140.6, 110, 16.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 160, 33.2);
    glVertex3f(140.6, 110, 33.2);
    glEnd();


    // pintu jendela kanan
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(155.5, 110, 60.0);
    glVertex3f(155.5, 160, 60.0);
    glVertex3f(140.5, 160, 50.0);
    glVertex3f(140.5, 110, 50.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(140.5, 110, 0.0);
    glVertex3f(140.5, 160, 0.0);
    glVertex3f(155.5, 160, -10.0);
    glVertex3f(155.5, 110, -10.0);
    glEnd();
    //..//

    // jendela pojok kiri atas
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.45f); // warna jendela dalam
    glVertex3f(140.5, 110, -80.0);
    glVertex3f(140.5, 160, -80.0);
    glVertex3f(140.5, 160, -30.0);
    glVertex3f(140.5, 110, -30.0);
    glEnd();

    // jendela pojok kiri atas (garis dalam hitam)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(140.5, 110, -80.0);
    glVertex3f(140.5, 160, -80.0);
    glVertex3f(140.5, 160, -30.0);
    glVertex3f(140.5, 110, -30.0);
    glEnd();

    // garis jendela dalam (pojok kiri atas)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(140.6, 109.5, -80.0);
    glVertex3f(140.6, 159.5, -80.0);
    glVertex3f(140.6, 159.5, -30.0);
    glVertex3f(140.6, 109.5, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 122.5, -80.0);
    glVertex3f(140.6, 122.5, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 135, -80.0);
    glVertex3f(140.6, 135, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 147.5, -80.0);
    glVertex3f(140.6, 147.5, -30.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 160, -46.6);
    glVertex3f(140.6, 110, -46.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 160, -63.2);
    glVertex3f(140.6, 110, -63.2);
    glEnd();


    // pintu jendela kiri
    glBegin(GL_QUADS);//jendela  kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(155.5, 110, -90.0);
    glVertex3f(155.5, 160, -90.0);
    glVertex3f(140.5, 160, -80.0);
    glVertex3f(140.5, 110, -80.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(140.5, 110, -30.0);
    glVertex3f(140.5, 160, -30.0);
    glVertex3f(155.5, 160, -20.0);
    glVertex3f(155.5, 110, -20.0);
    glEnd();

    //..//
    //JENDELA LANTAI 1//

    // jendela pojok kiri atas
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(0.5f, 0.5f, 0.45f); // warna jendela dalam
    glVertex3f(140.5, 20, 130.0);
    glVertex3f(140.5, 70, 130.0);
    glVertex3f(140.5, 70, 80.0);
    glVertex3f(140.5, 20, 80.0);
    glEnd();

    // jendela pojok kiri atas (garis jendela dalam)
    glBegin(GL_LINE_LOOP);//jendela pojok kanan atas kiri
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(140.5, 20, 130.0);
    glVertex3f(140.5, 70, 130.0);
    glVertex3f(140.5, 70, 80.0);
    glVertex3f(140.5, 20, 80.0);
    glEnd();

    // garis jendela dalam
    glBegin(GL_LINE_LOOP);//jendela pojok kanan atas kiri
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(140.6, 19.5, 130.0);
    glVertex3f(140.6, 69.5, 130.0);
    glVertex3f(140.6, 69.5, 80.0);
    glVertex3f(140.6, 19.5, 80.0);
    glEnd();


    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 32.5, 130.0);
    glVertex3f(140.6, 32.5, 80.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 45, 130.0);
    glVertex3f(140.6, 45, 80.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 57.5, 130.0);
    glVertex3f(140.6, 57.5, 80.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 70, 96.6);
    glVertex3f(140.6, 20, 96.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 70, 113.2);
    glVertex3f(140.6, 20, 113.2);
    glEnd();

    // pintu jendela kanan
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(155.5, 20, 140.0);
    glVertex3f(155.5, 70, 140.0);
    glVertex3f(140.5, 70, 130.0);
    glVertex3f(140.5, 20, 130.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(140.5, 20, 80.0);
    glVertex3f(140.5, 70, 80.0);
    glVertex3f(155.5, 70, 70.0);
    glVertex3f(155.5, 20, 70.0);
    glEnd();

    //..//
    // jendela tengah
    // jendela tengahjen
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.45f); //warna jendela dalam
    glVertex3f(140.5, 20, 50.0);
    glVertex3f(140.5, 70, 50.0);
    glVertex3f(140.5, 70, 0.0);
    glVertex3f(140.5, 20, 0.0);
    glEnd();

    // jendela tengah (garis dalam hitam)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(140.5, 20, 50.0);
    glVertex3f(140.5, 70, 50.0);
    glVertex3f(140.5, 70, 0.0);
    glVertex3f(140.5, 20, 0.0);
    glEnd();

    // garis jendela dalam (tengah)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(140.6, 19.5, 50.0);
    glVertex3f(140.6, 69.5, 50.0);
    glVertex3f(140.6, 69.5, 0.0);
    glVertex3f(140.6, 19.5, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 32.5, 50.0);
    glVertex3f(140.6, 32.5, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 45, 50.0);
    glVertex3f(140.6, 45, 0.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 57.5, 50.0);
    glVertex3f(140.6, 57.5, 0.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 70, 16.6);
    glVertex3f(140.6, 20, 16.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 70, 33.2);
    glVertex3f(140.6, 20, 33.2);
    glEnd();


    // pintu jendela kanan
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(155.5, 20, 60.0);
    glVertex3f(155.5, 70, 60.0);
    glVertex3f(140.5, 70, 50.0);
    glVertex3f(140.5, 20, 50.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela pojok kanan atas kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(140.5, 20, 0.0);
    glVertex3f(140.5, 70, 0.0);
    glVertex3f(155.5, 70, -10.0);
    glVertex3f(155.5, 20, -10.0);
    glEnd();
    //..//

    // jendela pojok kiri atas
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.45f); // warna jendela dalam
    glVertex3f(140.5, 20, -80.0);
    glVertex3f(140.5, 70, -80.0);
    glVertex3f(140.5, 70, -30.0);
    glVertex3f(140.5, 20, -30.0);
    glEnd();

    // jendela pojok kiri atas (garis dalam hitam)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(140.5, 20, -80.0);
    glVertex3f(140.5, 70, -80.0);
    glVertex3f(140.5, 70, -30.0);
    glVertex3f(140.5, 20, -30.0);
    glEnd();

    // garis jendela dalam (pojok kiri atas)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(140.6, 19.5, -80.0);
    glVertex3f(140.6, 69.5, -80.0);
    glVertex3f(140.6, 69.5, -30.0);
    glVertex3f(140.6, 19.5, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 32.5, -80.0);
    glVertex3f(140.6, 32.5, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 45, -80.0);
    glVertex3f(140.6, 45, -30.0);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 57.5, -80.0);
    glVertex3f(140.6, 57.5, -30.0);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 70, -46.6);
    glVertex3f(140.6, 20, -46.6);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(140.6, 70, -63.2);
    glVertex3f(140.6, 20, -63.2);
    glEnd();


    // pintu jendela kiri
    glBegin(GL_QUADS);//jendela  kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(155.5, 20, -90.0);
    glVertex3f(155.5, 70, -90.0);
    glVertex3f(140.5, 70, -80.0);
    glVertex3f(140.5, 20, -80.0);
    glEnd();

    // pintu jendela Kiri
    glBegin(GL_QUADS);//jendela kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(140.5, 20, -30.0);
    glVertex3f(140.5, 70, -30.0);
    glVertex3f(155.5, 70, -20.0);
    glVertex3f(155.5, 20, -20.0);
    glEnd();


    //..// ////





}

void jendelatengah(void) {

    glBegin(GL_QUADS);//jendela dalam
    glColor3f(0.5f, 0.5f, 0.45f);
    glVertex3f(-113.0, 110, 150.2);
    glVertex3f(-113.0, 160, 150.2);
    glVertex3f(-63.0, 160, 150.2);
    glVertex3f(-63.0, 110, 150.2);
    glEnd();


    glBegin(GL_LINE_LOOP);//garis jendela dalam
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-113.0, 110, 150.2);
    glVertex3f(-113.0, 160, 150.2);
    glVertex3f(-63.0, 160, 150.2);
    glVertex3f(-63.0, 110, 150.2);
    glEnd();

    // figura dalam
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-112.7, 110.3, 150.2);
    glVertex3f(-112.7, 159.7, 150.2);
    glVertex3f(-63.3, 159.7, 150.2);
    glVertex3f(-63.3, 110.3, 150.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-112.7, 122.5, 150.2);
    glVertex3f(-63.3, 122.5, 150.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-112.7, 135, 150.2);
    glVertex3f(-63.3, 135, 150.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-112.7, 147.5, 150.2);
    glVertex3f(-63.3, 147.5, 150.2);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-96.4, 160, 150.2);
    glVertex3f(-96.4, 110, 150.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-79.8, 160, 150.2);
    glVertex3f(-79.8, 110, 150.2);
    glEnd();

    // pintu jendela kiri
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-123.5, 110, 160.2);
    glVertex3f(-123.5, 160, 160.2);
    glVertex3f(-113.5, 160, 150.2);
    glVertex3f(-113.5, 110, 150.2);
    glEnd();

    // pintu jendela kanan
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-63.0, 110, 150.2);
    glVertex3f(-63.0, 160, 150.2);
    glVertex3f(-53.0, 160, 160.2);
    glVertex3f(-53.0, 110, 160.2);
    glEnd();

}
void jendeladepantengah(void) {
    //jendela tengah
    glBegin(GL_QUADS);//jendela dalam
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-18.0, 90, 140.2);
    glVertex3f(-18.0, 140, 140.2);
    glVertex3f(18.0, 140, 140.2);
    glVertex3f(18.0, 90, 140.2);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis jendela dalam
    glColor3f(97/255.0f, 95/255.0f, 98/255.0f);
    glVertex3f(-18.0, 90, 140.2);
    glVertex3f(-18.0, 140, 140.2);
    glVertex3f(18.0, 140, 140.2);
    glVertex3f(18.0, 90, 140.2);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(97/255.0f, 95/255.0f, 98/255.0f);
    glVertex3f(0, 140, 140.2);
    glVertex3f(0, 90, 140.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(97/255.0f, 95/255.0f, 98/255.0f);
    glVertex3f(-17.5, 105, 140.2);
    glVertex3f(17.5, 105, 140.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(97/255.0f, 95/255.0f, 98/255.0f);
    glVertex3f(-17.5, 125, 140.2);
    glVertex3f(17.5, 125, 140.2);
    glEnd();

    // jendela atas tengah
    glBegin(GL_QUADS);//jendela dalam
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-18.0, 140, 140.2);
    glVertex3f(-18.0, 155, 140.2);
    glVertex3f(18.0, 155, 140.2);
    glVertex3f(18.0, 140, 140.2);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis jendela dalam
    glColor3f(97/255.0f, 95/255.0f, 98/255.0f);
    glVertex3f(-18.0, 140, 140.2);
    glVertex3f(-18.0, 155, 140.2);
    glVertex3f(18.0, 155, 140.2);
    glVertex3f(18.0, 140, 140.2);
    glEnd();

    // pintu jendela kiri
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-30, 90, 150.2);
    glVertex3f(-30, 140, 150.2);
    glVertex3f(-19.5, 140, 140.2);
    glVertex3f(-19.5, 90, 140.2);
    glEnd();

    // pintu jendela kanan
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(19.5, 90, 140.2);
    glVertex3f(19.5, 140, 140.2);
    glVertex3f(30, 140, 150.2);
    glVertex3f(30, 90, 150.2);
    glEnd();

}

void jendelabelakang(void) {

    //jendela kanan atas
    glBegin(GL_QUADS);//jendela dalam
    glColor3f(0.5f, 0.5f, 0.45f);
    glVertex3f(-113.0, 110, -100.2);
    glVertex3f(-113.0, 160, -100.2);
    glVertex3f(-63.0, 160,  -100.2);
    glVertex3f(-63.0, 110,  -100.2);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis jendela dalam
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-113.0, 110, -100.2);
    glVertex3f(-113.0, 160, -100.2);
    glVertex3f(-63.0, 160,  -100.2);
    glVertex3f(-63.0, 110,  -100.2);
    glEnd();

    glBegin(GL_LINE_LOOP);// figura dalam
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-112.7, 110.3, -100.2);
    glVertex3f(-112.7, 159.7, -100.2);
    glVertex3f(-63.3, 159.7, -100.2);
    glVertex3f(-63.3, 110.3, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-112.7, 122.5, -100.2);
    glVertex3f(-63.3, 122.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-112.7, 135, -100.2);
    glVertex3f(-63.3, 135, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-112.7, 147.5, -100.2);
    glVertex3f(-63.3, 147.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-96.4, 160, -100.2);
    glVertex3f(-96.4, 110, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-79.8, 160, -100.2);
    glVertex3f(-79.8, 110, -100.2);
    glEnd();

    glBegin(GL_QUADS);    // pintu jendela kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-123.5, 110, -110.2);
    glVertex3f(-123.5, 160, -110.2);
    glVertex3f(-113.5, 160, -100.2);
    glVertex3f(-113.5, 110, -100.2);
    glEnd();

    glBegin(GL_QUADS); // pintu jendela kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-63.0, 110, -100.2);
    glVertex3f(-63.0, 160, -100.2);
    glVertex3f(-53.0, 160, -110.2);
    glVertex3f(-53.0, 110, -110.2);
    glEnd();


    //jendela kiri atas
    glBegin(GL_QUADS);//jendela dalam
    glColor3f(0.5f, 0.5f, 0.45f);
    glVertex3f(113.0, 110, -100.2);
    glVertex3f(113.0, 160, -100.2);
    glVertex3f(63.0, 160, -100.2);
    glVertex3f(63.0, 110, -100.2);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis jendela dalam
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(113.0, 110, -100.2);
    glVertex3f(113.0, 160, -100.2);
    glVertex3f(63.0, 160, -100.2);
    glVertex3f(63.0, 110, -100.2);
    glEnd();

    // figura dalam
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(112.7, 110.3, -100.2);
    glVertex3f(112.7, 159.7, -100.2);
    glVertex3f(63.3, 159.7, -100.2);
    glVertex3f(63.3, 110.3, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(112.7, 122.5, -100.2);
    glVertex3f(63.3, 122.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(112.7, 135, -100.2);
    glVertex3f(63.3, 135, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(112.7, 147.5, -100.2);
    glVertex3f(63.3, 147.5, -100.2);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(96.4, 160, -100.2);
    glVertex3f(96.4, 110, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(79.8, 160, -100.2);
    glVertex3f(79.8, 110, -100.2);
    glEnd();

    // pintu jendela kiri
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(123.5, 110, -110.2);
    glVertex3f(123.5, 160, -110.2);
    glVertex3f(113.5, 160, -100.2);
    glVertex3f(113.5, 110, -100.2);
    glEnd();

    // pintu jendela kanan
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(63.0, 110, -100.2);
    glVertex3f(63.0, 160, -100.2);
    glVertex3f(53.0, 160, -110.2);
    glVertex3f(53.0, 110, -110.2);
    glEnd();


    //jendela tengah atas
    glBegin(GL_QUADS);//jendela dalam
    glColor3f(0.5f, 0.5f, 0.45f);
    glVertex3f(25.0, 110, -100.2);
    glVertex3f(25.0, 160, -100.2);
    glVertex3f(-25.0, 160, -100.2);
    glVertex3f(-25.0, 110, -100.2);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis jendela dalam
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(25.0, 110, -100.2);
    glVertex3f(25.0, 160, -100.2);
    glVertex3f(-25.0, 160, -100.2);
    glVertex3f(-25.0, 110, -100.2);
    glEnd();

    // figura dalam
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(24.5, 110.3, -100.2);
    glVertex3f(24.5, 159.7, -100.2);
    glVertex3f(-24.5, 159.7, -100.2);
    glVertex3f(-24.5, 110.3, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(24.5, 122.5, -100.2);
    glVertex3f(-24.5, 122.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(24.5, 135, -100.2);
    glVertex3f(-24.5, 135, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(24.5, 147.5, -100.2);
    glVertex3f(-24.5, 147.5, -100.2);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-8, 160, -100.2);
    glVertex3f(-8, 110, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(8, 160, -100.2);
    glVertex3f(8, 110, -100.2);
    glEnd();

    // pintu jendela kiri
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(35.5, 110, -110.2);
    glVertex3f(35.5, 160, -110.2);
    glVertex3f(25.5, 160, -100.2);
    glVertex3f(25.5, 110, -100.2);
    glEnd();

    // pintu jendela kanan
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-25.5, 110, -100.2);
    glVertex3f(-25.5, 160, -100.2);
    glVertex3f(-35.5, 160, -110.2);
    glVertex3f(-35.5, 110, -110.2);
    glEnd();

    // LANTAI 1
    // jendela kanan bawah
    glBegin(GL_QUADS);//jendela dalam
    glColor3f(0.5f, 0.5f, 0.45f);
    glVertex3f(-113.0, 20, -100.2);
    glVertex3f(-113.0, 70, -100.2);
    glVertex3f(-63.0, 70, -100.2);
    glVertex3f(-63.0, 20, -100.2);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis jendela dalam
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-113.0, 20, -100.2);
    glVertex3f(-113.0, 70, -100.2);
    glVertex3f(-63.0, 70, -100.2);
    glVertex3f(-63.0, 20, -100.2);
    glEnd();

    glBegin(GL_LINE_LOOP);// figura dalam
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-112.7, 19.5, -100.2);
    glVertex3f(-112.7, 69.5, -100.2);
    glVertex3f(-63.3, 69.5, -100.2);
    glVertex3f(-63.3, 19.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-112.7, 32.5, -100.2);
    glVertex3f(-63.3, 32.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-112.7, 45, -100.2);
    glVertex3f(-63.3, 45, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-112.7, 57.5, -100.2);
    glVertex3f(-63.3, 57.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-96.4, 70, -100.2);
    glVertex3f(-96.4, 20, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-79.8, 70, -100.2);
    glVertex3f(-79.8, 20, -100.2);
    glEnd();

    glBegin(GL_QUADS);    // pintu jendela kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-123.5, 20, -110.2);
    glVertex3f(-123.5, 70, -110.2);
    glVertex3f(-113.5, 70, -100.2);
    glVertex3f(-113.5, 20, -100.2);
    glEnd();

    glBegin(GL_QUADS); // pintu jendela kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-63.0, 20, -100.2);
    glVertex3f(-63.0, 70, -100.2);
    glVertex3f(-53.0, 70, -110.2);
    glVertex3f(-53.0, 20, -110.2);
    glEnd();

    // jendela kiri bawah
    glBegin(GL_QUADS);//jendela dalam
    glColor3f(0.5f, 0.5f, 0.45f);
    glVertex3f(113.0, 20, -100.2);
    glVertex3f(113.0, 70, -100.2);
    glVertex3f(63.0, 70, -100.2);
    glVertex3f(63.0, 20, -100.2);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis jendela dalam
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(113.0, 20, -100.2);
    glVertex3f(113.0, 70, -100.2);
    glVertex3f(63.0, 70, -100.2);
    glVertex3f(63.0, 20, -100.2);
    glEnd();

    glBegin(GL_LINE_LOOP);// figura dalam
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(112.7, 19.5, -100.2);
    glVertex3f(112.7, 69.5, -100.2);
    glVertex3f(63.3, 69.5, -100.2);
    glVertex3f(63.3, 19.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(112.7, 32.5, -100.2);
    glVertex3f(63.3, 32.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(112.7, 45, -100.2);
    glVertex3f(63.3, 45, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(112.7, 57.5, -100.2);
    glVertex3f(63.3, 57.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(96.4, 70, -100.2);
    glVertex3f(96.4, 20, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(79.8, 70, -100.2);
    glVertex3f(79.8, 20, -100.2);
    glEnd();

    glBegin(GL_QUADS);    // pintu jendela kiri
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(123.5, 20, -110.2);
    glVertex3f(123.5, 70, -110.2);
    glVertex3f(113.5, 70, -100.2);
    glVertex3f(113.5, 20, -100.2);
    glEnd();

    glBegin(GL_QUADS); // pintu jendela kanan
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(63.0, 20, -100.2);
    glVertex3f(63.0, 70, -100.2);
    glVertex3f(53.0, 70, -110.2);
    glVertex3f(53.0, 20, -110.2);
    glEnd();


    //jendela tengah bawah
    glBegin(GL_QUADS);//jendela dalam
    glColor3f(0.5f, 0.5f, 0.45f);
    glVertex3f(25.0, 20, -100.2);
    glVertex3f(25.0, 70, -100.2);
    glVertex3f(-25.0, 70, -100.2);
    glVertex3f(-25.0, 20, -100.2);
    glEnd();

    glBegin(GL_LINE_LOOP);//garis jendela dalam
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(25.0, 20, -100.2);
    glVertex3f(25.0, 70, -100.2);
    glVertex3f(-25.0, 70, -100.2);
    glVertex3f(-25.0, 20, -100.2);
    glEnd();

    // figura dalam
    glBegin(GL_LINE_LOOP);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(24.5, 19.5, -100.2);
    glVertex3f(24.5, 69.5, -100.2);
    glVertex3f(-24.5, 69.5, -100.2);
    glVertex3f(-24.5, 19.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(24.5, 32.5, -100.2);
    glVertex3f(-24.5, 32.5, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(24.5, 45, -100.2);
    glVertex3f(-24.5, 45, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Horizontal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(24.5, 57.5, -100.2);
    glVertex3f(-24.5, 57.5, -100.2);
    glEnd();

    // Garis Verikal
    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(-8, 70, -100.2);
    glVertex3f(-8, 20, -100.2);
    glEnd();

    glBegin(GL_LINES); //Garis Vertikal
    glColor3f(143/255.0f, 137/255.0f, 137/255.0f);
    glVertex3f(8, 70, -100.2);
    glVertex3f(8, 20, -100.2);
    glEnd();

    // pintu jendela kiri
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(35.5, 20, -110.2);
    glVertex3f(35.5, 70, -110.2);
    glVertex3f(25.5, 70, -100.2);
    glVertex3f(25.5, 20, -100.2);
    glEnd();

    // pintu jendela kanan
    glBegin(GL_QUADS);
    glColor3f(5/255.0f, 6/255.0f, 10/255.0f);
    glVertex3f(-25.5, 20, -100.2);
    glVertex3f(-25.5, 70, -100.2);
    glVertex3f(-35.5, 70, -110.2);
    glVertex3f(-35.5, 20, -110.2);
    glEnd();

}


void jalanrumah(void) {
    glBegin(GL_QUADS);//Jalan Halaman kampus
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-400.0, -10.0, -400.0);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex3f(-400.0, -10.0, 400.0);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(400.0, -10.0, 400.0);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(400.0, -10.0, -400.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis Halaman kampus
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-400.0, -10.0, -400.0);
    glVertex3f(-400.0, -10.0, 400.0);
    glVertex3f(400.0, -10.0, 400.0);
    glVertex3f(400.0, -10.0, -400.0);
    glEnd();

}

void atap(void) {
    glBegin(GL_TRIANGLES); //atap segitiga depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(40.0, 180.0, 140.0);
    glVertex3f(0.0, 210.0, 140.0);
    glVertex3f(-40.0, 180.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap segitiga depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(40.0, 180.0, 140.0);
    glVertex3f(0.0, 210.0, 140.0);
    glVertex3f(-40.0, 180.0, 140.0);
    glEnd();
    glBegin(GL_TRIANGLES); //atap segitiga belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(40.0, 180.0, -100.0);
    glVertex3f(0.0, 210.0, -100.0);
    glVertex3f(-40.0, 180.0, -100.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap segitiga belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(40.0, 180.0, -100.0);
    glVertex3f(0.0, 210.0, -100.0);
    glVertex3f(-40.0, 180.0, -100.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); //atap segitiga kanan
    glVertex3f(40.0, 180.0, -100.0);
    glVertex3f(0.0, 210.0, -100.0);
    glVertex3f(0.0, 210.0, 140.0);
    glVertex3f(40.0, 180.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP); // garis atap segitiga kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(40.0, 180.0, -100.0);
    glVertex3f(0.0, 210.0, -100.0);
    glVertex3f(0.0, 210.0, 140.0);
    glVertex3f(40.0, 180.0, 140.0);
    glEnd();
    glBegin(GL_QUADS); //atap segitiga kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-40.0, 180.0, -100.0);
    glVertex3f(0.0, 210.0, -100.0);
    glVertex3f(0.0, 210.0, 140.0);
    glVertex3f(-40.0, 180.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap segitiga kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-40.0, 180.0, -100.0);
    glVertex3f(0.0, 210.0, -100.0);
    glVertex3f(0.0, 210.0, 140.0);
    glVertex3f(-40.0, 180.0, 140.0);
    glEnd();

    glBegin(GL_QUADS); //atap alas kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-140.0, 180.0, -100.0);
    glVertex3f(-40.0, 180.0, -100.0);
    glVertex3f(-40.0, 180.0, 150.0);
    glVertex3f(-140.0, 180.0, 150.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap alas kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-140.0, 180.0, -100.0);
    glVertex3f(-40.0, 180.0, -100.0);
    glVertex3f(-40.0, 180.0, 150.0);
    glVertex3f(-140.0, 180.0, 150.0);
    glEnd();
    glBegin(GL_QUADS); //atap alas kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(140.0, 180.0, -100.0);
    glVertex3f(40.0, 180.0, -100.0);
    glVertex3f(40.0, 180.0, 150.0);
    glVertex3f(140.0, 180.0, 150.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap alas kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(140.0, 180.0, -100.0);
    glVertex3f(40.0, 180.0, -100.0);
    glVertex3f(40.0, 180.0, 150.0);
    glVertex3f(140.0, 180.0, 150.0);
    glEnd();

    glBegin(GL_QUADS); //atap berdiri depan bagiam kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(130.0, 180.0, 140.0);
    glVertex3f(50.0, 180.0, 140.0);
    glVertex3f(50.0, 190.0, 140.0);
    glVertex3f(130.0, 190.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap berdiri depan bagiam kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(130.0, 181.0, 140.0);
    glVertex3f(50.0, 181.0, 140.0);
    glVertex3f(50.0, 190.0, 140.0);
    glVertex3f(130.0, 190.0, 140.0);
    glEnd();
    glBegin(GL_QUADS); //atap berdiri belakang bagiam kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(130.0, 180.0, -90.0);
    glVertex3f(50.0, 180.0, -90.0);
    glVertex3f(50.0, 190.0, -90.0);
    glVertex3f(130.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap berdiri belakang bagiam kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(130.0, 180.0, -90.0);
    glVertex3f(50.0, 180.0, -90.0);
    glVertex3f(50.0, 190.0, -90.0);
    glVertex3f(130.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_QUADS); //atap berdiri kiri bagiam kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(50.0, 180.0, -90.0);
    glVertex3f(50.0, 180.0, 140.0);
    glVertex3f(50.0, 190.0, 140.0);
    glVertex3f(50.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap berdiri kiri bagiam kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0, 180.0, -90.0);
    glVertex3f(50.0, 180.0, 140.0);
    glVertex3f(50.0, 190.0, 140.0);
    glVertex3f(50.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_QUADS); //atap berdiri kanan bagiam kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(130.0, 180.0, -90.0);
    glVertex3f(130.0, 180.0, 140.0);
    glVertex3f(130.0, 190.0, 140.0);
    glVertex3f(130.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap berdiri kanan bagiam kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(130.0, 180.0, -90.0);
    glVertex3f(130.0, 180.0, 140.0);
    glVertex3f(130.0, 190.0, 140.0);
    glVertex3f(130.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_QUADS); //tutup atap kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(140.0, 191.0, -95.0);
    glVertex3f(40.0, 191.0, -95.0);
    glVertex3f(40.0, 191.0, 145.0);
    glVertex3f(140.0, 191.0, 145.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tutup atap kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(140.0, 191.0, -95.0);
    glVertex3f(40.0, 191.0, -95.0);
    glVertex3f(40.0, 191.0, 145.0);
    glVertex3f(140.0, 191.0, 145.0);
    glEnd();

    glBegin(GL_QUADS); //atap berdiri depan bagiam kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-130.0, 180.0, 140.0);
    glVertex3f(-50.0, 180.0, 140.0);
    glVertex3f(-50.0, 190.0, 140.0);
    glVertex3f(-130.0, 190.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap berdiri depan bagiam kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-130.0, 181.0, 140.0);
    glVertex3f(-50.0, 181.0, 140.0);
    glVertex3f(-50.0, 190.0, 140.0);
    glVertex3f(-130.0, 190.0, 140.0);
    glEnd();
    glBegin(GL_QUADS); //atap berdiri belakang bagiam kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-130.0, 180.0, -90.0);
    glVertex3f(-50.0, 180.0, -90.0);
    glVertex3f(-50.0, 190.0, -90.0);
    glVertex3f(-130.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap berdiri belakang bagiam kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-130.0, 180.0, -90.0);
    glVertex3f(-50.0, 180.0, -90.0);
    glVertex3f(-50.0, 190.0, -90.0);
    glVertex3f(-130.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_QUADS); //atap berdiri kiri bagiam kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-50.0, 180.0, -90.0);
    glVertex3f(-50.0, 180.0, 140.0);
    glVertex3f(-50.0, 190.0, 140.0);
    glVertex3f(-50.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap berdiri kiri bagiam kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-50.0, 180.0, -90.0);
    glVertex3f(-50.0, 180.0, 140.0);
    glVertex3f(-50.0, 190.0, 140.0);
    glVertex3f(-50.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_QUADS); //atap berdiri kanan bagiam kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-130.0, 180.0, -90.0);
    glVertex3f(-130.0, 180.0, 140.0);
    glVertex3f(-130.0, 190.0, 140.0);
    glVertex3f(-130.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap berdiri kanan bagiam kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-130.0, 180.0, -90.0);
    glVertex3f(-130.0, 180.0, 140.0);
    glVertex3f(-130.0, 190.0, 140.0);
    glVertex3f(-130.0, 190.0, -90.0);
    glEnd();
    glBegin(GL_QUADS); //tutup atap kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-140.0, 191.0, -95.0);
    glVertex3f(-40.0, 191.0, -95.0);
    glVertex3f(-40.0, 191.0, 145.0);
    glVertex3f(-140.0, 191.0, 145.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tutup atap kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-140.0, 191.0, -95.0);
    glVertex3f(-40.0, 191.0, -95.0);
    glVertex3f(-40.0, 191.0, 145.0);
    glVertex3f(-140.0, 191.0, 145.0);
    glEnd();
}

void hiasandindingkiri(int y){


glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex3f(-139.5,160.0 - y,150.2);
glVertex3f(-131.5,160.0 - y,150.2);
glVertex3f(-131.5,155.0 - y,150.2);
glVertex3f(-139.5,155.0 - y,150.2);
glEnd();

glBegin(GL_LINE_STRIP); //garis
glLineWidth(0.0);
glColor3f(143/255.0f,143/255.0f,145/255.0f);
glVertex3f(-139.5,160.0 - y,150.2);
glVertex3f(-131.5,160.0 - y,150.2);
glVertex3f(-131.5,155.0 - y,150.2);
glVertex3f(-139.5,155.0 - y,150.2);
glEnd();

}

void hiasandindingkanan(int y){
glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex3f(-40.5,160.0 - y,150.2);
glVertex3f(-48.5,160.0 - y,150.2);
glVertex3f(-48.5,155.0 - y,150.2);
glVertex3f(-40.5,155.0 - y,150.2);
glEnd();

glBegin(GL_LINE_STRIP); //garis
glLineWidth(0.0);
glColor3f(143/255.0f,143/255.0f,145/255.0f);
glVertex3f(-40.5,160.0 - y,150.2);
glVertex3f(-48.5,160.0 - y,150.2);
glVertex3f(-48.5,155.0 - y,150.2);
glVertex3f(-40.5,155.0 - y,150.2);
glEnd();


}

void hiasandindingkiridalam(int y){
glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex3f(-40.0,160.0 - y,149.8);
glVertex3f(-40.0,160.0 - y,140.2);
glVertex3f(-40.0,155.0 - y,140.2);
glVertex3f(-40.0,155.0 - y,149.8);
glEnd();

glBegin(GL_LINE_STRIP); //garis
glLineWidth(0.0);
glColor3f(143/255.0f,143/255.0f,145/255.0f);
glVertex3f(-40.0,160.0 - y,149.8);
glVertex3f(-40.0,160.0 - y,140.2);
glVertex3f(-40.0,155.0 - y,140.2);
glVertex3f(-40.0,155.0 - y,149.8);
glEnd();
}


void pintukampus(void) {
    glBegin(GL_QUADS); //belakang pintu
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-18, 2.0, 141.05);
    glVertex3f(18, 2.0, 141.05);
    glVertex3f(18, 41.0, 141.05);
    glVertex3f(-18, 41.0, 141.05);
    glEnd();

    glPushMatrix();
    glTranslatef(angkatranslasi2, 1.0, 0.0);
    glBegin(GL_QUADS);//pintu kampus kiri
    glColor3f(34/255.0f, 14/255.0f, 13/255.0f);
    glVertex3f(-18, 1.0, 141.1);
    glVertex3f(-18, 40.0, 141.1);
    glVertex3f(0, 40.0, 141.1);
    glVertex3f(0, 1.0, 141.1);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis pintu kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-18, 1.0, 141.1);
    glVertex3f(-18, 40.0, 141.1);
    glVertex3f(0, 40.0, 141.1);
    glVertex3f(0, 1.0, 141.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(angkatranslasi, 1.0, 0.0);
    glBegin(GL_QUADS);//pintu kampus kanan
    glColor3f(34/255.0f, 14/255.0f, 13/255.0f);
    glVertex3f(0, 1.0, 141.1);
    glVertex3f(0, 40.0, 141.1);
    glVertex3f(18, 40.0, 141.1);
    glVertex3f(18, 1.0, 141.1);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(angkatranslasi, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);//garis pintu kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0, 1.0, 141.1);
    glVertex3f(0, 40.0, 141.1);
    glVertex3f(18, 40.0, 141.1);
    glVertex3f(18, 1.0, 141.1);
    glEnd();
    glPopMatrix();
}

void atapPintu(void) {
    glBegin(GL_QUADS); //tiang depan 1
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(23.0, 2.0, 200.0);
    glVertex3f(20.0, 2.0, 200.0);
    glVertex3f(20.0, 48.0, 200.0);
    glVertex3f(23.0, 48.0, 200.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tiang depan 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(23.0, 2.0, 200.0);
    glVertex3f(20.0, 2.0, 200.0);
    glVertex3f(20.0, 48.0, 200.0);
    glVertex3f(23.0, 48.0, 200.0);
    glEnd();
    glBegin(GL_QUADS); //tiang belakang 1
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(23.0, 2.0, 197.0);
    glVertex3f(20.0, 2.0, 197.0);
    glVertex3f(20.0, 48.0, 197.0);
    glVertex3f(23.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tiang belakang 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(23.0, 2.0, 197.0);
    glVertex3f(20.0, 2.0, 197.0);
    glVertex3f(20.0, 48.0, 197.0);
    glVertex3f(23.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_QUADS); //tiang kiri 1
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(20.0, 2.0, 197.0);
    glVertex3f(20.0, 2.0, 200.0);
    glVertex3f(20.0, 48.0, 200.0);
    glVertex3f(20.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tiang kiri 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(20.0, 2.0, 197.0);
    glVertex3f(20.0, 2.0, 200.0);
    glVertex3f(20.0, 48.0, 200.0);
    glVertex3f(20.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_QUADS); //tiang kanan 1
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(23.0, 2.0, 197.0);
    glVertex3f(23.0, 2.0, 200.0);
    glVertex3f(23.0, 48.0, 200.0);
    glVertex3f(23.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tiang kanan 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(23.0, 2.0, 197.0);
    glVertex3f(23.0, 2.0, 200.0);
    glVertex3f(23.0, 48.0, 200.0);
    glVertex3f(23.0, 48.0, 197.0);
    glEnd();

    glBegin(GL_QUADS); //tiang depan 1
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(-23.0, 2.0, 200.0);
    glVertex3f(-20.0, 2.0, 200.0);
    glVertex3f(-20.0, 48.0, 200.0);
    glVertex3f(-23.0, 48.0, 200.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tiang depan 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-23.0, 2.0, 200.0);
    glVertex3f(-20.0, 2.0, 200.0);
    glVertex3f(-20.0, 48.0, 200.0);
    glVertex3f(-23.0, 48.0, 200.0);
    glEnd();
    glBegin(GL_QUADS); //tiang belakang 1
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(-23.0, 2.0, 197.0);
    glVertex3f(-20.0, 2.0, 197.0);
    glVertex3f(-20.0, 48.0, 197.0);
    glVertex3f(-23.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tiang belakang 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-23.0, 2.0, 197.0);
    glVertex3f(-20.0, 2.0, 197.0);
    glVertex3f(-20.0, 48.0, 197.0);
    glVertex3f(-23.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_QUADS); //tiang kiri 1
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(-20.0, 2.0, 197.0);
    glVertex3f(-20.0, 2.0, 200.0);
    glVertex3f(-20.0, 48.0, 200.0);
    glVertex3f(-20.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tiang kiri 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-20.0, 2.0, 197.0);
    glVertex3f(-20.0, 2.0, 200.0);
    glVertex3f(-20.0, 48.0, 200.0);
    glVertex3f(-20.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_QUADS); //tiang kanan 1
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(-23.0, 2.0, 197.0);
    glVertex3f(-23.0, 2.0, 200.0);
    glVertex3f(-23.0, 48.0, 200.0);
    glVertex3f(-23.0, 48.0, 197.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis tiang kanan 1
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-23.0, 2.0, 197.0);
    glVertex3f(-23.0, 2.0, 200.0);
    glVertex3f(-23.0, 48.0, 200.0);
    glVertex3f(-23.0, 48.0, 197.0);
    glEnd();

    glBegin(GL_QUADS); //atap bawah
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(-28.0, 48.0, 210.0);
    glVertex3f(28.0, 48.0, 210.0);
    glVertex3f(28.0, 48.0, 140.0);
    glVertex3f(-28.0, 48.0, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap bawah
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-27.0, 48.0, 210.0);
    glVertex3f(27.0, 48.0, 210.0);
    glVertex3f(27.0, 48.0, 140.0);
    glVertex3f(-27.0, 48.0, 140.0);
    glEnd();
    glBegin(GL_QUADS); //atap samping kiri
    glColor3f(19/255.0f, 10/255.0f, 13/255.0f);
    glVertex3f(-35.0, 42, 215.0);
    glVertex3f(0.0, 72.0, 215.0);
    glVertex3f(0.0, 72.0, 140.0);
    glVertex3f(-35.0, 42, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap samping kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-35.0, 42, 215.0);
    glVertex3f(0.0, 72.0, 215.0);
    glVertex3f(0.0, 72.0, 140.0);
    glVertex3f(-35.0, 42, 140.0);
    glEnd();
    glBegin(GL_QUADS); //atap samping kanan
    glColor3f(19/255.0f, 10/255.0f, 13/255.0f);
    glVertex3f(35.0, 42, 215.0);
    glVertex3f(0.0, 72.0, 215.0);
    glVertex3f(0.0, 72.0, 140.0);
    glVertex3f(35.0, 42, 140.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap samping kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(35.0, 42, 215.0);
    glVertex3f(0.0, 72.0, 215.0);
    glVertex3f(0.0, 72.0, 140.0);
    glVertex3f(35.0, 42, 140.0);
    glEnd();
    glBegin(GL_TRIANGLES); //atap depan
    glColor3f(7/255.0f, 5/255.0f, 10/255.0f);
    glVertex3f(-28.0, 48.0, 200.0);
    glVertex3f(0.0, 72.0, 200.0);
    glVertex3f(28.0, 48.0, 200.0);
    glEnd();
    glBegin(GL_LINE_LOOP); //garis atap depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-28.0, 47.0, 200.0);
    glVertex3f(0.0, 72.0, 200.0);
    glVertex3f(28.0, 47.0, 200.0);
    glEnd();
}

void papantulis(void) {
    glBegin(GL_QUADS);//Papan Tulis
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-30, 10.0, -98);
    glVertex3f(-30, 40.0, -98);
    glVertex3f(30, 40.0, -98);
    glVertex3f(30, 10.0, -98);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis Papan Tulis
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-30, 10.0, -98);
    glVertex3f(-30, 40.0, -98);
    glVertex3f(30, 40.0, -98);
    glVertex3f(30, 10.0, -98);
    glEnd();
}

void redcarpet(void) {
    glBegin(GL_QUADS);// RED CARPET
    glColor3f(0.973f, 0.0f, 0.0f);
    glVertex3f(-60, -3.0, -50);
    glVertex3f(-60, -3.0, 50);
    glVertex3f(60, -3.0, 50);
    glVertex3f(60, -3.0, -50);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS RED CARPET
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-60, -3.0, -50);
    glVertex3f(-60, -3.0, 50);
    glVertex3f(60, -3.0, 50);
    glVertex3f(60, -3.0, -50);
    glEnd();
}

void pijakankaki(void) {
    glBegin(GL_QUADS); //Pijakan Kaki (belakang)
    glColor3f(0.165f, 0.09f, 0.004f);
    glVertex3f(-30, 0.0, -98);
    glVertex3f(-30, 8.0, -98);
    glVertex3f(30, 8.0, -98);
    glVertex3f(30, 0.0, -98);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis pijakan kaki (belakang)
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-30, 0.0, -98);
    glVertex3f(-30, 8.0, -98);
    glVertex3f(30, 8.0, -98);
    glVertex3f(30, 0.0, -98);
    glEnd();
    glBegin(GL_QUADS); //Pijakan Kaki (atas)
    glColor3f(0.165f, 0.09f, 0.004f);
    glVertex3f(-30, 8.0, -98);
    glVertex3f(-30, 8.0, -90);
    glVertex3f(30, 8.0, -90);
    glVertex3f(30, 8.0, -98);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis pijakan kaki (atas)
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-30, 8.0, -98);
    glVertex3f(-30, 8.0, -90);
    glVertex3f(30, 8.0, -90);
    glVertex3f(30, 8.0, -98);
    glEnd();
    glBegin(GL_QUADS); //Pijakan Kaki (depan)
    glColor3f(0.165f, 0.09f, 0.004f);
    glVertex3f(-30, 0.0, -85);
    glVertex3f(-30, 8.0, -90);
    glVertex3f(30, 8.0, -90);
    glVertex3f(30, 0.0, -85);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis pijakan kaki (depan)
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-30, 0.0, -85);
    glVertex3f(-30, 8.0, -90);
    glVertex3f(30, 8.0, -90);
    glVertex3f(30, 0.0, -85);
    glEnd();
    glBegin(GL_QUADS); //Pijakan Kaki (bawah)
    glColor3f(0.165f, 0.09f, 0.004f);
    glVertex3f(-30, 0.0, -98);
    glVertex3f(-30, 0.0, -85);
    glVertex3f(30, 0.0, -85);
    glVertex3f(30, 0.0, -98);
    glEnd();
    glBegin(GL_LINE_LOOP);//Garis pijakan kaki (depan)
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-30, 0.0, -98);
    glVertex3f(-30, 0.0, -85);
    glVertex3f(30, 0.0, -85);
    glVertex3f(30, 0.0, -98);
    glEnd();

}

void rakdinding(void) {
    glBegin(GL_QUADS);//Rak Dinding
    glColor3f(0.671f, 0.322f, 0.0f);
    glVertex3f(-120, 35.0, -50);
    glVertex3f(-120, 35.0, 50);
    glVertex3f(-138, 35.0, 50);
    glVertex3f(-138, 35.0, -50);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS Rak Dinding
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-120, 35.0, -50);
    glVertex3f(-120, 35.0, 50);
    glVertex3f(-138, 35.0, 50);
    glVertex3f(-138, 35.0, -50);
    glEnd();
}

void LCD(void) {
    glBegin(GL_QUADS); //LCD Atas
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0, 75.0, -7.0);
    glVertex3f(10.0, 75.0, -7.0);
    glVertex3f(10.0, 75.0, 7.0);
    glVertex3f(-10.0, 75.0, 7.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS Lcd Atas
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-10.0, 75.0, -7.0);
    glVertex3f(10.0, 75.0, -7.0);
    glVertex3f(10.0, 75.0, 7.0);
    glVertex3f(-10.0, 75.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD bawah
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0, 67.0, -7.0);
    glVertex3f(10.0, 67.0, -7.0);
    glVertex3f(10.0, 67.0, 7.0);
    glVertex3f(-10.0, 67.0, 7.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS Lcd bawah
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-10.0, 67.0, -7.0);
    glVertex3f(10.0, 67.0, -7.0);
    glVertex3f(10.0, 67.0, 7.0);
    glVertex3f(-10.0, 67.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD kanan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(10.0, 67.0, -7.0);
    glVertex3f(10.0, 75.0, -7.0);
    glVertex3f(10.0, 75.0, 7.0);
    glVertex3f(10.0, 67.0, 7.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS Lcd kanan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(10.0, 67.0, -7.0);
    glVertex3f(10.0, 75.0, -7.0);
    glVertex3f(10.0, 75.0, 7.0);
    glVertex3f(10.0, 67.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD kiri
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0, 67.0, -7.0);
    glVertex3f(-10.0, 75.0, -7.0);
    glVertex3f(-10.0, 75.0, 7.0);
    glVertex3f(-10.0, 67.0, 7.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS Lcd kiri
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-10.0, 67.0, -7.0);
    glVertex3f(-10.0, 75.0, -7.0);
    glVertex3f(-10.0, 75.0, 7.0);
    glVertex3f(-10.0, 67.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0, 67.0, -7.0);
    glVertex3f(-10.0, 75.0, -7.0);
    glVertex3f(10.0, 75.0, -7.0);
    glVertex3f(10.0, 67.0, -7.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS Lcd depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-10.0, 67.0, -7.0);
    glVertex3f(-10.0, 75.0, -7.0);
    glVertex3f(-10.0, 75.0, 7.0);
    glVertex3f(-10.0, 67.0, 7.0);
    glEnd();
    glBegin(GL_QUADS); //LCD belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-10.0, 67.0, 7.0);
    glVertex3f(-10.0, 75.0, 7.0);
    glVertex3f(10.0, 75.0, 7.0);
    glVertex3f(10.0, 67.0, 7.0);
    glEnd();
    glBegin(GL_LINE_LOOP);//GARIS lcd belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-10.0, 67.0, 7.0);
    glVertex3f(-10.0, 75.0, 7.0);
    glVertex3f(10.0, 75.0, 7.0);
    glVertex3f(10.0, 67.0, 7.0);
    glEnd();

    glBegin(GL_QUADS); //LCD Tiang Bawah
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-5.0, 75.0, -3.5);
    glVertex3f(5.0, 75.0, -3.5);
    glVertex3f(5.0, 75.0, 3.5);
    glVertex3f(-5.0, 75.0, 3.5);
    glEnd();
    glBegin(GL_LINE_LOOP); // Garis LCD Tiang Bawah
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-5.0, 75.0, -3.5);
    glVertex3f(5.0, 75.0, -3.5);
    glVertex3f(5.0, 75.0, 3.5);
    glVertex3f(-5.0, 75.0, 3.5);
    glEnd();
    glBegin(GL_QUADS); //LCD Tiang Atas
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-5.0, 180.0, -3.5);
    glVertex3f(5.0, 180.0, -3.5);
    glVertex3f(5.0, 180.0, 3.5);
    glVertex3f(-5.0, 180.0, 3.5);
    glEnd();
    glBegin(GL_LINE_LOOP); // Garis LCD Tiang Atas
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-5.0, 180.0, -3.5);
    glVertex3f(5.0, 180.0, -3.5);
    glVertex3f(5.0, 180.0, 3.5);
    glVertex3f(-5.0, 180.0, 3.5);
    glEnd();
    glBegin(GL_QUADS); //LCD Tiang
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-2.0, 75.0, 0);
    glVertex3f(2.0, 75.0, 0);
    glVertex3f(2.0, 180.0, 0);
    glVertex3f(-2.0, 180.0, 0);
    glEnd();
    glBegin(GL_LINE_LOOP); // Garis LCD Tiang
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-2.0, 75.0, 0);
    glVertex3f(2.0, 75.0, 0);
    glVertex3f(2.0, 180.0, 0);
    glVertex3f(-2.0, 180.0, 0);
    glEnd();
}

void kakikursi(int px, int py, int pz) {


    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0 + px, -10.0 + py, 50.0 - pz);
    glVertex3f(1 + px, -10.0 + py, 50.0 - pz);                //kaki kursi depan
    glVertex3f(1 + px, -5.0 + py, 50.0 - pz);
    glVertex3f(0 + px, -5.0 + py, 50.0 - pz);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0 + px, -10.0 + py, 49.0 - pz);
    glVertex3f(1 + px, -10.0 + py, 49.0 - pz);                //kaki kursi belakang
    glVertex3f(1 + px, -5.0 + py, 49.0 - pz);
    glVertex3f(0 + px, -5.0 + py, 49.0 - pz);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0 + px, -10.0 + py, 50.0 - pz);
    glVertex3f(0 + px, -10.0 + py, 49.0 - pz);                //kaki kursi kiri
    glVertex3f(0 + px, -5.0 + py, 49.0 - pz);
    glVertex3f(0 + px, -5.0 + py, 50.0 - pz);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1 + px, -5.0 + py, 50.0 - pz);
    glVertex3f(1 + px, -10.0 + py, 50.0 - pz);                //kaki kursi kanan
    glVertex3f(1 + px, -10.0 + py, 49.0 - pz);
    glVertex3f(1 + px, -5.0 + py, 49.0 - pz);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0 + px, -10.0 + py, 50.0 - pz);
    glVertex3f(1 + px, -10.0 + py, 50.0 - pz);                //kaki kursi bawah
    glVertex3f(1 + px, -10.0 + py, 49.0 - pz);
    glVertex3f(0 + px, -10.0 + py, 49.0 - pz);
    glEnd();

}
void bantalkursi(void) {
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, -5.0, 50.0);
    glVertex3f(4, -5.0, 50.0);
    glVertex3f(4, -5.0, 46.0);
    glVertex3f(0, -5.0, 46.0);
    glEnd();

}

void kakimeja(int px, int py, int pz) {
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0 + px, -10.0 + py, 50.0 - pz);
    glVertex3f(1 + px, -10.0 + py, 50.0 - pz);                //kaki meja depan
    glVertex3f(1 + px, -5.0 + py, 50.0 - pz);
    glVertex3f(0 + px, -5.0 + py, 50.0 - pz);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0 + px, -10.0 + py, 49.0 - pz);
    glVertex3f(1 + px, -10.0 + py, 49.0 - pz);                //kaki meja belakang
    glVertex3f(1 + px, -5.0 + py, 49.0 - pz);
    glVertex3f(0 + px, -5.0 + py, 49.0 - pz);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0 + px, -10.0 + py, 50.0 - pz);
    glVertex3f(0 + px, -10.0 + py, 49.0 - pz);                //kaki meja kiri
    glVertex3f(0 + px, -5.0 + py, 49.0 - pz);
    glVertex3f(0 + px, -5.0 + py, 50.0 - pz);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1 + px, -5.0 + py, 50.0 - pz);
    glVertex3f(1 + px, -10.0 + py, 50.0 - pz);                //kaki meja kanan
    glVertex3f(1 + px, -10.0 + py, 49.0 - pz);
    glVertex3f(1 + px, -5.0 + py, 49.0 - pz);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0 + px, -10.0 + py, 50.0 - pz);
    glVertex3f(1 + px, -10.0 + py, 50.0 - pz);                //kaki meja bawah
    glVertex3f(1 + px, -10.0 + py, 49.0 - pz);
    glVertex3f(0 + px, -10.0 + py, 49.0 - pz);
    glEnd();


}

void tutupmeja(void) {
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.9, 0.0);
    glVertex3f(0, -5.0, 50.0);
    glVertex3f(4, -5.0, 50.0);
    glVertex3f(4, -5.0, 43.0);
    glVertex3f(0, -5.0, 43.0);
    glEnd();
}

void penutupkursi(void) {
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0, 0.0, 50.0);
    glVertex3f(1, 0.0, 50.0);
    glVertex3f(1, 0.0, 46.0);
    glVertex3f(0, 0.0, 46.0);
    glEnd();

}

void lampugantung(void) {

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.375, 8.25, 49.5);               //tali
    glVertex3f(0.375, 11.0, 49.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.375, 11.0, 49.5);               //tali
    glVertex3f(3.0, 11.0, 49.5);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0, 8.25, 50.0);
    glVertex3f(0.75, 8.25, 50.0);                //lampu atas
    glVertex3f(0.75, 8.25, 49.0);
    glVertex3f(0, 8.25, 49.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0, 6.5, 50.0);
    glVertex3f(0.75, 6.5, 50.0);                //lampu depan
    glVertex3f(0.75, 8.25, 50.0);
    glVertex3f(0, 8.25, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0, 6.5, 49.0);
    glVertex3f(0.75, 6.5, 49.0);                //lampu belakang
    glVertex3f(0.75, 8.25, 49.0);
    glVertex3f(0, 8.25, 49.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0, 6.5, 50.0);
    glVertex3f(0, 6.5, 49.0);                //lampu kiri
    glVertex3f(0, 8.25, 49.0);
    glVertex3f(0, 8.25, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.75, 6.5, 50.0);
    glVertex3f(0.75, 6.5, 49.0);                //lampu kanan
    glVertex3f(0.75, 8.25, 49.0);
    glVertex3f(0.75, 8.25, 50.0);
    glEnd();

}

void display(void) {
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
    jalanrumah();
    jendelakiri();
    jendelakanan();
    jendelatengah();
    jendeladepantengah();
    jendelabelakang();

    for (int i = 0; i<155; i+=5){
        hiasandindingkiri(i);
    }

    for (int i = 0; i<155; i+=5){
        hiasandindingkanan(i);
    }

    for (int i = 0; i<155; i+=5){
       hiasandindingkiridalam(i);
    }

    for (int i = 0; i<155; i+=5){
    glPushMatrix();
    glTranslatef(180,0,0);
    hiasandindingkiri(i);
    glPopMatrix();
    }

    for (int i = 0; i<155; i+=5){
    glPushMatrix();
    glTranslatef(180,0,0);
    hiasandindingkanan(i);
    glPopMatrix();
    }

    for (int i = 0; i<155; i+=5){
    glPushMatrix();
    glTranslatef(80,0,0);
    hiasandindingkiridalam(i);
    glPopMatrix();
    }


    glPushMatrix();
    glTranslatef(180, 0, 0);
    jendelatengah();
    glPopMatrix();


    atapPintu();
    interior(60, 60, 80);

    /*
       ISI KAMPUS

   */
    pintukampus();
    papantulis();
    pijakankaki();
    redcarpet();
    rakdinding();
    LCD();
    atap();

    //kursi
    glPushMatrix();
    glTranslated(-240, 47, -20);
    glScalef(5, 5, 5);
    glRotatef(90, 0.0, 1.0, 0.0);
    kakikursi(0, 0, 0);
    kakikursi(3, 0, 0);
    kakikursi(0, 0, 3);
    kakikursi(3, 0, 3);
    bantalkursi();
    kakikursi(0, 5, 0);
    kakikursi(0, 5, 3);
    penutupkursi();
    glPopMatrix();

    //meja
    glPushMatrix();
    glTranslated(-100, 47, -200);
    glScalef(5, 5, 5);
    kakimeja(0, 0, 0);
    kakimeja(3, 0, 0);
    kakimeja(0, 0, 6);
    kakimeja(3, 0, 6);
    tutupmeja();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-125, 20, 220);
    glScalef(5, 5, 5);
    glRotatef(180, 0.0, 1.0, 0.0);
    lampugantung();
    glPopMatrix();


    glPopMatrix();
    glutSwapBuffers();
}

void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}
/*
Cara penggunaan :
+++++++++++++++++++++----------------------------------------------------+++++++++++++
untuk penggunaan mouse langsung klik rumah dan arahkan
+++++++++++++++++++++----------------------------------------------------+++++++++++++
tombol pada keyboard:
"a": ke kiri
"d": ke kanan
"w": ke depan
"s": ke belakang
"z" : ke atas
"x" : ke bawah
"i" : rotasi ke bawah terhadap sumbu X
"k" : rotasi ke atas terhadap sumbu X
"j" : rotasi ke kiri terhadap sumbu Y
"l" : rotasi ke kanan terhadap sumbu Y
"m" : rotasi ke kiri terhadap sumbu Z
"n" : rotasi ke kanan terhadap sumbu Z
"5" : transparankan rumah
*/
void keyboard(unsigned char key, int x, int y) {

    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(5.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-5.0, 0.0, 0.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 5.0, 0.0);
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, -5.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 5.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0, 1.0, 0.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0, 1.0, 0.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0, 0.0, 1.0, 0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0, 0.0, 0.0, 1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}
void resize(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, width / height, 1.0, 1000.0);
    glTranslatef(0.0, -70.0, -700.0);
    glMatrixMode(GL_MODELVIEW);
}
