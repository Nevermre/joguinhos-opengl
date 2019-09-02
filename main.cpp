/*
 Lucas Cunha Peres Rodrigues 83481
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <time.h>
//#include <conio2.h>
#include <cstdlib>
#include <sstream>

#define QUADRADO 1
#define TRIANGULO 2
#define LOSANGO   3

using namespace std;
// Variáveis
char texto[30];
int ordem[5];
char tab[40][40];

const int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;
GLfloat win, r, g, b;
GLint view_w, view_h, facilidade,segundos;
int x1,x2,x3,x4,x5,y1,y2,y3,y4,y5,xx,yy,falta=0,chances=0,acertou=0;
double corR=0,corB=0,corG=0;

GLboolean b1=false,b2=false,b3=false,b4=false,b5=false, trancado=true, escolhido=false, ganhou=false;



void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);

    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
void DesenhaMemoria(void)
{

    if((chances>=15 && facilidade==QUADRADO) || (chances>=25 && facilidade==TRIANGULO) ){
            std::stringstream ss; //from
            ss << acertou;
            std::string s = ss.str ();
            char* char_type = (char*) s.c_str();
            renderBitmapString(25,550,(void *)font,"FIM DE JOGO");
            renderBitmapString(25,500,(void *)font,"NUMERO DE ACERTOS:");
            renderBitmapString(300,500,(void *)font,char_type);

    }
    else{
    renderBitmapString(25,25,(void *)font,"Jogo da memoria");
    if(escolhido==false){
        segundos = glutGet(GLUT_ELAPSED_TIME);
             xx=6;
             yy=5;
        if(facilidade==TRIANGULO){
            xx=10;
            yy=8;
        }

        while(1){
        x1=rand()%xx;
        x2=rand()%xx;
        x3=rand()%xx;
        y1=rand()%yy;
        y2=rand()%yy;
        y3=rand()%yy;
        x4=rand()%xx;
        x5=rand()%xx;
        y4=rand()%yy;
        y5=rand()%yy;
        corR=(rand()%100)/100.0;
        corG=(rand()%100)/100.0;
        corB=(rand()%100)/100.0;

        if((x1!=x2 &&y1!=y2)&&(x1!=x3 && y1!=y3) && (x2!=x3 && y2!=y3) )
            if((x1!=x4 && y1!=y4) && (x1!=x5 && y1!=y5)&& (x2!=x5 && y2!=y5)&& (x2!=x4 && y2!=y4)&& (x3!=x4 && y3!=y4)&& (x3!=x5 && y3!=y5)&& (x4!=x5 && y4!=y5))
            break;
            break;
        }
        escolhido=true;
    }
     	glColor3f (0.0, 0.0, 0.0);
    glPointSize (20.0);
    for(int j=0; j<yy; j++){
    for(int i=0;i<xx; i++){
    glBegin(GL_LINE_LOOP);

        glVertex2f(i*70+50,j*70+50);
        glVertex2f(i*70+120,j*70+50);
        glVertex2f(i*70+120,j*70+120);
        glVertex2f(i*70+50,j*70+120);

    glEnd();
}}

glColor3f (1.0, 0.5, 0.0);
    glPointSize (10.0);
glEdgeFlag(true);
    for(int j=0; j<yy; j++){
    for(int i=0;i<xx; i++){
    glBegin(GL_POLYGON);

        glVertex2f(i*70+52,j*70+52);
        glVertex2f(i*70+118,j*70+52);
        glVertex2f(i*70+118,j*70+118);
        glVertex2f(i*70+52,j*70+118);

    glEnd();
}}

//delay(5000);



    glutPostRedisplay();


    glColor3f (0.0, 0.0, 1.0);
    glPointSize (10.0);
glEdgeFlag(true);


   glColor3f (corR, corG, corB);
    glPointSize (10.0);
glEdgeFlag(true);


    if(glutGet(GLUT_ELAPSED_TIME)<5000+segundos){

        glBegin(GL_POLYGON);
            glVertex2f(x1*70+52,y1*70+52);
            glVertex2f(x1*70+118,y1*70+52);
            glVertex2f(x1*70+118,y1*70+118);
            glVertex2f(x1*70+52,y1*70+118);

        glEnd();



        glBegin(GL_POLYGON);

            glVertex2f(x2*70+52,y2*70+52);
            glVertex2f(x2*70+118,y2*70+52);
            glVertex2f(x2*70+118,y2*70+118);
            glVertex2f(x2*70+52,y2*70+118);

        glEnd();

        glBegin(GL_POLYGON);

            glVertex2f(x3*70+52,y3*70+52);
            glVertex2f(x3*70+118,y3*70+52);
            glVertex2f(x3*70+118,y3*70+118);
            glVertex2f(x3*70+52,y3*70+118);

        glEnd();
        if(facilidade==TRIANGULO){

            glBegin(GL_POLYGON);

            glVertex2f(x4*70+52,y4*70+52);
            glVertex2f(x4*70+118,y4*70+52);
            glVertex2f(x4*70+118,y4*70+118);
            glVertex2f(x4*70+52,y4*70+118);

            glEnd();

            glBegin(GL_POLYGON);

            glVertex2f(x5*70+52,y5*70+52);
            glVertex2f(x5*70+118,y5*70+52);
            glVertex2f(x5*70+118,y5*70+118);
            glVertex2f(x5*70+52,y5*70+118);

            glEnd();

        }
        trancado=true;
    }
        else
            trancado=false;
        }
    glutPostRedisplay();


}





void DesenhaOrdem(){


    if(ganhou==true){
        glColor3f(0,0,0);
        renderBitmapString(25,550,(void *)font,"FIM DE JOGO");
        renderBitmapString(50,500,(void *)font,"VOCE VENCEU");


    }

    else{

    if(escolhido==false){
        segundos = glutGet(GLUT_ELAPSED_TIME);


    while(1){
        x1=rand()%9;
        x2=rand()%9;
        x3=rand()%9;
        x4=rand()%9;
         x5=rand()%9;


        if(x1!=x2 && x1!=x3 && x1!=x4 && x1!=x5 && x2!=x3 && x2!=x4 && x2!=x5 && x3!=x4 && x3!=x5 && x4!=x5 )
             break;
  }

        ordem[0]=x1;
        ordem[1]=x2;
        ordem[2]=x3;
        ordem[3]=x4;
        ordem[4]=x5;
        int temp;
        for (int o = 0; o < 5 - 1; o++){
        for (int t = (o+1); t < 5; t++){
            if(facilidade==3){
                if (ordem[t] < ordem[o]){
                    temp = ordem[o];
                    ordem[o] = ordem[t];
                    ordem[t] = temp;}
                }
            else{
                    if (ordem[t] > ordem[o]){
                    temp = ordem[o];
                    ordem[o] = ordem[t];
                    ordem[t] = temp;}
                }

                }}



        for(int o=0;o<5;o++)
            cout << ordem[o];
        escolhido=true;
        falta=4;
    }

  glColor3f(0,0,0);
  glBegin(GL_LINE_LOOP);
    glVertex2f(375,125);
    glVertex2f(425,125);
    glVertex2f(425,175);
    glVertex2f(375,175);
    glEnd();


  glBegin(GL_LINE_LOOP);
    glVertex2f(25,525);
    glVertex2f(75,525);
    glVertex2f(75,575);
    glVertex2f(25,575);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(225,325);
    glVertex2f(275,325);
    glVertex2f(275,375);
    glVertex2f(225,375);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(50,150);
    glVertex2f(100,150);
    glVertex2f(100,200);
    glVertex2f(50,200);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glVertex2f(525,525);
    glVertex2f(575,525);
    glVertex2f(575,575);
    glVertex2f(525,575);
    glEnd();

    glColor3f(1,1,1);
  glBegin(GL_LINE_LOOP);
    glVertex2f(373,123);
    glVertex2f(423,123);
    glVertex2f(423,173);
    glVertex2f(373,173);
    glEnd();


  glBegin(GL_LINE_LOOP);
    glVertex2f(23,523);
    glVertex2f(73,523);
    glVertex2f(73,573);
    glVertex2f(23,573);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(223,323);
    glVertex2f(273,323);
    glVertex2f(273,373);
    glVertex2f(223,373);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(48,148);
    glVertex2f(98,148);
    glVertex2f(98,198);
    glVertex2f(48,198);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glVertex2f(523,523);
    glVertex2f(573,523);
    glVertex2f(573,573);
    glVertex2f(523,573);
    glEnd();


    glColor3f(0,0,0);
    if(glutGet(GLUT_ELAPSED_TIME)<5000+segundos){

    std::stringstream ss; //from
            ss << x1;
            std::string s = ss.str ();
            char* char_type = (char*) s.c_str();


  renderBitmapString(395,145,(void *)font,char_type);

    ss.str("");
        ss << x2;
             s = ss.str ();
             char_type = (char*) s.c_str();


  renderBitmapString(45,545,(void *)font,char_type);

  ss.str("");
        ss << x3;
             s = ss.str ();
             char_type = (char*) s.c_str();


  renderBitmapString(245,345,(void *)font,char_type);

  ss.str("");
        ss << x4;
             s = ss.str ();
             char_type = (char*) s.c_str();


  renderBitmapString(70,170,(void *)font,char_type);

  ss.str("");
        ss << x5;
             s = ss.str ();
             char_type = (char*) s.c_str();


  renderBitmapString(545,545,(void *)font,char_type);

    }
    }
    glutPostRedisplay();




}






void DesenhaNaval(void){

    ganhou =true;
    for(int i =0; i<40; i++)
        for(int j=0; j<40; j++){
            if(tab[i][j]!='A' && tab[i][j]!='B' && tab[i][j]!='E' && tab[i][j]!='T')
                ganhou=false;

    }




    if(escolhido==false){
    if (ganhou==true){

        glColor3f(0,0,0);
        renderBitmapString(25,550,(void *)font,"FIM DE JOGO");
        renderBitmapString(50,500,(void *)font,"VOCE VENCEU");


    }

        chances=2;
            for(int i=0; i<40; i++)
                for(int j=0; j<40; j++)
                    tab[i][j]='A';

        x1=rand()%35;
        y1=rand()%38;
        cout << x1 << " " << y1;
        tab[x1][y1]='D';
        tab[x1][y1+1]='D';
        tab[x1-1][y1+1]='D';
        tab[x1-1][y1+2]='D';
        tab[x1-1][y1+3]='D';


        x1=rand()%38;
        y1=rand()%34;
        int k=0;
        while(k!=2){
        while(tab[x1][y1]=='A'){

            if(tab[x1][y1+1]=='A' && tab[x1][y1+2]=='A' && tab[x1+1][y1+2]=='A' && tab[x1][y1+3]=='A' && tab[x1][y1+4]=='A'){
                tab[x1][y1]='S';
                tab[x1][y1+1]='S'; tab[x1][y1+2]='S'; tab[x1+1][y1+2]='S'; tab[x1][y1+3]='S'; tab[x1][y1+4]='S';
                break;
            }


            x1=rand()%34;
            y1=rand()%38;

            }

            x1=rand()%34;
            y1=rand()%38;
            k++;

        }
            x1=rand()%38;
        y1=rand()%33;
        k=0;
        while(k!=2){
        while(tab[x1][y1]=='A'){

            if(tab[x1][y1+1]=='A' && tab[x1][y1+2]=='A' && tab[x1+1][y1+2]=='A' && tab[x1][y1+3]=='A' && tab[x1+1][y1+3]=='A'&& tab[x1+1][y1+4]=='A'&& tab[x1+1][y1+5]=='A'){
                tab[x1][y1]='P';
                tab[x1][y1+1]='P'; tab[x1][y1+2]='P'; tab[x1+1][y1+2]='P'; tab[x1][y1+3]='P'; tab[x1+1][y1+3]='P'; tab[x1+1][y1+4]='P'; tab[x1+1][y1+5]='P';
                break;
            }
            x1=rand()%33;
            y1=rand()%38;
        }
        k++;
            x1=rand()%33;
            y1=rand()%38;
        }

            x1=rand()%38;
        y1=rand()%38;
        k=0;
        while(k!=3){
        while(tab[x1][y1]=='A'){

            if(tab[x1][y1+1]=='A' && tab[x1+1][y1+1]=='A'){

                tab[x1][y1]='C';
                tab[x1][y1+1]='C'; tab[x1+1][y1+1]='C';

                break;
            }

            x1=rand()%38;
        y1=rand()%38;
        }
         x1=rand()%38;
        y1=rand()%38;

        k++;
        }

        k=0;
        x1=rand()%38;
        y1=rand()%37;

        while(k!=2){

                while(tab[x1][y1]=='A'){

                    if(tab[x1][y1+1]=='A' && tab[x1+1][y1+2]=='A'){

                        tab[x1][y1]='L';
                        tab[x1][y1+1]='L';
                        tab[x1+1][y1+2]='L';
                        break;

                    }

                    x1=rand()%38;
                    y1=rand()%37;

                }


        x1=rand()%38;
        y1=rand()%37;
            k++;
        }

        x1=rand()%39;
        y1=rand()%39;
        k=0;
        while(tab[x1][y1]=='A' && k!=3){

            tab[x1][y1]='B';
            x1=rand()%39;
            y1=rand()%39;
            k++;
        }


        for(int i=0; i<40; i++){
                for(int j=0; j<40; j++)
                    cout << tab[i][j];
                cout << endl;
        }

        escolhido=true;


    }
if(chances==0 || ganhou == true){


        glColor3f(0,0,0);
        renderBitmapString(25,550,(void *)font,"FIM DE JOGO");
        if(ganhou == true)
            renderBitmapString(50,500,(void *)font,"VOCE GANHOU");
        else
            renderBitmapString(50,500,(void *)font,"VOCE PERDEU");




    }
    else{

    //cout << "entrou";
    	glColor3f (0.0, 0.0, 0.0);
    glPointSize (20.0);
    //  glPolygonMode (GL_FRONT, GL_POINT);
     //glPolygonMode (GL_FRONT, GL_LINE);
    //    glPolygonMode (GL_FRONT, GL_FILL);
    glEdgeFlag(true);
    for(int j=0; j<40; j++){
    for(int i=0;i<40; i++){
    glBegin(GL_LINE_LOOP);

        glVertex2f(i*18+15,j*15+15);
        glVertex2f(i*18+30,j*15+15);
        glVertex2f(i*18+30,j*15+30);
        glVertex2f(i*18+15,j*15+30);

    glEnd();
}}

 	glColor3f (0.0, 0.0, 1.0);
    glPointSize (20.0);
    //  glPolygonMode (GL_FRONT, GL_POINT);
     //glPolygonMode (GL_FRONT, GL_LINE);
    //    glPolygonMode (GL_FRONT, GL_FILL);
    glEdgeFlag(true);
    for(int j=0; j<40; j++){
    for(int i=0;i<40; i++){
            if(tab[i][j]=='T')
               glColor3f (0.0, 1.0, 0.0);
            if(tab[i][j]=='E' )
               glColor3f (1.0, 0.0, 0.0);



    glBegin(GL_POLYGON);

        glVertex2f(i*18+16,j*15+16);
        glVertex2f(i*18+29,j*15+16);
        glVertex2f(i*18+29,j*15+29);
        glVertex2f(i*18+16,j*15+29);

    glEnd();
    glColor3f (0.0, 0.0, 1.0);
}}

glutPostRedisplay();
}

}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glClear(GL_COLOR_BUFFER_BIT);

     // Define a cor corrente
     glColor3f(r,g,b);

     // Desenha uma facilidade
     switch (facilidade) {
            case QUADRADO:  DesenhaMemoria();
                            break;
            case TRIANGULO:  DesenhaMemoria();
                            break;
             case 3:  DesenhaOrdem();
                            break;
            case 4: DesenhaOrdem();
                            break;
            case 5: DesenhaNaval();
                            break;
            case 6: //glutDestroyWindow(glutGetWindow());
                     exit(0);
                     break;

     }

     // Exibe a posição do mouse na janela
     glColor3f(1.0f,1.0f,1.0f);
     //DesenhaTexto(texto);

     glutSwapBuffers();
}



// Gerenciamento do menu com as opções de cores
void MenuMemoria(int op)
{
   switch(op) {
            case 0:
                     facilidade = QUADRADO;
                     break;
            case 1:
                     facilidade = TRIANGULO;
                     break;
            case 2:
                     facilidade = 3;
                     break;
            case 3:
                     facilidade = 4;
                     break;
            case 4:
                     facilidade = 5;
                     break;
            case 6:
                    glutDestroyWindow(glutGetWindow());
                     exit(0);
                     break;
    }
    glutPostRedisplay();
}

// Gerenciamento do menu principal
void MenuPrincipal(int op)
{
}

// Criacao do Menu
void CriaMenu()
{
    int menu,submenu1,submenu2,submenu3,submenu4;



    submenu2 = glutCreateMenu(MenuMemoria);
    glutAddMenuEntry("Facil",0);
    glutAddMenuEntry("Dificil",1);
    submenu1 = glutCreateMenu(MenuMemoria);
    glutAddMenuEntry("Crescente",2);
    glutAddMenuEntry("Decrescente",3);
    submenu3 = glutCreateMenu(MenuMemoria);
    glutAddMenuEntry("Batalha Naval",4);
    submenu4 = glutCreateMenu(MenuMemoria);

    glutAddMenuEntry("exit",6);
    menu = glutCreateMenu(MenuPrincipal);


    glutAddSubMenu("Memoria",submenu2);
    glutAddSubMenu("Em Ordem",submenu1);
    glutAddSubMenu("Batalha Naval",submenu3);
    glutAddSubMenu("Exit",submenu4);



    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    win=150.0f;
    r = 0.0f;
    g = 0.0f;
    b = 1.0f;
    strcpy(texto, "(0,0)");

    CriaMenu();

}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (0, 750, 0, 650);
}

// Função callback chamada sempre que o mouse é movimentado
// sobre a janela GLUT com um botão pressionado
void MoveMouseBotaoPressionado(int x, int y)
{
     sprintf(texto, "Botao pressionado (%d,%d)", x, y);
     glutPostRedisplay();
}




void HandleMouse(int button, int state, int x, int y)
{
     /* Os valores de x e y retornados pelo clique do mouse
        sao tomados em relacao ao canto superior esquerdo da
        janela e correspondem ao numero de pixels na janela de
        tamanho (view_w, view_h). Como o sistema de coordenadas
        define que a origem do sistema, ponto (0,0), esta no centro
        da janela de dimensao (2win, 2win), definido pelo viewport,
        entao as coordenadas (x,y) precisam ser ajustadas:

          x pixels na janela de largura view_w valem
          (2win/view_h) * x na janela de largura 2win.
          Idem para a coordenada y.

      */



	if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN) {

                if(facilidade==5){

                    for(int i=0;i<40; i++)
                        for(int j=0; j<40;j++)
                            if( x>i*18+15 && x< i*18+30 && (650-y) >j*15+15 && (650-y) < j*15+30){
                                cout << "linha " << i << " coluna " << j << tab[i][j];
                                if(tab[i][j]!='A' && tab[i][j]!='B')
                                    tab[i][j]='T';
                                if(tab[i][j]=='B'){
                                    tab[i][j]='E';
                                        chances--;
                                }


                            }


                   // cout << (x*18+30)/40;



                }

                if(facilidade==3 || facilidade==4){
                    int escolha=0;
                    if(x<425 && x>375 && (650-y)<175 && (650-y)>125 )
                        escolha = x1;

                    if(x<75 && x>25 && (650-y)<575 && (650-y)>525 )
                        escolha = x2;

                    if(x<275 && x>225 && (650-y)<375 && (650-y)>325 )
                        escolha = x3;

                    if(x<100 && x>50 && (650-y)<200 && (650-y)>150 )
                        escolha = x4;

                    if(x<575 && x>525 && (650-y)<575 && (650-y)>525 )
                        escolha = x5;

                        cout << escolha;


                        if(escolha == ordem[0]){
                        cout << "acertou" << endl;
                    for(int o=0; o < falta;o++)
                            ordem[o]=ordem[o+1];
                    ordem[falta]=-1;
                    falta--;

                        }
                        else{

                            escolhido=false;
                        }
                    if(ordem[0]==-1){
                        cout << "venceu" << endl;
                        ganhou=true;
                    }

                }

                if(facilidade == TRIANGULO || facilidade==QUADRADO){
                if(trancado==false){
                chances++;
                int mod=3;
                if(facilidade==TRIANGULO)
                    mod=5;
                if(chances%mod==0)
                    escolhido=false;

            cout << "x = " << x << "  y = " << y << "(View_h, View_w) = (" << view_h << ", " << view_w << ")" << endl;
			if(x>=x1*70+52 && x<=x1*70+118 && (650-y)>=y1*70+52 && (650-y)<=y1*70+118){
                acertou++;
                if(b1==true){
                    acertou--;
                    chances--;
                    if(escolhido==false)
                        escolhido=true;
                }
                b1=true;
                cout << "acertou " << chances << endl;


			}
			if(x>=x2*70+52 && x<=x2*70+118 && (650-y)>=y2*70+52 && (650-y)<=y2*70+118){
                acertou++;
                if(b2==true){
                    acertou--;
                    chances--;
                    if(escolhido==false)
                        escolhido=true;
                }
                b2=true;
                cout << "acertou" << endl;


			}

			if(x>=x3*70+52 && x<=x3*70+118 && (650-y)>=y3*70+52 && (650-y)<=y3*70+118){
                acertou++;
                if(b3==true){
                    acertou--;
                    chances--;
                    if(escolhido==false)
                        escolhido=true;
                }
                b3=true;
                cout << "acertou" << endl;


			}
			if(facilidade==TRIANGULO){
                if(x>=x4*70+52 && x<=x4*70+118 && (650-y)>=y4*70+52 && (650-y)<=y4*70+118){
                    acertou++;
                    if(b4==true){
                        acertou--;
                        chances--;
                        if(escolhido==false)
                            escolhido=true;
                    }
                    b4=true;
                    cout << "acertou" << endl;


                }

                if(x>=x5*70+52 && x<=x5*70+118 && (650-y)>=y5*70+52 && (650-y)<=y5*70+118){
                acertou++;
                if(b5==true){
                    acertou--;
                    chances--;
                    if(escolhido==false)
                        escolhido=true;
                }
                b5=true;
                cout << "acertou" << endl;


                }

			}


			if(chances%mod==0){
                b1=false;
                b2=false;
                b3=false;
                b4=false;
                b5=false;
                trancado=true;
			}


            glutPostRedisplay();
		}
		}}
//		if (state == GLUT_UP) {
//
//             Inclua o codigo para fazer o retangulo voltar ao tamanho original
//
//        }
        glutPostRedisplay();
    }


}



// Programa Principal
int main(int argc, char** argv)
{
    srand(time(0));
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(750,650);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Joguinhos computação gráfica");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutMotionFunc(MoveMouseBotaoPressionado);
     //glutPassiveMotionFunc(MoveMouse);
     glutMouseFunc(HandleMouse);
     //glutSpecialFunc(TeclasEspeciais);
     Inicializa();

     glutMainLoop();
}

