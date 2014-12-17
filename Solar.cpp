#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
/**
 * This program draws a model of the solar system.
 *
 * @author Diego H. Gonzalez 
 * @author William Stiles
 *
 * @version 4.30.14
 */

/* One astronomical unit */
GLfloat au = 4;

/* Ratios of size compared to Earth */
GLfloat mercuryf = .383;
GLfloat venusf = .949;
GLfloat earthf = .30;
GLfloat marsf = .532;
GLfloat jupiterf = 11.21;
GLfloat saturnf = 9.45;
GLfloat uranusf = 4.01;
GLfloat neptunef = 3.88;

/* Distances of orbit from the sun compared to one Astronomical Unit*/
GLfloat mercuryd = .311;
GLfloat venusd = .727;
GLfloat earthd = 1.0;
GLfloat marsd = 1.60;
GLfloat jupiterd = 5.24;
GLfloat saturnd = 9.9;
GLfloat uranusd = 20.0;
GLfloat neptuned = 29.97;

/* Angles for planet rotation */
GLfloat mercurya = 55.92;
GLfloat venusa = 284.83;
GLfloat eartha = 219.1;
GLfloat marsa = 208.56;
GLfloat jupitera = 114.84;
GLfloat saturna = 229.66;
GLfloat uranusa = 12.77;
GLfloat neptunea = 335.44;

/* Orbital periods of planets */
GLfloat mercuryv = .241;
GLfloat venusv = .615;
GLfloat earthv = 1;
GLfloat marsv = 1.88;
GLfloat jupiterv = 11.9;
GLfloat saturnv = 29.4;
GLfloat uranusv = 83.7;
GLfloat neptunev = 163.7;

/* Years to display */
int years = 0;

/* Speed variables */
GLfloat speed = 1.0;
GLfloat MAX = 5.0;
GLfloat MIN = 0.1;

/**
 * Initializes Opengl
 */
void init(void) {                                                               
    glClearColor(0.0, 0.0, 0.0, 1.0);                                           
    glMatrixMode(GL_PROJECTION);                                                
    glLoadIdentity();                                                           
    glOrtho(-(neptuned*au/4.1) , (neptuned*au/4.1), -(neptuned*au/4.1),
            (neptuned*au/4.1), -(neptuned*au/4.1), (neptuned*au/4.1));                                        
    glEnable(GL_COLOR_MATERIAL);
}

/**
 * Function used to draw the Sun
 */
void DrawSun() {
    //Draws the sun as the origin    
    GLfloat surface[] = {1.0, 1.0, 0.0, 1.0};
    glColor3f(1.0, 1.0, 0.0);                                                   
    GLUquadricObj* sun;                                                      
    sun = gluNewQuadric();                                                   
    gluQuadricNormals(sun, GL_TRUE);                                         
    gluSphere(sun, .75, 20, 20);  
}

/**
 * Function used to draw the planet Mercury
 */
void DrawMercury() {
    //Draws Mercury and sets its position    
    glPushMatrix();
    glColor3f(.5,.4,0);    
    glRotatef(mercurya, 0, 1, 0);
    glTranslatef(mercuryd*au, 0.0, 0.0);
    GLUquadricObj* mercury;                                                      
    mercury = gluNewQuadric();                                                   
    gluQuadricNormals(mercury, GL_TRUE);                                         
    gluSphere(mercury, mercuryf*earthf, 20, 20);
    glPopMatrix();
    //Draws the orbit path
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* ring;
    ring = gluNewQuadric();
    gluDisk(ring, (mercuryd * au) - .05, (mercuryd * au) + .05, 100, 100);
    glPopMatrix();

}

/**
 * Function used to draw the planet Venus
 */
void DrawVenus() {    
    //Draws Venus and sets its position 
    glPushMatrix();                                                             
    glColor3f(1.0,0.0,2.0);
    glRotatef(venusa, 0, 1, 0);
    glTranslatef(venusd*au, 0.0, 0.0); 
    GLUquadricObj* venus;                                                      
    venus = gluNewQuadric();                                                   
    gluQuadricNormals(venus, GL_TRUE);                                         
    gluSphere(venus, venusf*earthf, 20, 20);                                             
    glPopMatrix();
    //Draws the orbit path
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* ring;
    ring = gluNewQuadric();
    gluDisk(ring, (venusd * au) - .05, (venusd * au) + .05, 100, 100);
    glPopMatrix();
}

/**
 * Function used to draw the planet Venus
 */
void DrawEarth() {    
    //Draws Earth and sets its position
    glPushMatrix();              
    glColor3f(0,1,0); 
    glRotatef(eartha, 0, 1, 0);
    glTranslatef(earthd*au, 0.0, 0.0); 
    GLUquadricObj* earth;                                                      
    earth = gluNewQuadric();                                                   
    gluQuadricNormals(earth, GL_TRUE);
    gluSphere(earth, earthf, 20, 20);                                             
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //Draws the orbit path
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* ring;
    ring = gluNewQuadric();
    gluDisk(ring, (earthd * au) - .05, (earthd * au) + .05, 100, 100);
    glPopMatrix();
}

/**
 * Function used to draw Mars
 */
void DrawMars() {    
    //Draws Mars and sets its position     
    glPushMatrix();    
    glColor3f(1.0,0,0);    
    glRotatef(marsa, 0, 1, 0);
    glTranslatef(marsd*au, 0.0, 0.0); 
    GLUquadricObj* mars;                                                      
    mars = gluNewQuadric();                                                   
    gluQuadricNormals(mars, GL_TRUE);                                         
    gluSphere(mars, marsf*earthf, 20, 20);                                             
    glPopMatrix();
    //Draws the orbit path
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* ring;
    ring = gluNewQuadric();
    gluDisk(ring, (marsd * au) - .05, (marsd * au) + .05, 100, 100);
    glPopMatrix();
}

/**
 * Function used to draw Jupiter
 */
void DrawJupiter() {    
    //Draws Jupitor and sets its position   
    GLfloat scaling = 2.0;
    glPushMatrix();
    glColor3f(1.0,0.4,0);    
    glRotatef(jupitera, 0, 1, 0);
    glTranslatef(jupiterd*au/scaling, 0.0, 0.0); 
    GLUquadricObj* jupiter;                                                      
    jupiter = gluNewQuadric();                                                   
    gluQuadricNormals(jupiter, GL_TRUE);                                         
    gluSphere(jupiter, earthf*jupiterf, 20, 20);                                             
    glPopMatrix();
    //Draws the orbit path
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* ring;
    ring = gluNewQuadric();
    gluDisk(ring, (jupiterd * au / scaling) - .05, (jupiterd * au / scaling) +
            .05, 100, 100);
    glPopMatrix();

}

/**
 * Function used to draw Saturn 
 */
void DrawSaturn() {    
    //Draws Saturn and sets its position 
    GLfloat scaling = 2.2;
    glPushMatrix();   
    glColor3f(.8,.2,0);    
    glRotatef(saturna, 0, 1, 0);
    glTranslatef(saturnd*au/scaling, 0.0, 0.0); 
    GLUquadricObj* saturn;                                                      
    saturn = gluNewQuadric();                                                   
    gluQuadricNormals(saturn, GL_TRUE);                                         
    gluSphere(saturn, saturnf*earthf, 20, 20);                                             
    glPopMatrix();
    //Draws the orbit path
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* ring;
    ring = gluNewQuadric();
    gluDisk(ring, (saturnd * au / scaling) - .05, (saturnd * au / scaling) +
            .05, 100, 100);
    glPopMatrix();
}

/**
 * Function used to draw Uranus
 */
void DrawUranus() {    
    //Draws Uranus and sets its position 
    GLfloat scaling = 3.45;    
    glPushMatrix();                                                             
    glColor3f(0,.4,1.0); 
    glRotatef(uranusa, 0, 1, 0);
    glTranslatef(uranusd*au/scaling, 0.0, 0.0);
    GLUquadricObj* uranus;                                                      
    uranus = gluNewQuadric();                                                   
    gluQuadricNormals(uranus, GL_TRUE);                                         
    gluSphere(uranus, uranusf*earthf, 20, 20);                                             
    glPopMatrix();
    //Draws the orbit path
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* ring;
    ring = gluNewQuadric();
    gluDisk(ring, (uranusd * au / scaling) - .05, (uranusd * au / scaling) +
            .05, 100, 100);
    glPopMatrix();

}

/**
 * Function used to draw Neptune
 */
void DrawNeptune() {    
    //Draws Neptune and sets its position
    GLfloat scaling = 4.2;    
    glPushMatrix();                                                             
    glColor3f(0, 0, 1);
    glRotatef(neptunea, 0, 1, 0);
    glTranslatef(neptuned*au/scaling, 0.0, 0.0); 
    GLUquadricObj* neptune;                                                      
    neptune = gluNewQuadric();                                                   
    gluQuadricNormals(neptune, GL_TRUE);                                         
    gluSphere(neptune, neptunef*earthf, 20, 20);                                             
    glPopMatrix();
    //Draws the orbit path
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadricObj* ring;
    ring = gluNewQuadric();
    gluDisk(ring, (neptuned * au / scaling) - .05, (neptuned * au / scaling) + .05, 100, 100);
    glPopMatrix();

}

/**
 * Function used to set the light on the solar model
 */
void setLight() {
    //Diffuse color 
    GLfloat LightDiffuse[] = { 1.0f, 1.0f, 0.8f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, LightDiffuse);
    //Enable each individual light
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
    glEnable(GL_LIGHT5);
    //Initializes the positions of the light
    GLfloat position0[] = {0, 3, 0, 1};
    GLfloat position1[] = {0, -3, 0, 1};
    GLfloat position2[] = {0, 0, -3, 1};
    GLfloat position3[] = {0, 0, 3, 1};
    GLfloat position4[] = {3, 0, 0, 1};
    GLfloat position5[] = {-3, 0, 0, 1};
    //Places the lights in their respective positions
    glLightfv(GL_LIGHT0, GL_POSITION, position0);
    glLightfv(GL_LIGHT1, GL_POSITION, position1);
    glLightfv(GL_LIGHT2, GL_POSITION, position2);
    glLightfv(GL_LIGHT3, GL_POSITION, position3);
    glLightfv(GL_LIGHT4, GL_POSITION, position4);
    glLightfv(GL_LIGHT5, GL_POSITION, position5);
    glEnable(GL_LIGHTING);
}

/**
 * Function used to draw the solar system
 */
void render(void) {                                                             
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                         
    glMatrixMode(GL_MODELVIEW);                                                 
    glEnable(GL_DEPTH_TEST);                                                    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);                        
    glLoadIdentity();                                                           
    gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);   
    // Draws the Planet and Sun Models    
    DrawEarth();
    DrawMercury();   
    DrawVenus();
    DrawMars();
    DrawJupiter();
    DrawSaturn(); 
    DrawUranus();
    DrawNeptune();
    DrawSun();   
    // Turns on the lights
    setLight();
    // Counts the Earth Years
    if((eartha + earthv*speed) > 360){
        years++;
    }
    
    // Determines the angle of the planets position
    mercurya = fmod((mercurya + speed*(earthv/mercuryv)), 360);
    venusa = fmod((venusa + speed*(earthv/venusv)), 360);
    eartha = fmod((eartha + speed*(earthv/earthv)), 360);
    marsa = fmod((marsa + speed*(earthv/marsv)), 360);
    jupitera = fmod((jupitera + speed*(earthv/jupiterv)), 360);
    saturna = fmod((saturna + speed*(earthv/saturnv)), 360);
    uranusa = fmod((uranusa + speed*(earthv/uranusv)), 360);
    neptunea = fmod((neptunea + speed*(earthv/neptunev)), 360);
    glutSwapBuffers();
    // prints the number of Earth years to the title
    char temp[100];
    sprintf(temp, "Earth years: %d", years);
    glutSetWindowTitle(temp);    
    glutPostRedisplay();    
} 

/**
 * Function that handles keys being pressed
 */
void myKey(unsigned char key, int x, int y) {
    // If the j key is pressed increase the rotation of the planets unless the 
    // speed is alread at the maximum allowed
    if (key == 'j' && speed <= MAX) {
        speed +=  .1;
    }
    // If the k key is pressed decrease the rotation of the planets unless the 
    // speed is already the minimum allowed
    else if (key == 'k' && speed >= MIN) {
        speed -= .1;
    }    
}                                                                               
  
/**
 * Th
 */
int main(int argc, char**argv) {   
    glutInit(&argc, argv);                                                      
    glutInitWindowPosition(0,0);                                                
    glutInitWindowSize(800,600);                                                
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);                  
    glEnable(GL_DEPTH_TEST);                                                    

    glutCreateWindow("Earth years: 0");                                                 

    init();                                                                     
    glutDisplayFunc(render);                                                    
    glutKeyboardFunc(myKey);
    glutMainLoop();      
}    
